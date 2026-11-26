package cweng

import (
	"context"
	"errors"
	"fmt"
	"uacgo/capwap"
)

// CommandTicket separates submission from AP acknowledgement. Firmware
// serv_packet_send queues an immutable packet; business policies must not
// wait for one AP's ACK before issuing another AP's command.
type CommandTicket struct {
	done   chan struct{}
	result CommandResult
	err    error
}

func (t *CommandTicket) Wait(ctx context.Context) (CommandResult, error) {
	select {
	case <-t.done:
		return t.result, t.err
	case <-ctx.Done():
		return CommandResult{}, ctx.Err()
	}
}

type queuedCommand struct {
	session *Session
	ctx     context.Context
	packet  *capwap.ParsedPacket
	ticket  *CommandTicket
}
type commandQueue struct {
	jobs []queuedCommand
	wake chan struct{}
}

// QueueAP uses the live reference captured with an APStatus. It takes no
// session lock, so event callbacks may submit responses to their own AP.
// The worker rechecks identity, RUN state and the pinned session before send.
func (e *Engine) QueueAP(ctx context.Context, ap APStatus, kind uint32, elements []capwap.Element) (*CommandTicket, error) {
	s := ap.liveSession
	if s == nil || !s.Created.Equal(ap.ConnectedAt) {
		return nil, errors.New("AP snapshot has no matching live session")
	}
	if kind%2 == 0 || !(kind == 7 || kind == 15 || kind == 17 || kind == 21 || kind == 23 || kind == 25 || kind == capwap.MsgIe1) {
		return nil, fmt.Errorf("unsupported AC request type %d", kind)
	}
	p, err := capwap.NewParsedPacket(kind)
	if err != nil {
		return nil, err
	}
	return e.queueOnSession(PinAP(ctx, ap), s, p, elements)
}
func (e *Engine) queueOnSession(ctx context.Context, s *Session, p *capwap.ParsedPacket, elements []capwap.Element) (*CommandTicket, error) {
	if err := ctx.Err(); err != nil {
		return nil, err
	}
	select {
	case <-s.closed:
		return nil, errors.New("AP session closed")
	default:
	}
	root := s.transportRoot()
	select {
	case <-root.closed:
		return nil, errors.New("AP transport closed")
	default:
	}
	p.Elements = append([]capwap.Element{}, elements...)
	for i := range p.Elements {
		p.Elements[i].Value = append([]byte{}, p.Elements[i].Value...)
	}
	ticket := &CommandTicket{done: make(chan struct{})}
	e.outboundMu.Lock()
	if e.outbound == nil {
		e.outbound = map[*Session]*commandQueue{}
	}
	q := e.outbound[root]
	if q == nil {
		q = &commandQueue{wake: make(chan struct{}, 1)}
		e.outbound[root] = q
		go e.runCommandQueue(root, q)
	}
	q.jobs = append(q.jobs, queuedCommand{s, ctx, p, ticket})
	select {
	case q.wake <- struct{}{}:
	default:
	}
	e.outboundMu.Unlock()
	return ticket, nil
}
func (e *Engine) runCommandQueue(root *Session, q *commandQueue) {
	for {
		e.outboundMu.Lock()
		select {
		case <-root.closed:
			delete(e.outbound, root)
			pending := q.jobs
			q.jobs = nil
			e.outboundMu.Unlock()
			for _, job := range pending {
				job.ticket.err = errors.New("AP transport closed")
				close(job.ticket.done)
			}
			return
		default:
		}
		if len(q.jobs) == 0 {
			e.outboundMu.Unlock()
			select {
			case <-root.closed:
			case <-q.wake:
			}
			continue
		}
		job := q.jobs[0]
		q.jobs[0] = queuedCommand{}
		q.jobs = q.jobs[1:]
		e.outboundMu.Unlock()
		job.ticket.result, job.ticket.err = e.executeOnSession(job.ctx, job.session, job.packet, job.packet.Elements)
		close(job.ticket.done)
	}
}

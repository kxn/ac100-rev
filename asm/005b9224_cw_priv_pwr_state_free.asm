; func cw_priv_pwr_state_free @ 0x005b9224 size=0x3c
  5b9224:	27bdffe0 	addiu	sp,sp,-32
  5b9228:	afb00018 	sw	s0,24(sp)
  5b922c:	00808021 	move	s0,a0
  5b9230:	afbf001c 	sw	ra,28(sp)
  5b9234:	8c840010 	lw	a0,16(a0)
  5b9238:	10800005 	beqz	a0,0x5b9250
  5b923c:	8fbf001c 	lw	ra,28(sp)
  5b9240:	0c101f7c 	jal	0x407df0
  5b9244:	00000000 	nop
  5b9248:	ae000010 	sw	zero,16(s0)
  5b924c:	8fbf001c 	lw	ra,28(sp)
  5b9250:	00001021 	move	v0,zero
  5b9254:	8fb00018 	lw	s0,24(sp)
  5b9258:	03e00008 	jr	ra
  5b925c:	27bd0020 	addiu	sp,sp,32

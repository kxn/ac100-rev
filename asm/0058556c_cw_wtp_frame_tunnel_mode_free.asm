; func cw_wtp_frame_tunnel_mode_free @ 0x0058556c size=0x3c
  58556c:	27bdffe0 	addiu	sp,sp,-32
  585570:	afb00018 	sw	s0,24(sp)
  585574:	00808021 	move	s0,a0
  585578:	afbf001c 	sw	ra,28(sp)
  58557c:	8c840010 	lw	a0,16(a0)
  585580:	10800005 	beqz	a0,0x585598
  585584:	8fbf001c 	lw	ra,28(sp)
  585588:	0c101f7c 	jal	0x407df0
  58558c:	00000000 	nop
  585590:	ae000010 	sw	zero,16(s0)
  585594:	8fbf001c 	lw	ra,28(sp)
  585598:	00001021 	move	v0,zero
  58559c:	8fb00018 	lw	s0,24(sp)
  5855a0:	03e00008 	jr	ra
  5855a4:	27bd0020 	addiu	sp,sp,32

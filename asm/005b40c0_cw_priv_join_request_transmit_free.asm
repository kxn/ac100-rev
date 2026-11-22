; func cw_priv_join_request_transmit_free @ 0x005b40c0 size=0x3c
  5b40c0:	27bdffe0 	addiu	sp,sp,-32
  5b40c4:	afb00018 	sw	s0,24(sp)
  5b40c8:	00808021 	move	s0,a0
  5b40cc:	afbf001c 	sw	ra,28(sp)
  5b40d0:	8c840010 	lw	a0,16(a0)
  5b40d4:	10800005 	beqz	a0,0x5b40ec
  5b40d8:	8fbf001c 	lw	ra,28(sp)
  5b40dc:	0c101f7c 	jal	0x407df0
  5b40e0:	00000000 	nop
  5b40e4:	ae000010 	sw	zero,16(s0)
  5b40e8:	8fbf001c 	lw	ra,28(sp)
  5b40ec:	00001021 	move	v0,zero
  5b40f0:	8fb00018 	lw	s0,24(sp)
  5b40f4:	03e00008 	jr	ra
  5b40f8:	27bd0020 	addiu	sp,sp,32

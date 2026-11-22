; func cw_radio_administrative_state_free @ 0x0057f4b8 size=0x3c
  57f4b8:	27bdffe0 	addiu	sp,sp,-32
  57f4bc:	afb00018 	sw	s0,24(sp)
  57f4c0:	00808021 	move	s0,a0
  57f4c4:	afbf001c 	sw	ra,28(sp)
  57f4c8:	8c840010 	lw	a0,16(a0)
  57f4cc:	10800005 	beqz	a0,0x57f4e4
  57f4d0:	8fbf001c 	lw	ra,28(sp)
  57f4d4:	0c101f7c 	jal	0x407df0
  57f4d8:	00000000 	nop
  57f4dc:	ae000010 	sw	zero,16(s0)
  57f4e0:	8fbf001c 	lw	ra,28(sp)
  57f4e4:	00001021 	move	v0,zero
  57f4e8:	8fb00018 	lw	s0,24(sp)
  57f4ec:	03e00008 	jr	ra
  57f4f0:	27bd0020 	addiu	sp,sp,32

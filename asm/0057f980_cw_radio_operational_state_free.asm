; func cw_radio_operational_state_free @ 0x0057f980 size=0x3c
  57f980:	27bdffe0 	addiu	sp,sp,-32
  57f984:	afb00018 	sw	s0,24(sp)
  57f988:	00808021 	move	s0,a0
  57f98c:	afbf001c 	sw	ra,28(sp)
  57f990:	8c840010 	lw	a0,16(a0)
  57f994:	10800005 	beqz	a0,0x57f9ac
  57f998:	8fbf001c 	lw	ra,28(sp)
  57f99c:	0c101f7c 	jal	0x407df0
  57f9a0:	00000000 	nop
  57f9a4:	ae000010 	sw	zero,16(s0)
  57f9a8:	8fbf001c 	lw	ra,28(sp)
  57f9ac:	00001021 	move	v0,zero
  57f9b0:	8fb00018 	lw	s0,24(sp)
  57f9b4:	03e00008 	jr	ra
  57f9b8:	27bd0020 	addiu	sp,sp,32

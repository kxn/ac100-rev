; func cw_priv_except_free @ 0x005b0968 size=0x3c
  5b0968:	27bdffe0 	addiu	sp,sp,-32
  5b096c:	afb00018 	sw	s0,24(sp)
  5b0970:	00808021 	move	s0,a0
  5b0974:	afbf001c 	sw	ra,28(sp)
  5b0978:	8c840010 	lw	a0,16(a0)
  5b097c:	10800005 	beqz	a0,0x5b0994
  5b0980:	8fbf001c 	lw	ra,28(sp)
  5b0984:	0c101f7c 	jal	0x407df0
  5b0988:	00000000 	nop
  5b098c:	ae000010 	sw	zero,16(s0)
  5b0990:	8fbf001c 	lw	ra,28(sp)
  5b0994:	00001021 	move	v0,zero
  5b0998:	8fb00018 	lw	s0,24(sp)
  5b099c:	03e00008 	jr	ra
  5b09a0:	27bd0020 	addiu	sp,sp,32

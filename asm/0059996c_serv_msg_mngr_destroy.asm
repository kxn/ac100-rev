; func serv_msg_mngr_destroy @ 0x0059996c size=0xa4
  59996c:	27bdffd8 	addiu	sp,sp,-40
  599970:	afb0001c 	sw	s0,28(sp)
  599974:	3c10007c 	lui	s0,0x7c
  599978:	afb10020 	sw	s1,32(sp)
  59997c:	261059d8 	addiu	s0,s0,23000
  599980:	afbf0024 	sw	ra,36(sp)
  599984:	26110068 	addiu	s1,s0,104
  599988:	8e040000 	lw	a0,0(s0)
  59998c:	50800007 	beqzl	a0,0x5999ac
  599990:	26100004 	addiu	s0,s0,4
  599994:	0c16663b 	jal	0x5998ec
  599998:	00000000 	nop
  59999c:	0c101f7c 	jal	0x407df0
  5999a0:	8e040000 	lw	a0,0(s0)
  5999a4:	ae000000 	sw	zero,0(s0)
  5999a8:	26100004 	addiu	s0,s0,4
  5999ac:	5611fff7 	bnel	s0,s1,0x59998c
  5999b0:	8e040000 	lw	a0,0(s0)
  5999b4:	3c10007c 	lui	s0,0x7c
  5999b8:	8e0459d0 	lw	a0,22992(s0)
  5999bc:	50800007 	beqzl	a0,0x5999dc
  5999c0:	261059d0 	addiu	s0,s0,22992
  5999c4:	0c16663b 	jal	0x5998ec
  5999c8:	00000000 	nop
  5999cc:	0c101f7c 	jal	0x407df0
  5999d0:	8e0459d0 	lw	a0,22992(s0)
  5999d4:	ae0059d0 	sw	zero,22992(s0)
  5999d8:	261059d0 	addiu	s0,s0,22992
  5999dc:	8e040004 	lw	a0,4(s0)
  5999e0:	10800007 	beqz	a0,0x599a00
  5999e4:	8fbf0024 	lw	ra,36(sp)
  5999e8:	0c16663b 	jal	0x5998ec
  5999ec:	00000000 	nop
  5999f0:	0c101f7c 	jal	0x407df0
  5999f4:	8e040004 	lw	a0,4(s0)
  5999f8:	ae000004 	sw	zero,4(s0)
  5999fc:	8fbf0024 	lw	ra,36(sp)
  599a00:	8fb10020 	lw	s1,32(sp)
  599a04:	8fb0001c 	lw	s0,28(sp)
  599a08:	03e00008 	jr	ra
  599a0c:	27bd0028 	addiu	sp,sp,40

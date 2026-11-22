; func cw_priv_mac_filter_free @ 0x005b56a4 size=0x58
  5b56a4:	27bdffd8 	addiu	sp,sp,-40
  5b56a8:	afb10020 	sw	s1,32(sp)
  5b56ac:	afbf0024 	sw	ra,36(sp)
  5b56b0:	afb0001c 	sw	s0,28(sp)
  5b56b4:	8c900010 	lw	s0,16(a0)
  5b56b8:	1200000a 	beqz	s0,0x5b56e4
  5b56bc:	00808821 	move	s1,a0
  5b56c0:	8e040008 	lw	a0,8(s0)
  5b56c4:	10800004 	beqz	a0,0x5b56d8
  5b56c8:	00000000 	nop
  5b56cc:	0c101f7c 	jal	0x407df0
  5b56d0:	00000000 	nop
  5b56d4:	ae000008 	sw	zero,8(s0)
  5b56d8:	0c101f7c 	jal	0x407df0
  5b56dc:	8e240010 	lw	a0,16(s1)
  5b56e0:	ae200010 	sw	zero,16(s1)
  5b56e4:	8fbf0024 	lw	ra,36(sp)
  5b56e8:	00001021 	move	v0,zero
  5b56ec:	8fb10020 	lw	s1,32(sp)
  5b56f0:	8fb0001c 	lw	s0,28(sp)
  5b56f4:	03e00008 	jr	ra
  5b56f8:	27bd0028 	addiu	sp,sp,40

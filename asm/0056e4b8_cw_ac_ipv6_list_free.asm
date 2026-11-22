; func cw_ac_ipv6_list_free @ 0x0056e4b8 size=0x54
  56e4b8:	27bdffd8 	addiu	sp,sp,-40
  56e4bc:	afb10020 	sw	s1,32(sp)
  56e4c0:	afbf0024 	sw	ra,36(sp)
  56e4c4:	afb0001c 	sw	s0,28(sp)
  56e4c8:	8c900010 	lw	s0,16(a0)
  56e4cc:	12000009 	beqz	s0,0x56e4f4
  56e4d0:	00808821 	move	s1,a0
  56e4d4:	8e040004 	lw	a0,4(s0)
  56e4d8:	10800003 	beqz	a0,0x56e4e8
  56e4dc:	00000000 	nop
  56e4e0:	0c101f7c 	jal	0x407df0
  56e4e4:	00000000 	nop
  56e4e8:	0c101f7c 	jal	0x407df0
  56e4ec:	02002021 	move	a0,s0
  56e4f0:	ae200010 	sw	zero,16(s1)
  56e4f4:	8fbf0024 	lw	ra,36(sp)
  56e4f8:	00001021 	move	v0,zero
  56e4fc:	8fb10020 	lw	s1,32(sp)
  56e500:	8fb0001c 	lw	s0,28(sp)
  56e504:	03e00008 	jr	ra
  56e508:	27bd0028 	addiu	sp,sp,40

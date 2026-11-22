; func cw_priv_wechat_iplist_free @ 0x005cb174 size=0x58
  5cb174:	27bdffd8 	addiu	sp,sp,-40
  5cb178:	afb10020 	sw	s1,32(sp)
  5cb17c:	afbf0024 	sw	ra,36(sp)
  5cb180:	afb0001c 	sw	s0,28(sp)
  5cb184:	8c900010 	lw	s0,16(a0)
  5cb188:	1200000a 	beqz	s0,0x5cb1b4
  5cb18c:	00808821 	move	s1,a0
  5cb190:	8e040004 	lw	a0,4(s0)
  5cb194:	10800004 	beqz	a0,0x5cb1a8
  5cb198:	00000000 	nop
  5cb19c:	0c101f7c 	jal	0x407df0
  5cb1a0:	00000000 	nop
  5cb1a4:	ae000004 	sw	zero,4(s0)
  5cb1a8:	0c101f7c 	jal	0x407df0
  5cb1ac:	8e240010 	lw	a0,16(s1)
  5cb1b0:	ae200010 	sw	zero,16(s1)
  5cb1b4:	8fbf0024 	lw	ra,36(sp)
  5cb1b8:	00001021 	move	v0,zero
  5cb1bc:	8fb10020 	lw	s1,32(sp)
  5cb1c0:	8fb0001c 	lw	s0,28(sp)
  5cb1c4:	03e00008 	jr	ra
  5cb1c8:	27bd0028 	addiu	sp,sp,40

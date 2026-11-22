; func cw_80211_antenna_free @ 0x005641c8 size=0x54
  5641c8:	27bdffd8 	addiu	sp,sp,-40
  5641cc:	afb10020 	sw	s1,32(sp)
  5641d0:	afbf0024 	sw	ra,36(sp)
  5641d4:	afb0001c 	sw	s0,28(sp)
  5641d8:	8c900010 	lw	s0,16(a0)
  5641dc:	12000009 	beqz	s0,0x564204
  5641e0:	00808821 	move	s1,a0
  5641e4:	8e040004 	lw	a0,4(s0)
  5641e8:	10800003 	beqz	a0,0x5641f8
  5641ec:	00000000 	nop
  5641f0:	0c101f7c 	jal	0x407df0
  5641f4:	00000000 	nop
  5641f8:	0c101f7c 	jal	0x407df0
  5641fc:	02002021 	move	a0,s0
  564200:	ae200010 	sw	zero,16(s1)
  564204:	8fbf0024 	lw	ra,36(sp)
  564208:	00001021 	move	v0,zero
  56420c:	8fb10020 	lw	s1,32(sp)
  564210:	8fb0001c 	lw	s0,28(sp)
  564214:	03e00008 	jr	ra
  564218:	27bd0028 	addiu	sp,sp,40

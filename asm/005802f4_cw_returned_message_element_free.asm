; func cw_returned_message_element_free @ 0x005802f4 size=0x54
  5802f4:	27bdffd8 	addiu	sp,sp,-40
  5802f8:	afb10020 	sw	s1,32(sp)
  5802fc:	afbf0024 	sw	ra,36(sp)
  580300:	afb0001c 	sw	s0,28(sp)
  580304:	8c900010 	lw	s0,16(a0)
  580308:	12000009 	beqz	s0,0x580330
  58030c:	00808821 	move	s1,a0
  580310:	8e040004 	lw	a0,4(s0)
  580314:	10800003 	beqz	a0,0x580324
  580318:	00000000 	nop
  58031c:	0c101f7c 	jal	0x407df0
  580320:	00000000 	nop
  580324:	0c101f7c 	jal	0x407df0
  580328:	02002021 	move	a0,s0
  58032c:	ae200010 	sw	zero,16(s1)
  580330:	8fbf0024 	lw	ra,36(sp)
  580334:	00001021 	move	v0,zero
  580338:	8fb10020 	lw	s1,32(sp)
  58033c:	8fb0001c 	lw	s0,28(sp)
  580340:	03e00008 	jr	ra
  580344:	27bd0028 	addiu	sp,sp,40

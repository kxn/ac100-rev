; func cw_80211_station_free @ 0x005683f4 size=0x54
  5683f4:	27bdffd8 	addiu	sp,sp,-40
  5683f8:	afb10020 	sw	s1,32(sp)
  5683fc:	afbf0024 	sw	ra,36(sp)
  568400:	afb0001c 	sw	s0,28(sp)
  568404:	8c900010 	lw	s0,16(a0)
  568408:	12000009 	beqz	s0,0x568430
  56840c:	00808821 	move	s1,a0
  568410:	8e040010 	lw	a0,16(s0)
  568414:	10800003 	beqz	a0,0x568424
  568418:	00000000 	nop
  56841c:	0c101f7c 	jal	0x407df0
  568420:	00000000 	nop
  568424:	0c101f7c 	jal	0x407df0
  568428:	02002021 	move	a0,s0
  56842c:	ae200010 	sw	zero,16(s1)
  568430:	8fbf0024 	lw	ra,36(sp)
  568434:	00001021 	move	v0,zero
  568438:	8fb10020 	lw	s1,32(sp)
  56843c:	8fb0001c 	lw	s0,28(sp)
  568440:	03e00008 	jr	ra
  568444:	27bd0028 	addiu	sp,sp,40

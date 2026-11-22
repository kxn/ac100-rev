; func cw_priv_igmp_query_config_by_ssid_free @ 0x005b2458 size=0x54
  5b2458:	27bdffd8 	addiu	sp,sp,-40
  5b245c:	afb10020 	sw	s1,32(sp)
  5b2460:	afbf0024 	sw	ra,36(sp)
  5b2464:	afb0001c 	sw	s0,28(sp)
  5b2468:	8c900010 	lw	s0,16(a0)
  5b246c:	12000009 	beqz	s0,0x5b2494
  5b2470:	00808821 	move	s1,a0
  5b2474:	8e040004 	lw	a0,4(s0)
  5b2478:	10800003 	beqz	a0,0x5b2488
  5b247c:	00000000 	nop
  5b2480:	0c101f7c 	jal	0x407df0
  5b2484:	00000000 	nop
  5b2488:	0c101f7c 	jal	0x407df0
  5b248c:	02002021 	move	a0,s0
  5b2490:	ae200010 	sw	zero,16(s1)
  5b2494:	8fbf0024 	lw	ra,36(sp)
  5b2498:	00001021 	move	v0,zero
  5b249c:	8fb10020 	lw	s1,32(sp)
  5b24a0:	8fb0001c 	lw	s0,28(sp)
  5b24a4:	03e00008 	jr	ra
  5b24a8:	27bd0028 	addiu	sp,sp,40

; func cw_decryption_error_report_free @ 0x00573548 size=0x54
  573548:	27bdffd8 	addiu	sp,sp,-40
  57354c:	afb10020 	sw	s1,32(sp)
  573550:	afbf0024 	sw	ra,36(sp)
  573554:	afb0001c 	sw	s0,28(sp)
  573558:	8c900010 	lw	s0,16(a0)
  57355c:	12000009 	beqz	s0,0x573584
  573560:	00808821 	move	s1,a0
  573564:	8e040004 	lw	a0,4(s0)
  573568:	10800003 	beqz	a0,0x573578
  57356c:	00000000 	nop
  573570:	0c101f7c 	jal	0x407df0
  573574:	00000000 	nop
  573578:	0c101f7c 	jal	0x407df0
  57357c:	02002021 	move	a0,s0
  573580:	ae200010 	sw	zero,16(s1)
  573584:	8fbf0024 	lw	ra,36(sp)
  573588:	00001021 	move	v0,zero
  57358c:	8fb10020 	lw	s1,32(sp)
  573590:	8fb0001c 	lw	s0,28(sp)
  573594:	03e00008 	jr	ra
  573598:	27bd0028 	addiu	sp,sp,40

; func cw_priv_radio_role_table_free @ 0x005b9604 size=0x98
  5b9604:	3c02007c 	lui	v0,0x7c
  5b9608:	27bdffd8 	addiu	sp,sp,-40
  5b960c:	8c425988 	lw	v0,22920(v0)
  5b9610:	afb10020 	sw	s1,32(sp)
  5b9614:	00808821 	move	s1,a0
  5b9618:	afbf0024 	sw	ra,36(sp)
  5b961c:	14400013 	bnez	v0,0x5b966c
  5b9620:	afb0001c 	sw	s0,28(sp)
  5b9624:	8e300010 	lw	s0,16(s1)
  5b9628:	1200000b 	beqz	s0,0x5b9658
  5b962c:	8fbf0024 	lw	ra,36(sp)
  5b9630:	8e040004 	lw	a0,4(s0)
  5b9634:	10800004 	beqz	a0,0x5b9648
  5b9638:	00000000 	nop
  5b963c:	0c101f7c 	jal	0x407df0
  5b9640:	00000000 	nop
  5b9644:	ae000004 	sw	zero,4(s0)
  5b9648:	0c101f7c 	jal	0x407df0
  5b964c:	8e240010 	lw	a0,16(s1)
  5b9650:	ae200010 	sw	zero,16(s1)
  5b9654:	8fbf0024 	lw	ra,36(sp)
  5b9658:	00001021 	move	v0,zero
  5b965c:	8fb10020 	lw	s1,32(sp)
  5b9660:	8fb0001c 	lw	s0,28(sp)
  5b9664:	03e00008 	jr	ra
  5b9668:	27bd0028 	addiu	sp,sp,40
  5b966c:	0c16276a 	jal	0x589da8
  5b9670:	00000000 	nop
  5b9674:	5040ffec 	beqzl	v0,0x5b9628
  5b9678:	8e300010 	lw	s0,16(s1)
  5b967c:	3c04006f 	lui	a0,0x6f
  5b9680:	3c05006f 	lui	a1,0x6f
  5b9684:	2484d1bc 	addiu	a0,a0,-11844
  5b9688:	24a5d3c0 	addiu	a1,a1,-11328
  5b968c:	0c101b74 	jal	0x406dd0
  5b9690:	2406014d 	li	a2,333
  5b9694:	0816e58a 	j	0x5b9628
  5b9698:	8e300010 	lw	s0,16(s1)

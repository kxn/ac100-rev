; func cw_priv_fit_fat_button_status_create @ 0x005b15bc size=0xdc
  5b15bc:	27bdffd8 	addiu	sp,sp,-40
  5b15c0:	24050004 	li	a1,4
  5b15c4:	afb0001c 	sw	s0,28(sp)
  5b15c8:	afbf0024 	sw	ra,36(sp)
  5b15cc:	0c15c8cc 	jal	0x572330
  5b15d0:	afb10020 	sw	s1,32(sp)
  5b15d4:	1040000d 	beqz	v0,0x5b160c
  5b15d8:	00408021 	move	s0,v0
  5b15dc:	240400a4 	li	a0,164
  5b15e0:	24050004 	li	a1,4
  5b15e4:	0c15c943 	jal	0x57250c
  5b15e8:	00403021 	move	a2,v0
  5b15ec:	10400017 	beqz	v0,0x5b164c
  5b15f0:	00408821 	move	s1,v0
  5b15f4:	8fbf0024 	lw	ra,36(sp)
  5b15f8:	02201021 	move	v0,s1
  5b15fc:	8fb10020 	lw	s1,32(sp)
  5b1600:	8fb0001c 	lw	s0,28(sp)
  5b1604:	03e00008 	jr	ra
  5b1608:	27bd0028 	addiu	sp,sp,40
  5b160c:	3c020075 	lui	v0,0x75
  5b1610:	8c42cf58 	lw	v0,-12456(v0)
  5b1614:	1040fff7 	beqz	v0,0x5b15f4
  5b1618:	00008821 	move	s1,zero
  5b161c:	0c16276a 	jal	0x589da8
  5b1620:	00000000 	nop
  5b1624:	5040fff4 	beqzl	v0,0x5b15f8
  5b1628:	8fbf0024 	lw	ra,36(sp)
  5b162c:	3c04006d 	lui	a0,0x6d
  5b1630:	3c05006f 	lui	a1,0x6f
  5b1634:	248434fc 	addiu	a0,a0,13564
  5b1638:	24a5af30 	addiu	a1,a1,-20688
  5b163c:	0c101b74 	jal	0x406dd0
  5b1640:	240600a8 	li	a2,168
  5b1644:	0816c57e 	j	0x5b15f8
  5b1648:	8fbf0024 	lw	ra,36(sp)
  5b164c:	3c020075 	lui	v0,0x75
  5b1650:	8c42cf58 	lw	v0,-12456(v0)
  5b1654:	14400005 	bnez	v0,0x5b166c
  5b1658:	00000000 	nop
  5b165c:	0c101f7c 	jal	0x407df0
  5b1660:	02002021 	move	a0,s0
  5b1664:	0816c57e 	j	0x5b15f8
  5b1668:	8fbf0024 	lw	ra,36(sp)
  5b166c:	0c16276a 	jal	0x589da8
  5b1670:	00000000 	nop
  5b1674:	1040fff9 	beqz	v0,0x5b165c
  5b1678:	3c04006d 	lui	a0,0x6d
  5b167c:	3c05006f 	lui	a1,0x6f
  5b1680:	248447f0 	addiu	a0,a0,18416
  5b1684:	24a5af30 	addiu	a1,a1,-20688
  5b1688:	0c101b74 	jal	0x406dd0
  5b168c:	240600b0 	li	a2,176
  5b1690:	0816c597 	j	0x5b165c
  5b1694:	00000000 	nop

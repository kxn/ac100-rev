; func cw_priv_port_info_create @ 0x005b8504 size=0x210
  5b8504:	27bdffd8 	addiu	sp,sp,-40
  5b8508:	afb20020 	sw	s2,32(sp)
  5b850c:	afbf0024 	sw	ra,36(sp)
  5b8510:	afb1001c 	sw	s1,28(sp)
  5b8514:	afb00018 	sw	s0,24(sp)
  5b8518:	90820000 	lbu	v0,0(a0)
  5b851c:	2c420041 	sltiu	v0,v0,65
  5b8520:	14400010 	bnez	v0,0x5b8564
  5b8524:	00809021 	move	s2,a0
  5b8528:	3c020075 	lui	v0,0x75
  5b852c:	8c42cf58 	lw	v0,-12456(v0)
  5b8530:	10400005 	beqz	v0,0x5b8548
  5b8534:	00008821 	move	s1,zero
  5b8538:	0c16276a 	jal	0x589da8
  5b853c:	00000000 	nop
  5b8540:	14400030 	bnez	v0,0x5b8604
  5b8544:	3c04006f 	lui	a0,0x6f
  5b8548:	8fbf0024 	lw	ra,36(sp)
  5b854c:	02201021 	move	v0,s1
  5b8550:	8fb20020 	lw	s2,32(sp)
  5b8554:	8fb1001c 	lw	s1,28(sp)
  5b8558:	8fb00018 	lw	s0,24(sp)
  5b855c:	03e00008 	jr	ra
  5b8560:	27bd0028 	addiu	sp,sp,40
  5b8564:	0c15c8cc 	jal	0x572330
  5b8568:	24050008 	li	a1,8
  5b856c:	10400041 	beqz	v0,0x5b8674
  5b8570:	00408021 	move	s0,v0
  5b8574:	ac400004 	sw	zero,4(v0)
  5b8578:	92450000 	lbu	a1,0(s2)
  5b857c:	10a00008 	beqz	a1,0x5b85a0
  5b8580:	00000000 	nop
  5b8584:	8e440004 	lw	a0,4(s2)
  5b8588:	1080004a 	beqz	a0,0x5b86b4
  5b858c:	3c020075 	lui	v0,0x75
  5b8590:	0c15c8cc 	jal	0x572330
  5b8594:	000528c0 	sll	a1,a1,0x3
  5b8598:	1040002e 	beqz	v0,0x5b8654
  5b859c:	ae020004 	sw	v0,4(s0)
  5b85a0:	0c16dfcc 	jal	0x5b7f30
  5b85a4:	02002021 	move	a0,s0
  5b85a8:	240400a2 	li	a0,162
  5b85ac:	00402821 	move	a1,v0
  5b85b0:	0c15c943 	jal	0x57250c
  5b85b4:	02003021 	move	a2,s0
  5b85b8:	1440ffe3 	bnez	v0,0x5b8548
  5b85bc:	00408821 	move	s1,v0
  5b85c0:	3c020075 	lui	v0,0x75
  5b85c4:	8c42cf58 	lw	v0,-12456(v0)
  5b85c8:	14400016 	bnez	v0,0x5b8624
  5b85cc:	00000000 	nop
  5b85d0:	92020000 	lbu	v0,0(s0)
  5b85d4:	10400007 	beqz	v0,0x5b85f4
  5b85d8:	00000000 	nop
  5b85dc:	8e040004 	lw	a0,4(s0)
  5b85e0:	10800004 	beqz	a0,0x5b85f4
  5b85e4:	00000000 	nop
  5b85e8:	0c101f7c 	jal	0x407df0
  5b85ec:	00000000 	nop
  5b85f0:	ae000004 	sw	zero,4(s0)
  5b85f4:	0c101f7c 	jal	0x407df0
  5b85f8:	02002021 	move	a0,s0
  5b85fc:	0816e153 	j	0x5b854c
  5b8600:	8fbf0024 	lw	ra,36(sp)
  5b8604:	92470000 	lbu	a3,0(s2)
  5b8608:	3c05006f 	lui	a1,0x6f
  5b860c:	2484cda4 	addiu	a0,a0,-12892
  5b8610:	24a5cec8 	addiu	a1,a1,-12600
  5b8614:	0c101b74 	jal	0x406dd0
  5b8618:	24060119 	li	a2,281
  5b861c:	0816e153 	j	0x5b854c
  5b8620:	8fbf0024 	lw	ra,36(sp)
  5b8624:	0c16276a 	jal	0x589da8
  5b8628:	00000000 	nop
  5b862c:	5040ffe9 	beqzl	v0,0x5b85d4
  5b8630:	92020000 	lbu	v0,0(s0)
  5b8634:	3c04006d 	lui	a0,0x6d
  5b8638:	3c05006f 	lui	a1,0x6f
  5b863c:	248447f0 	addiu	a0,a0,18416
  5b8640:	24a5cec8 	addiu	a1,a1,-12600
  5b8644:	0c101b74 	jal	0x406dd0
  5b8648:	2406013b 	li	a2,315
  5b864c:	0816e175 	j	0x5b85d4
  5b8650:	92020000 	lbu	v0,0(s0)
  5b8654:	3c020075 	lui	v0,0x75
  5b8658:	8c42cf58 	lw	v0,-12456(v0)
  5b865c:	14400024 	bnez	v0,0x5b86f0
  5b8660:	00000000 	nop
  5b8664:	0c101f7c 	jal	0x407df0
  5b8668:	02002021 	move	a0,s0
  5b866c:	0816e152 	j	0x5b8548
  5b8670:	00008821 	move	s1,zero
  5b8674:	3c020075 	lui	v0,0x75
  5b8678:	8c42cf58 	lw	v0,-12456(v0)
  5b867c:	1040ffb2 	beqz	v0,0x5b8548
  5b8680:	00008821 	move	s1,zero
  5b8684:	0c16276a 	jal	0x589da8
  5b8688:	00000000 	nop
  5b868c:	5040ffaf 	beqzl	v0,0x5b854c
  5b8690:	8fbf0024 	lw	ra,36(sp)
  5b8694:	3c04006d 	lui	a0,0x6d
  5b8698:	3c05006f 	lui	a1,0x6f
  5b869c:	248434fc 	addiu	a0,a0,13564
  5b86a0:	24a5cec8 	addiu	a1,a1,-12600
  5b86a4:	0c101b74 	jal	0x406dd0
  5b86a8:	24060120 	li	a2,288
  5b86ac:	0816e153 	j	0x5b854c
  5b86b0:	8fbf0024 	lw	ra,36(sp)
  5b86b4:	8c42cf58 	lw	v0,-12456(v0)
  5b86b8:	1040ffea 	beqz	v0,0x5b8664
  5b86bc:	00000000 	nop
  5b86c0:	0c16276a 	jal	0x589da8
  5b86c4:	00000000 	nop
  5b86c8:	1040ffe6 	beqz	v0,0x5b8664
  5b86cc:	3c04006f 	lui	a0,0x6f
  5b86d0:	3c05006f 	lui	a1,0x6f
  5b86d4:	2484ce6c 	addiu	a0,a0,-12692
  5b86d8:	24a5cec8 	addiu	a1,a1,-12600
  5b86dc:	2406012a 	li	a2,298
  5b86e0:	0c101b74 	jal	0x406dd0
  5b86e4:	00000000 	nop
  5b86e8:	0816e199 	j	0x5b8664
  5b86ec:	00000000 	nop
  5b86f0:	0c16276a 	jal	0x589da8
  5b86f4:	00000000 	nop
  5b86f8:	1040ffda 	beqz	v0,0x5b8664
  5b86fc:	3c04006e 	lui	a0,0x6e
  5b8700:	3c05006f 	lui	a1,0x6f
  5b8704:	24847c94 	addiu	a0,a0,31892
  5b8708:	24a5cec8 	addiu	a1,a1,-12600
  5b870c:	0816e1b8 	j	0x5b86e0
  5b8710:	24060131 	li	a2,305
	...

; func cw_priv_delete_implicitly_leave_station_parse @ 0x005af5bc size=0x218
  5af5bc:	27bdffd0 	addiu	sp,sp,-48
  5af5c0:	afb20024 	sw	s2,36(sp)
  5af5c4:	00a09021 	move	s2,a1
  5af5c8:	afb10020 	sw	s1,32(sp)
  5af5cc:	24050066 	li	a1,102
  5af5d0:	afb0001c 	sw	s0,28(sp)
  5af5d4:	00808821 	move	s1,a0
  5af5d8:	afbf002c 	sw	ra,44(sp)
  5af5dc:	afb30028 	sw	s3,40(sp)
  5af5e0:	94930006 	lhu	s3,6(a0)
  5af5e4:	0c102114 	jal	0x408450
  5af5e8:	24040008 	li	a0,8
  5af5ec:	1040002c 	beqz	v0,0x5af6a0
  5af5f0:	00408021 	move	s0,v0
  5af5f4:	00002821 	move	a1,zero
  5af5f8:	24060008 	li	a2,8
  5af5fc:	0c101cf0 	jal	0x4073c0
  5af600:	00402021 	move	a0,v0
  5af604:	0c15c5b0 	jal	0x5716c0
  5af608:	02202021 	move	a0,s1
  5af60c:	a2020000 	sb	v0,0(s0)
  5af610:	2c420020 	sltiu	v0,v0,32
  5af614:	10400039 	beqz	v0,0x5af6fc
  5af618:	3c020075 	lui	v0,0x75
  5af61c:	0c15c5b0 	jal	0x5716c0
  5af620:	02202021 	move	a0,s1
  5af624:	24030006 	li	v1,6
  5af628:	10430004 	beq	v0,v1,0x5af63c
  5af62c:	a2020001 	sb	v0,1(s0)
  5af630:	24030008 	li	v1,8
  5af634:	5443003e 	bnel	v0,v1,0x5af730
  5af638:	3c020075 	lui	v0,0x75
  5af63c:	9643000e 	lhu	v1,14(s2)
  5af640:	2463fffe 	addiu	v1,v1,-2
  5af644:	54620026 	bnel	v1,v0,0x5af6e0
  5af648:	3c020075 	lui	v0,0x75
  5af64c:	02202021 	move	a0,s1
  5af650:	0c15c6bc 	jal	0x571af0
  5af654:	00402821 	move	a1,v0
  5af658:	1040004f 	beqz	v0,0x5af798
  5af65c:	ae020004 	sw	v0,4(s0)
  5af660:	9642000e 	lhu	v0,14(s2)
  5af664:	ae500010 	sw	s0,16(s2)
  5af668:	96300006 	lhu	s0,6(s1)
  5af66c:	02138023 	subu	s0,s0,s3
  5af670:	02028026 	xor	s0,s0,v0
  5af674:	2402ffff 	li	v0,-1
  5af678:	0010100a 	movz	v0,zero,s0
  5af67c:	00408021 	move	s0,v0
  5af680:	8fbf002c 	lw	ra,44(sp)
  5af684:	02001021 	move	v0,s0
  5af688:	8fb30028 	lw	s3,40(sp)
  5af68c:	8fb20024 	lw	s2,36(sp)
  5af690:	8fb10020 	lw	s1,32(sp)
  5af694:	8fb0001c 	lw	s0,28(sp)
  5af698:	03e00008 	jr	ra
  5af69c:	27bd0030 	addiu	sp,sp,48
  5af6a0:	3c020075 	lui	v0,0x75
  5af6a4:	8c42cf58 	lw	v0,-12456(v0)
  5af6a8:	1040fff5 	beqz	v0,0x5af680
  5af6ac:	2410ffff 	li	s0,-1
  5af6b0:	0c16276a 	jal	0x589da8
  5af6b4:	00000000 	nop
  5af6b8:	5040fff2 	beqzl	v0,0x5af684
  5af6bc:	8fbf002c 	lw	ra,44(sp)
  5af6c0:	3c04006d 	lui	a0,0x6d
  5af6c4:	3c05006f 	lui	a1,0x6f
  5af6c8:	2484381c 	addiu	a0,a0,14364
  5af6cc:	24a5a7c4 	addiu	a1,a1,-22588
  5af6d0:	0c101b74 	jal	0x406dd0
  5af6d4:	24060069 	li	a2,105
  5af6d8:	0816bda1 	j	0x5af684
  5af6dc:	8fbf002c 	lw	ra,44(sp)
  5af6e0:	8c42cf58 	lw	v0,-12456(v0)
  5af6e4:	14400022 	bnez	v0,0x5af770
  5af6e8:	00000000 	nop
  5af6ec:	0c101f7c 	jal	0x407df0
  5af6f0:	02002021 	move	a0,s0
  5af6f4:	0816bda0 	j	0x5af680
  5af6f8:	2410ffff 	li	s0,-1
  5af6fc:	8c42cf58 	lw	v0,-12456(v0)
  5af700:	1040fffa 	beqz	v0,0x5af6ec
  5af704:	00000000 	nop
  5af708:	0c16276a 	jal	0x589da8
  5af70c:	00000000 	nop
  5af710:	1040fff6 	beqz	v0,0x5af6ec
  5af714:	3c04006d 	lui	a0,0x6d
  5af718:	92070000 	lbu	a3,0(s0)
  5af71c:	3c05006f 	lui	a1,0x6f
  5af720:	24843f08 	addiu	a0,a0,16136
  5af724:	24a5a7c4 	addiu	a1,a1,-22588
  5af728:	0816bdd8 	j	0x5af760
  5af72c:	24060072 	li	a2,114
  5af730:	8c42cf58 	lw	v0,-12456(v0)
  5af734:	1040ffed 	beqz	v0,0x5af6ec
  5af738:	00000000 	nop
  5af73c:	0c16276a 	jal	0x589da8
  5af740:	00000000 	nop
  5af744:	1040ffe9 	beqz	v0,0x5af6ec
  5af748:	3c04006d 	lui	a0,0x6d
  5af74c:	92070001 	lbu	a3,1(s0)
  5af750:	3c05006f 	lui	a1,0x6f
  5af754:	24847450 	addiu	a0,a0,29776
  5af758:	24a5a7c4 	addiu	a1,a1,-22588
  5af75c:	2406007b 	li	a2,123
  5af760:	0c101b74 	jal	0x406dd0
  5af764:	00000000 	nop
  5af768:	0816bdbb 	j	0x5af6ec
  5af76c:	00000000 	nop
  5af770:	0c16276a 	jal	0x589da8
  5af774:	00000000 	nop
  5af778:	1040ffdc 	beqz	v0,0x5af6ec
  5af77c:	3c04006d 	lui	a0,0x6d
  5af780:	9647000e 	lhu	a3,14(s2)
  5af784:	3c05006f 	lui	a1,0x6f
  5af788:	24846dec 	addiu	a0,a0,28140
  5af78c:	24a5a7c4 	addiu	a1,a1,-22588
  5af790:	0816bdd8 	j	0x5af760
  5af794:	24060083 	li	a2,131
  5af798:	3c020075 	lui	v0,0x75
  5af79c:	8c42cf58 	lw	v0,-12456(v0)
  5af7a0:	1040ffd2 	beqz	v0,0x5af6ec
  5af7a4:	00000000 	nop
  5af7a8:	0c16276a 	jal	0x589da8
  5af7ac:	00000000 	nop
  5af7b0:	1040ffce 	beqz	v0,0x5af6ec
  5af7b4:	3c04006d 	lui	a0,0x6d
  5af7b8:	3c05006f 	lui	a1,0x6f
  5af7bc:	24847500 	addiu	a0,a0,29952
  5af7c0:	24a5a7c4 	addiu	a1,a1,-22588
  5af7c4:	0c101b74 	jal	0x406dd0
  5af7c8:	2406008a 	li	a2,138
  5af7cc:	0816bdbb 	j	0x5af6ec
  5af7d0:	00000000 	nop
	...

; func apmngr_callback_proc @ 0x0052a504 size=0x21c
  52a504:	27bdffb8 	addiu	sp,sp,-72
  52a508:	afb20028 	sw	s2,40(sp)
  52a50c:	00809021 	move	s2,a0
  52a510:	3c04007c 	lui	a0,0x7c
  52a514:	afb40030 	sw	s4,48(sp)
  52a518:	afb3002c 	sw	s3,44(sp)
  52a51c:	3c140075 	lui	s4,0x75
  52a520:	248457f8 	addiu	a0,a0,22520
  52a524:	afb10024 	sw	s1,36(sp)
  52a528:	3c13006c 	lui	s3,0x6c
  52a52c:	afb00020 	sw	s0,32(sp)
  52a530:	afbf0044 	sw	ra,68(sp)
  52a534:	00a08821 	move	s1,a1
  52a538:	afbe0040 	sw	s8,64(sp)
  52a53c:	26737820 	addiu	s3,s3,30752
  52a540:	afb7003c 	sw	s7,60(sp)
  52a544:	2694beb0 	addiu	s4,s4,-16720
  52a548:	afb60038 	sw	s6,56(sp)
  52a54c:	0c10206c 	jal	0x4081b0
  52a550:	afb50034 	sw	s5,52(sp)
  52a554:	00408021 	move	s0,v0
  52a558:	00121080 	sll	v0,s2,0x2
  52a55c:	02629821 	addu	s3,s3,v0
  52a560:	12000016 	beqz	s0,0x52a5bc
  52a564:	0054a021 	addu	s4,v0,s4
  52a568:	2e42000e 	sltiu	v0,s2,14
  52a56c:	1040000e 	beqz	v0,0x52a5a8
  52a570:	00000000 	nop
  52a574:	8e620000 	lw	v0,0(s3)
  52a578:	00400008 	jr	v0
  52a57c:	00000000 	nop
  52a580:	8e190044 	lw	t9,68(s0)
  52a584:	13200008 	beqz	t9,0x52a5a8
  52a588:	00000000 	nop
  52a58c:	0320f809 	jalr	t9
  52a590:	02202021 	move	a0,s1
  52a594:	10400004 	beqz	v0,0x52a5a8
  52a598:	3c030075 	lui	v1,0x75
  52a59c:	8062bea4 	lb	v0,-16732(v1)
  52a5a0:	14400051 	bnez	v0,0x52a6e8
  52a5a4:	00000000 	nop
  52a5a8:	0c1021a0 	jal	0x408680
  52a5ac:	02002021 	move	a0,s0
  52a5b0:	00408021 	move	s0,v0
  52a5b4:	1600ffed 	bnez	s0,0x52a56c
  52a5b8:	2e42000e 	sltiu	v0,s2,14
  52a5bc:	8fbf0044 	lw	ra,68(sp)
  52a5c0:	00001021 	move	v0,zero
  52a5c4:	8fbe0040 	lw	s8,64(sp)
  52a5c8:	8fb7003c 	lw	s7,60(sp)
  52a5cc:	8fb60038 	lw	s6,56(sp)
  52a5d0:	8fb50034 	lw	s5,52(sp)
  52a5d4:	8fb40030 	lw	s4,48(sp)
  52a5d8:	8fb3002c 	lw	s3,44(sp)
  52a5dc:	8fb20028 	lw	s2,40(sp)
  52a5e0:	8fb10024 	lw	s1,36(sp)
  52a5e4:	8fb00020 	lw	s0,32(sp)
  52a5e8:	03e00008 	jr	ra
  52a5ec:	27bd0048 	addiu	sp,sp,72
  52a5f0:	8e19002c 	lw	t9,44(s0)
  52a5f4:	1320ffec 	beqz	t9,0x52a5a8
  52a5f8:	00000000 	nop
  52a5fc:	8e240000 	lw	a0,0(s1)
  52a600:	0814a999 	j	0x52a664
  52a604:	8e250004 	lw	a1,4(s1)
  52a608:	0814a961 	j	0x52a584
  52a60c:	8e190020 	lw	t9,32(s0)
  52a610:	0814a961 	j	0x52a584
  52a614:	8e190014 	lw	t9,20(s0)
  52a618:	0814a961 	j	0x52a584
  52a61c:	8e190048 	lw	t9,72(s0)
  52a620:	0814a961 	j	0x52a584
  52a624:	8e19001c 	lw	t9,28(s0)
  52a628:	0814a961 	j	0x52a584
  52a62c:	8e190018 	lw	t9,24(s0)
  52a630:	8e190030 	lw	t9,48(s0)
  52a634:	1320ffdc 	beqz	t9,0x52a5a8
  52a638:	00000000 	nop
  52a63c:	8e240000 	lw	a0,0(s1)
  52a640:	8e250004 	lw	a1,4(s1)
  52a644:	0320f809 	jalr	t9
  52a648:	8e260008 	lw	a2,8(s1)
  52a64c:	0814a965 	j	0x52a594
  52a650:	00000000 	nop
  52a654:	8e190028 	lw	t9,40(s0)
  52a658:	1320ffd3 	beqz	t9,0x52a5a8
  52a65c:	26250008 	addiu	a1,s1,8
  52a660:	96240000 	lhu	a0,0(s1)
  52a664:	0320f809 	jalr	t9
  52a668:	00000000 	nop
  52a66c:	0814a965 	j	0x52a594
  52a670:	00000000 	nop
  52a674:	0814a961 	j	0x52a584
  52a678:	8e190024 	lw	t9,36(s0)
  52a67c:	8e020034 	lw	v0,52(s0)
  52a680:	1040ffc9 	beqz	v0,0x52a5a8
  52a684:	3c160052 	lui	s6,0x52
  52a688:	26350008 	addiu	s5,s1,8
  52a68c:	26d6beb4 	addiu	s6,s6,-16716
  52a690:	24170002 	li	s7,2
  52a694:	241e0001 	li	s8,1
  52a698:	8e190034 	lw	t9,52(s0)
  52a69c:	02a02021 	move	a0,s5
  52a6a0:	8e260000 	lw	a2,0(s1)
  52a6a4:	0320f809 	jalr	t9
  52a6a8:	02c02821 	move	a1,s6
  52a6ac:	1057ffbb 	beq	v0,s7,0x52a59c
  52a6b0:	3c030075 	lui	v1,0x75
  52a6b4:	505efff9 	beql	v0,s8,0x52a69c
  52a6b8:	8e190034 	lw	t9,52(s0)
  52a6bc:	0814a965 	j	0x52a594
  52a6c0:	00000000 	nop
  52a6c4:	8e19003c 	lw	t9,60(s0)
  52a6c8:	1320ffb7 	beqz	t9,0x52a5a8
  52a6cc:	02202021 	move	a0,s1
  52a6d0:	0814a999 	j	0x52a664
  52a6d4:	262502d8 	addiu	a1,s1,728
  52a6d8:	0814a996 	j	0x52a658
  52a6dc:	8e190038 	lw	t9,56(s0)
  52a6e0:	0814a961 	j	0x52a584
  52a6e4:	8e190040 	lw	t9,64(s0)
  52a6e8:	0c16276a 	jal	0x589da8
  52a6ec:	00000000 	nop
  52a6f0:	1040ffad 	beqz	v0,0x52a5a8
  52a6f4:	3c04006c 	lui	a0,0x6c
  52a6f8:	8e870000 	lw	a3,0(s4)
  52a6fc:	3c05006c 	lui	a1,0x6c
  52a700:	8e02000c 	lw	v0,12(s0)
  52a704:	248455c4 	addiu	a0,a0,21956
  52a708:	24a578a8 	addiu	a1,a1,30888
  52a70c:	240601d0 	li	a2,464
  52a710:	0c101b74 	jal	0x406dd0
  52a714:	afa20010 	sw	v0,16(sp)
  52a718:	0814a96a 	j	0x52a5a8
  52a71c:	00000000 	nop

; func cw_priv_ap_log_report_para_create @ 0x005a6628 size=0xf0
  5a6628:	27bdffd8 	addiu	sp,sp,-40
  5a662c:	2405001c 	li	a1,28
  5a6630:	afb0001c 	sw	s0,28(sp)
  5a6634:	afbf0024 	sw	ra,36(sp)
  5a6638:	0c15c8cc 	jal	0x572330
  5a663c:	afb10020 	sw	s1,32(sp)
  5a6640:	1040001a 	beqz	v0,0x5a66ac
  5a6644:	00408021 	move	s0,v0
  5a6648:	90450004 	lbu	a1,4(v0)
  5a664c:	24030019 	li	v1,25
  5a6650:	2402000d 	li	v0,13
  5a6654:	24040060 	li	a0,96
  5a6658:	38a50001 	xori	a1,a1,0x1
  5a665c:	0065100b 	movn	v0,v1,a1
  5a6660:	02003021 	move	a2,s0
  5a6664:	0c15c943 	jal	0x57250c
  5a6668:	00402821 	move	a1,v0
  5a666c:	10400007 	beqz	v0,0x5a668c
  5a6670:	00408821 	move	s1,v0
  5a6674:	8fbf0024 	lw	ra,36(sp)
  5a6678:	02201021 	move	v0,s1
  5a667c:	8fb10020 	lw	s1,32(sp)
  5a6680:	8fb0001c 	lw	s0,28(sp)
  5a6684:	03e00008 	jr	ra
  5a6688:	27bd0028 	addiu	sp,sp,40
  5a668c:	3c020075 	lui	v0,0x75
  5a6690:	8c42cf58 	lw	v0,-12456(v0)
  5a6694:	14400015 	bnez	v0,0x5a66ec
  5a6698:	00000000 	nop
  5a669c:	0c101f7c 	jal	0x407df0
  5a66a0:	02002021 	move	a0,s0
  5a66a4:	0816999e 	j	0x5a6678
  5a66a8:	8fbf0024 	lw	ra,36(sp)
  5a66ac:	3c020075 	lui	v0,0x75
  5a66b0:	8c42cf58 	lw	v0,-12456(v0)
  5a66b4:	1040ffef 	beqz	v0,0x5a6674
  5a66b8:	00008821 	move	s1,zero
  5a66bc:	0c16276a 	jal	0x589da8
  5a66c0:	00000000 	nop
  5a66c4:	5040ffec 	beqzl	v0,0x5a6678
  5a66c8:	8fbf0024 	lw	ra,36(sp)
  5a66cc:	3c04006d 	lui	a0,0x6d
  5a66d0:	3c05006e 	lui	a1,0x6e
  5a66d4:	248434fc 	addiu	a0,a0,13564
  5a66d8:	24a57ed0 	addiu	a1,a1,32464
  5a66dc:	0c101b74 	jal	0x406dd0
  5a66e0:	240600bd 	li	a2,189
  5a66e4:	0816999e 	j	0x5a6678
  5a66e8:	8fbf0024 	lw	ra,36(sp)
  5a66ec:	0c16276a 	jal	0x589da8
  5a66f0:	00000000 	nop
  5a66f4:	1040ffe9 	beqz	v0,0x5a669c
  5a66f8:	3c04006d 	lui	a0,0x6d
  5a66fc:	3c05006e 	lui	a1,0x6e
  5a6700:	248447f0 	addiu	a0,a0,18416
  5a6704:	24a57ed0 	addiu	a1,a1,32464
  5a6708:	0c101b74 	jal	0x406dd0
  5a670c:	240600c5 	li	a2,197
  5a6710:	081699a7 	j	0x5a669c
  5a6714:	00000000 	nop
	...

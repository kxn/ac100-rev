; func cw_priv_region_config_create @ 0x005ba4b8 size=0xdc
  5ba4b8:	27bdffd8 	addiu	sp,sp,-40
  5ba4bc:	24050001 	li	a1,1
  5ba4c0:	afb0001c 	sw	s0,28(sp)
  5ba4c4:	afbf0024 	sw	ra,36(sp)
  5ba4c8:	0c15c8cc 	jal	0x572330
  5ba4cc:	afb10020 	sw	s1,32(sp)
  5ba4d0:	1040000d 	beqz	v0,0x5ba508
  5ba4d4:	00408021 	move	s0,v0
  5ba4d8:	24040098 	li	a0,152
  5ba4dc:	24050001 	li	a1,1
  5ba4e0:	0c15c943 	jal	0x57250c
  5ba4e4:	00403021 	move	a2,v0
  5ba4e8:	10400017 	beqz	v0,0x5ba548
  5ba4ec:	00408821 	move	s1,v0
  5ba4f0:	8fbf0024 	lw	ra,36(sp)
  5ba4f4:	02201021 	move	v0,s1
  5ba4f8:	8fb10020 	lw	s1,32(sp)
  5ba4fc:	8fb0001c 	lw	s0,28(sp)
  5ba500:	03e00008 	jr	ra
  5ba504:	27bd0028 	addiu	sp,sp,40
  5ba508:	3c020075 	lui	v0,0x75
  5ba50c:	8c42cf58 	lw	v0,-12456(v0)
  5ba510:	1040fff7 	beqz	v0,0x5ba4f0
  5ba514:	00008821 	move	s1,zero
  5ba518:	0c16276a 	jal	0x589da8
  5ba51c:	00000000 	nop
  5ba520:	5040fff4 	beqzl	v0,0x5ba4f4
  5ba524:	8fbf0024 	lw	ra,36(sp)
  5ba528:	3c04006d 	lui	a0,0x6d
  5ba52c:	3c05006f 	lui	a1,0x6f
  5ba530:	248434fc 	addiu	a0,a0,13564
  5ba534:	24a5d610 	addiu	a1,a1,-10736
  5ba538:	0c101b74 	jal	0x406dd0
  5ba53c:	240600a2 	li	a2,162
  5ba540:	0816e93d 	j	0x5ba4f4
  5ba544:	8fbf0024 	lw	ra,36(sp)
  5ba548:	3c020075 	lui	v0,0x75
  5ba54c:	8c42cf58 	lw	v0,-12456(v0)
  5ba550:	14400005 	bnez	v0,0x5ba568
  5ba554:	00000000 	nop
  5ba558:	0c101f7c 	jal	0x407df0
  5ba55c:	02002021 	move	a0,s0
  5ba560:	0816e93d 	j	0x5ba4f4
  5ba564:	8fbf0024 	lw	ra,36(sp)
  5ba568:	0c16276a 	jal	0x589da8
  5ba56c:	00000000 	nop
  5ba570:	1040fff9 	beqz	v0,0x5ba558
  5ba574:	3c04006d 	lui	a0,0x6d
  5ba578:	3c05006f 	lui	a1,0x6f
  5ba57c:	248447f0 	addiu	a0,a0,18416
  5ba580:	24a5d610 	addiu	a1,a1,-10736
  5ba584:	0c101b74 	jal	0x406dd0
  5ba588:	240600aa 	li	a2,170
  5ba58c:	0816e956 	j	0x5ba558
  5ba590:	00000000 	nop

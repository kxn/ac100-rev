; func cw_ac_timestamp_create @ 0x0056f40c size=0xdc
  56f40c:	27bdffd8 	addiu	sp,sp,-40
  56f410:	24050004 	li	a1,4
  56f414:	afb0001c 	sw	s0,28(sp)
  56f418:	afbf0024 	sw	ra,36(sp)
  56f41c:	0c15c8cc 	jal	0x572330
  56f420:	afb10020 	sw	s1,32(sp)
  56f424:	1040000d 	beqz	v0,0x56f45c
  56f428:	00408021 	move	s0,v0
  56f42c:	24040006 	li	a0,6
  56f430:	24050004 	li	a1,4
  56f434:	0c15c943 	jal	0x57250c
  56f438:	00403021 	move	a2,v0
  56f43c:	10400017 	beqz	v0,0x56f49c
  56f440:	00408821 	move	s1,v0
  56f444:	8fbf0024 	lw	ra,36(sp)
  56f448:	02201021 	move	v0,s1
  56f44c:	8fb10020 	lw	s1,32(sp)
  56f450:	8fb0001c 	lw	s0,28(sp)
  56f454:	03e00008 	jr	ra
  56f458:	27bd0028 	addiu	sp,sp,40
  56f45c:	3c020075 	lui	v0,0x75
  56f460:	8c42cf58 	lw	v0,-12456(v0)
  56f464:	1040fff7 	beqz	v0,0x56f444
  56f468:	00008821 	move	s1,zero
  56f46c:	0c16276a 	jal	0x589da8
  56f470:	00000000 	nop
  56f474:	5040fff4 	beqzl	v0,0x56f448
  56f478:	8fbf0024 	lw	ra,36(sp)
  56f47c:	3c04006d 	lui	a0,0x6d
  56f480:	3c05006d 	lui	a1,0x6d
  56f484:	248434fc 	addiu	a0,a0,13564
  56f488:	24a572e0 	addiu	a1,a1,29408
  56f48c:	0c101b74 	jal	0x406dd0
  56f490:	24060099 	li	a2,153
  56f494:	0815bd12 	j	0x56f448
  56f498:	8fbf0024 	lw	ra,36(sp)
  56f49c:	3c020075 	lui	v0,0x75
  56f4a0:	8c42cf58 	lw	v0,-12456(v0)
  56f4a4:	14400005 	bnez	v0,0x56f4bc
  56f4a8:	00000000 	nop
  56f4ac:	0c101f7c 	jal	0x407df0
  56f4b0:	02002021 	move	a0,s0
  56f4b4:	0815bd12 	j	0x56f448
  56f4b8:	8fbf0024 	lw	ra,36(sp)
  56f4bc:	0c16276a 	jal	0x589da8
  56f4c0:	00000000 	nop
  56f4c4:	1040fff9 	beqz	v0,0x56f4ac
  56f4c8:	3c04006d 	lui	a0,0x6d
  56f4cc:	3c05006d 	lui	a1,0x6d
  56f4d0:	24843580 	addiu	a0,a0,13696
  56f4d4:	24a572e0 	addiu	a1,a1,29408
  56f4d8:	0c101b74 	jal	0x406dd0
  56f4dc:	240600a1 	li	a2,161
  56f4e0:	0815bd2b 	j	0x56f4ac
  56f4e4:	00000000 	nop

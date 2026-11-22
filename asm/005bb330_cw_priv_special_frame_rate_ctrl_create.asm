; func cw_priv_special_frame_rate_ctrl_create @ 0x005bb330 size=0x1ac
  5bb330:	27bdffd8 	addiu	sp,sp,-40
  5bb334:	24050008 	li	a1,8
  5bb338:	afb10020 	sw	s1,32(sp)
  5bb33c:	afb0001c 	sw	s0,28(sp)
  5bb340:	afbf0024 	sw	ra,36(sp)
  5bb344:	0c15c8cc 	jal	0x572330
  5bb348:	00808821 	move	s1,a0
  5bb34c:	10400027 	beqz	v0,0x5bb3ec
  5bb350:	00408021 	move	s0,v0
  5bb354:	ac400004 	sw	zero,4(v0)
  5bb358:	92250002 	lbu	a1,2(s1)
  5bb35c:	10a0000a 	beqz	a1,0x5bb388
  5bb360:	2404008e 	li	a0,142
  5bb364:	8e240004 	lw	a0,4(s1)
  5bb368:	1080003c 	beqz	a0,0x5bb45c
  5bb36c:	3c020075 	lui	v0,0x75
  5bb370:	0c15c8cc 	jal	0x572330
  5bb374:	00052880 	sll	a1,a1,0x2
  5bb378:	1040003f 	beqz	v0,0x5bb478
  5bb37c:	ae020004 	sw	v0,4(s0)
  5bb380:	92250002 	lbu	a1,2(s1)
  5bb384:	2404008e 	li	a0,142
  5bb388:	02003021 	move	a2,s0
  5bb38c:	24a50001 	addiu	a1,a1,1
  5bb390:	0c15c943 	jal	0x57250c
  5bb394:	00052880 	sll	a1,a1,0x2
  5bb398:	10400007 	beqz	v0,0x5bb3b8
  5bb39c:	00408821 	move	s1,v0
  5bb3a0:	8fbf0024 	lw	ra,36(sp)
  5bb3a4:	02201021 	move	v0,s1
  5bb3a8:	8fb10020 	lw	s1,32(sp)
  5bb3ac:	8fb0001c 	lw	s0,28(sp)
  5bb3b0:	03e00008 	jr	ra
  5bb3b4:	27bd0028 	addiu	sp,sp,40
  5bb3b8:	3c020075 	lui	v0,0x75
  5bb3bc:	8c42cf58 	lw	v0,-12456(v0)
  5bb3c0:	1440001a 	bnez	v0,0x5bb42c
  5bb3c4:	00000000 	nop
  5bb3c8:	8e040004 	lw	a0,4(s0)
  5bb3cc:	10800003 	beqz	a0,0x5bb3dc
  5bb3d0:	00000000 	nop
  5bb3d4:	0c101f7c 	jal	0x407df0
  5bb3d8:	00000000 	nop
  5bb3dc:	0c101f7c 	jal	0x407df0
  5bb3e0:	02002021 	move	a0,s0
  5bb3e4:	0816ece9 	j	0x5bb3a4
  5bb3e8:	8fbf0024 	lw	ra,36(sp)
  5bb3ec:	3c020075 	lui	v0,0x75
  5bb3f0:	8c42cf58 	lw	v0,-12456(v0)
  5bb3f4:	1040ffea 	beqz	v0,0x5bb3a0
  5bb3f8:	00008821 	move	s1,zero
  5bb3fc:	0c16276a 	jal	0x589da8
  5bb400:	00000000 	nop
  5bb404:	5040ffe7 	beqzl	v0,0x5bb3a4
  5bb408:	8fbf0024 	lw	ra,36(sp)
  5bb40c:	3c04006d 	lui	a0,0x6d
  5bb410:	3c05006f 	lui	a1,0x6f
  5bb414:	248434fc 	addiu	a0,a0,13564
  5bb418:	24a5db70 	addiu	a1,a1,-9360
  5bb41c:	0c101b74 	jal	0x406dd0
  5bb420:	240600e3 	li	a2,227
  5bb424:	0816ece9 	j	0x5bb3a4
  5bb428:	8fbf0024 	lw	ra,36(sp)
  5bb42c:	0c16276a 	jal	0x589da8
  5bb430:	00000000 	nop
  5bb434:	5040ffe5 	beqzl	v0,0x5bb3cc
  5bb438:	8e040004 	lw	a0,4(s0)
  5bb43c:	3c04006d 	lui	a0,0x6d
  5bb440:	3c05006f 	lui	a1,0x6f
  5bb444:	248447f0 	addiu	a0,a0,18416
  5bb448:	24a5db70 	addiu	a1,a1,-9360
  5bb44c:	0c101b74 	jal	0x406dd0
  5bb450:	240600fe 	li	a2,254
  5bb454:	0816ecf3 	j	0x5bb3cc
  5bb458:	8e040004 	lw	a0,4(s0)
  5bb45c:	8c42cf58 	lw	v0,-12456(v0)
  5bb460:	14400015 	bnez	v0,0x5bb4b8
  5bb464:	00000000 	nop
  5bb468:	0c101f7c 	jal	0x407df0
  5bb46c:	02002021 	move	a0,s0
  5bb470:	0816ece8 	j	0x5bb3a0
  5bb474:	00008821 	move	s1,zero
  5bb478:	3c020075 	lui	v0,0x75
  5bb47c:	8c42cf58 	lw	v0,-12456(v0)
  5bb480:	1040fff9 	beqz	v0,0x5bb468
  5bb484:	00000000 	nop
  5bb488:	0c16276a 	jal	0x589da8
  5bb48c:	00000000 	nop
  5bb490:	1040fff5 	beqz	v0,0x5bb468
  5bb494:	3c04006f 	lui	a0,0x6f
  5bb498:	3c05006f 	lui	a1,0x6f
  5bb49c:	2484dabc 	addiu	a0,a0,-9540
  5bb4a0:	24a5db70 	addiu	a1,a1,-9360
  5bb4a4:	240600f4 	li	a2,244
  5bb4a8:	0c101b74 	jal	0x406dd0
  5bb4ac:	00000000 	nop
  5bb4b0:	0816ed1a 	j	0x5bb468
  5bb4b4:	00000000 	nop
  5bb4b8:	0c16276a 	jal	0x589da8
  5bb4bc:	00000000 	nop
  5bb4c0:	1040ffe9 	beqz	v0,0x5bb468
  5bb4c4:	3c04006f 	lui	a0,0x6f
  5bb4c8:	3c05006f 	lui	a1,0x6f
  5bb4cc:	2484da94 	addiu	a0,a0,-9580
  5bb4d0:	24a5db70 	addiu	a1,a1,-9360
  5bb4d4:	0816ed2a 	j	0x5bb4a8
  5bb4d8:	240600ed 	li	a2,237

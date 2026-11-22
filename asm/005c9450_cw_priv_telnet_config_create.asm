; func cw_priv_telnet_config_create @ 0x005c9450 size=0xdc
  5c9450:	27bdffd8 	addiu	sp,sp,-40
  5c9454:	24050004 	li	a1,4
  5c9458:	afb0001c 	sw	s0,28(sp)
  5c945c:	afbf0024 	sw	ra,36(sp)
  5c9460:	0c15c8cc 	jal	0x572330
  5c9464:	afb10020 	sw	s1,32(sp)
  5c9468:	1040000d 	beqz	v0,0x5c94a0
  5c946c:	00408021 	move	s0,v0
  5c9470:	2404009f 	li	a0,159
  5c9474:	24050003 	li	a1,3
  5c9478:	0c15c943 	jal	0x57250c
  5c947c:	00403021 	move	a2,v0
  5c9480:	10400017 	beqz	v0,0x5c94e0
  5c9484:	00408821 	move	s1,v0
  5c9488:	8fbf0024 	lw	ra,36(sp)
  5c948c:	02201021 	move	v0,s1
  5c9490:	8fb10020 	lw	s1,32(sp)
  5c9494:	8fb0001c 	lw	s0,28(sp)
  5c9498:	03e00008 	jr	ra
  5c949c:	27bd0028 	addiu	sp,sp,40
  5c94a0:	3c020075 	lui	v0,0x75
  5c94a4:	8c42cf58 	lw	v0,-12456(v0)
  5c94a8:	1040fff7 	beqz	v0,0x5c9488
  5c94ac:	00008821 	move	s1,zero
  5c94b0:	0c16276a 	jal	0x589da8
  5c94b4:	00000000 	nop
  5c94b8:	5040fff4 	beqzl	v0,0x5c948c
  5c94bc:	8fbf0024 	lw	ra,36(sp)
  5c94c0:	3c04006d 	lui	a0,0x6d
  5c94c4:	3c05006f 	lui	a1,0x6f
  5c94c8:	248434fc 	addiu	a0,a0,13564
  5c94cc:	24a50c20 	addiu	a1,a1,3104
  5c94d0:	0c101b74 	jal	0x406dd0
  5c94d4:	240600ad 	li	a2,173
  5c94d8:	08172523 	j	0x5c948c
  5c94dc:	8fbf0024 	lw	ra,36(sp)
  5c94e0:	3c020075 	lui	v0,0x75
  5c94e4:	8c42cf58 	lw	v0,-12456(v0)
  5c94e8:	14400005 	bnez	v0,0x5c9500
  5c94ec:	00000000 	nop
  5c94f0:	0c101f7c 	jal	0x407df0
  5c94f4:	02002021 	move	a0,s0
  5c94f8:	08172523 	j	0x5c948c
  5c94fc:	8fbf0024 	lw	ra,36(sp)
  5c9500:	0c16276a 	jal	0x589da8
  5c9504:	00000000 	nop
  5c9508:	1040fff9 	beqz	v0,0x5c94f0
  5c950c:	3c04006d 	lui	a0,0x6d
  5c9510:	3c05006f 	lui	a1,0x6f
  5c9514:	248447f0 	addiu	a0,a0,18416
  5c9518:	24a50c20 	addiu	a1,a1,3104
  5c951c:	0c101b74 	jal	0x406dd0
  5c9520:	240600b5 	li	a2,181
  5c9524:	0817253c 	j	0x5c94f0
  5c9528:	00000000 	nop

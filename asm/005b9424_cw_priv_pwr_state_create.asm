; func cw_priv_pwr_state_create @ 0x005b9424 size=0xdc
  5b9424:	27bdffd8 	addiu	sp,sp,-40
  5b9428:	24050002 	li	a1,2
  5b942c:	afb0001c 	sw	s0,28(sp)
  5b9430:	afbf0024 	sw	ra,36(sp)
  5b9434:	0c15c8cc 	jal	0x572330
  5b9438:	afb10020 	sw	s1,32(sp)
  5b943c:	1040000d 	beqz	v0,0x5b9474
  5b9440:	00408021 	move	s0,v0
  5b9444:	24040007 	li	a0,7
  5b9448:	24050002 	li	a1,2
  5b944c:	0c15c943 	jal	0x57250c
  5b9450:	00403021 	move	a2,v0
  5b9454:	10400017 	beqz	v0,0x5b94b4
  5b9458:	00408821 	move	s1,v0
  5b945c:	8fbf0024 	lw	ra,36(sp)
  5b9460:	02201021 	move	v0,s1
  5b9464:	8fb10020 	lw	s1,32(sp)
  5b9468:	8fb0001c 	lw	s0,28(sp)
  5b946c:	03e00008 	jr	ra
  5b9470:	27bd0028 	addiu	sp,sp,40
  5b9474:	3c020075 	lui	v0,0x75
  5b9478:	8c42cf58 	lw	v0,-12456(v0)
  5b947c:	1040fff7 	beqz	v0,0x5b945c
  5b9480:	00008821 	move	s1,zero
  5b9484:	0c16276a 	jal	0x589da8
  5b9488:	00000000 	nop
  5b948c:	5040fff4 	beqzl	v0,0x5b9460
  5b9490:	8fbf0024 	lw	ra,36(sp)
  5b9494:	3c04006d 	lui	a0,0x6d
  5b9498:	3c05006f 	lui	a1,0x6f
  5b949c:	248434fc 	addiu	a0,a0,13564
  5b94a0:	24a5d150 	addiu	a1,a1,-11952
  5b94a4:	0c101b74 	jal	0x406dd0
  5b94a8:	240600b0 	li	a2,176
  5b94ac:	0816e518 	j	0x5b9460
  5b94b0:	8fbf0024 	lw	ra,36(sp)
  5b94b4:	3c020075 	lui	v0,0x75
  5b94b8:	8c42cf58 	lw	v0,-12456(v0)
  5b94bc:	14400005 	bnez	v0,0x5b94d4
  5b94c0:	00000000 	nop
  5b94c4:	0c101f7c 	jal	0x407df0
  5b94c8:	02002021 	move	a0,s0
  5b94cc:	0816e518 	j	0x5b9460
  5b94d0:	8fbf0024 	lw	ra,36(sp)
  5b94d4:	0c16276a 	jal	0x589da8
  5b94d8:	00000000 	nop
  5b94dc:	1040fff9 	beqz	v0,0x5b94c4
  5b94e0:	3c04006d 	lui	a0,0x6d
  5b94e4:	3c05006f 	lui	a1,0x6f
  5b94e8:	248447f0 	addiu	a0,a0,18416
  5b94ec:	24a5d150 	addiu	a1,a1,-11952
  5b94f0:	0c101b74 	jal	0x406dd0
  5b94f4:	240600b8 	li	a2,184
  5b94f8:	0816e531 	j	0x5b94c4
  5b94fc:	00000000 	nop

; func cw_priv_lag_config_create @ 0x005b4394 size=0x1ac
  5b4394:	27bdffd8 	addiu	sp,sp,-40
  5b4398:	24050008 	li	a1,8
  5b439c:	afb10020 	sw	s1,32(sp)
  5b43a0:	afb0001c 	sw	s0,28(sp)
  5b43a4:	afbf0024 	sw	ra,36(sp)
  5b43a8:	0c15c8cc 	jal	0x572330
  5b43ac:	00808821 	move	s1,a0
  5b43b0:	10400027 	beqz	v0,0x5b4450
  5b43b4:	00408021 	move	s0,v0
  5b43b8:	ac400004 	sw	zero,4(v0)
  5b43bc:	92250002 	lbu	a1,2(s1)
  5b43c0:	10a0000a 	beqz	a1,0x5b43ec
  5b43c4:	240400a3 	li	a0,163
  5b43c8:	8e240004 	lw	a0,4(s1)
  5b43cc:	1080003c 	beqz	a0,0x5b44c0
  5b43d0:	3c020075 	lui	v0,0x75
  5b43d4:	0c15c8cc 	jal	0x572330
  5b43d8:	00000000 	nop
  5b43dc:	1040003f 	beqz	v0,0x5b44dc
  5b43e0:	ae020004 	sw	v0,4(s0)
  5b43e4:	92250002 	lbu	a1,2(s1)
  5b43e8:	240400a3 	li	a0,163
  5b43ec:	02003021 	move	a2,s0
  5b43f0:	0c15c943 	jal	0x57250c
  5b43f4:	24a50003 	addiu	a1,a1,3
  5b43f8:	10400007 	beqz	v0,0x5b4418
  5b43fc:	00408821 	move	s1,v0
  5b4400:	8fbf0024 	lw	ra,36(sp)
  5b4404:	02201021 	move	v0,s1
  5b4408:	8fb10020 	lw	s1,32(sp)
  5b440c:	8fb0001c 	lw	s0,28(sp)
  5b4410:	03e00008 	jr	ra
  5b4414:	27bd0028 	addiu	sp,sp,40
  5b4418:	3c020075 	lui	v0,0x75
  5b441c:	8c42cf58 	lw	v0,-12456(v0)
  5b4420:	1440001b 	bnez	v0,0x5b4490
  5b4424:	00000000 	nop
  5b4428:	8e040004 	lw	a0,4(s0)
  5b442c:	10800004 	beqz	a0,0x5b4440
  5b4430:	00000000 	nop
  5b4434:	0c101f7c 	jal	0x407df0
  5b4438:	00000000 	nop
  5b443c:	ae000004 	sw	zero,4(s0)
  5b4440:	0c101f7c 	jal	0x407df0
  5b4444:	02002021 	move	a0,s0
  5b4448:	0816d101 	j	0x5b4404
  5b444c:	8fbf0024 	lw	ra,36(sp)
  5b4450:	3c020075 	lui	v0,0x75
  5b4454:	8c42cf58 	lw	v0,-12456(v0)
  5b4458:	1040ffe9 	beqz	v0,0x5b4400
  5b445c:	00008821 	move	s1,zero
  5b4460:	0c16276a 	jal	0x589da8
  5b4464:	00000000 	nop
  5b4468:	5040ffe6 	beqzl	v0,0x5b4404
  5b446c:	8fbf0024 	lw	ra,36(sp)
  5b4470:	3c04006d 	lui	a0,0x6d
  5b4474:	3c05006f 	lui	a1,0x6f
  5b4478:	248434fc 	addiu	a0,a0,13564
  5b447c:	24a5bfa0 	addiu	a1,a1,-16480
  5b4480:	0c101b74 	jal	0x406dd0
  5b4484:	240600c5 	li	a2,197
  5b4488:	0816d101 	j	0x5b4404
  5b448c:	8fbf0024 	lw	ra,36(sp)
  5b4490:	0c16276a 	jal	0x589da8
  5b4494:	00000000 	nop
  5b4498:	5040ffe4 	beqzl	v0,0x5b442c
  5b449c:	8e040004 	lw	a0,4(s0)
  5b44a0:	3c04006d 	lui	a0,0x6d
  5b44a4:	3c05006f 	lui	a1,0x6f
  5b44a8:	248447f0 	addiu	a0,a0,18416
  5b44ac:	24a5bfa0 	addiu	a1,a1,-16480
  5b44b0:	0c101b74 	jal	0x406dd0
  5b44b4:	240600e3 	li	a2,227
  5b44b8:	0816d10b 	j	0x5b442c
  5b44bc:	8e040004 	lw	a0,4(s0)
  5b44c0:	8c42cf58 	lw	v0,-12456(v0)
  5b44c4:	14400015 	bnez	v0,0x5b451c
  5b44c8:	00000000 	nop
  5b44cc:	0c101f7c 	jal	0x407df0
  5b44d0:	02002021 	move	a0,s0
  5b44d4:	0816d100 	j	0x5b4400
  5b44d8:	00008821 	move	s1,zero
  5b44dc:	3c020075 	lui	v0,0x75
  5b44e0:	8c42cf58 	lw	v0,-12456(v0)
  5b44e4:	1040fff9 	beqz	v0,0x5b44cc
  5b44e8:	00000000 	nop
  5b44ec:	0c16276a 	jal	0x589da8
  5b44f0:	00000000 	nop
  5b44f4:	1040fff5 	beqz	v0,0x5b44cc
  5b44f8:	3c04006e 	lui	a0,0x6e
  5b44fc:	3c05006f 	lui	a1,0x6f
  5b4500:	24848050 	addiu	a0,a0,-32688
  5b4504:	24a5bfa0 	addiu	a1,a1,-16480
  5b4508:	240600d9 	li	a2,217
  5b450c:	0c101b74 	jal	0x406dd0
  5b4510:	00000000 	nop
  5b4514:	0816d133 	j	0x5b44cc
  5b4518:	00000000 	nop
  5b451c:	0c16276a 	jal	0x589da8
  5b4520:	00000000 	nop
  5b4524:	1040ffe9 	beqz	v0,0x5b44cc
  5b4528:	3c04006e 	lui	a0,0x6e
  5b452c:	3c05006f 	lui	a1,0x6f
  5b4530:	248480d8 	addiu	a0,a0,-32552
  5b4534:	24a5bfa0 	addiu	a1,a1,-16480
  5b4538:	0816d143 	j	0x5b450c
  5b453c:	240600d0 	li	a2,208

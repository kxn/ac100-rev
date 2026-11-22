; func cw_priv_ap_checksum_result_create @ 0x005a4440 size=0xdc
  5a4440:	27bdffd8 	addiu	sp,sp,-40
  5a4444:	24050001 	li	a1,1
  5a4448:	afb0001c 	sw	s0,28(sp)
  5a444c:	afbf0024 	sw	ra,36(sp)
  5a4450:	0c15c8cc 	jal	0x572330
  5a4454:	afb10020 	sw	s1,32(sp)
  5a4458:	1040000d 	beqz	v0,0x5a4490
  5a445c:	00408021 	move	s0,v0
  5a4460:	24040085 	li	a0,133
  5a4464:	24050001 	li	a1,1
  5a4468:	0c15c943 	jal	0x57250c
  5a446c:	00403021 	move	a2,v0
  5a4470:	10400017 	beqz	v0,0x5a44d0
  5a4474:	00408821 	move	s1,v0
  5a4478:	8fbf0024 	lw	ra,36(sp)
  5a447c:	02201021 	move	v0,s1
  5a4480:	8fb10020 	lw	s1,32(sp)
  5a4484:	8fb0001c 	lw	s0,28(sp)
  5a4488:	03e00008 	jr	ra
  5a448c:	27bd0028 	addiu	sp,sp,40
  5a4490:	3c020075 	lui	v0,0x75
  5a4494:	8c42cf58 	lw	v0,-12456(v0)
  5a4498:	1040fff7 	beqz	v0,0x5a4478
  5a449c:	00008821 	move	s1,zero
  5a44a0:	0c16276a 	jal	0x589da8
  5a44a4:	00000000 	nop
  5a44a8:	5040fff4 	beqzl	v0,0x5a447c
  5a44ac:	8fbf0024 	lw	ra,36(sp)
  5a44b0:	3c04006d 	lui	a0,0x6d
  5a44b4:	3c05006e 	lui	a1,0x6e
  5a44b8:	248434fc 	addiu	a0,a0,13564
  5a44bc:	24a57530 	addiu	a1,a1,30000
  5a44c0:	0c101b74 	jal	0x406dd0
  5a44c4:	240600a3 	li	a2,163
  5a44c8:	0816911f 	j	0x5a447c
  5a44cc:	8fbf0024 	lw	ra,36(sp)
  5a44d0:	3c020075 	lui	v0,0x75
  5a44d4:	8c42cf58 	lw	v0,-12456(v0)
  5a44d8:	14400005 	bnez	v0,0x5a44f0
  5a44dc:	00000000 	nop
  5a44e0:	0c101f7c 	jal	0x407df0
  5a44e4:	02002021 	move	a0,s0
  5a44e8:	0816911f 	j	0x5a447c
  5a44ec:	8fbf0024 	lw	ra,36(sp)
  5a44f0:	0c16276a 	jal	0x589da8
  5a44f4:	00000000 	nop
  5a44f8:	1040fff9 	beqz	v0,0x5a44e0
  5a44fc:	3c04006d 	lui	a0,0x6d
  5a4500:	3c05006e 	lui	a1,0x6e
  5a4504:	248447f0 	addiu	a0,a0,18416
  5a4508:	24a57530 	addiu	a1,a1,30000
  5a450c:	0c101b74 	jal	0x406dd0
  5a4510:	240600ab 	li	a2,171
  5a4514:	08169138 	j	0x5a44e0
  5a4518:	00000000 	nop

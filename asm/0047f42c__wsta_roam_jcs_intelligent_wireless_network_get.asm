; func _wsta_roam_jcs_intelligent_wireless_network_get @ 0x0047f42c size=0xac
  47f42c:	27bdffb0 	addiu	sp,sp,-80
  47f430:	24060022 	li	a2,34
  47f434:	27a40018 	addiu	a0,sp,24
  47f438:	afb10048 	sw	s1,72(sp)
  47f43c:	00a08821 	move	s1,a1
  47f440:	00002821 	move	a1,zero
  47f444:	afbf004c 	sw	ra,76(sp)
  47f448:	0c101cf0 	jal	0x4073c0
  47f44c:	afb00044 	sw	s0,68(sp)
  47f450:	0c120ae0 	jal	0x482b80
  47f454:	27a40018 	addiu	a0,sp,24
  47f458:	00408021 	move	s0,v0
  47f45c:	2402ffff 	li	v0,-1
  47f460:	12020004 	beq	s0,v0,0x47f474
  47f464:	93a40019 	lbu	a0,25(sp)
  47f468:	1480000e 	bnez	a0,0x47f4a4
  47f46c:	2c820003 	sltiu	v0,a0,3
  47f470:	2410ffff 	li	s0,-1
  47f474:	0c101d34 	jal	0x4074d0
  47f478:	02002021 	move	a0,s0
  47f47c:	3c05006e 	lui	a1,0x6e
  47f480:	02202021 	move	a0,s1
  47f484:	24a57528 	addiu	a1,a1,29992
  47f488:	0c101d78 	jal	0x4075e0
  47f48c:	00403021 	move	a2,v0
  47f490:	8fbf004c 	lw	ra,76(sp)
  47f494:	8fb10048 	lw	s1,72(sp)
  47f498:	8fb00044 	lw	s0,68(sp)
  47f49c:	03e00008 	jr	ra
  47f4a0:	27bd0050 	addiu	sp,sp,80
  47f4a4:	5040fff3 	beqzl	v0,0x47f474
  47f4a8:	2410ffff 	li	s0,-1
  47f4ac:	1600fff1 	bnez	s0,0x47f474
  47f4b0:	00000000 	nop
  47f4b4:	0c101d34 	jal	0x4074d0
  47f4b8:	00000000 	nop
  47f4bc:	3c050069 	lui	a1,0x69
  47f4c0:	02202021 	move	a0,s1
  47f4c4:	24a53578 	addiu	a1,a1,13688
  47f4c8:	0c101d78 	jal	0x4075e0
  47f4cc:	00403021 	move	a2,v0
  47f4d0:	0811fd1d 	j	0x47f474
  47f4d4:	00000000 	nop

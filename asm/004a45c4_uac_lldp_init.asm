; func uac_lldp_init @ 0x004a45c4 size=0x140
  4a45c4:	27bdffe0 	addiu	sp,sp,-32
  4a45c8:	afb00018 	sw	s0,24(sp)
  4a45cc:	3c100076 	lui	s0,0x76
  4a45d0:	afbf001c 	sw	ra,28(sp)
  4a45d4:	82027b34 	lb	v0,31540(s0)
  4a45d8:	5440001f 	bnezl	v0,0x4a4658
  4a45dc:	3c04006a 	lui	a0,0x6a
  4a45e0:	3c04006a 	lui	a0,0x6a
  4a45e4:	00002821 	move	a1,zero
  4a45e8:	0c101fc0 	jal	0x407f00
  4a45ec:	2484e480 	addiu	a0,a0,-7040
  4a45f0:	3c030076 	lui	v1,0x76
  4a45f4:	10400038 	beqz	v0,0x4a46d8
  4a45f8:	ac627b38 	sw	v0,31544(v1)
  4a45fc:	3c040076 	lui	a0,0x76
  4a4600:	3c020076 	lui	v0,0x76
  4a4604:	24847b3c 	addiu	a0,a0,31548
  4a4608:	0c146b62 	jal	0x51ad88
  4a460c:	ac407b48 	sw	zero,31560(v0)
  4a4610:	82027b34 	lb	v0,31540(s0)
  4a4614:	14400029 	bnez	v0,0x4a46bc
  4a4618:	3c04006a 	lui	a0,0x6a
  4a461c:	3c10006a 	lui	s0,0x6a
  4a4620:	3c06004a 	lui	a2,0x4a
  4a4624:	2604e3e4 	addiu	a0,s0,-7196
  4a4628:	24050002 	li	a1,2
  4a462c:	0c102134 	jal	0x4084d0
  4a4630:	24c63c14 	addiu	a2,a2,15380
  4a4634:	1040000f 	beqz	v0,0x4a4674
  4a4638:	3c06004a 	lui	a2,0x4a
  4a463c:	0c129162 	jal	0x4a4588
  4a4640:	00000000 	nop
  4a4644:	2402ffff 	li	v0,-1
  4a4648:	8fbf001c 	lw	ra,28(sp)
  4a464c:	8fb00018 	lw	s0,24(sp)
  4a4650:	03e00008 	jr	ra
  4a4654:	27bd0020 	addiu	sp,sp,32
  4a4658:	3c05006a 	lui	a1,0x6a
  4a465c:	2484e440 	addiu	a0,a0,-7104
  4a4660:	24a5e57c 	addiu	a1,a1,-6788
  4a4664:	0c101b74 	jal	0x406dd0
  4a4668:	24060237 	li	a2,567
  4a466c:	08129179 	j	0x4a45e4
  4a4670:	3c04006a 	lui	a0,0x6a
  4a4674:	2604e3e4 	addiu	a0,s0,-7196
  4a4678:	24050003 	li	a1,3
  4a467c:	0c102134 	jal	0x4084d0
  4a4680:	24c637cc 	addiu	a2,a2,14284
  4a4684:	1440ffed 	bnez	v0,0x4a463c
  4a4688:	00000000 	nop
  4a468c:	0c14aa26 	jal	0x52a898
  4a4690:	24040025 	li	a0,37
  4a4694:	1440ffe9 	bnez	v0,0x4a463c
  4a4698:	00000000 	nop
  4a469c:	0c129107 	jal	0x4a441c
  4a46a0:	00000000 	nop
  4a46a4:	1440ffe5 	bnez	v0,0x4a463c
  4a46a8:	00000000 	nop
  4a46ac:	0c12914c 	jal	0x4a4530
  4a46b0:	00000000 	nop
  4a46b4:	08129192 	j	0x4a4648
  4a46b8:	00001021 	move	v0,zero
  4a46bc:	3c05006a 	lui	a1,0x6a
  4a46c0:	2484e4d0 	addiu	a0,a0,-6960
  4a46c4:	24a5e58c 	addiu	a1,a1,-6772
  4a46c8:	0c101b74 	jal	0x406dd0
  4a46cc:	240601b8 	li	a2,440
  4a46d0:	08129188 	j	0x4a4620
  4a46d4:	3c10006a 	lui	s0,0x6a
  4a46d8:	3c020073 	lui	v0,0x73
  4a46dc:	80421888 	lb	v0,6280(v0)
  4a46e0:	1040ffd6 	beqz	v0,0x4a463c
  4a46e4:	3c04006a 	lui	a0,0x6a
  4a46e8:	3c05006a 	lui	a1,0x6a
  4a46ec:	2484e490 	addiu	a0,a0,-7024
  4a46f0:	24a5e57c 	addiu	a1,a1,-6788
  4a46f4:	0c101b74 	jal	0x406dd0
  4a46f8:	2406023c 	li	a2,572
  4a46fc:	0812918f 	j	0x4a463c
  4a4700:	00000000 	nop
	...

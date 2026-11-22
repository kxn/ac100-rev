; func uac_bcast_storm_ctrl_init @ 0x0045f0b8 size=0x160
  45f0b8:	27bdffd0 	addiu	sp,sp,-48
  45f0bc:	afbf002c 	sw	ra,44(sp)
  45f0c0:	0c117ca7 	jal	0x45f29c
  45f0c4:	00000000 	nop
  45f0c8:	1440002f 	bnez	v0,0x45f188
  45f0cc:	3c020073 	lui	v0,0x73
  45f0d0:	3c040069 	lui	a0,0x69
  45f0d4:	3c060046 	lui	a2,0x46
  45f0d8:	2484b224 	addiu	a0,a0,-19932
  45f0dc:	24050002 	li	a1,2
  45f0e0:	0c102134 	jal	0x4084d0
  45f0e4:	24c6ed94 	addiu	a2,a2,-4716
  45f0e8:	14400036 	bnez	v0,0x45f1c4
  45f0ec:	3c020073 	lui	v0,0x73
  45f0f0:	3c02006f 	lui	v0,0x6f
  45f0f4:	afa0001c 	sw	zero,28(sp)
  45f0f8:	27a40018 	addiu	a0,sp,24
  45f0fc:	afa00024 	sw	zero,36(sp)
  45f100:	244299ec 	addiu	v0,v0,-26132
  45f104:	afa20018 	sw	v0,24(sp)
  45f108:	24020064 	li	v0,100
  45f10c:	a3a2001c 	sb	v0,28(sp)
  45f110:	3c020046 	lui	v0,0x46
  45f114:	2442ebc4 	addiu	v0,v0,-5180
  45f118:	0c198ed8 	jal	0x663b60
  45f11c:	afa20020 	sw	v0,32(sp)
  45f120:	1040000c 	beqz	v0,0x45f154
  45f124:	3c020073 	lui	v0,0x73
  45f128:	8c421410 	lw	v0,5136(v0)
  45f12c:	1440000f 	bnez	v0,0x45f16c
  45f130:	3c040069 	lui	a0,0x69
  45f134:	3c020073 	lui	v0,0x73
  45f138:	8c421420 	lw	v0,5152(v0)
  45f13c:	1440002d 	bnez	v0,0x45f1f4
  45f140:	00000000 	nop
  45f144:	0c117d2d 	jal	0x45f4b4
  45f148:	00000000 	nop
  45f14c:	08117c58 	j	0x45f160
  45f150:	2402ffff 	li	v0,-1
  45f154:	0c14aa26 	jal	0x52a898
  45f158:	2404000e 	li	a0,14
  45f15c:	00001021 	move	v0,zero
  45f160:	8fbf002c 	lw	ra,44(sp)
  45f164:	03e00008 	jr	ra
  45f168:	27bd0030 	addiu	sp,sp,48
  45f16c:	3c050069 	lui	a1,0x69
  45f170:	2484b29c 	addiu	a0,a0,-19812
  45f174:	24a5b35c 	addiu	a1,a1,-19620
  45f178:	0c101b74 	jal	0x406dd0
  45f17c:	240601a5 	li	a2,421
  45f180:	08117c4e 	j	0x45f138
  45f184:	3c020073 	lui	v0,0x73
  45f188:	8c421420 	lw	v0,5152(v0)
  45f18c:	1040ffed 	beqz	v0,0x45f144
  45f190:	00000000 	nop
  45f194:	0c16276a 	jal	0x589da8
  45f198:	00000000 	nop
  45f19c:	1040ffe9 	beqz	v0,0x45f144
  45f1a0:	3c050069 	lui	a1,0x69
  45f1a4:	3c040069 	lui	a0,0x69
  45f1a8:	2484b1cc 	addiu	a0,a0,-20020
  45f1ac:	24a5b340 	addiu	a1,a1,-19648
  45f1b0:	240601c2 	li	a2,450
  45f1b4:	0c101b74 	jal	0x406dd0
  45f1b8:	00000000 	nop
  45f1bc:	08117c51 	j	0x45f144
  45f1c0:	00000000 	nop
  45f1c4:	8c421420 	lw	v0,5152(v0)
  45f1c8:	1040ffde 	beqz	v0,0x45f144
  45f1cc:	00000000 	nop
  45f1d0:	0c16276a 	jal	0x589da8
  45f1d4:	00000000 	nop
  45f1d8:	1040ffda 	beqz	v0,0x45f144
  45f1dc:	3c050069 	lui	a1,0x69
  45f1e0:	3c040069 	lui	a0,0x69
  45f1e4:	2484b238 	addiu	a0,a0,-19912
  45f1e8:	24a5b340 	addiu	a1,a1,-19648
  45f1ec:	08117c6d 	j	0x45f1b4
  45f1f0:	240601cb 	li	a2,459
  45f1f4:	0c16276a 	jal	0x589da8
  45f1f8:	00000000 	nop
  45f1fc:	1040ffd1 	beqz	v0,0x45f144
  45f200:	3c050069 	lui	a1,0x69
  45f204:	3c040069 	lui	a0,0x69
  45f208:	2484b2d8 	addiu	a0,a0,-19752
  45f20c:	24a5b340 	addiu	a1,a1,-19648
  45f210:	08117c6d 	j	0x45f1b4
  45f214:	240601d4 	li	a2,468

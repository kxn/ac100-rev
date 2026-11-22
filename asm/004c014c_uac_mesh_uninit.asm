; func uac_mesh_uninit @ 0x004c014c size=0xa8
  4c014c:	3c020077 	lui	v0,0x77
  4c0150:	27bdffe0 	addiu	sp,sp,-32
  4c0154:	8c448050 	lw	a0,-32688(v0)
  4c0158:	afbf001c 	sw	ra,28(sp)
  4c015c:	10800003 	beqz	a0,0x4c016c
  4c0160:	afb00018 	sw	s0,24(sp)
  4c0164:	0c1020e4 	jal	0x408390
  4c0168:	00000000 	nop
  4c016c:	0c12eaf6 	jal	0x4babd8
  4c0170:	00000000 	nop
  4c0174:	10400009 	beqz	v0,0x4c019c
  4c0178:	3c020073 	lui	v0,0x73
  4c017c:	80421a84 	lb	v0,6788(v0)
  4c0180:	14400013 	bnez	v0,0x4c01d0
  4c0184:	2410ffff 	li	s0,-1
  4c0188:	8fbf001c 	lw	ra,28(sp)
  4c018c:	02001021 	move	v0,s0
  4c0190:	8fb00018 	lw	s0,24(sp)
  4c0194:	03e00008 	jr	ra
  4c0198:	27bd0020 	addiu	sp,sp,32
  4c019c:	0c131629 	jal	0x4c58a4
  4c01a0:	00008021 	move	s0,zero
  4c01a4:	1040fff8 	beqz	v0,0x4c0188
  4c01a8:	3c020073 	lui	v0,0x73
  4c01ac:	80421a84 	lb	v0,6788(v0)
  4c01b0:	1040fff5 	beqz	v0,0x4c0188
  4c01b4:	2410ffff 	li	s0,-1
  4c01b8:	3c04006a 	lui	a0,0x6a
  4c01bc:	3c05006a 	lui	a1,0x6a
  4c01c0:	24844a48 	addiu	a0,a0,19016
  4c01c4:	24a550b4 	addiu	a1,a1,20660
  4c01c8:	08130079 	j	0x4c01e4
  4c01cc:	2406090e 	li	a2,2318
  4c01d0:	3c04006a 	lui	a0,0x6a
  4c01d4:	3c05006a 	lui	a1,0x6a
  4c01d8:	24844a48 	addiu	a0,a0,19016
  4c01dc:	24a550b4 	addiu	a1,a1,20660
  4c01e0:	24060909 	li	a2,2313
  4c01e4:	0c101b74 	jal	0x406dd0
  4c01e8:	00000000 	nop
  4c01ec:	08130063 	j	0x4c018c
  4c01f0:	8fbf001c 	lw	ra,28(sp)

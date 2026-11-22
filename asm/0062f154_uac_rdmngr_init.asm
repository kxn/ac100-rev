; func uac_rdmngr_init @ 0x0062f154 size=0x17c
  62f154:	27bdffe0 	addiu	sp,sp,-32
  62f158:	afbf001c 	sw	ra,28(sp)
  62f15c:	0c1884cc 	jal	0x621330
  62f160:	afb00018 	sw	s0,24(sp)
  62f164:	1040000d 	beqz	v0,0x62f19c
  62f168:	3c020075 	lui	v0,0x75
  62f16c:	8c42feb4 	lw	v0,-332(v0)
  62f170:	10400005 	beqz	v0,0x62f188
  62f174:	2410ffff 	li	s0,-1
  62f178:	0c16276a 	jal	0x589da8
  62f17c:	00000000 	nop
  62f180:	1440001a 	bnez	v0,0x62f1ec
  62f184:	3c040071 	lui	a0,0x71
  62f188:	8fbf001c 	lw	ra,28(sp)
  62f18c:	02001021 	move	v0,s0
  62f190:	8fb00018 	lw	s0,24(sp)
  62f194:	03e00008 	jr	ra
  62f198:	27bd0020 	addiu	sp,sp,32
  62f19c:	0c185fba 	jal	0x617ee8
  62f1a0:	00000000 	nop
  62f1a4:	10400016 	beqz	v0,0x62f200
  62f1a8:	3c020075 	lui	v0,0x75
  62f1ac:	8c42feb4 	lw	v0,-332(v0)
  62f1b0:	1040fff5 	beqz	v0,0x62f188
  62f1b4:	2410ffff 	li	s0,-1
  62f1b8:	0c16276a 	jal	0x589da8
  62f1bc:	00000000 	nop
  62f1c0:	5040fff2 	beqzl	v0,0x62f18c
  62f1c4:	8fbf001c 	lw	ra,28(sp)
  62f1c8:	3c040071 	lui	a0,0x71
  62f1cc:	3c050071 	lui	a1,0x71
  62f1d0:	2484c5cc 	addiu	a0,a0,-14900
  62f1d4:	24a5cb68 	addiu	a1,a1,-13464
  62f1d8:	24060a73 	li	a2,2675
  62f1dc:	0c101b74 	jal	0x406dd0
  62f1e0:	00000000 	nop
  62f1e4:	0818bc63 	j	0x62f18c
  62f1e8:	8fbf001c 	lw	ra,28(sp)
  62f1ec:	3c050071 	lui	a1,0x71
  62f1f0:	2484c59c 	addiu	a0,a0,-14948
  62f1f4:	24a5cb68 	addiu	a1,a1,-13464
  62f1f8:	0818bc77 	j	0x62f1dc
  62f1fc:	24060a6d 	li	a2,2669
  62f200:	0c18bc2e 	jal	0x62f0b8
  62f204:	00000000 	nop
  62f208:	1040000e 	beqz	v0,0x62f244
  62f20c:	3c020075 	lui	v0,0x75
  62f210:	8c42feb4 	lw	v0,-332(v0)
  62f214:	1040ffdc 	beqz	v0,0x62f188
  62f218:	2410ffff 	li	s0,-1
  62f21c:	0c16276a 	jal	0x589da8
  62f220:	00000000 	nop
  62f224:	5040ffd9 	beqzl	v0,0x62f18c
  62f228:	8fbf001c 	lw	ra,28(sp)
  62f22c:	3c040071 	lui	a0,0x71
  62f230:	3c050071 	lui	a1,0x71
  62f234:	2484c5f8 	addiu	a0,a0,-14856
  62f238:	24a5cb68 	addiu	a1,a1,-13464
  62f23c:	0818bc77 	j	0x62f1dc
  62f240:	24060a78 	li	a2,2680
  62f244:	0c18bc09 	jal	0x62f024
  62f248:	00000000 	nop
  62f24c:	1040000e 	beqz	v0,0x62f288
  62f250:	3c020075 	lui	v0,0x75
  62f254:	8c42feb4 	lw	v0,-332(v0)
  62f258:	1040ffcb 	beqz	v0,0x62f188
  62f25c:	2410ffff 	li	s0,-1
  62f260:	0c16276a 	jal	0x589da8
  62f264:	00000000 	nop
  62f268:	5040ffc8 	beqzl	v0,0x62f18c
  62f26c:	8fbf001c 	lw	ra,28(sp)
  62f270:	3c040071 	lui	a0,0x71
  62f274:	3c050071 	lui	a1,0x71
  62f278:	2484c634 	addiu	a0,a0,-14796
  62f27c:	24a5cb68 	addiu	a1,a1,-13464
  62f280:	0818bc77 	j	0x62f1dc
  62f284:	24060a7d 	li	a2,2685
  62f288:	3c040071 	lui	a0,0x71
  62f28c:	00008021 	move	s0,zero
  62f290:	0c101d74 	jal	0x4075d0
  62f294:	2484c66c 	addiu	a0,a0,-14740
  62f298:	0c14aa26 	jal	0x52a898
  62f29c:	24040001 	li	a0,1
  62f2a0:	0c14aa26 	jal	0x52a898
  62f2a4:	24040009 	li	a0,9
  62f2a8:	0c14aa26 	jal	0x52a898
  62f2ac:	2404000a 	li	a0,10
  62f2b0:	0c14aa26 	jal	0x52a898
  62f2b4:	24040015 	li	a0,21
  62f2b8:	0c14aa26 	jal	0x52a898
  62f2bc:	24040026 	li	a0,38
  62f2c0:	0c14aa26 	jal	0x52a898
  62f2c4:	24040039 	li	a0,57
  62f2c8:	0818bc63 	j	0x62f18c
  62f2cc:	8fbf001c 	lw	ra,28(sp)

; func uac_rdmngr_uninit @ 0x0062f2d0 size=0xac
  62f2d0:	27bdffe0 	addiu	sp,sp,-32
  62f2d4:	afbf001c 	sw	ra,28(sp)
  62f2d8:	0c188481 	jal	0x621204
  62f2dc:	afb00018 	sw	s0,24(sp)
  62f2e0:	1040000d 	beqz	v0,0x62f318
  62f2e4:	3c020075 	lui	v0,0x75
  62f2e8:	8c42feb4 	lw	v0,-332(v0)
  62f2ec:	10400005 	beqz	v0,0x62f304
  62f2f0:	2410ffff 	li	s0,-1
  62f2f4:	0c16276a 	jal	0x589da8
  62f2f8:	00000000 	nop
  62f2fc:	14400017 	bnez	v0,0x62f35c
  62f300:	3c040071 	lui	a0,0x71
  62f304:	8fbf001c 	lw	ra,28(sp)
  62f308:	02001021 	move	v0,s0
  62f30c:	8fb00018 	lw	s0,24(sp)
  62f310:	03e00008 	jr	ra
  62f314:	27bd0020 	addiu	sp,sp,32
  62f318:	0c1860c3 	jal	0x61830c
  62f31c:	00008021 	move	s0,zero
  62f320:	1040fff8 	beqz	v0,0x62f304
  62f324:	3c020075 	lui	v0,0x75
  62f328:	8c42feb4 	lw	v0,-332(v0)
  62f32c:	1040fff5 	beqz	v0,0x62f304
  62f330:	2410ffff 	li	s0,-1
  62f334:	0c16276a 	jal	0x589da8
  62f338:	00000000 	nop
  62f33c:	5040fff2 	beqzl	v0,0x62f308
  62f340:	8fbf001c 	lw	ra,28(sp)
  62f344:	3c040071 	lui	a0,0x71
  62f348:	3c050071 	lui	a1,0x71
  62f34c:	2484c72c 	addiu	a0,a0,-14548
  62f350:	24a5cb78 	addiu	a1,a1,-13448
  62f354:	0818bcdb 	j	0x62f36c
  62f358:	24060aa0 	li	a2,2720
  62f35c:	3c050071 	lui	a1,0x71
  62f360:	2484c6f8 	addiu	a0,a0,-14600
  62f364:	24a5cb78 	addiu	a1,a1,-13448
  62f368:	24060a9a 	li	a2,2714
  62f36c:	0c101b74 	jal	0x406dd0
  62f370:	00000000 	nop
  62f374:	0818bcc2 	j	0x62f308
  62f378:	8fbf001c 	lw	ra,28(sp)

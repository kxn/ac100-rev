; func cw_priv_sniffing_control_create @ 0x005c02a8 size=0xdc
  5c02a8:	27bdffd8 	addiu	sp,sp,-40
  5c02ac:	24050006 	li	a1,6
  5c02b0:	afb0001c 	sw	s0,28(sp)
  5c02b4:	afbf0024 	sw	ra,36(sp)
  5c02b8:	0c15c8cc 	jal	0x572330
  5c02bc:	afb10020 	sw	s1,32(sp)
  5c02c0:	10400015 	beqz	v0,0x5c0318
  5c02c4:	00408021 	move	s0,v0
  5c02c8:	2404006d 	li	a0,109
  5c02cc:	24050005 	li	a1,5
  5c02d0:	0c15c943 	jal	0x57250c
  5c02d4:	00403021 	move	a2,v0
  5c02d8:	10400007 	beqz	v0,0x5c02f8
  5c02dc:	00408821 	move	s1,v0
  5c02e0:	8fbf0024 	lw	ra,36(sp)
  5c02e4:	02201021 	move	v0,s1
  5c02e8:	8fb10020 	lw	s1,32(sp)
  5c02ec:	8fb0001c 	lw	s0,28(sp)
  5c02f0:	03e00008 	jr	ra
  5c02f4:	27bd0028 	addiu	sp,sp,40
  5c02f8:	3c020075 	lui	v0,0x75
  5c02fc:	8c42cf58 	lw	v0,-12456(v0)
  5c0300:	14400015 	bnez	v0,0x5c0358
  5c0304:	00000000 	nop
  5c0308:	0c101f7c 	jal	0x407df0
  5c030c:	02002021 	move	a0,s0
  5c0310:	081700b9 	j	0x5c02e4
  5c0314:	8fbf0024 	lw	ra,36(sp)
  5c0318:	3c020075 	lui	v0,0x75
  5c031c:	8c42cf58 	lw	v0,-12456(v0)
  5c0320:	1040ffef 	beqz	v0,0x5c02e0
  5c0324:	00008821 	move	s1,zero
  5c0328:	0c16276a 	jal	0x589da8
  5c032c:	00000000 	nop
  5c0330:	5040ffec 	beqzl	v0,0x5c02e4
  5c0334:	8fbf0024 	lw	ra,36(sp)
  5c0338:	3c04006d 	lui	a0,0x6d
  5c033c:	3c05006f 	lui	a1,0x6f
  5c0340:	248434fc 	addiu	a0,a0,13564
  5c0344:	24a5f0d0 	addiu	a1,a1,-3888
  5c0348:	0c101b74 	jal	0x406dd0
  5c034c:	240600b2 	li	a2,178
  5c0350:	081700b9 	j	0x5c02e4
  5c0354:	8fbf0024 	lw	ra,36(sp)
  5c0358:	0c16276a 	jal	0x589da8
  5c035c:	00000000 	nop
  5c0360:	1040ffe9 	beqz	v0,0x5c0308
  5c0364:	3c04006d 	lui	a0,0x6d
  5c0368:	3c05006f 	lui	a1,0x6f
  5c036c:	248447f0 	addiu	a0,a0,18416
  5c0370:	24a5f0d0 	addiu	a1,a1,-3888
  5c0374:	0c101b74 	jal	0x406dd0
  5c0378:	240600ba 	li	a2,186
  5c037c:	081700c2 	j	0x5c0308
  5c0380:	00000000 	nop

; func cw_priv_rate_create @ 0x005ba2b8 size=0xdc
  5ba2b8:	27bdffd8 	addiu	sp,sp,-40
  5ba2bc:	24050037 	li	a1,55
  5ba2c0:	afb0001c 	sw	s0,28(sp)
  5ba2c4:	afbf0024 	sw	ra,36(sp)
  5ba2c8:	0c15c8cc 	jal	0x572330
  5ba2cc:	afb10020 	sw	s1,32(sp)
  5ba2d0:	1040000d 	beqz	v0,0x5ba308
  5ba2d4:	00408021 	move	s0,v0
  5ba2d8:	2404000a 	li	a0,10
  5ba2dc:	24050037 	li	a1,55
  5ba2e0:	0c15c943 	jal	0x57250c
  5ba2e4:	00403021 	move	a2,v0
  5ba2e8:	10400017 	beqz	v0,0x5ba348
  5ba2ec:	00408821 	move	s1,v0
  5ba2f0:	8fbf0024 	lw	ra,36(sp)
  5ba2f4:	02201021 	move	v0,s1
  5ba2f8:	8fb10020 	lw	s1,32(sp)
  5ba2fc:	8fb0001c 	lw	s0,28(sp)
  5ba300:	03e00008 	jr	ra
  5ba304:	27bd0028 	addiu	sp,sp,40
  5ba308:	3c020075 	lui	v0,0x75
  5ba30c:	8c42cf58 	lw	v0,-12456(v0)
  5ba310:	1040fff7 	beqz	v0,0x5ba2f0
  5ba314:	00008821 	move	s1,zero
  5ba318:	0c16276a 	jal	0x589da8
  5ba31c:	00000000 	nop
  5ba320:	5040fff4 	beqzl	v0,0x5ba2f4
  5ba324:	8fbf0024 	lw	ra,36(sp)
  5ba328:	3c04006d 	lui	a0,0x6d
  5ba32c:	3c05006f 	lui	a1,0x6f
  5ba330:	248434fc 	addiu	a0,a0,13564
  5ba334:	24a5d540 	addiu	a1,a1,-10944
  5ba338:	0c101b74 	jal	0x406dd0
  5ba33c:	240600eb 	li	a2,235
  5ba340:	0816e8bd 	j	0x5ba2f4
  5ba344:	8fbf0024 	lw	ra,36(sp)
  5ba348:	3c020075 	lui	v0,0x75
  5ba34c:	8c42cf58 	lw	v0,-12456(v0)
  5ba350:	14400005 	bnez	v0,0x5ba368
  5ba354:	00000000 	nop
  5ba358:	0c101f7c 	jal	0x407df0
  5ba35c:	02002021 	move	a0,s0
  5ba360:	0816e8bd 	j	0x5ba2f4
  5ba364:	8fbf0024 	lw	ra,36(sp)
  5ba368:	0c16276a 	jal	0x589da8
  5ba36c:	00000000 	nop
  5ba370:	1040fff9 	beqz	v0,0x5ba358
  5ba374:	3c04006d 	lui	a0,0x6d
  5ba378:	3c05006f 	lui	a1,0x6f
  5ba37c:	248447f0 	addiu	a0,a0,18416
  5ba380:	24a5d540 	addiu	a1,a1,-10944
  5ba384:	0c101b74 	jal	0x406dd0
  5ba388:	240600f3 	li	a2,243
  5ba38c:	0816e8d6 	j	0x5ba358
  5ba390:	00000000 	nop
	...

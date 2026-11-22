; func cw_priv_ap_led_op_create @ 0x005a5324 size=0xdc
  5a5324:	27bdffd8 	addiu	sp,sp,-40
  5a5328:	24050004 	li	a1,4
  5a532c:	afb0001c 	sw	s0,28(sp)
  5a5330:	afbf0024 	sw	ra,36(sp)
  5a5334:	0c15c8cc 	jal	0x572330
  5a5338:	afb10020 	sw	s1,32(sp)
  5a533c:	1040000d 	beqz	v0,0x5a5374
  5a5340:	00408021 	move	s0,v0
  5a5344:	24040039 	li	a0,57
  5a5348:	24050004 	li	a1,4
  5a534c:	0c15c943 	jal	0x57250c
  5a5350:	00403021 	move	a2,v0
  5a5354:	10400017 	beqz	v0,0x5a53b4
  5a5358:	00408821 	move	s1,v0
  5a535c:	8fbf0024 	lw	ra,36(sp)
  5a5360:	02201021 	move	v0,s1
  5a5364:	8fb10020 	lw	s1,32(sp)
  5a5368:	8fb0001c 	lw	s0,28(sp)
  5a536c:	03e00008 	jr	ra
  5a5370:	27bd0028 	addiu	sp,sp,40
  5a5374:	3c020075 	lui	v0,0x75
  5a5378:	8c42cf58 	lw	v0,-12456(v0)
  5a537c:	1040fff7 	beqz	v0,0x5a535c
  5a5380:	00008821 	move	s1,zero
  5a5384:	0c16276a 	jal	0x589da8
  5a5388:	00000000 	nop
  5a538c:	5040fff4 	beqzl	v0,0x5a5360
  5a5390:	8fbf0024 	lw	ra,36(sp)
  5a5394:	3c04006d 	lui	a0,0x6d
  5a5398:	3c05006e 	lui	a1,0x6e
  5a539c:	248434fc 	addiu	a0,a0,13564
  5a53a0:	24a579a0 	addiu	a1,a1,31136
  5a53a4:	0c101b74 	jal	0x406dd0
  5a53a8:	240600a2 	li	a2,162
  5a53ac:	081694d8 	j	0x5a5360
  5a53b0:	8fbf0024 	lw	ra,36(sp)
  5a53b4:	3c020075 	lui	v0,0x75
  5a53b8:	8c42cf58 	lw	v0,-12456(v0)
  5a53bc:	14400005 	bnez	v0,0x5a53d4
  5a53c0:	00000000 	nop
  5a53c4:	0c101f7c 	jal	0x407df0
  5a53c8:	02002021 	move	a0,s0
  5a53cc:	081694d8 	j	0x5a5360
  5a53d0:	8fbf0024 	lw	ra,36(sp)
  5a53d4:	0c16276a 	jal	0x589da8
  5a53d8:	00000000 	nop
  5a53dc:	1040fff9 	beqz	v0,0x5a53c4
  5a53e0:	3c04006d 	lui	a0,0x6d
  5a53e4:	3c05006e 	lui	a1,0x6e
  5a53e8:	248447f0 	addiu	a0,a0,18416
  5a53ec:	24a579a0 	addiu	a1,a1,31136
  5a53f0:	0c101b74 	jal	0x406dd0
  5a53f4:	240600aa 	li	a2,170
  5a53f8:	081694f1 	j	0x5a53c4
  5a53fc:	00000000 	nop

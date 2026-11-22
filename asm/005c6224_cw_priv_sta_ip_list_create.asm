; func cw_priv_sta_ip_list_create @ 0x005c6224 size=0x1b4
  5c6224:	27bdffd8 	addiu	sp,sp,-40
  5c6228:	24050008 	li	a1,8
  5c622c:	afb10020 	sw	s1,32(sp)
  5c6230:	afb0001c 	sw	s0,28(sp)
  5c6234:	afbf0024 	sw	ra,36(sp)
  5c6238:	0c15c8cc 	jal	0x572330
  5c623c:	00808021 	move	s0,a0
  5c6240:	10400029 	beqz	v0,0x5c62e8
  5c6244:	00408821 	move	s1,v0
  5c6248:	ac400004 	sw	zero,4(v0)
  5c624c:	8e020000 	lw	v0,0(s0)
  5c6250:	1040000a 	beqz	v0,0x5c627c
  5c6254:	00000000 	nop
  5c6258:	8e040004 	lw	a0,4(s0)
  5c625c:	5080003e 	beqzl	a0,0x5c6358
  5c6260:	3c020075 	lui	v0,0x75
  5c6264:	2405001c 	li	a1,28
  5c6268:	70452802 	mul	a1,v0,a1
  5c626c:	0c15c8cc 	jal	0x572330
  5c6270:	30a5fffc 	andi	a1,a1,0xfffc
  5c6274:	1040003f 	beqz	v0,0x5c6374
  5c6278:	ae220004 	sw	v0,4(s1)
  5c627c:	0c171804 	jal	0x5c6010
  5c6280:	02202021 	move	a0,s1
  5c6284:	2404004d 	li	a0,77
  5c6288:	00402821 	move	a1,v0
  5c628c:	0c15c943 	jal	0x57250c
  5c6290:	02203021 	move	a2,s1
  5c6294:	10400007 	beqz	v0,0x5c62b4
  5c6298:	00408021 	move	s0,v0
  5c629c:	8fbf0024 	lw	ra,36(sp)
  5c62a0:	02001021 	move	v0,s0
  5c62a4:	8fb10020 	lw	s1,32(sp)
  5c62a8:	8fb0001c 	lw	s0,28(sp)
  5c62ac:	03e00008 	jr	ra
  5c62b0:	27bd0028 	addiu	sp,sp,40
  5c62b4:	3c020075 	lui	v0,0x75
  5c62b8:	8c42cf58 	lw	v0,-12456(v0)
  5c62bc:	1440001a 	bnez	v0,0x5c6328
  5c62c0:	00000000 	nop
  5c62c4:	8e240004 	lw	a0,4(s1)
  5c62c8:	10800003 	beqz	a0,0x5c62d8
  5c62cc:	00000000 	nop
  5c62d0:	0c101f7c 	jal	0x407df0
  5c62d4:	00000000 	nop
  5c62d8:	0c101f7c 	jal	0x407df0
  5c62dc:	02202021 	move	a0,s1
  5c62e0:	081718a8 	j	0x5c62a0
  5c62e4:	8fbf0024 	lw	ra,36(sp)
  5c62e8:	3c020075 	lui	v0,0x75
  5c62ec:	8c42cf58 	lw	v0,-12456(v0)
  5c62f0:	1040ffea 	beqz	v0,0x5c629c
  5c62f4:	00008021 	move	s0,zero
  5c62f8:	0c16276a 	jal	0x589da8
  5c62fc:	00000000 	nop
  5c6300:	5040ffe7 	beqzl	v0,0x5c62a0
  5c6304:	8fbf0024 	lw	ra,36(sp)
  5c6308:	3c04006d 	lui	a0,0x6d
  5c630c:	3c05006f 	lui	a1,0x6f
  5c6310:	248434fc 	addiu	a0,a0,13564
  5c6314:	24a500e0 	addiu	a1,a1,224
  5c6318:	0c101b74 	jal	0x406dd0
  5c631c:	240600e6 	li	a2,230
  5c6320:	081718a8 	j	0x5c62a0
  5c6324:	8fbf0024 	lw	ra,36(sp)
  5c6328:	0c16276a 	jal	0x589da8
  5c632c:	00000000 	nop
  5c6330:	5040ffe5 	beqzl	v0,0x5c62c8
  5c6334:	8e240004 	lw	a0,4(s1)
  5c6338:	3c04006d 	lui	a0,0x6d
  5c633c:	3c05006f 	lui	a1,0x6f
  5c6340:	248447f0 	addiu	a0,a0,18416
  5c6344:	24a500e0 	addiu	a1,a1,224
  5c6348:	0c101b74 	jal	0x406dd0
  5c634c:	24060101 	li	a2,257
  5c6350:	081718b2 	j	0x5c62c8
  5c6354:	8e240004 	lw	a0,4(s1)
  5c6358:	8c42cf58 	lw	v0,-12456(v0)
  5c635c:	14400015 	bnez	v0,0x5c63b4
  5c6360:	00000000 	nop
  5c6364:	0c101f7c 	jal	0x407df0
  5c6368:	02202021 	move	a0,s1
  5c636c:	081718a7 	j	0x5c629c
  5c6370:	00008021 	move	s0,zero
  5c6374:	3c020075 	lui	v0,0x75
  5c6378:	8c42cf58 	lw	v0,-12456(v0)
  5c637c:	1040fff9 	beqz	v0,0x5c6364
  5c6380:	00000000 	nop
  5c6384:	0c16276a 	jal	0x589da8
  5c6388:	00000000 	nop
  5c638c:	1040fff5 	beqz	v0,0x5c6364
  5c6390:	3c04006f 	lui	a0,0x6f
  5c6394:	3c05006f 	lui	a1,0x6f
  5c6398:	2484bab0 	addiu	a0,a0,-17744
  5c639c:	24a500e0 	addiu	a1,a1,224
  5c63a0:	240600f7 	li	a2,247
  5c63a4:	0c101b74 	jal	0x406dd0
  5c63a8:	00000000 	nop
  5c63ac:	081718d9 	j	0x5c6364
  5c63b0:	00000000 	nop
  5c63b4:	0c16276a 	jal	0x589da8
  5c63b8:	00000000 	nop
  5c63bc:	1040ffe9 	beqz	v0,0x5c6364
  5c63c0:	3c04006f 	lui	a0,0x6f
  5c63c4:	3c05006f 	lui	a1,0x6f
  5c63c8:	2484ba88 	addiu	a0,a0,-17784
  5c63cc:	24a500e0 	addiu	a1,a1,224
  5c63d0:	081718e9 	j	0x5c63a4
  5c63d4:	240600f0 	li	a2,240

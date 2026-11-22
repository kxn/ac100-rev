; func cw_priv_sub_fireware_info_create @ 0x005c9234 size=0xdc
  5c9234:	27bdffd8 	addiu	sp,sp,-40
  5c9238:	2405001c 	li	a1,28
  5c923c:	afb0001c 	sw	s0,28(sp)
  5c9240:	afbf0024 	sw	ra,36(sp)
  5c9244:	0c15c8cc 	jal	0x572330
  5c9248:	afb10020 	sw	s1,32(sp)
  5c924c:	1040000d 	beqz	v0,0x5c9284
  5c9250:	00408021 	move	s0,v0
  5c9254:	240400b0 	li	a0,176
  5c9258:	2405001a 	li	a1,26
  5c925c:	0c15c943 	jal	0x57250c
  5c9260:	00403021 	move	a2,v0
  5c9264:	10400017 	beqz	v0,0x5c92c4
  5c9268:	00408821 	move	s1,v0
  5c926c:	8fbf0024 	lw	ra,36(sp)
  5c9270:	02201021 	move	v0,s1
  5c9274:	8fb10020 	lw	s1,32(sp)
  5c9278:	8fb0001c 	lw	s0,28(sp)
  5c927c:	03e00008 	jr	ra
  5c9280:	27bd0028 	addiu	sp,sp,40
  5c9284:	3c020075 	lui	v0,0x75
  5c9288:	8c42cf58 	lw	v0,-12456(v0)
  5c928c:	1040fff7 	beqz	v0,0x5c926c
  5c9290:	00008821 	move	s1,zero
  5c9294:	0c16276a 	jal	0x589da8
  5c9298:	00000000 	nop
  5c929c:	5040fff4 	beqzl	v0,0x5c9270
  5c92a0:	8fbf0024 	lw	ra,36(sp)
  5c92a4:	3c04006d 	lui	a0,0x6d
  5c92a8:	3c05006f 	lui	a1,0x6f
  5c92ac:	248434fc 	addiu	a0,a0,13564
  5c92b0:	24a50b30 	addiu	a1,a1,2864
  5c92b4:	0c101b74 	jal	0x406dd0
  5c92b8:	240600b6 	li	a2,182
  5c92bc:	0817249c 	j	0x5c9270
  5c92c0:	8fbf0024 	lw	ra,36(sp)
  5c92c4:	3c020075 	lui	v0,0x75
  5c92c8:	8c42cf58 	lw	v0,-12456(v0)
  5c92cc:	14400005 	bnez	v0,0x5c92e4
  5c92d0:	00000000 	nop
  5c92d4:	0c101f7c 	jal	0x407df0
  5c92d8:	02002021 	move	a0,s0
  5c92dc:	0817249c 	j	0x5c9270
  5c92e0:	8fbf0024 	lw	ra,36(sp)
  5c92e4:	0c16276a 	jal	0x589da8
  5c92e8:	00000000 	nop
  5c92ec:	1040fff9 	beqz	v0,0x5c92d4
  5c92f0:	3c04006d 	lui	a0,0x6d
  5c92f4:	3c05006f 	lui	a1,0x6f
  5c92f8:	248447f0 	addiu	a0,a0,18416
  5c92fc:	24a50b30 	addiu	a1,a1,2864
  5c9300:	0c101b74 	jal	0x406dd0
  5c9304:	240600be 	li	a2,190
  5c9308:	081724b5 	j	0x5c92d4
  5c930c:	00000000 	nop

; func cw_80211_tx_power_level_create @ 0x0056a27c size=0xe4
  56a27c:	27bdffd8 	addiu	sp,sp,-40
  56a280:	24050012 	li	a1,18
  56a284:	afb0001c 	sw	s0,28(sp)
  56a288:	afbf0024 	sw	ra,36(sp)
  56a28c:	0c15c8cc 	jal	0x572330
  56a290:	afb10020 	sw	s1,32(sp)
  56a294:	1040000f 	beqz	v0,0x56a2d4
  56a298:	00408021 	move	s0,v0
  56a29c:	90450001 	lbu	a1,1(v0)
  56a2a0:	24040412 	li	a0,1042
  56a2a4:	00403021 	move	a2,v0
  56a2a8:	24a50001 	addiu	a1,a1,1
  56a2ac:	0c15c943 	jal	0x57250c
  56a2b0:	00052840 	sll	a1,a1,0x1
  56a2b4:	10400017 	beqz	v0,0x56a314
  56a2b8:	00408821 	move	s1,v0
  56a2bc:	8fbf0024 	lw	ra,36(sp)
  56a2c0:	02201021 	move	v0,s1
  56a2c4:	8fb10020 	lw	s1,32(sp)
  56a2c8:	8fb0001c 	lw	s0,28(sp)
  56a2cc:	03e00008 	jr	ra
  56a2d0:	27bd0028 	addiu	sp,sp,40
  56a2d4:	3c020075 	lui	v0,0x75
  56a2d8:	8c42cf58 	lw	v0,-12456(v0)
  56a2dc:	1040fff7 	beqz	v0,0x56a2bc
  56a2e0:	00008821 	move	s1,zero
  56a2e4:	0c16276a 	jal	0x589da8
  56a2e8:	00000000 	nop
  56a2ec:	5040fff4 	beqzl	v0,0x56a2c0
  56a2f0:	8fbf0024 	lw	ra,36(sp)
  56a2f4:	3c04006d 	lui	a0,0x6d
  56a2f8:	3c05006d 	lui	a1,0x6d
  56a2fc:	248434fc 	addiu	a0,a0,13564
  56a300:	24a55820 	addiu	a1,a1,22560
  56a304:	0c101b74 	jal	0x406dd0
  56a308:	240600c3 	li	a2,195
  56a30c:	0815a8b0 	j	0x56a2c0
  56a310:	8fbf0024 	lw	ra,36(sp)
  56a314:	3c020075 	lui	v0,0x75
  56a318:	8c42cf58 	lw	v0,-12456(v0)
  56a31c:	14400005 	bnez	v0,0x56a334
  56a320:	00000000 	nop
  56a324:	0c101f7c 	jal	0x407df0
  56a328:	02002021 	move	a0,s0
  56a32c:	0815a8b0 	j	0x56a2c0
  56a330:	8fbf0024 	lw	ra,36(sp)
  56a334:	0c16276a 	jal	0x589da8
  56a338:	00000000 	nop
  56a33c:	1040fff9 	beqz	v0,0x56a324
  56a340:	3c04006d 	lui	a0,0x6d
  56a344:	3c05006d 	lui	a1,0x6d
  56a348:	248447f0 	addiu	a0,a0,18416
  56a34c:	24a55820 	addiu	a1,a1,22560
  56a350:	0c101b74 	jal	0x406dd0
  56a354:	240600cb 	li	a2,203
  56a358:	0815a8c9 	j	0x56a324
  56a35c:	00000000 	nop

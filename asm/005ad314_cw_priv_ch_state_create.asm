; func cw_priv_ch_state_create @ 0x005ad314 size=0xdc
  5ad314:	27bdffd8 	addiu	sp,sp,-40
  5ad318:	24050002 	li	a1,2
  5ad31c:	afb0001c 	sw	s0,28(sp)
  5ad320:	afbf0024 	sw	ra,36(sp)
  5ad324:	0c15c8cc 	jal	0x572330
  5ad328:	afb10020 	sw	s1,32(sp)
  5ad32c:	1040000d 	beqz	v0,0x5ad364
  5ad330:	00408021 	move	s0,v0
  5ad334:	24040006 	li	a0,6
  5ad338:	24050002 	li	a1,2
  5ad33c:	0c15c943 	jal	0x57250c
  5ad340:	00403021 	move	a2,v0
  5ad344:	10400017 	beqz	v0,0x5ad3a4
  5ad348:	00408821 	move	s1,v0
  5ad34c:	8fbf0024 	lw	ra,36(sp)
  5ad350:	02201021 	move	v0,s1
  5ad354:	8fb10020 	lw	s1,32(sp)
  5ad358:	8fb0001c 	lw	s0,28(sp)
  5ad35c:	03e00008 	jr	ra
  5ad360:	27bd0028 	addiu	sp,sp,40
  5ad364:	3c020075 	lui	v0,0x75
  5ad368:	8c42cf58 	lw	v0,-12456(v0)
  5ad36c:	1040fff7 	beqz	v0,0x5ad34c
  5ad370:	00008821 	move	s1,zero
  5ad374:	0c16276a 	jal	0x589da8
  5ad378:	00000000 	nop
  5ad37c:	5040fff4 	beqzl	v0,0x5ad350
  5ad380:	8fbf0024 	lw	ra,36(sp)
  5ad384:	3c04006d 	lui	a0,0x6d
  5ad388:	3c05006f 	lui	a1,0x6f
  5ad38c:	248434fc 	addiu	a0,a0,13564
  5ad390:	24a5a020 	addiu	a1,a1,-24544
  5ad394:	0c101b74 	jal	0x406dd0
  5ad398:	240600b0 	li	a2,176
  5ad39c:	0816b4d4 	j	0x5ad350
  5ad3a0:	8fbf0024 	lw	ra,36(sp)
  5ad3a4:	3c020075 	lui	v0,0x75
  5ad3a8:	8c42cf58 	lw	v0,-12456(v0)
  5ad3ac:	14400005 	bnez	v0,0x5ad3c4
  5ad3b0:	00000000 	nop
  5ad3b4:	0c101f7c 	jal	0x407df0
  5ad3b8:	02002021 	move	a0,s0
  5ad3bc:	0816b4d4 	j	0x5ad350
  5ad3c0:	8fbf0024 	lw	ra,36(sp)
  5ad3c4:	0c16276a 	jal	0x589da8
  5ad3c8:	00000000 	nop
  5ad3cc:	1040fff9 	beqz	v0,0x5ad3b4
  5ad3d0:	3c04006d 	lui	a0,0x6d
  5ad3d4:	3c05006f 	lui	a1,0x6f
  5ad3d8:	248447f0 	addiu	a0,a0,18416
  5ad3dc:	24a5a020 	addiu	a1,a1,-24544
  5ad3e0:	0c101b74 	jal	0x406dd0
  5ad3e4:	240600b8 	li	a2,184
  5ad3e8:	0816b4ed 	j	0x5ad3b4
  5ad3ec:	00000000 	nop

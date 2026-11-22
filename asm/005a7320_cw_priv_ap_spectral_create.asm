; func cw_priv_ap_spectral_create @ 0x005a7320 size=0xdc
  5a7320:	27bdffd8 	addiu	sp,sp,-40
  5a7324:	24050004 	li	a1,4
  5a7328:	afb0001c 	sw	s0,28(sp)
  5a732c:	afbf0024 	sw	ra,36(sp)
  5a7330:	0c15c8cc 	jal	0x572330
  5a7334:	afb10020 	sw	s1,32(sp)
  5a7338:	1040000d 	beqz	v0,0x5a7370
  5a733c:	00408021 	move	s0,v0
  5a7340:	2404003a 	li	a0,58
  5a7344:	24050004 	li	a1,4
  5a7348:	0c15c943 	jal	0x57250c
  5a734c:	00403021 	move	a2,v0
  5a7350:	10400017 	beqz	v0,0x5a73b0
  5a7354:	00408821 	move	s1,v0
  5a7358:	8fbf0024 	lw	ra,36(sp)
  5a735c:	02201021 	move	v0,s1
  5a7360:	8fb10020 	lw	s1,32(sp)
  5a7364:	8fb0001c 	lw	s0,28(sp)
  5a7368:	03e00008 	jr	ra
  5a736c:	27bd0028 	addiu	sp,sp,40
  5a7370:	3c020075 	lui	v0,0x75
  5a7374:	8c42cf58 	lw	v0,-12456(v0)
  5a7378:	1040fff7 	beqz	v0,0x5a7358
  5a737c:	00008821 	move	s1,zero
  5a7380:	0c16276a 	jal	0x589da8
  5a7384:	00000000 	nop
  5a7388:	5040fff4 	beqzl	v0,0x5a735c
  5a738c:	8fbf0024 	lw	ra,36(sp)
  5a7390:	3c04006d 	lui	a0,0x6d
  5a7394:	3c05006f 	lui	a1,0x6f
  5a7398:	248434fc 	addiu	a0,a0,13564
  5a739c:	24a58330 	addiu	a1,a1,-31952
  5a73a0:	0c101b74 	jal	0x406dd0
  5a73a4:	240600a8 	li	a2,168
  5a73a8:	08169cd7 	j	0x5a735c
  5a73ac:	8fbf0024 	lw	ra,36(sp)
  5a73b0:	3c020075 	lui	v0,0x75
  5a73b4:	8c42cf58 	lw	v0,-12456(v0)
  5a73b8:	14400005 	bnez	v0,0x5a73d0
  5a73bc:	00000000 	nop
  5a73c0:	0c101f7c 	jal	0x407df0
  5a73c4:	02002021 	move	a0,s0
  5a73c8:	08169cd7 	j	0x5a735c
  5a73cc:	8fbf0024 	lw	ra,36(sp)
  5a73d0:	0c16276a 	jal	0x589da8
  5a73d4:	00000000 	nop
  5a73d8:	1040fff9 	beqz	v0,0x5a73c0
  5a73dc:	3c04006d 	lui	a0,0x6d
  5a73e0:	3c05006f 	lui	a1,0x6f
  5a73e4:	248447f0 	addiu	a0,a0,18416
  5a73e8:	24a58330 	addiu	a1,a1,-31952
  5a73ec:	0c101b74 	jal	0x406dd0
  5a73f0:	240600b0 	li	a2,176
  5a73f4:	08169cf0 	j	0x5a73c0
  5a73f8:	00000000 	nop

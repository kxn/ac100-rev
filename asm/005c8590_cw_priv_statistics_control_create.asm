; func cw_priv_statistics_control_create @ 0x005c8590 size=0xdc
  5c8590:	27bdffd8 	addiu	sp,sp,-40
  5c8594:	2405000a 	li	a1,10
  5c8598:	afb0001c 	sw	s0,28(sp)
  5c859c:	afbf0024 	sw	ra,36(sp)
  5c85a0:	0c15c8cc 	jal	0x572330
  5c85a4:	afb10020 	sw	s1,32(sp)
  5c85a8:	1040000d 	beqz	v0,0x5c85e0
  5c85ac:	00408021 	move	s0,v0
  5c85b0:	24040055 	li	a0,85
  5c85b4:	24050009 	li	a1,9
  5c85b8:	0c15c943 	jal	0x57250c
  5c85bc:	00403021 	move	a2,v0
  5c85c0:	10400017 	beqz	v0,0x5c8620
  5c85c4:	00408821 	move	s1,v0
  5c85c8:	8fbf0024 	lw	ra,36(sp)
  5c85cc:	02201021 	move	v0,s1
  5c85d0:	8fb10020 	lw	s1,32(sp)
  5c85d4:	8fb0001c 	lw	s0,28(sp)
  5c85d8:	03e00008 	jr	ra
  5c85dc:	27bd0028 	addiu	sp,sp,40
  5c85e0:	3c020075 	lui	v0,0x75
  5c85e4:	8c42cf58 	lw	v0,-12456(v0)
  5c85e8:	1040fff7 	beqz	v0,0x5c85c8
  5c85ec:	00008821 	move	s1,zero
  5c85f0:	0c16276a 	jal	0x589da8
  5c85f4:	00000000 	nop
  5c85f8:	5040fff4 	beqzl	v0,0x5c85cc
  5c85fc:	8fbf0024 	lw	ra,36(sp)
  5c8600:	3c04006d 	lui	a0,0x6d
  5c8604:	3c05006f 	lui	a1,0x6f
  5c8608:	248434fc 	addiu	a0,a0,13564
  5c860c:	24a50800 	addiu	a1,a1,2048
  5c8610:	0c101b74 	jal	0x406dd0
  5c8614:	240600b6 	li	a2,182
  5c8618:	08172173 	j	0x5c85cc
  5c861c:	8fbf0024 	lw	ra,36(sp)
  5c8620:	3c020075 	lui	v0,0x75
  5c8624:	8c42cf58 	lw	v0,-12456(v0)
  5c8628:	14400005 	bnez	v0,0x5c8640
  5c862c:	00000000 	nop
  5c8630:	0c101f7c 	jal	0x407df0
  5c8634:	02002021 	move	a0,s0
  5c8638:	08172173 	j	0x5c85cc
  5c863c:	8fbf0024 	lw	ra,36(sp)
  5c8640:	0c16276a 	jal	0x589da8
  5c8644:	00000000 	nop
  5c8648:	1040fff9 	beqz	v0,0x5c8630
  5c864c:	3c04006d 	lui	a0,0x6d
  5c8650:	3c05006f 	lui	a1,0x6f
  5c8654:	248447f0 	addiu	a0,a0,18416
  5c8658:	24a50800 	addiu	a1,a1,2048
  5c865c:	0c101b74 	jal	0x406dd0
  5c8660:	240600be 	li	a2,190
  5c8664:	0817218c 	j	0x5c8630
  5c8668:	00000000 	nop
  5c866c:	00000000 	nop

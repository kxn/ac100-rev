; func wips_delete_whitelist_due_to_wserv @ 0x004cb3e8 size=0xa8
  4cb3e8:	27bdffd8 	addiu	sp,sp,-40
  4cb3ec:	afb10020 	sw	s1,32(sp)
  4cb3f0:	3c110077 	lui	s1,0x77
  4cb3f4:	afa40028 	sw	a0,40(sp)
  4cb3f8:	afa5002c 	sw	a1,44(sp)
  4cb3fc:	2405ffff 	li	a1,-1
  4cb400:	afbf0024 	sw	ra,36(sp)
  4cb404:	afb0001c 	sw	s0,28(sp)
  4cb408:	afa60030 	sw	a2,48(sp)
  4cb40c:	afa70034 	sw	a3,52(sp)
  4cb410:	0c1020b4 	jal	0x4082d0
  4cb414:	8e248074 	lw	a0,-32652(s1)
  4cb418:	3c040077 	lui	a0,0x77
  4cb41c:	0c10206c 	jal	0x4081b0
  4cb420:	24848088 	addiu	a0,a0,-32632
  4cb424:	08132d16 	j	0x4cb458
  4cb428:	00000000 	nop
  4cb42c:	26040016 	addiu	a0,s0,22
  4cb430:	27a50158 	addiu	a1,sp,344
  4cb434:	0c101c04 	jal	0x407010
  4cb438:	24060032 	li	a2,50
  4cb43c:	14400004 	bnez	v0,0x4cb450
  4cb440:	8fa20154 	lw	v0,340(sp)
  4cb444:	8e030048 	lw	v1,72(s0)
  4cb448:	1062000d 	beq	v1,v0,0x4cb480
  4cb44c:	00000000 	nop
  4cb450:	0c1021a0 	jal	0x408680
  4cb454:	02002021 	move	a0,s0
  4cb458:	1440fff4 	bnez	v0,0x4cb42c
  4cb45c:	00408021 	move	s0,v0
  4cb460:	0c101fcc 	jal	0x407f30
  4cb464:	8e248074 	lw	a0,-32652(s1)
  4cb468:	00001021 	move	v0,zero
  4cb46c:	8fbf0024 	lw	ra,36(sp)
  4cb470:	8fb10020 	lw	s1,32(sp)
  4cb474:	8fb0001c 	lw	s0,28(sp)
  4cb478:	03e00008 	jr	ra
  4cb47c:	27bd0028 	addiu	sp,sp,40
  4cb480:	0c132be6 	jal	0x4caf98
  4cb484:	02002021 	move	a0,s0
  4cb488:	08132d14 	j	0x4cb450
  4cb48c:	00000000 	nop

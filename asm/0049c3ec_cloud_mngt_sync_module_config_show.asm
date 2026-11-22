; func cloud_mngt_sync_module_config_show @ 0x0049c3ec size=0x8c
  49c3ec:	3c04006a 	lui	a0,0x6a
  49c3f0:	27bdffd8 	addiu	sp,sp,-40
  49c3f4:	2484a3f8 	addiu	a0,a0,-23560
  49c3f8:	afbf0024 	sw	ra,36(sp)
  49c3fc:	afb10020 	sw	s1,32(sp)
  49c400:	0c101dd4 	jal	0x407750
  49c404:	afb0001c 	sw	s0,28(sp)
  49c408:	3c040076 	lui	a0,0x76
  49c40c:	0c10206c 	jal	0x4081b0
  49c410:	248478a8 	addiu	a0,a0,30888
  49c414:	10400013 	beqz	v0,0x49c464
  49c418:	00408821 	move	s1,v0
  49c41c:	0c101dd4 	jal	0x407750
  49c420:	2624000c 	addiu	a0,s1,12
  49c424:	0c10206c 	jal	0x4081b0
  49c428:	26240040 	addiu	a0,s1,64
  49c42c:	08127111 	j	0x49c444
  49c430:	00000000 	nop
  49c434:	0c101dd4 	jal	0x407750
  49c438:	2604000c 	addiu	a0,s0,12
  49c43c:	0c1021a0 	jal	0x408680
  49c440:	02002021 	move	a0,s0
  49c444:	1440fffb 	bnez	v0,0x49c434
  49c448:	00408021 	move	s0,v0
  49c44c:	0c101ce4 	jal	0x407390
  49c450:	2404000a 	li	a0,10
  49c454:	0c1021a0 	jal	0x408680
  49c458:	02202021 	move	a0,s1
  49c45c:	08127105 	j	0x49c414
  49c460:	00000000 	nop
  49c464:	8fbf0024 	lw	ra,36(sp)
  49c468:	8fb10020 	lw	s1,32(sp)
  49c46c:	8fb0001c 	lw	s0,28(sp)
  49c470:	03e00008 	jr	ra
  49c474:	27bd0028 	addiu	sp,sp,40

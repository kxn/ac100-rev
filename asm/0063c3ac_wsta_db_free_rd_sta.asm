; func wsta_db_free_rd_sta @ 0x0063c3ac size=0x150
  63c3ac:	27bdffc0 	addiu	sp,sp,-64
  63c3b0:	afb50038 	sw	s5,56(sp)
  63c3b4:	00c0a821 	move	s5,a2
  63c3b8:	afb40034 	sw	s4,52(sp)
  63c3bc:	00e0a021 	move	s4,a3
  63c3c0:	afb2002c 	sw	s2,44(sp)
  63c3c4:	00809021 	move	s2,a0
  63c3c8:	afb10028 	sw	s1,40(sp)
  63c3cc:	30b100ff 	andi	s1,a1,0xff
  63c3d0:	afbf003c 	sw	ra,60(sp)
  63c3d4:	afb30030 	sw	s3,48(sp)
  63c3d8:	04800006 	bltz	a0,0x63c3f4
  63c3dc:	afb00024 	sw	s0,36(sp)
  63c3e0:	0c1506a9 	jal	0x541aa4
  63c3e4:	00000000 	nop
  63c3e8:	0242102a 	slt	v0,s2,v0
  63c3ec:	14400013 	bnez	v0,0x63c43c
  63c3f0:	00000000 	nop
  63c3f4:	3c02007d 	lui	v0,0x7d
  63c3f8:	8c42c6a0 	lw	v0,-14688(v0)
  63c3fc:	10400005 	beqz	v0,0x63c414
  63c400:	2410ffff 	li	s0,-1
  63c404:	0c16276a 	jal	0x589da8
  63c408:	00000000 	nop
  63c40c:	1440001b 	bnez	v0,0x63c47c
  63c410:	3c040071 	lui	a0,0x71
  63c414:	8fbf003c 	lw	ra,60(sp)
  63c418:	02001021 	move	v0,s0
  63c41c:	8fb50038 	lw	s5,56(sp)
  63c420:	8fb40034 	lw	s4,52(sp)
  63c424:	8fb30030 	lw	s3,48(sp)
  63c428:	8fb2002c 	lw	s2,44(sp)
  63c42c:	8fb10028 	lw	s1,40(sp)
  63c430:	8fb00024 	lw	s0,36(sp)
  63c434:	03e00008 	jr	ra
  63c438:	27bd0040 	addiu	sp,sp,64
  63c43c:	16200018 	bnez	s1,0x63c4a0
  63c440:	3c02007d 	lui	v0,0x7d
  63c444:	8c42c6a0 	lw	v0,-14688(v0)
  63c448:	1040fff2 	beqz	v0,0x63c414
  63c44c:	2410ffff 	li	s0,-1
  63c450:	0c16276a 	jal	0x589da8
  63c454:	00000000 	nop
  63c458:	5040ffef 	beqzl	v0,0x63c418
  63c45c:	8fbf003c 	lw	ra,60(sp)
  63c460:	3c040071 	lui	a0,0x71
  63c464:	3c050071 	lui	a1,0x71
  63c468:	2484de18 	addiu	a0,a0,-8680
  63c46c:	24a50560 	addiu	a1,a1,1376
  63c470:	24060a63 	li	a2,2659
  63c474:	0818f124 	j	0x63c490
  63c478:	02203821 	move	a3,s1
  63c47c:	3c050071 	lui	a1,0x71
  63c480:	2484dde4 	addiu	a0,a0,-8732
  63c484:	24a50560 	addiu	a1,a1,1376
  63c488:	24060a5e 	li	a2,2654
  63c48c:	02403821 	move	a3,s2
  63c490:	0c101b74 	jal	0x406dd0
  63c494:	00000000 	nop
  63c498:	0818f106 	j	0x63c418
  63c49c:	8fbf003c 	lw	ra,60(sp)
  63c4a0:	0c1868f4 	jal	0x61a3d0
  63c4a4:	00000000 	nop
  63c4a8:	0051102b 	sltu	v0,v0,s1
  63c4ac:	1440ffe5 	bnez	v0,0x63c444
  63c4b0:	3c02007d 	lui	v0,0x7d
  63c4b4:	24130001 	li	s3,1
  63c4b8:	0818f138 	j	0x63c4e0
  63c4bc:	00008021 	move	s0,zero
  63c4c0:	afb40010 	sw	s4,16(sp)
  63c4c4:	02402021 	move	a0,s2
  63c4c8:	02202821 	move	a1,s1
  63c4cc:	02a03821 	move	a3,s5
  63c4d0:	0c18ef86 	jal	0x63be18
  63c4d4:	26730001 	addiu	s3,s3,1
  63c4d8:	02028025 	or	s0,s0,v0
  63c4dc:	327300ff 	andi	s3,s3,0xff
  63c4e0:	0c1868f7 	jal	0x61a3dc
  63c4e4:	00000000 	nop
  63c4e8:	0053102b 	sltu	v0,v0,s3
  63c4ec:	1040fff4 	beqz	v0,0x63c4c0
  63c4f0:	02603021 	move	a2,s3
  63c4f4:	0818f106 	j	0x63c418
  63c4f8:	8fbf003c 	lw	ra,60(sp)

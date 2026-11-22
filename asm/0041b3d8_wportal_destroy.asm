; func wportal_destroy @ 0x0041b3d8 size=0xc8
  41b3d8:	27bdffe0 	addiu	sp,sp,-32
  41b3dc:	3c020073 	lui	v0,0x73
  41b3e0:	afb00018 	sw	s0,24(sp)
  41b3e4:	3c100076 	lui	s0,0x76
  41b3e8:	afbf001c 	sw	ra,28(sp)
  41b3ec:	0c102018 	jal	0x408060
  41b3f0:	8c441234 	lw	a0,4660(v0)
  41b3f4:	2405ffff 	li	a1,-1
  41b3f8:	0c1020b4 	jal	0x4082d0
  41b3fc:	8e04a0c0 	lw	a0,-24384(s0)
  41b400:	3c040076 	lui	a0,0x76
  41b404:	0c166906 	jal	0x59a418
  41b408:	24849f74 	addiu	a0,a0,-24716
  41b40c:	3c040076 	lui	a0,0x76
  41b410:	0c166906 	jal	0x59a418
  41b414:	24849f64 	addiu	a0,a0,-24732
  41b418:	3c040076 	lui	a0,0x76
  41b41c:	0c166906 	jal	0x59a418
  41b420:	24849f54 	addiu	a0,a0,-24748
  41b424:	0c101fcc 	jal	0x407f30
  41b428:	8e04a0c0 	lw	a0,-24384(s0)
  41b42c:	0c1020d8 	jal	0x408360
  41b430:	8e04a0c0 	lw	a0,-24384(s0)
  41b434:	ae00a0c0 	sw	zero,-24384(s0)
  41b438:	3c100076 	lui	s0,0x76
  41b43c:	0c1020d8 	jal	0x408360
  41b440:	8e04a0c8 	lw	a0,-24376(s0)
  41b444:	ae00a0c8 	sw	zero,-24376(s0)
  41b448:	3c100076 	lui	s0,0x76
  41b44c:	0c102088 	jal	0x408220
  41b450:	8e04a0d8 	lw	a0,-24360(s0)
  41b454:	ae00a0d8 	sw	zero,-24360(s0)
  41b458:	3c100076 	lui	s0,0x76
  41b45c:	8e04a0fc 	lw	a0,-24324(s0)
  41b460:	10800004 	beqz	a0,0x41b474
  41b464:	00000000 	nop
  41b468:	0c101da0 	jal	0x407680
  41b46c:	24050003 	li	a1,3
  41b470:	ae00a0fc 	sw	zero,-24324(s0)
  41b474:	0c10b57e 	jal	0x42d5f8
  41b478:	00000000 	nop
  41b47c:	0c10e6f9 	jal	0x439be4
  41b480:	00000000 	nop
  41b484:	0c10ea19 	jal	0x43a864
  41b488:	00000000 	nop
  41b48c:	00001021 	move	v0,zero
  41b490:	8fbf001c 	lw	ra,28(sp)
  41b494:	8fb00018 	lw	s0,24(sp)
  41b498:	03e00008 	jr	ra
  41b49c:	27bd0020 	addiu	sp,sp,32

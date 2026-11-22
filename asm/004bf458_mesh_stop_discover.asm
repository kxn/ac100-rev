; func mesh_stop_discover @ 0x004bf458 size=0xbc
  4bf458:	27bdffd0 	addiu	sp,sp,-48
  4bf45c:	afbf002c 	sw	ra,44(sp)
  4bf460:	afb10028 	sw	s1,40(sp)
  4bf464:	afb00024 	sw	s0,36(sp)
  4bf468:	0c12e474 	jal	0x4b91d0
  4bf46c:	afa00018 	sw	zero,24(sp)
  4bf470:	10400022 	beqz	v0,0x4bf4fc
  4bf474:	00001821 	move	v1,zero
  4bf478:	3c110073 	lui	s1,0x73
  4bf47c:	2410ffff 	li	s0,-1
  4bf480:	8e241a9c 	lw	a0,6812(s1)
  4bf484:	50900006 	beql	a0,s0,0x4bf4a0
  4bf488:	3c110073 	lui	s1,0x73
  4bf48c:	0c102018 	jal	0x408060
  4bf490:	00000000 	nop
  4bf494:	ae301a9c 	sw	s0,6812(s1)
  4bf498:	3c110073 	lui	s1,0x73
  4bf49c:	2410ffff 	li	s0,-1
  4bf4a0:	8e241a98 	lw	a0,6808(s1)
  4bf4a4:	50900005 	beql	a0,s0,0x4bf4bc
  4bf4a8:	3c110073 	lui	s1,0x73
  4bf4ac:	0c102018 	jal	0x408060
  4bf4b0:	00000000 	nop
  4bf4b4:	ae301a98 	sw	s0,6808(s1)
  4bf4b8:	3c110073 	lui	s1,0x73
  4bf4bc:	2410ffff 	li	s0,-1
  4bf4c0:	8e241a94 	lw	a0,6804(s1)
  4bf4c4:	10900004 	beq	a0,s0,0x4bf4d8
  4bf4c8:	00000000 	nop
  4bf4cc:	0c102018 	jal	0x408060
  4bf4d0:	00000000 	nop
  4bf4d4:	ae301a94 	sw	s0,6804(s1)
  4bf4d8:	0c12e486 	jal	0x4b9218
  4bf4dc:	00002021 	move	a0,zero
  4bf4e0:	0c12e7e1 	jal	0x4b9f84
  4bf4e4:	00000000 	nop
  4bf4e8:	00002021 	move	a0,zero
  4bf4ec:	0c130481 	jal	0x4c1204
  4bf4f0:	27a50018 	addiu	a1,sp,24
  4bf4f4:	2403ffff 	li	v1,-1
  4bf4f8:	0002180a 	movz	v1,zero,v0
  4bf4fc:	8fbf002c 	lw	ra,44(sp)
  4bf500:	00601021 	move	v0,v1
  4bf504:	8fb10028 	lw	s1,40(sp)
  4bf508:	8fb00024 	lw	s0,36(sp)
  4bf50c:	03e00008 	jr	ra
  4bf510:	27bd0030 	addiu	sp,sp,48

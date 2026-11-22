; func mesh_stop_re_auto_add_proc @ 0x004bf600 size=0x7c
  4bf600:	3c020076 	lui	v0,0x76
  4bf604:	27bdffd8 	addiu	sp,sp,-40
  4bf608:	80427fbd 	lb	v0,32701(v0)
  4bf60c:	afbf0024 	sw	ra,36(sp)
  4bf610:	afb10020 	sw	s1,32(sp)
  4bf614:	14400011 	bnez	v0,0x4bf65c
  4bf618:	afb0001c 	sw	s0,28(sp)
  4bf61c:	3c110073 	lui	s1,0x73
  4bf620:	2410ffff 	li	s0,-1
  4bf624:	8e241a90 	lw	a0,6800(s1)
  4bf628:	10900004 	beq	a0,s0,0x4bf63c
  4bf62c:	00000000 	nop
  4bf630:	0c102018 	jal	0x408060
  4bf634:	00000000 	nop
  4bf638:	ae301a90 	sw	s0,6800(s1)
  4bf63c:	0c12e4af 	jal	0x4b92bc
  4bf640:	00002021 	move	a0,zero
  4bf644:	00001021 	move	v0,zero
  4bf648:	8fbf0024 	lw	ra,36(sp)
  4bf64c:	8fb10020 	lw	s1,32(sp)
  4bf650:	8fb0001c 	lw	s0,28(sp)
  4bf654:	03e00008 	jr	ra
  4bf658:	27bd0028 	addiu	sp,sp,40
  4bf65c:	3c04006a 	lui	a0,0x6a
  4bf660:	3c05006a 	lui	a1,0x6a
  4bf664:	24844650 	addiu	a0,a0,18000
  4bf668:	24a54e2c 	addiu	a1,a1,20012
  4bf66c:	0c101b74 	jal	0x406dd0
  4bf670:	2406081e 	li	a2,2078
  4bf674:	0812fd88 	j	0x4bf620
  4bf678:	3c110073 	lui	s1,0x73

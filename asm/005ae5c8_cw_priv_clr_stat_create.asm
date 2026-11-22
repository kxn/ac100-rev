; func cw_priv_clr_stat_create @ 0x005ae5c8 size=0xdc
  5ae5c8:	27bdffd8 	addiu	sp,sp,-40
  5ae5cc:	24050004 	li	a1,4
  5ae5d0:	afb0001c 	sw	s0,28(sp)
  5ae5d4:	afbf0024 	sw	ra,36(sp)
  5ae5d8:	0c15c8cc 	jal	0x572330
  5ae5dc:	afb10020 	sw	s1,32(sp)
  5ae5e0:	1040000d 	beqz	v0,0x5ae618
  5ae5e4:	00408021 	move	s0,v0
  5ae5e8:	2404000d 	li	a0,13
  5ae5ec:	24050004 	li	a1,4
  5ae5f0:	0c15c943 	jal	0x57250c
  5ae5f4:	00403021 	move	a2,v0
  5ae5f8:	10400017 	beqz	v0,0x5ae658
  5ae5fc:	00408821 	move	s1,v0
  5ae600:	8fbf0024 	lw	ra,36(sp)
  5ae604:	02201021 	move	v0,s1
  5ae608:	8fb10020 	lw	s1,32(sp)
  5ae60c:	8fb0001c 	lw	s0,28(sp)
  5ae610:	03e00008 	jr	ra
  5ae614:	27bd0028 	addiu	sp,sp,40
  5ae618:	3c020075 	lui	v0,0x75
  5ae61c:	8c42cf58 	lw	v0,-12456(v0)
  5ae620:	1040fff7 	beqz	v0,0x5ae600
  5ae624:	00008821 	move	s1,zero
  5ae628:	0c16276a 	jal	0x589da8
  5ae62c:	00000000 	nop
  5ae630:	5040fff4 	beqzl	v0,0x5ae604
  5ae634:	8fbf0024 	lw	ra,36(sp)
  5ae638:	3c04006d 	lui	a0,0x6d
  5ae63c:	3c05006f 	lui	a1,0x6f
  5ae640:	248434fc 	addiu	a0,a0,13564
  5ae644:	24a5a430 	addiu	a1,a1,-23504
  5ae648:	0c101b74 	jal	0x406dd0
  5ae64c:	240600a6 	li	a2,166
  5ae650:	0816b981 	j	0x5ae604
  5ae654:	8fbf0024 	lw	ra,36(sp)
  5ae658:	3c020075 	lui	v0,0x75
  5ae65c:	8c42cf58 	lw	v0,-12456(v0)
  5ae660:	14400005 	bnez	v0,0x5ae678
  5ae664:	00000000 	nop
  5ae668:	0c101f7c 	jal	0x407df0
  5ae66c:	02002021 	move	a0,s0
  5ae670:	0816b981 	j	0x5ae604
  5ae674:	8fbf0024 	lw	ra,36(sp)
  5ae678:	0c16276a 	jal	0x589da8
  5ae67c:	00000000 	nop
  5ae680:	1040fff9 	beqz	v0,0x5ae668
  5ae684:	3c04006d 	lui	a0,0x6d
  5ae688:	3c05006f 	lui	a1,0x6f
  5ae68c:	248447f0 	addiu	a0,a0,18416
  5ae690:	24a5a430 	addiu	a1,a1,-23504
  5ae694:	0c101b74 	jal	0x406dd0
  5ae698:	240600ae 	li	a2,174
  5ae69c:	0816b99a 	j	0x5ae668
  5ae6a0:	00000000 	nop

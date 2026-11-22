; func cw_radio_administrative_state_create @ 0x0057f780 size=0xdc
  57f780:	27bdffd8 	addiu	sp,sp,-40
  57f784:	24050002 	li	a1,2
  57f788:	afb0001c 	sw	s0,28(sp)
  57f78c:	afbf0024 	sw	ra,36(sp)
  57f790:	0c15c8cc 	jal	0x572330
  57f794:	afb10020 	sw	s1,32(sp)
  57f798:	1040000d 	beqz	v0,0x57f7d0
  57f79c:	00408021 	move	s0,v0
  57f7a0:	2404001f 	li	a0,31
  57f7a4:	24050002 	li	a1,2
  57f7a8:	0c15c943 	jal	0x57250c
  57f7ac:	00403021 	move	a2,v0
  57f7b0:	10400017 	beqz	v0,0x57f810
  57f7b4:	00408821 	move	s1,v0
  57f7b8:	8fbf0024 	lw	ra,36(sp)
  57f7bc:	02201021 	move	v0,s1
  57f7c0:	8fb10020 	lw	s1,32(sp)
  57f7c4:	8fb0001c 	lw	s0,28(sp)
  57f7c8:	03e00008 	jr	ra
  57f7cc:	27bd0028 	addiu	sp,sp,40
  57f7d0:	3c020075 	lui	v0,0x75
  57f7d4:	8c42cf58 	lw	v0,-12456(v0)
  57f7d8:	1040fff7 	beqz	v0,0x57f7b8
  57f7dc:	00008821 	move	s1,zero
  57f7e0:	0c16276a 	jal	0x589da8
  57f7e4:	00000000 	nop
  57f7e8:	5040fff4 	beqzl	v0,0x57f7bc
  57f7ec:	8fbf0024 	lw	ra,36(sp)
  57f7f0:	3c04006d 	lui	a0,0x6d
  57f7f4:	3c05006e 	lui	a1,0x6e
  57f7f8:	248434fc 	addiu	a0,a0,13564
  57f7fc:	24a5b100 	addiu	a1,a1,-20224
  57f800:	0c101b74 	jal	0x406dd0
  57f804:	240600bf 	li	a2,191
  57f808:	0815fdef 	j	0x57f7bc
  57f80c:	8fbf0024 	lw	ra,36(sp)
  57f810:	3c020075 	lui	v0,0x75
  57f814:	8c42cf58 	lw	v0,-12456(v0)
  57f818:	14400005 	bnez	v0,0x57f830
  57f81c:	00000000 	nop
  57f820:	0c101f7c 	jal	0x407df0
  57f824:	02002021 	move	a0,s0
  57f828:	0815fdef 	j	0x57f7bc
  57f82c:	8fbf0024 	lw	ra,36(sp)
  57f830:	0c16276a 	jal	0x589da8
  57f834:	00000000 	nop
  57f838:	1040fff9 	beqz	v0,0x57f820
  57f83c:	3c04006d 	lui	a0,0x6d
  57f840:	3c05006e 	lui	a1,0x6e
  57f844:	248447f0 	addiu	a0,a0,18416
  57f848:	24a5b100 	addiu	a1,a1,-20224
  57f84c:	0c101b74 	jal	0x406dd0
  57f850:	240600c7 	li	a2,199
  57f854:	0815fe08 	j	0x57f820
  57f858:	00000000 	nop
  57f85c:	00000000 	nop

; func cw_priv_wlan_list_create @ 0x005cb740 size=0x1bc
  5cb740:	27bdffd8 	addiu	sp,sp,-40
  5cb744:	2405000c 	li	a1,12
  5cb748:	afb10020 	sw	s1,32(sp)
  5cb74c:	afb0001c 	sw	s0,28(sp)
  5cb750:	afbf0024 	sw	ra,36(sp)
  5cb754:	0c15c8cc 	jal	0x572330
  5cb758:	00808021 	move	s0,a0
  5cb75c:	1040002b 	beqz	v0,0x5cb80c
  5cb760:	00408821 	move	s1,v0
  5cb764:	ac400008 	sw	zero,8(v0)
  5cb768:	8e020004 	lw	v0,4(s0)
  5cb76c:	5040000b 	beqzl	v0,0x5cb79c
  5cb770:	8e250004 	lw	a1,4(s1)
  5cb774:	8e040008 	lw	a0,8(s0)
  5cb778:	50800040 	beqzl	a0,0x5cb87c
  5cb77c:	3c020075 	lui	v0,0x75
  5cb780:	24050021 	li	a1,33
  5cb784:	70452802 	mul	a1,v0,a1
  5cb788:	0c15c8cc 	jal	0x572330
  5cb78c:	30a5ffff 	andi	a1,a1,0xffff
  5cb790:	10400041 	beqz	v0,0x5cb898
  5cb794:	ae220008 	sw	v0,8(s1)
  5cb798:	8e250004 	lw	a1,4(s1)
  5cb79c:	24020021 	li	v0,33
  5cb7a0:	2404001e 	li	a0,30
  5cb7a4:	02203021 	move	a2,s1
  5cb7a8:	70a22802 	mul	a1,a1,v0
  5cb7ac:	24a50008 	addiu	a1,a1,8
  5cb7b0:	0c15c943 	jal	0x57250c
  5cb7b4:	30a5ffff 	andi	a1,a1,0xffff
  5cb7b8:	10400007 	beqz	v0,0x5cb7d8
  5cb7bc:	00408021 	move	s0,v0
  5cb7c0:	8fbf0024 	lw	ra,36(sp)
  5cb7c4:	02001021 	move	v0,s0
  5cb7c8:	8fb10020 	lw	s1,32(sp)
  5cb7cc:	8fb0001c 	lw	s0,28(sp)
  5cb7d0:	03e00008 	jr	ra
  5cb7d4:	27bd0028 	addiu	sp,sp,40
  5cb7d8:	3c020075 	lui	v0,0x75
  5cb7dc:	8c42cf58 	lw	v0,-12456(v0)
  5cb7e0:	1440001a 	bnez	v0,0x5cb84c
  5cb7e4:	00000000 	nop
  5cb7e8:	8e240008 	lw	a0,8(s1)
  5cb7ec:	10800003 	beqz	a0,0x5cb7fc
  5cb7f0:	00000000 	nop
  5cb7f4:	0c101f7c 	jal	0x407df0
  5cb7f8:	00000000 	nop
  5cb7fc:	0c101f7c 	jal	0x407df0
  5cb800:	02202021 	move	a0,s1
  5cb804:	08172df1 	j	0x5cb7c4
  5cb808:	8fbf0024 	lw	ra,36(sp)
  5cb80c:	3c020075 	lui	v0,0x75
  5cb810:	8c42cf58 	lw	v0,-12456(v0)
  5cb814:	1040ffea 	beqz	v0,0x5cb7c0
  5cb818:	00008021 	move	s0,zero
  5cb81c:	0c16276a 	jal	0x589da8
  5cb820:	00000000 	nop
  5cb824:	5040ffe7 	beqzl	v0,0x5cb7c4
  5cb828:	8fbf0024 	lw	ra,36(sp)
  5cb82c:	3c04006d 	lui	a0,0x6d
  5cb830:	3c05006f 	lui	a1,0x6f
  5cb834:	248434fc 	addiu	a0,a0,13564
  5cb838:	24a51580 	addiu	a1,a1,5504
  5cb83c:	0c101b74 	jal	0x406dd0
  5cb840:	240600da 	li	a2,218
  5cb844:	08172df1 	j	0x5cb7c4
  5cb848:	8fbf0024 	lw	ra,36(sp)
  5cb84c:	0c16276a 	jal	0x589da8
  5cb850:	00000000 	nop
  5cb854:	5040ffe5 	beqzl	v0,0x5cb7ec
  5cb858:	8e240008 	lw	a0,8(s1)
  5cb85c:	3c04006d 	lui	a0,0x6d
  5cb860:	3c05006f 	lui	a1,0x6f
  5cb864:	248447f0 	addiu	a0,a0,18416
  5cb868:	24a51580 	addiu	a1,a1,5504
  5cb86c:	0c101b74 	jal	0x406dd0
  5cb870:	240600f5 	li	a2,245
  5cb874:	08172dfb 	j	0x5cb7ec
  5cb878:	8e240008 	lw	a0,8(s1)
  5cb87c:	8c42cf58 	lw	v0,-12456(v0)
  5cb880:	14400015 	bnez	v0,0x5cb8d8
  5cb884:	00000000 	nop
  5cb888:	0c101f7c 	jal	0x407df0
  5cb88c:	02202021 	move	a0,s1
  5cb890:	08172df0 	j	0x5cb7c0
  5cb894:	00008021 	move	s0,zero
  5cb898:	3c020075 	lui	v0,0x75
  5cb89c:	8c42cf58 	lw	v0,-12456(v0)
  5cb8a0:	1040fff9 	beqz	v0,0x5cb888
  5cb8a4:	00000000 	nop
  5cb8a8:	0c16276a 	jal	0x589da8
  5cb8ac:	00000000 	nop
  5cb8b0:	1040fff5 	beqz	v0,0x5cb888
  5cb8b4:	3c04006e 	lui	a0,0x6e
  5cb8b8:	3c05006f 	lui	a1,0x6f
  5cb8bc:	24847c94 	addiu	a0,a0,31892
  5cb8c0:	24a51580 	addiu	a1,a1,5504
  5cb8c4:	240600eb 	li	a2,235
  5cb8c8:	0c101b74 	jal	0x406dd0
  5cb8cc:	00000000 	nop
  5cb8d0:	08172e22 	j	0x5cb888
  5cb8d4:	00000000 	nop
  5cb8d8:	0c16276a 	jal	0x589da8
  5cb8dc:	00000000 	nop
  5cb8e0:	1040ffe9 	beqz	v0,0x5cb888
  5cb8e4:	3c04006e 	lui	a0,0x6e
  5cb8e8:	3c05006f 	lui	a1,0x6f
  5cb8ec:	24847c6c 	addiu	a0,a0,31852
  5cb8f0:	24a51580 	addiu	a1,a1,5504
  5cb8f4:	08172e32 	j	0x5cb8c8
  5cb8f8:	240600e4 	li	a2,228

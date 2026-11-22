; func cw_priv_sub_device_report_create @ 0x005c87ac size=0x1d4
  5c87ac:	27bdffd8 	addiu	sp,sp,-40
  5c87b0:	2405000c 	li	a1,12
  5c87b4:	afb10020 	sw	s1,32(sp)
  5c87b8:	afb0001c 	sw	s0,28(sp)
  5c87bc:	afbf0024 	sw	ra,36(sp)
  5c87c0:	0c15c8cc 	jal	0x572330
  5c87c4:	00808821 	move	s1,a0
  5c87c8:	10400031 	beqz	v0,0x5c8890
  5c87cc:	00408021 	move	s0,v0
  5c87d0:	ac400008 	sw	zero,8(v0)
  5c87d4:	ac400004 	sw	zero,4(v0)
  5c87d8:	a4400000 	sh	zero,0(v0)
  5c87dc:	a4400002 	sh	zero,2(v0)
  5c87e0:	8e250004 	lw	a1,4(s1)
  5c87e4:	10a00011 	beqz	a1,0x5c882c
  5c87e8:	24040080 	li	a0,128
  5c87ec:	8e240008 	lw	a0,8(s1)
  5c87f0:	10800043 	beqz	a0,0x5c8900
  5c87f4:	3c020075 	lui	v0,0x75
  5c87f8:	24a50001 	addiu	a1,a1,1
  5c87fc:	0c15c8cc 	jal	0x572330
  5c8800:	30a5ffff 	andi	a1,a1,0xffff
  5c8804:	10400045 	beqz	v0,0x5c891c
  5c8808:	ae020008 	sw	v0,8(s0)
  5c880c:	8e220004 	lw	v0,4(s1)
  5c8810:	ae020004 	sw	v0,4(s0)
  5c8814:	96220000 	lhu	v0,0(s1)
  5c8818:	a6020000 	sh	v0,0(s0)
  5c881c:	96220002 	lhu	v0,2(s1)
  5c8820:	a6020002 	sh	v0,2(s0)
  5c8824:	8e250004 	lw	a1,4(s1)
  5c8828:	24040080 	li	a0,128
  5c882c:	02003021 	move	a2,s0
  5c8830:	24a50008 	addiu	a1,a1,8
  5c8834:	0c15c943 	jal	0x57250c
  5c8838:	30a5ffff 	andi	a1,a1,0xffff
  5c883c:	10400007 	beqz	v0,0x5c885c
  5c8840:	00408821 	move	s1,v0
  5c8844:	8fbf0024 	lw	ra,36(sp)
  5c8848:	02201021 	move	v0,s1
  5c884c:	8fb10020 	lw	s1,32(sp)
  5c8850:	8fb0001c 	lw	s0,28(sp)
  5c8854:	03e00008 	jr	ra
  5c8858:	27bd0028 	addiu	sp,sp,40
  5c885c:	3c020075 	lui	v0,0x75
  5c8860:	8c42cf58 	lw	v0,-12456(v0)
  5c8864:	1440001a 	bnez	v0,0x5c88d0
  5c8868:	00000000 	nop
  5c886c:	8e040008 	lw	a0,8(s0)
  5c8870:	10800003 	beqz	a0,0x5c8880
  5c8874:	00000000 	nop
  5c8878:	0c101f7c 	jal	0x407df0
  5c887c:	00000000 	nop
  5c8880:	0c101f7c 	jal	0x407df0
  5c8884:	02002021 	move	a0,s0
  5c8888:	08172212 	j	0x5c8848
  5c888c:	8fbf0024 	lw	ra,36(sp)
  5c8890:	3c020075 	lui	v0,0x75
  5c8894:	8c42cf58 	lw	v0,-12456(v0)
  5c8898:	1040ffea 	beqz	v0,0x5c8844
  5c889c:	00008821 	move	s1,zero
  5c88a0:	0c16276a 	jal	0x589da8
  5c88a4:	00000000 	nop
  5c88a8:	5040ffe7 	beqzl	v0,0x5c8848
  5c88ac:	8fbf0024 	lw	ra,36(sp)
  5c88b0:	3c04006d 	lui	a0,0x6d
  5c88b4:	3c05006f 	lui	a1,0x6f
  5c88b8:	248434fc 	addiu	a0,a0,13564
  5c88bc:	24a50920 	addiu	a1,a1,2336
  5c88c0:	0c101b74 	jal	0x406dd0
  5c88c4:	240600c1 	li	a2,193
  5c88c8:	08172212 	j	0x5c8848
  5c88cc:	8fbf0024 	lw	ra,36(sp)
  5c88d0:	0c16276a 	jal	0x589da8
  5c88d4:	00000000 	nop
  5c88d8:	5040ffe5 	beqzl	v0,0x5c8870
  5c88dc:	8e040008 	lw	a0,8(s0)
  5c88e0:	3c04006d 	lui	a0,0x6d
  5c88e4:	3c05006f 	lui	a1,0x6f
  5c88e8:	248447f0 	addiu	a0,a0,18416
  5c88ec:	24a50920 	addiu	a1,a1,2336
  5c88f0:	0c101b74 	jal	0x406dd0
  5c88f4:	240600e0 	li	a2,224
  5c88f8:	0817221c 	j	0x5c8870
  5c88fc:	8e040008 	lw	a0,8(s0)
  5c8900:	8c42cf58 	lw	v0,-12456(v0)
  5c8904:	14400015 	bnez	v0,0x5c895c
  5c8908:	00000000 	nop
  5c890c:	0c101f7c 	jal	0x407df0
  5c8910:	02002021 	move	a0,s0
  5c8914:	08172211 	j	0x5c8844
  5c8918:	00008821 	move	s1,zero
  5c891c:	3c020075 	lui	v0,0x75
  5c8920:	8c42cf58 	lw	v0,-12456(v0)
  5c8924:	1040fff9 	beqz	v0,0x5c890c
  5c8928:	00000000 	nop
  5c892c:	0c16276a 	jal	0x589da8
  5c8930:	00000000 	nop
  5c8934:	1040fff5 	beqz	v0,0x5c890c
  5c8938:	3c04006e 	lui	a0,0x6e
  5c893c:	3c05006f 	lui	a1,0x6f
  5c8940:	24848050 	addiu	a0,a0,-32688
  5c8944:	24a50920 	addiu	a1,a1,2336
  5c8948:	240600d4 	li	a2,212
  5c894c:	0c101b74 	jal	0x406dd0
  5c8950:	00000000 	nop
  5c8954:	08172243 	j	0x5c890c
  5c8958:	00000000 	nop
  5c895c:	0c16276a 	jal	0x589da8
  5c8960:	00000000 	nop
  5c8964:	1040ffe9 	beqz	v0,0x5c890c
  5c8968:	3c04006e 	lui	a0,0x6e
  5c896c:	3c05006f 	lui	a1,0x6f
  5c8970:	248480d8 	addiu	a0,a0,-32552
  5c8974:	24a50920 	addiu	a1,a1,2336
  5c8978:	08172253 	j	0x5c894c
  5c897c:	240600cd 	li	a2,205

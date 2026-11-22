; func cw_priv_dhcp_defend_create @ 0x005af858 size=0x1bc
  5af858:	27bdffd8 	addiu	sp,sp,-40
  5af85c:	2405000c 	li	a1,12
  5af860:	afb10020 	sw	s1,32(sp)
  5af864:	afb0001c 	sw	s0,28(sp)
  5af868:	afbf0024 	sw	ra,36(sp)
  5af86c:	0c15c8cc 	jal	0x572330
  5af870:	00808021 	move	s0,a0
  5af874:	1040002b 	beqz	v0,0x5af924
  5af878:	00408821 	move	s1,v0
  5af87c:	ac400008 	sw	zero,8(v0)
  5af880:	8e020004 	lw	v0,4(s0)
  5af884:	5040000b 	beqzl	v0,0x5af8b4
  5af888:	8e250004 	lw	a1,4(s1)
  5af88c:	8e040008 	lw	a0,8(s0)
  5af890:	50800040 	beqzl	a0,0x5af994
  5af894:	3c020075 	lui	v0,0x75
  5af898:	24050007 	li	a1,7
  5af89c:	70452802 	mul	a1,v0,a1
  5af8a0:	0c15c8cc 	jal	0x572330
  5af8a4:	30a5ffff 	andi	a1,a1,0xffff
  5af8a8:	10400041 	beqz	v0,0x5af9b0
  5af8ac:	ae220008 	sw	v0,8(s1)
  5af8b0:	8e250004 	lw	a1,4(s1)
  5af8b4:	24020007 	li	v0,7
  5af8b8:	24040047 	li	a0,71
  5af8bc:	02203021 	move	a2,s1
  5af8c0:	70a22802 	mul	a1,a1,v0
  5af8c4:	24a50006 	addiu	a1,a1,6
  5af8c8:	0c15c943 	jal	0x57250c
  5af8cc:	30a5ffff 	andi	a1,a1,0xffff
  5af8d0:	10400007 	beqz	v0,0x5af8f0
  5af8d4:	00408021 	move	s0,v0
  5af8d8:	8fbf0024 	lw	ra,36(sp)
  5af8dc:	02001021 	move	v0,s0
  5af8e0:	8fb10020 	lw	s1,32(sp)
  5af8e4:	8fb0001c 	lw	s0,28(sp)
  5af8e8:	03e00008 	jr	ra
  5af8ec:	27bd0028 	addiu	sp,sp,40
  5af8f0:	3c020075 	lui	v0,0x75
  5af8f4:	8c42cf58 	lw	v0,-12456(v0)
  5af8f8:	1440001a 	bnez	v0,0x5af964
  5af8fc:	00000000 	nop
  5af900:	8e240008 	lw	a0,8(s1)
  5af904:	10800003 	beqz	a0,0x5af914
  5af908:	00000000 	nop
  5af90c:	0c101f7c 	jal	0x407df0
  5af910:	00000000 	nop
  5af914:	0c101f7c 	jal	0x407df0
  5af918:	02202021 	move	a0,s1
  5af91c:	0816be37 	j	0x5af8dc
  5af920:	8fbf0024 	lw	ra,36(sp)
  5af924:	3c020075 	lui	v0,0x75
  5af928:	8c42cf58 	lw	v0,-12456(v0)
  5af92c:	1040ffea 	beqz	v0,0x5af8d8
  5af930:	00008021 	move	s0,zero
  5af934:	0c16276a 	jal	0x589da8
  5af938:	00000000 	nop
  5af93c:	5040ffe7 	beqzl	v0,0x5af8dc
  5af940:	8fbf0024 	lw	ra,36(sp)
  5af944:	3c04006d 	lui	a0,0x6d
  5af948:	3c05006f 	lui	a1,0x6f
  5af94c:	248434fc 	addiu	a0,a0,13564
  5af950:	24a5aa00 	addiu	a1,a1,-22016
  5af954:	0c101b74 	jal	0x406dd0
  5af958:	240600e5 	li	a2,229
  5af95c:	0816be37 	j	0x5af8dc
  5af960:	8fbf0024 	lw	ra,36(sp)
  5af964:	0c16276a 	jal	0x589da8
  5af968:	00000000 	nop
  5af96c:	5040ffe5 	beqzl	v0,0x5af904
  5af970:	8e240008 	lw	a0,8(s1)
  5af974:	3c04006d 	lui	a0,0x6d
  5af978:	3c05006f 	lui	a1,0x6f
  5af97c:	248447f0 	addiu	a0,a0,18416
  5af980:	24a5aa00 	addiu	a1,a1,-22016
  5af984:	0c101b74 	jal	0x406dd0
  5af988:	24060100 	li	a2,256
  5af98c:	0816be41 	j	0x5af904
  5af990:	8e240008 	lw	a0,8(s1)
  5af994:	8c42cf58 	lw	v0,-12456(v0)
  5af998:	14400015 	bnez	v0,0x5af9f0
  5af99c:	00000000 	nop
  5af9a0:	0c101f7c 	jal	0x407df0
  5af9a4:	02202021 	move	a0,s1
  5af9a8:	0816be36 	j	0x5af8d8
  5af9ac:	00008021 	move	s0,zero
  5af9b0:	3c020075 	lui	v0,0x75
  5af9b4:	8c42cf58 	lw	v0,-12456(v0)
  5af9b8:	1040fff9 	beqz	v0,0x5af9a0
  5af9bc:	00000000 	nop
  5af9c0:	0c16276a 	jal	0x589da8
  5af9c4:	00000000 	nop
  5af9c8:	1040fff5 	beqz	v0,0x5af9a0
  5af9cc:	3c04006f 	lui	a0,0x6f
  5af9d0:	3c05006f 	lui	a1,0x6f
  5af9d4:	2484a82c 	addiu	a0,a0,-22484
  5af9d8:	24a5aa00 	addiu	a1,a1,-22016
  5af9dc:	240600f6 	li	a2,246
  5af9e0:	0c101b74 	jal	0x406dd0
  5af9e4:	00000000 	nop
  5af9e8:	0816be68 	j	0x5af9a0
  5af9ec:	00000000 	nop
  5af9f0:	0c16276a 	jal	0x589da8
  5af9f4:	00000000 	nop
  5af9f8:	1040ffe9 	beqz	v0,0x5af9a0
  5af9fc:	3c04006f 	lui	a0,0x6f
  5afa00:	3c05006f 	lui	a1,0x6f
  5afa04:	2484a800 	addiu	a0,a0,-22528
  5afa08:	24a5aa00 	addiu	a1,a1,-22016
  5afa0c:	0816be78 	j	0x5af9e0
  5afa10:	240600ef 	li	a2,239

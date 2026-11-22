; func cw_priv_sta_list_create @ 0x005c68b8 size=0x1bc
  5c68b8:	27bdffd8 	addiu	sp,sp,-40
  5c68bc:	2405000c 	li	a1,12
  5c68c0:	afb10020 	sw	s1,32(sp)
  5c68c4:	afb0001c 	sw	s0,28(sp)
  5c68c8:	afbf0024 	sw	ra,36(sp)
  5c68cc:	0c15c8cc 	jal	0x572330
  5c68d0:	00808021 	move	s0,a0
  5c68d4:	1040002b 	beqz	v0,0x5c6984
  5c68d8:	00408821 	move	s1,v0
  5c68dc:	ac400008 	sw	zero,8(v0)
  5c68e0:	8e020004 	lw	v0,4(s0)
  5c68e4:	5040000b 	beqzl	v0,0x5c6914
  5c68e8:	8e250004 	lw	a1,4(s1)
  5c68ec:	8e040008 	lw	a0,8(s0)
  5c68f0:	50800040 	beqzl	a0,0x5c69f4
  5c68f4:	3c020075 	lui	v0,0x75
  5c68f8:	24050006 	li	a1,6
  5c68fc:	70452802 	mul	a1,v0,a1
  5c6900:	0c15c8cc 	jal	0x572330
  5c6904:	30a5fffe 	andi	a1,a1,0xfffe
  5c6908:	10400041 	beqz	v0,0x5c6a10
  5c690c:	ae220008 	sw	v0,8(s1)
  5c6910:	8e250004 	lw	a1,4(s1)
  5c6914:	24020006 	li	v0,6
  5c6918:	2404001f 	li	a0,31
  5c691c:	02203021 	move	a2,s1
  5c6920:	24a50001 	addiu	a1,a1,1
  5c6924:	70a22802 	mul	a1,a1,v0
  5c6928:	0c15c943 	jal	0x57250c
  5c692c:	30a5fffe 	andi	a1,a1,0xfffe
  5c6930:	10400007 	beqz	v0,0x5c6950
  5c6934:	00408021 	move	s0,v0
  5c6938:	8fbf0024 	lw	ra,36(sp)
  5c693c:	02001021 	move	v0,s0
  5c6940:	8fb10020 	lw	s1,32(sp)
  5c6944:	8fb0001c 	lw	s0,28(sp)
  5c6948:	03e00008 	jr	ra
  5c694c:	27bd0028 	addiu	sp,sp,40
  5c6950:	3c020075 	lui	v0,0x75
  5c6954:	8c42cf58 	lw	v0,-12456(v0)
  5c6958:	1440001a 	bnez	v0,0x5c69c4
  5c695c:	00000000 	nop
  5c6960:	8e240008 	lw	a0,8(s1)
  5c6964:	10800003 	beqz	a0,0x5c6974
  5c6968:	00000000 	nop
  5c696c:	0c101f7c 	jal	0x407df0
  5c6970:	00000000 	nop
  5c6974:	0c101f7c 	jal	0x407df0
  5c6978:	02202021 	move	a0,s1
  5c697c:	08171a4f 	j	0x5c693c
  5c6980:	8fbf0024 	lw	ra,36(sp)
  5c6984:	3c020075 	lui	v0,0x75
  5c6988:	8c42cf58 	lw	v0,-12456(v0)
  5c698c:	1040ffea 	beqz	v0,0x5c6938
  5c6990:	00008021 	move	s0,zero
  5c6994:	0c16276a 	jal	0x589da8
  5c6998:	00000000 	nop
  5c699c:	5040ffe7 	beqzl	v0,0x5c693c
  5c69a0:	8fbf0024 	lw	ra,36(sp)
  5c69a4:	3c04006d 	lui	a0,0x6d
  5c69a8:	3c05006f 	lui	a1,0x6f
  5c69ac:	248434fc 	addiu	a0,a0,13564
  5c69b0:	24a50250 	addiu	a1,a1,592
  5c69b4:	0c101b74 	jal	0x406dd0
  5c69b8:	240600e0 	li	a2,224
  5c69bc:	08171a4f 	j	0x5c693c
  5c69c0:	8fbf0024 	lw	ra,36(sp)
  5c69c4:	0c16276a 	jal	0x589da8
  5c69c8:	00000000 	nop
  5c69cc:	5040ffe5 	beqzl	v0,0x5c6964
  5c69d0:	8e240008 	lw	a0,8(s1)
  5c69d4:	3c04006d 	lui	a0,0x6d
  5c69d8:	3c05006f 	lui	a1,0x6f
  5c69dc:	248447f0 	addiu	a0,a0,18416
  5c69e0:	24a50250 	addiu	a1,a1,592
  5c69e4:	0c101b74 	jal	0x406dd0
  5c69e8:	240600fb 	li	a2,251
  5c69ec:	08171a59 	j	0x5c6964
  5c69f0:	8e240008 	lw	a0,8(s1)
  5c69f4:	8c42cf58 	lw	v0,-12456(v0)
  5c69f8:	14400015 	bnez	v0,0x5c6a50
  5c69fc:	00000000 	nop
  5c6a00:	0c101f7c 	jal	0x407df0
  5c6a04:	02202021 	move	a0,s1
  5c6a08:	08171a4e 	j	0x5c6938
  5c6a0c:	00008021 	move	s0,zero
  5c6a10:	3c020075 	lui	v0,0x75
  5c6a14:	8c42cf58 	lw	v0,-12456(v0)
  5c6a18:	1040fff9 	beqz	v0,0x5c6a00
  5c6a1c:	00000000 	nop
  5c6a20:	0c16276a 	jal	0x589da8
  5c6a24:	00000000 	nop
  5c6a28:	1040fff5 	beqz	v0,0x5c6a00
  5c6a2c:	3c04006f 	lui	a0,0x6f
  5c6a30:	3c05006f 	lui	a1,0x6f
  5c6a34:	2484dabc 	addiu	a0,a0,-9540
  5c6a38:	24a50250 	addiu	a1,a1,592
  5c6a3c:	240600f1 	li	a2,241
  5c6a40:	0c101b74 	jal	0x406dd0
  5c6a44:	00000000 	nop
  5c6a48:	08171a80 	j	0x5c6a00
  5c6a4c:	00000000 	nop
  5c6a50:	0c16276a 	jal	0x589da8
  5c6a54:	00000000 	nop
  5c6a58:	1040ffe9 	beqz	v0,0x5c6a00
  5c6a5c:	3c04006f 	lui	a0,0x6f
  5c6a60:	3c05006f 	lui	a1,0x6f
  5c6a64:	2484da94 	addiu	a0,a0,-9580
  5c6a68:	24a50250 	addiu	a1,a1,592
  5c6a6c:	08171a90 	j	0x5c6a40
  5c6a70:	240600ea 	li	a2,234

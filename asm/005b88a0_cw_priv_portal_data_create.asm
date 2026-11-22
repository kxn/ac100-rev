; func cw_priv_portal_data_create @ 0x005b88a0 size=0x1ac
  5b88a0:	27bdffd8 	addiu	sp,sp,-40
  5b88a4:	24050008 	li	a1,8
  5b88a8:	afb10020 	sw	s1,32(sp)
  5b88ac:	afb0001c 	sw	s0,28(sp)
  5b88b0:	afbf0024 	sw	ra,36(sp)
  5b88b4:	0c15c8cc 	jal	0x572330
  5b88b8:	00808021 	move	s0,a0
  5b88bc:	10400027 	beqz	v0,0x5b895c
  5b88c0:	00408821 	move	s1,v0
  5b88c4:	ac400004 	sw	zero,4(v0)
  5b88c8:	96050000 	lhu	a1,0(s0)
  5b88cc:	50a00009 	beqzl	a1,0x5b88f4
  5b88d0:	96250000 	lhu	a1,0(s1)
  5b88d4:	8e040004 	lw	a0,4(s0)
  5b88d8:	1080003c 	beqz	a0,0x5b89cc
  5b88dc:	3c020075 	lui	v0,0x75
  5b88e0:	0c15c8cc 	jal	0x572330
  5b88e4:	00000000 	nop
  5b88e8:	1040003f 	beqz	v0,0x5b89e8
  5b88ec:	ae220004 	sw	v0,4(s1)
  5b88f0:	96250000 	lhu	a1,0(s1)
  5b88f4:	24040028 	li	a0,40
  5b88f8:	02203021 	move	a2,s1
  5b88fc:	24a50002 	addiu	a1,a1,2
  5b8900:	0c15c943 	jal	0x57250c
  5b8904:	30a5ffff 	andi	a1,a1,0xffff
  5b8908:	10400007 	beqz	v0,0x5b8928
  5b890c:	00408021 	move	s0,v0
  5b8910:	8fbf0024 	lw	ra,36(sp)
  5b8914:	02001021 	move	v0,s0
  5b8918:	8fb10020 	lw	s1,32(sp)
  5b891c:	8fb0001c 	lw	s0,28(sp)
  5b8920:	03e00008 	jr	ra
  5b8924:	27bd0028 	addiu	sp,sp,40
  5b8928:	3c020075 	lui	v0,0x75
  5b892c:	8c42cf58 	lw	v0,-12456(v0)
  5b8930:	1440001a 	bnez	v0,0x5b899c
  5b8934:	00000000 	nop
  5b8938:	8e240004 	lw	a0,4(s1)
  5b893c:	10800003 	beqz	a0,0x5b894c
  5b8940:	00000000 	nop
  5b8944:	0c101f7c 	jal	0x407df0
  5b8948:	00000000 	nop
  5b894c:	0c101f7c 	jal	0x407df0
  5b8950:	02202021 	move	a0,s1
  5b8954:	0816e245 	j	0x5b8914
  5b8958:	8fbf0024 	lw	ra,36(sp)
  5b895c:	3c020075 	lui	v0,0x75
  5b8960:	8c42cf58 	lw	v0,-12456(v0)
  5b8964:	1040ffea 	beqz	v0,0x5b8910
  5b8968:	00008021 	move	s0,zero
  5b896c:	0c16276a 	jal	0x589da8
  5b8970:	00000000 	nop
  5b8974:	5040ffe7 	beqzl	v0,0x5b8914
  5b8978:	8fbf0024 	lw	ra,36(sp)
  5b897c:	3c04006d 	lui	a0,0x6d
  5b8980:	3c05006f 	lui	a1,0x6f
  5b8984:	248434fc 	addiu	a0,a0,13564
  5b8988:	24a5cff0 	addiu	a1,a1,-12304
  5b898c:	0c101b74 	jal	0x406dd0
  5b8990:	240600b8 	li	a2,184
  5b8994:	0816e245 	j	0x5b8914
  5b8998:	8fbf0024 	lw	ra,36(sp)
  5b899c:	0c16276a 	jal	0x589da8
  5b89a0:	00000000 	nop
  5b89a4:	5040ffe5 	beqzl	v0,0x5b893c
  5b89a8:	8e240004 	lw	a0,4(s1)
  5b89ac:	3c04006d 	lui	a0,0x6d
  5b89b0:	3c05006f 	lui	a1,0x6f
  5b89b4:	248447f0 	addiu	a0,a0,18416
  5b89b8:	24a5cff0 	addiu	a1,a1,-12304
  5b89bc:	0c101b74 	jal	0x406dd0
  5b89c0:	240600d3 	li	a2,211
  5b89c4:	0816e24f 	j	0x5b893c
  5b89c8:	8e240004 	lw	a0,4(s1)
  5b89cc:	8c42cf58 	lw	v0,-12456(v0)
  5b89d0:	14400015 	bnez	v0,0x5b8a28
  5b89d4:	00000000 	nop
  5b89d8:	0c101f7c 	jal	0x407df0
  5b89dc:	02202021 	move	a0,s1
  5b89e0:	0816e244 	j	0x5b8910
  5b89e4:	00008021 	move	s0,zero
  5b89e8:	3c020075 	lui	v0,0x75
  5b89ec:	8c42cf58 	lw	v0,-12456(v0)
  5b89f0:	1040fff9 	beqz	v0,0x5b89d8
  5b89f4:	00000000 	nop
  5b89f8:	0c16276a 	jal	0x589da8
  5b89fc:	00000000 	nop
  5b8a00:	1040fff5 	beqz	v0,0x5b89d8
  5b8a04:	3c04006e 	lui	a0,0x6e
  5b8a08:	3c05006f 	lui	a1,0x6f
  5b8a0c:	24848050 	addiu	a0,a0,-32688
  5b8a10:	24a5cff0 	addiu	a1,a1,-12304
  5b8a14:	240600c9 	li	a2,201
  5b8a18:	0c101b74 	jal	0x406dd0
  5b8a1c:	00000000 	nop
  5b8a20:	0816e276 	j	0x5b89d8
  5b8a24:	00000000 	nop
  5b8a28:	0c16276a 	jal	0x589da8
  5b8a2c:	00000000 	nop
  5b8a30:	1040ffe9 	beqz	v0,0x5b89d8
  5b8a34:	3c04006e 	lui	a0,0x6e
  5b8a38:	3c05006f 	lui	a1,0x6f
  5b8a3c:	248480d8 	addiu	a0,a0,-32552
  5b8a40:	24a5cff0 	addiu	a1,a1,-12304
  5b8a44:	0816e286 	j	0x5b8a18
  5b8a48:	240600c2 	li	a2,194

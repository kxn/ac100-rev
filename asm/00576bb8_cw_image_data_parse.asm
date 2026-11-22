; func cw_image_data_parse @ 0x00576bb8 size=0x244
  576bb8:	27bdffc8 	addiu	sp,sp,-56
  576bbc:	afb3002c 	sw	s3,44(sp)
  576bc0:	00a09821 	move	s3,a1
  576bc4:	afb20028 	sw	s2,40(sp)
  576bc8:	00809021 	move	s2,a0
  576bcc:	afb10024 	sw	s1,36(sp)
  576bd0:	afbf0034 	sw	ra,52(sp)
  576bd4:	afb40030 	sw	s4,48(sp)
  576bd8:	afb00020 	sw	s0,32(sp)
  576bdc:	94940006 	lhu	s4,6(a0)
  576be0:	24040008 	li	a0,8
  576be4:	94b0000e 	lhu	s0,14(a1)
  576be8:	0c102114 	jal	0x408450
  576bec:	24050066 	li	a1,102
  576bf0:	10400031 	beqz	v0,0x576cb8
  576bf4:	00408821 	move	s1,v0
  576bf8:	00002821 	move	a1,zero
  576bfc:	24060008 	li	a2,8
  576c00:	0c101cf0 	jal	0x4073c0
  576c04:	00402021 	move	a0,v0
  576c08:	0c15c5b0 	jal	0x5716c0
  576c0c:	02402021 	move	a0,s2
  576c10:	2610ffff 	addiu	s0,s0,-1
  576c14:	2443ffff 	addiu	v1,v0,-1
  576c18:	a2220000 	sb	v0,0(s1)
  576c1c:	2c630002 	sltiu	v1,v1,2
  576c20:	14600019 	bnez	v1,0x576c88
  576c24:	3210ffff 	andi	s0,s0,0xffff
  576c28:	24030005 	li	v1,5
  576c2c:	14430032 	bne	v0,v1,0x576cf8
  576c30:	3c020075 	lui	v0,0x75
  576c34:	16000046 	bnez	s0,0x576d50
  576c38:	3c020075 	lui	v0,0x75
  576c3c:	a6200002 	sh	zero,2(s1)
  576c40:	ae200004 	sw	zero,4(s1)
  576c44:	9662000e 	lhu	v0,14(s3)
  576c48:	ae710010 	sw	s1,16(s3)
  576c4c:	96500006 	lhu	s0,6(s2)
  576c50:	02148023 	subu	s0,s0,s4
  576c54:	02028026 	xor	s0,s0,v0
  576c58:	2402ffff 	li	v0,-1
  576c5c:	0010100a 	movz	v0,zero,s0
  576c60:	00408021 	move	s0,v0
  576c64:	8fbf0034 	lw	ra,52(sp)
  576c68:	02001021 	move	v0,s0
  576c6c:	8fb40030 	lw	s4,48(sp)
  576c70:	8fb3002c 	lw	s3,44(sp)
  576c74:	8fb20028 	lw	s2,40(sp)
  576c78:	8fb10024 	lw	s1,36(sp)
  576c7c:	8fb00020 	lw	s0,32(sp)
  576c80:	03e00008 	jr	ra
  576c84:	27bd0038 	addiu	sp,sp,56
  576c88:	12000031 	beqz	s0,0x576d50
  576c8c:	3c020075 	lui	v0,0x75
  576c90:	2e020401 	sltiu	v0,s0,1025
  576c94:	1040003f 	beqz	v0,0x576d94
  576c98:	3c020075 	lui	v0,0x75
  576c9c:	02402021 	move	a0,s2
  576ca0:	0c15c6bc 	jal	0x571af0
  576ca4:	02002821 	move	a1,s0
  576ca8:	1040001a 	beqz	v0,0x576d14
  576cac:	ae220004 	sw	v0,4(s1)
  576cb0:	0815db11 	j	0x576c44
  576cb4:	a6300002 	sh	s0,2(s1)
  576cb8:	3c020075 	lui	v0,0x75
  576cbc:	8c42cf58 	lw	v0,-12456(v0)
  576cc0:	1040ffe8 	beqz	v0,0x576c64
  576cc4:	2410ffff 	li	s0,-1
  576cc8:	0c16276a 	jal	0x589da8
  576ccc:	00000000 	nop
  576cd0:	5040ffe5 	beqzl	v0,0x576c68
  576cd4:	8fbf0034 	lw	ra,52(sp)
  576cd8:	3c04006d 	lui	a0,0x6d
  576cdc:	3c05006e 	lui	a1,0x6e
  576ce0:	2484381c 	addiu	a0,a0,14364
  576ce4:	24a58f20 	addiu	a1,a1,-28896
  576ce8:	0c101b74 	jal	0x406dd0
  576cec:	24060069 	li	a2,105
  576cf0:	0815db1a 	j	0x576c68
  576cf4:	8fbf0034 	lw	ra,52(sp)
  576cf8:	8c42cf58 	lw	v0,-12456(v0)
  576cfc:	14400035 	bnez	v0,0x576dd4
  576d00:	00000000 	nop
  576d04:	0c101f7c 	jal	0x407df0
  576d08:	02202021 	move	a0,s1
  576d0c:	0815db19 	j	0x576c64
  576d10:	2410ffff 	li	s0,-1
  576d14:	3c020075 	lui	v0,0x75
  576d18:	8c42cf58 	lw	v0,-12456(v0)
  576d1c:	1040fff9 	beqz	v0,0x576d04
  576d20:	00000000 	nop
  576d24:	0c16276a 	jal	0x589da8
  576d28:	00000000 	nop
  576d2c:	1040fff5 	beqz	v0,0x576d04
  576d30:	3c05006e 	lui	a1,0x6e
  576d34:	3c04006d 	lui	a0,0x6d
  576d38:	24846af8 	addiu	a0,a0,27384
  576d3c:	24a58f20 	addiu	a1,a1,-28896
  576d40:	0c101b74 	jal	0x406dd0
  576d44:	24060092 	li	a2,146
  576d48:	0815db41 	j	0x576d04
  576d4c:	00000000 	nop
  576d50:	8c42cf58 	lw	v0,-12456(v0)
  576d54:	1040ffeb 	beqz	v0,0x576d04
  576d58:	00000000 	nop
  576d5c:	0c16276a 	jal	0x589da8
  576d60:	00000000 	nop
  576d64:	1040ffe7 	beqz	v0,0x576d04
  576d68:	3c05006e 	lui	a1,0x6e
  576d6c:	3c04006e 	lui	a0,0x6e
  576d70:	92220000 	lbu	v0,0(s1)
  576d74:	9667000e 	lhu	a3,14(s3)
  576d78:	24848e94 	addiu	a0,a0,-29036
  576d7c:	24a58f20 	addiu	a1,a1,-28896
  576d80:	afa20010 	sw	v0,16(sp)
  576d84:	0c101b74 	jal	0x406dd0
  576d88:	2406007a 	li	a2,122
  576d8c:	0815db41 	j	0x576d04
  576d90:	00000000 	nop
  576d94:	8c42cf58 	lw	v0,-12456(v0)
  576d98:	1040ffda 	beqz	v0,0x576d04
  576d9c:	00000000 	nop
  576da0:	0c16276a 	jal	0x589da8
  576da4:	00000000 	nop
  576da8:	1040ffd6 	beqz	v0,0x576d04
  576dac:	3c05006e 	lui	a1,0x6e
  576db0:	3c04006e 	lui	a0,0x6e
  576db4:	248480a4 	addiu	a0,a0,-32604
  576db8:	24a58f20 	addiu	a1,a1,-28896
  576dbc:	24060082 	li	a2,130
  576dc0:	02003821 	move	a3,s0
  576dc4:	0c101b74 	jal	0x406dd0
  576dc8:	00000000 	nop
  576dcc:	0815db41 	j	0x576d04
  576dd0:	00000000 	nop
  576dd4:	0c16276a 	jal	0x589da8
  576dd8:	00000000 	nop
  576ddc:	1040ffc9 	beqz	v0,0x576d04
  576de0:	3c05006e 	lui	a1,0x6e
  576de4:	3c04006d 	lui	a0,0x6d
  576de8:	92270000 	lbu	a3,0(s1)
  576dec:	24846028 	addiu	a0,a0,24616
  576df0:	24a58f20 	addiu	a1,a1,-28896
  576df4:	0815db71 	j	0x576dc4
  576df8:	24060072 	li	a2,114
  576dfc:	00000000 	nop

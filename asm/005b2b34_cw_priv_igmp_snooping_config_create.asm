; func cw_priv_igmp_snooping_config_create @ 0x005b2b34 size=0x1ac
  5b2b34:	27bdffd8 	addiu	sp,sp,-40
  5b2b38:	24050008 	li	a1,8
  5b2b3c:	afb10020 	sw	s1,32(sp)
  5b2b40:	afb0001c 	sw	s0,28(sp)
  5b2b44:	afbf0024 	sw	ra,36(sp)
  5b2b48:	0c15c8cc 	jal	0x572330
  5b2b4c:	00808021 	move	s0,a0
  5b2b50:	10400027 	beqz	v0,0x5b2bf0
  5b2b54:	00408821 	move	s1,v0
  5b2b58:	ac400004 	sw	zero,4(v0)
  5b2b5c:	92050002 	lbu	a1,2(s0)
  5b2b60:	10a00008 	beqz	a1,0x5b2b84
  5b2b64:	00000000 	nop
  5b2b68:	8e040004 	lw	a0,4(s0)
  5b2b6c:	1080003c 	beqz	a0,0x5b2c60
  5b2b70:	3c020075 	lui	v0,0x75
  5b2b74:	0c15c8cc 	jal	0x572330
  5b2b78:	00052880 	sll	a1,a1,0x2
  5b2b7c:	1040003f 	beqz	v0,0x5b2c7c
  5b2b80:	ae220004 	sw	v0,4(s1)
  5b2b84:	0c16ca54 	jal	0x5b2950
  5b2b88:	02202021 	move	a0,s1
  5b2b8c:	24040070 	li	a0,112
  5b2b90:	00402821 	move	a1,v0
  5b2b94:	0c15c943 	jal	0x57250c
  5b2b98:	02203021 	move	a2,s1
  5b2b9c:	10400007 	beqz	v0,0x5b2bbc
  5b2ba0:	00408021 	move	s0,v0
  5b2ba4:	8fbf0024 	lw	ra,36(sp)
  5b2ba8:	02001021 	move	v0,s0
  5b2bac:	8fb10020 	lw	s1,32(sp)
  5b2bb0:	8fb0001c 	lw	s0,28(sp)
  5b2bb4:	03e00008 	jr	ra
  5b2bb8:	27bd0028 	addiu	sp,sp,40
  5b2bbc:	3c020075 	lui	v0,0x75
  5b2bc0:	8c42cf58 	lw	v0,-12456(v0)
  5b2bc4:	1440001a 	bnez	v0,0x5b2c30
  5b2bc8:	00000000 	nop
  5b2bcc:	8e240004 	lw	a0,4(s1)
  5b2bd0:	10800003 	beqz	a0,0x5b2be0
  5b2bd4:	00000000 	nop
  5b2bd8:	0c101f7c 	jal	0x407df0
  5b2bdc:	00000000 	nop
  5b2be0:	0c101f7c 	jal	0x407df0
  5b2be4:	02202021 	move	a0,s1
  5b2be8:	0816caea 	j	0x5b2ba8
  5b2bec:	8fbf0024 	lw	ra,36(sp)
  5b2bf0:	3c020075 	lui	v0,0x75
  5b2bf4:	8c42cf58 	lw	v0,-12456(v0)
  5b2bf8:	1040ffea 	beqz	v0,0x5b2ba4
  5b2bfc:	00008021 	move	s0,zero
  5b2c00:	0c16276a 	jal	0x589da8
  5b2c04:	00000000 	nop
  5b2c08:	5040ffe7 	beqzl	v0,0x5b2ba8
  5b2c0c:	8fbf0024 	lw	ra,36(sp)
  5b2c10:	3c04006d 	lui	a0,0x6d
  5b2c14:	3c05006f 	lui	a1,0x6f
  5b2c18:	248434fc 	addiu	a0,a0,13564
  5b2c1c:	24a5b7f0 	addiu	a1,a1,-18448
  5b2c20:	0c101b74 	jal	0x406dd0
  5b2c24:	240600d9 	li	a2,217
  5b2c28:	0816caea 	j	0x5b2ba8
  5b2c2c:	8fbf0024 	lw	ra,36(sp)
  5b2c30:	0c16276a 	jal	0x589da8
  5b2c34:	00000000 	nop
  5b2c38:	5040ffe5 	beqzl	v0,0x5b2bd0
  5b2c3c:	8e240004 	lw	a0,4(s1)
  5b2c40:	3c04006d 	lui	a0,0x6d
  5b2c44:	3c05006f 	lui	a1,0x6f
  5b2c48:	248447f0 	addiu	a0,a0,18416
  5b2c4c:	24a5b7f0 	addiu	a1,a1,-18448
  5b2c50:	0c101b74 	jal	0x406dd0
  5b2c54:	240600f4 	li	a2,244
  5b2c58:	0816caf4 	j	0x5b2bd0
  5b2c5c:	8e240004 	lw	a0,4(s1)
  5b2c60:	8c42cf58 	lw	v0,-12456(v0)
  5b2c64:	14400015 	bnez	v0,0x5b2cbc
  5b2c68:	00000000 	nop
  5b2c6c:	0c101f7c 	jal	0x407df0
  5b2c70:	02202021 	move	a0,s1
  5b2c74:	0816cae9 	j	0x5b2ba4
  5b2c78:	00008021 	move	s0,zero
  5b2c7c:	3c020075 	lui	v0,0x75
  5b2c80:	8c42cf58 	lw	v0,-12456(v0)
  5b2c84:	1040fff9 	beqz	v0,0x5b2c6c
  5b2c88:	00000000 	nop
  5b2c8c:	0c16276a 	jal	0x589da8
  5b2c90:	00000000 	nop
  5b2c94:	1040fff5 	beqz	v0,0x5b2c6c
  5b2c98:	3c04006f 	lui	a0,0x6f
  5b2c9c:	3c05006f 	lui	a1,0x6f
  5b2ca0:	248488b0 	addiu	a0,a0,-30544
  5b2ca4:	24a5b7f0 	addiu	a1,a1,-18448
  5b2ca8:	240600ea 	li	a2,234
  5b2cac:	0c101b74 	jal	0x406dd0
  5b2cb0:	00000000 	nop
  5b2cb4:	0816cb1b 	j	0x5b2c6c
  5b2cb8:	00000000 	nop
  5b2cbc:	0c16276a 	jal	0x589da8
  5b2cc0:	00000000 	nop
  5b2cc4:	1040ffe9 	beqz	v0,0x5b2c6c
  5b2cc8:	3c04006f 	lui	a0,0x6f
  5b2ccc:	3c05006f 	lui	a1,0x6f
  5b2cd0:	248487f8 	addiu	a0,a0,-30728
  5b2cd4:	24a5b7f0 	addiu	a1,a1,-18448
  5b2cd8:	0816cb2b 	j	0x5b2cac
  5b2cdc:	240600e3 	li	a2,227

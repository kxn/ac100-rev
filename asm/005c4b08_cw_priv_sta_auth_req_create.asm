; func cw_priv_sta_auth_req_create @ 0x005c4b08 size=0x184
  5c4b08:	27bdffd8 	addiu	sp,sp,-40
  5c4b0c:	24050010 	li	a1,16
  5c4b10:	afb10020 	sw	s1,32(sp)
  5c4b14:	afb0001c 	sw	s0,28(sp)
  5c4b18:	afbf0024 	sw	ra,36(sp)
  5c4b1c:	0c15c8cc 	jal	0x572330
  5c4b20:	00808021 	move	s0,a0
  5c4b24:	1040002a 	beqz	v0,0x5c4bd0
  5c4b28:	00408821 	move	s1,v0
  5c4b2c:	ac400008 	sw	zero,8(v0)
  5c4b30:	ac40000c 	sw	zero,12(v0)
  5c4b34:	8e020008 	lw	v0,8(s0)
  5c4b38:	5040000b 	beqzl	v0,0x5c4b68
  5c4b3c:	8e250008 	lw	a1,8(s1)
  5c4b40:	8e03000c 	lw	v1,12(s0)
  5c4b44:	50600008 	beqzl	v1,0x5c4b68
  5c4b48:	8e250008 	lw	a1,8(s1)
  5c4b4c:	ae220008 	sw	v0,8(s1)
  5c4b50:	8e04000c 	lw	a0,12(s0)
  5c4b54:	0c15c8cc 	jal	0x572330
  5c4b58:	9605000a 	lhu	a1,10(s0)
  5c4b5c:	10400038 	beqz	v0,0x5c4c40
  5c4b60:	ae22000c 	sw	v0,12(s1)
  5c4b64:	8e250008 	lw	a1,8(s1)
  5c4b68:	24040001 	li	a0,1
  5c4b6c:	02203021 	move	a2,s1
  5c4b70:	24a5000c 	addiu	a1,a1,12
  5c4b74:	0c15c943 	jal	0x57250c
  5c4b78:	30a5ffff 	andi	a1,a1,0xffff
  5c4b7c:	10400007 	beqz	v0,0x5c4b9c
  5c4b80:	00408021 	move	s0,v0
  5c4b84:	8fbf0024 	lw	ra,36(sp)
  5c4b88:	02001021 	move	v0,s0
  5c4b8c:	8fb10020 	lw	s1,32(sp)
  5c4b90:	8fb0001c 	lw	s0,28(sp)
  5c4b94:	03e00008 	jr	ra
  5c4b98:	27bd0028 	addiu	sp,sp,40
  5c4b9c:	3c020075 	lui	v0,0x75
  5c4ba0:	8c42cf58 	lw	v0,-12456(v0)
  5c4ba4:	1440001a 	bnez	v0,0x5c4c10
  5c4ba8:	00000000 	nop
  5c4bac:	8e24000c 	lw	a0,12(s1)
  5c4bb0:	10800003 	beqz	a0,0x5c4bc0
  5c4bb4:	00000000 	nop
  5c4bb8:	0c101f7c 	jal	0x407df0
  5c4bbc:	00000000 	nop
  5c4bc0:	0c101f7c 	jal	0x407df0
  5c4bc4:	02202021 	move	a0,s1
  5c4bc8:	081712e2 	j	0x5c4b88
  5c4bcc:	8fbf0024 	lw	ra,36(sp)
  5c4bd0:	3c020075 	lui	v0,0x75
  5c4bd4:	8c42cf58 	lw	v0,-12456(v0)
  5c4bd8:	1040ffea 	beqz	v0,0x5c4b84
  5c4bdc:	00008021 	move	s0,zero
  5c4be0:	0c16276a 	jal	0x589da8
  5c4be4:	00000000 	nop
  5c4be8:	5040ffe7 	beqzl	v0,0x5c4b88
  5c4bec:	8fbf0024 	lw	ra,36(sp)
  5c4bf0:	3c04006d 	lui	a0,0x6d
  5c4bf4:	3c05006f 	lui	a1,0x6f
  5c4bf8:	248434fc 	addiu	a0,a0,13564
  5c4bfc:	24a5fcc0 	addiu	a1,a1,-832
  5c4c00:	0c101b74 	jal	0x406dd0
  5c4c04:	240600ef 	li	a2,239
  5c4c08:	081712e2 	j	0x5c4b88
  5c4c0c:	8fbf0024 	lw	ra,36(sp)
  5c4c10:	0c16276a 	jal	0x589da8
  5c4c14:	00000000 	nop
  5c4c18:	5040ffe5 	beqzl	v0,0x5c4bb0
  5c4c1c:	8e24000c 	lw	a0,12(s1)
  5c4c20:	3c04006d 	lui	a0,0x6d
  5c4c24:	3c05006f 	lui	a1,0x6f
  5c4c28:	248447f0 	addiu	a0,a0,18416
  5c4c2c:	24a5fcc0 	addiu	a1,a1,-832
  5c4c30:	0c101b74 	jal	0x406dd0
  5c4c34:	24060106 	li	a2,262
  5c4c38:	081712ec 	j	0x5c4bb0
  5c4c3c:	8e24000c 	lw	a0,12(s1)
  5c4c40:	3c020075 	lui	v0,0x75
  5c4c44:	8c42cf58 	lw	v0,-12456(v0)
  5c4c48:	14400005 	bnez	v0,0x5c4c60
  5c4c4c:	00000000 	nop
  5c4c50:	0c101f7c 	jal	0x407df0
  5c4c54:	02202021 	move	a0,s1
  5c4c58:	081712e1 	j	0x5c4b84
  5c4c5c:	00008021 	move	s0,zero
  5c4c60:	0c16276a 	jal	0x589da8
  5c4c64:	00000000 	nop
  5c4c68:	1040fff9 	beqz	v0,0x5c4c50
  5c4c6c:	3c04006f 	lui	a0,0x6f
  5c4c70:	3c05006f 	lui	a1,0x6f
  5c4c74:	2484f510 	addiu	a0,a0,-2800
  5c4c78:	24a5fcc0 	addiu	a1,a1,-832
  5c4c7c:	0c101b74 	jal	0x406dd0
  5c4c80:	240600fc 	li	a2,252
  5c4c84:	08171314 	j	0x5c4c50
  5c4c88:	00000000 	nop

; func cw_priv_large_fireware_info_create @ 0x005b4be4 size=0xdc
  5b4be4:	27bdffd8 	addiu	sp,sp,-40
  5b4be8:	24050020 	li	a1,32
  5b4bec:	afb0001c 	sw	s0,28(sp)
  5b4bf0:	afbf0024 	sw	ra,36(sp)
  5b4bf4:	0c15c8cc 	jal	0x572330
  5b4bf8:	afb10020 	sw	s1,32(sp)
  5b4bfc:	1040000d 	beqz	v0,0x5b4c34
  5b4c00:	00408021 	move	s0,v0
  5b4c04:	240400af 	li	a0,175
  5b4c08:	2405001d 	li	a1,29
  5b4c0c:	0c15c943 	jal	0x57250c
  5b4c10:	00403021 	move	a2,v0
  5b4c14:	10400017 	beqz	v0,0x5b4c74
  5b4c18:	00408821 	move	s1,v0
  5b4c1c:	8fbf0024 	lw	ra,36(sp)
  5b4c20:	02201021 	move	v0,s1
  5b4c24:	8fb10020 	lw	s1,32(sp)
  5b4c28:	8fb0001c 	lw	s0,28(sp)
  5b4c2c:	03e00008 	jr	ra
  5b4c30:	27bd0028 	addiu	sp,sp,40
  5b4c34:	3c020075 	lui	v0,0x75
  5b4c38:	8c42cf58 	lw	v0,-12456(v0)
  5b4c3c:	1040fff7 	beqz	v0,0x5b4c1c
  5b4c40:	00008821 	move	s1,zero
  5b4c44:	0c16276a 	jal	0x589da8
  5b4c48:	00000000 	nop
  5b4c4c:	5040fff4 	beqzl	v0,0x5b4c20
  5b4c50:	8fbf0024 	lw	ra,36(sp)
  5b4c54:	3c04006d 	lui	a0,0x6d
  5b4c58:	3c05006f 	lui	a1,0x6f
  5b4c5c:	248434fc 	addiu	a0,a0,13564
  5b4c60:	24a5c0f0 	addiu	a1,a1,-16144
  5b4c64:	0c101b74 	jal	0x406dd0
  5b4c68:	240600ba 	li	a2,186
  5b4c6c:	0816d308 	j	0x5b4c20
  5b4c70:	8fbf0024 	lw	ra,36(sp)
  5b4c74:	3c020075 	lui	v0,0x75
  5b4c78:	8c42cf58 	lw	v0,-12456(v0)
  5b4c7c:	14400005 	bnez	v0,0x5b4c94
  5b4c80:	00000000 	nop
  5b4c84:	0c101f7c 	jal	0x407df0
  5b4c88:	02002021 	move	a0,s0
  5b4c8c:	0816d308 	j	0x5b4c20
  5b4c90:	8fbf0024 	lw	ra,36(sp)
  5b4c94:	0c16276a 	jal	0x589da8
  5b4c98:	00000000 	nop
  5b4c9c:	1040fff9 	beqz	v0,0x5b4c84
  5b4ca0:	3c04006d 	lui	a0,0x6d
  5b4ca4:	3c05006f 	lui	a1,0x6f
  5b4ca8:	248447f0 	addiu	a0,a0,18416
  5b4cac:	24a5c0f0 	addiu	a1,a1,-16144
  5b4cb0:	0c101b74 	jal	0x406dd0
  5b4cb4:	240600c2 	li	a2,194
  5b4cb8:	0816d321 	j	0x5b4c84
  5b4cbc:	00000000 	nop

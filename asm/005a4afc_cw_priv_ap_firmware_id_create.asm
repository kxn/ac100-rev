; func cw_priv_ap_firmware_id_create @ 0x005a4afc size=0x198
  5a4afc:	27bdffd8 	addiu	sp,sp,-40
  5a4b00:	24050018 	li	a1,24
  5a4b04:	afb10020 	sw	s1,32(sp)
  5a4b08:	afb0001c 	sw	s0,28(sp)
  5a4b0c:	afbf0024 	sw	ra,36(sp)
  5a4b10:	0c15c8cc 	jal	0x572330
  5a4b14:	00808021 	move	s0,a0
  5a4b18:	10400023 	beqz	v0,0x5a4ba8
  5a4b1c:	00408821 	move	s1,v0
  5a4b20:	ac400014 	sw	zero,20(v0)
  5a4b24:	92050010 	lbu	a1,16(s0)
  5a4b28:	50a00009 	beqzl	a1,0x5a4b50
  5a4b2c:	92250010 	lbu	a1,16(s1)
  5a4b30:	8e040014 	lw	a0,20(s0)
  5a4b34:	10800037 	beqz	a0,0x5a4c14
  5a4b38:	3c020075 	lui	v0,0x75
  5a4b3c:	0c15c8cc 	jal	0x572330
  5a4b40:	00052900 	sll	a1,a1,0x4
  5a4b44:	1040003a 	beqz	v0,0x5a4c30
  5a4b48:	ae220014 	sw	v0,20(s1)
  5a4b4c:	92250010 	lbu	a1,16(s1)
  5a4b50:	2404005b 	li	a0,91
  5a4b54:	02203021 	move	a2,s1
  5a4b58:	00052900 	sll	a1,a1,0x4
  5a4b5c:	24a50011 	addiu	a1,a1,17
  5a4b60:	0c15c943 	jal	0x57250c
  5a4b64:	30a5ffff 	andi	a1,a1,0xffff
  5a4b68:	10400007 	beqz	v0,0x5a4b88
  5a4b6c:	00408021 	move	s0,v0
  5a4b70:	8fbf0024 	lw	ra,36(sp)
  5a4b74:	02001021 	move	v0,s0
  5a4b78:	8fb10020 	lw	s1,32(sp)
  5a4b7c:	8fb0001c 	lw	s0,28(sp)
  5a4b80:	03e00008 	jr	ra
  5a4b84:	27bd0028 	addiu	sp,sp,40
  5a4b88:	3c020075 	lui	v0,0x75
  5a4b8c:	8c42cf58 	lw	v0,-12456(v0)
  5a4b90:	14400015 	bnez	v0,0x5a4be8
  5a4b94:	00000000 	nop
  5a4b98:	0c101f7c 	jal	0x407df0
  5a4b9c:	02202021 	move	a0,s1
  5a4ba0:	081692dd 	j	0x5a4b74
  5a4ba4:	8fbf0024 	lw	ra,36(sp)
  5a4ba8:	3c020075 	lui	v0,0x75
  5a4bac:	8c42cf58 	lw	v0,-12456(v0)
  5a4bb0:	1040ffef 	beqz	v0,0x5a4b70
  5a4bb4:	00008021 	move	s0,zero
  5a4bb8:	0c16276a 	jal	0x589da8
  5a4bbc:	00000000 	nop
  5a4bc0:	5040ffec 	beqzl	v0,0x5a4b74
  5a4bc4:	8fbf0024 	lw	ra,36(sp)
  5a4bc8:	3c04006d 	lui	a0,0x6d
  5a4bcc:	3c05006e 	lui	a1,0x6e
  5a4bd0:	248434fc 	addiu	a0,a0,13564
  5a4bd4:	24a577f0 	addiu	a1,a1,30704
  5a4bd8:	0c101b74 	jal	0x406dd0
  5a4bdc:	240600c5 	li	a2,197
  5a4be0:	081692dd 	j	0x5a4b74
  5a4be4:	8fbf0024 	lw	ra,36(sp)
  5a4be8:	0c16276a 	jal	0x589da8
  5a4bec:	00000000 	nop
  5a4bf0:	1040ffe9 	beqz	v0,0x5a4b98
  5a4bf4:	3c04006d 	lui	a0,0x6d
  5a4bf8:	3c05006e 	lui	a1,0x6e
  5a4bfc:	248447f0 	addiu	a0,a0,18416
  5a4c00:	24a577f0 	addiu	a1,a1,30704
  5a4c04:	0c101b74 	jal	0x406dd0
  5a4c08:	240600dd 	li	a2,221
  5a4c0c:	081692e6 	j	0x5a4b98
  5a4c10:	00000000 	nop
  5a4c14:	8c42cf58 	lw	v0,-12456(v0)
  5a4c18:	14400015 	bnez	v0,0x5a4c70
  5a4c1c:	00000000 	nop
  5a4c20:	0c101f7c 	jal	0x407df0
  5a4c24:	02202021 	move	a0,s1
  5a4c28:	081692dc 	j	0x5a4b70
  5a4c2c:	00008021 	move	s0,zero
  5a4c30:	3c020075 	lui	v0,0x75
  5a4c34:	8c42cf58 	lw	v0,-12456(v0)
  5a4c38:	1040fff9 	beqz	v0,0x5a4c20
  5a4c3c:	00000000 	nop
  5a4c40:	0c16276a 	jal	0x589da8
  5a4c44:	00000000 	nop
  5a4c48:	1040fff5 	beqz	v0,0x5a4c20
  5a4c4c:	3c04006e 	lui	a0,0x6e
  5a4c50:	3c05006e 	lui	a1,0x6e
  5a4c54:	24847768 	addiu	a0,a0,30568
  5a4c58:	24a577f0 	addiu	a1,a1,30704
  5a4c5c:	240600d4 	li	a2,212
  5a4c60:	0c101b74 	jal	0x406dd0
  5a4c64:	00000000 	nop
  5a4c68:	08169308 	j	0x5a4c20
  5a4c6c:	00000000 	nop
  5a4c70:	0c16276a 	jal	0x589da8
  5a4c74:	00000000 	nop
  5a4c78:	1040ffe9 	beqz	v0,0x5a4c20
  5a4c7c:	3c04006e 	lui	a0,0x6e
  5a4c80:	3c05006e 	lui	a1,0x6e
  5a4c84:	24847738 	addiu	a0,a0,30520
  5a4c88:	24a577f0 	addiu	a1,a1,30704
  5a4c8c:	08169318 	j	0x5a4c60
  5a4c90:	240600cd 	li	a2,205

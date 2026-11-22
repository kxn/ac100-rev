; func cw_priv_trans_data_request_create @ 0x005c9b10 size=0x1ac
  5c9b10:	27bdffd8 	addiu	sp,sp,-40
  5c9b14:	2405000c 	li	a1,12
  5c9b18:	afb10020 	sw	s1,32(sp)
  5c9b1c:	afb0001c 	sw	s0,28(sp)
  5c9b20:	afbf0024 	sw	ra,36(sp)
  5c9b24:	0c15c8cc 	jal	0x572330
  5c9b28:	00808021 	move	s0,a0
  5c9b2c:	10400027 	beqz	v0,0x5c9bcc
  5c9b30:	00408821 	move	s1,v0
  5c9b34:	ac400008 	sw	zero,8(v0)
  5c9b38:	8e050004 	lw	a1,4(s0)
  5c9b3c:	50a00009 	beqzl	a1,0x5c9b64
  5c9b40:	8e250004 	lw	a1,4(s1)
  5c9b44:	8e040008 	lw	a0,8(s0)
  5c9b48:	1080003c 	beqz	a0,0x5c9c3c
  5c9b4c:	3c020075 	lui	v0,0x75
  5c9b50:	0c15c8cc 	jal	0x572330
  5c9b54:	30a5ffff 	andi	a1,a1,0xffff
  5c9b58:	1040003f 	beqz	v0,0x5c9c58
  5c9b5c:	ae220008 	sw	v0,8(s1)
  5c9b60:	8e250004 	lw	a1,4(s1)
  5c9b64:	24040014 	li	a0,20
  5c9b68:	02203021 	move	a2,s1
  5c9b6c:	24a50004 	addiu	a1,a1,4
  5c9b70:	0c15c943 	jal	0x57250c
  5c9b74:	30a5ffff 	andi	a1,a1,0xffff
  5c9b78:	10400007 	beqz	v0,0x5c9b98
  5c9b7c:	00408021 	move	s0,v0
  5c9b80:	8fbf0024 	lw	ra,36(sp)
  5c9b84:	02001021 	move	v0,s0
  5c9b88:	8fb10020 	lw	s1,32(sp)
  5c9b8c:	8fb0001c 	lw	s0,28(sp)
  5c9b90:	03e00008 	jr	ra
  5c9b94:	27bd0028 	addiu	sp,sp,40
  5c9b98:	3c020075 	lui	v0,0x75
  5c9b9c:	8c42cf58 	lw	v0,-12456(v0)
  5c9ba0:	1440001a 	bnez	v0,0x5c9c0c
  5c9ba4:	00000000 	nop
  5c9ba8:	8e240008 	lw	a0,8(s1)
  5c9bac:	10800003 	beqz	a0,0x5c9bbc
  5c9bb0:	00000000 	nop
  5c9bb4:	0c101f7c 	jal	0x407df0
  5c9bb8:	00000000 	nop
  5c9bbc:	0c101f7c 	jal	0x407df0
  5c9bc0:	02202021 	move	a0,s1
  5c9bc4:	081726e1 	j	0x5c9b84
  5c9bc8:	8fbf0024 	lw	ra,36(sp)
  5c9bcc:	3c020075 	lui	v0,0x75
  5c9bd0:	8c42cf58 	lw	v0,-12456(v0)
  5c9bd4:	1040ffea 	beqz	v0,0x5c9b80
  5c9bd8:	00008021 	move	s0,zero
  5c9bdc:	0c16276a 	jal	0x589da8
  5c9be0:	00000000 	nop
  5c9be4:	5040ffe7 	beqzl	v0,0x5c9b84
  5c9be8:	8fbf0024 	lw	ra,36(sp)
  5c9bec:	3c04006d 	lui	a0,0x6d
  5c9bf0:	3c05006f 	lui	a1,0x6f
  5c9bf4:	248434fc 	addiu	a0,a0,13564
  5c9bf8:	24a50e60 	addiu	a1,a1,3680
  5c9bfc:	0c101b74 	jal	0x406dd0
  5c9c00:	240600ba 	li	a2,186
  5c9c04:	081726e1 	j	0x5c9b84
  5c9c08:	8fbf0024 	lw	ra,36(sp)
  5c9c0c:	0c16276a 	jal	0x589da8
  5c9c10:	00000000 	nop
  5c9c14:	5040ffe5 	beqzl	v0,0x5c9bac
  5c9c18:	8e240008 	lw	a0,8(s1)
  5c9c1c:	3c04006d 	lui	a0,0x6d
  5c9c20:	3c05006f 	lui	a1,0x6f
  5c9c24:	248447f0 	addiu	a0,a0,18416
  5c9c28:	24a50e60 	addiu	a1,a1,3680
  5c9c2c:	0c101b74 	jal	0x406dd0
  5c9c30:	240600d5 	li	a2,213
  5c9c34:	081726eb 	j	0x5c9bac
  5c9c38:	8e240008 	lw	a0,8(s1)
  5c9c3c:	8c42cf58 	lw	v0,-12456(v0)
  5c9c40:	14400015 	bnez	v0,0x5c9c98
  5c9c44:	00000000 	nop
  5c9c48:	0c101f7c 	jal	0x407df0
  5c9c4c:	02202021 	move	a0,s1
  5c9c50:	081726e0 	j	0x5c9b80
  5c9c54:	00008021 	move	s0,zero
  5c9c58:	3c020075 	lui	v0,0x75
  5c9c5c:	8c42cf58 	lw	v0,-12456(v0)
  5c9c60:	1040fff9 	beqz	v0,0x5c9c48
  5c9c64:	00000000 	nop
  5c9c68:	0c16276a 	jal	0x589da8
  5c9c6c:	00000000 	nop
  5c9c70:	1040fff5 	beqz	v0,0x5c9c48
  5c9c74:	3c04006e 	lui	a0,0x6e
  5c9c78:	3c05006f 	lui	a1,0x6f
  5c9c7c:	24848050 	addiu	a0,a0,-32688
  5c9c80:	24a50e60 	addiu	a1,a1,3680
  5c9c84:	240600cb 	li	a2,203
  5c9c88:	0c101b74 	jal	0x406dd0
  5c9c8c:	00000000 	nop
  5c9c90:	08172712 	j	0x5c9c48
  5c9c94:	00000000 	nop
  5c9c98:	0c16276a 	jal	0x589da8
  5c9c9c:	00000000 	nop
  5c9ca0:	1040ffe9 	beqz	v0,0x5c9c48
  5c9ca4:	3c04006e 	lui	a0,0x6e
  5c9ca8:	3c05006f 	lui	a1,0x6f
  5c9cac:	248480d8 	addiu	a0,a0,-32552
  5c9cb0:	24a50e60 	addiu	a1,a1,3680
  5c9cb4:	08172722 	j	0x5c9c88
  5c9cb8:	240600c4 	li	a2,196

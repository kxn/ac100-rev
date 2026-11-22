; func cw_priv_sniffing_statistics_create @ 0x005c0acc size=0x20c
  5c0acc:	27bdffd8 	addiu	sp,sp,-40
  5c0ad0:	afb00018 	sw	s0,24(sp)
  5c0ad4:	afbf0024 	sw	ra,36(sp)
  5c0ad8:	afb20020 	sw	s2,32(sp)
  5c0adc:	afb1001c 	sw	s1,28(sp)
  5c0ae0:	8c820000 	lw	v0,0(a0)
  5c0ae4:	284301f5 	slti	v1,v0,501
  5c0ae8:	14600010 	bnez	v1,0x5c0b2c
  5c0aec:	00808021 	move	s0,a0
  5c0af0:	3c020075 	lui	v0,0x75
  5c0af4:	8c42cf58 	lw	v0,-12456(v0)
  5c0af8:	10400005 	beqz	v0,0x5c0b10
  5c0afc:	00009021 	move	s2,zero
  5c0b00:	0c16276a 	jal	0x589da8
  5c0b04:	00000000 	nop
  5c0b08:	14400032 	bnez	v0,0x5c0bd4
  5c0b0c:	3c04006f 	lui	a0,0x6f
  5c0b10:	8fbf0024 	lw	ra,36(sp)
  5c0b14:	02401021 	move	v0,s2
  5c0b18:	8fb20020 	lw	s2,32(sp)
  5c0b1c:	8fb1001c 	lw	s1,28(sp)
  5c0b20:	8fb00018 	lw	s0,24(sp)
  5c0b24:	03e00008 	jr	ra
  5c0b28:	27bd0028 	addiu	sp,sp,40
  5c0b2c:	18400004 	blez	v0,0x5c0b40
  5c0b30:	24050008 	li	a1,8
  5c0b34:	8c820004 	lw	v0,4(a0)
  5c0b38:	1040002e 	beqz	v0,0x5c0bf4
  5c0b3c:	3c020075 	lui	v0,0x75
  5c0b40:	0c15c8cc 	jal	0x572330
  5c0b44:	02002021 	move	a0,s0
  5c0b48:	10400037 	beqz	v0,0x5c0c28
  5c0b4c:	00408821 	move	s1,v0
  5c0b50:	ac400004 	sw	zero,4(v0)
  5c0b54:	8e020000 	lw	v0,0(s0)
  5c0b58:	18400009 	blez	v0,0x5c0b80
  5c0b5c:	00000000 	nop
  5c0b60:	8e040004 	lw	a0,4(s0)
  5c0b64:	10800006 	beqz	a0,0x5c0b80
  5c0b68:	24050014 	li	a1,20
  5c0b6c:	70452802 	mul	a1,v0,a1
  5c0b70:	0c15c8cc 	jal	0x572330
  5c0b74:	30a5fffc 	andi	a1,a1,0xfffc
  5c0b78:	1040003c 	beqz	v0,0x5c0c6c
  5c0b7c:	ae220004 	sw	v0,4(s1)
  5c0b80:	0c170120 	jal	0x5c0480
  5c0b84:	02202021 	move	a0,s1
  5c0b88:	2404006e 	li	a0,110
  5c0b8c:	00402821 	move	a1,v0
  5c0b90:	0c15c943 	jal	0x57250c
  5c0b94:	02203021 	move	a2,s1
  5c0b98:	1440ffdd 	bnez	v0,0x5c0b10
  5c0b9c:	00409021 	move	s2,v0
  5c0ba0:	3c020075 	lui	v0,0x75
  5c0ba4:	8c42cf58 	lw	v0,-12456(v0)
  5c0ba8:	14400041 	bnez	v0,0x5c0cb0
  5c0bac:	00000000 	nop
  5c0bb0:	8e240004 	lw	a0,4(s1)
  5c0bb4:	10800003 	beqz	a0,0x5c0bc4
  5c0bb8:	00000000 	nop
  5c0bbc:	0c101f7c 	jal	0x407df0
  5c0bc0:	00000000 	nop
  5c0bc4:	0c101f7c 	jal	0x407df0
  5c0bc8:	02202021 	move	a0,s1
  5c0bcc:	081702c4 	j	0x5c0b10
  5c0bd0:	00009021 	move	s2,zero
  5c0bd4:	8e070000 	lw	a3,0(s0)
  5c0bd8:	3c05006f 	lui	a1,0x6f
  5c0bdc:	24848880 	addiu	a0,a0,-30592
  5c0be0:	24a5f220 	addiu	a1,a1,-3552
  5c0be4:	0c101b74 	jal	0x406dd0
  5c0be8:	240600f8 	li	a2,248
  5c0bec:	081702c5 	j	0x5c0b14
  5c0bf0:	8fbf0024 	lw	ra,36(sp)
  5c0bf4:	8c42cf58 	lw	v0,-12456(v0)
  5c0bf8:	1040ffc5 	beqz	v0,0x5c0b10
  5c0bfc:	00009021 	move	s2,zero
  5c0c00:	0c16276a 	jal	0x589da8
  5c0c04:	00000000 	nop
  5c0c08:	5040ffc2 	beqzl	v0,0x5c0b14
  5c0c0c:	8fbf0024 	lw	ra,36(sp)
  5c0c10:	3c04006f 	lui	a0,0x6f
  5c0c14:	3c05006f 	lui	a1,0x6f
  5c0c18:	2484ad9c 	addiu	a0,a0,-21092
  5c0c1c:	24a5f220 	addiu	a1,a1,-3552
  5c0c20:	08170317 	j	0x5c0c5c
  5c0c24:	240600fe 	li	a2,254
  5c0c28:	3c020075 	lui	v0,0x75
  5c0c2c:	8c42cf58 	lw	v0,-12456(v0)
  5c0c30:	1040ffb7 	beqz	v0,0x5c0b10
  5c0c34:	00009021 	move	s2,zero
  5c0c38:	0c16276a 	jal	0x589da8
  5c0c3c:	00000000 	nop
  5c0c40:	5040ffb4 	beqzl	v0,0x5c0b14
  5c0c44:	8fbf0024 	lw	ra,36(sp)
  5c0c48:	3c04006d 	lui	a0,0x6d
  5c0c4c:	3c05006f 	lui	a1,0x6f
  5c0c50:	248434fc 	addiu	a0,a0,13564
  5c0c54:	24a5f220 	addiu	a1,a1,-3552
  5c0c58:	24060106 	li	a2,262
  5c0c5c:	0c101b74 	jal	0x406dd0
  5c0c60:	00000000 	nop
  5c0c64:	081702c5 	j	0x5c0b14
  5c0c68:	8fbf0024 	lw	ra,36(sp)
  5c0c6c:	3c020075 	lui	v0,0x75
  5c0c70:	8c42cf58 	lw	v0,-12456(v0)
  5c0c74:	5040ffcf 	beqzl	v0,0x5c0bb4
  5c0c78:	8e240004 	lw	a0,4(s1)
  5c0c7c:	0c16276a 	jal	0x589da8
  5c0c80:	00000000 	nop
  5c0c84:	5040ffcb 	beqzl	v0,0x5c0bb4
  5c0c88:	8e240004 	lw	a0,4(s1)
  5c0c8c:	3c04006f 	lui	a0,0x6f
  5c0c90:	3c05006f 	lui	a1,0x6f
  5c0c94:	2484adc8 	addiu	a0,a0,-21048
  5c0c98:	24a5f220 	addiu	a1,a1,-3552
  5c0c9c:	24060111 	li	a2,273
  5c0ca0:	0c101b74 	jal	0x406dd0
  5c0ca4:	00000000 	nop
  5c0ca8:	081702ed 	j	0x5c0bb4
  5c0cac:	8e240004 	lw	a0,4(s1)
  5c0cb0:	0c16276a 	jal	0x589da8
  5c0cb4:	00000000 	nop
  5c0cb8:	5040ffbe 	beqzl	v0,0x5c0bb4
  5c0cbc:	8e240004 	lw	a0,4(s1)
  5c0cc0:	3c04006d 	lui	a0,0x6d
  5c0cc4:	3c05006f 	lui	a1,0x6f
  5c0cc8:	248447f0 	addiu	a0,a0,18416
  5c0ccc:	24a5f220 	addiu	a1,a1,-3552
  5c0cd0:	08170328 	j	0x5c0ca0
  5c0cd4:	2406011a 	li	a2,282
	...

; func _uac_wsta_ap_disconnect @ 0x00632d78 size=0x108
  632d78:	27bdffd8 	addiu	sp,sp,-40
  632d7c:	afb10020 	sw	s1,32(sp)
  632d80:	00808821 	move	s1,a0
  632d84:	afb0001c 	sw	s0,28(sp)
  632d88:	afbf0024 	sw	ra,36(sp)
  632d8c:	8c82000c 	lw	v0,12(a0)
  632d90:	10400015 	beqz	v0,0x632de8
  632d94:	00008021 	move	s0,zero
  632d98:	24030003 	li	v1,3
  632d9c:	10430013 	beq	v0,v1,0x632dec
  632da0:	8fbf0024 	lw	ra,36(sp)
  632da4:	3c10007d 	lui	s0,0x7d
  632da8:	8e02c69c 	lw	v0,-14692(s0)
  632dac:	14400028 	bnez	v0,0x632e50
  632db0:	00000000 	nop
  632db4:	96240010 	lhu	a0,16(s1)
  632db8:	0c18cb01 	jal	0x632c04
  632dbc:	00002821 	move	a1,zero
  632dc0:	1040000f 	beqz	v0,0x632e00
  632dc4:	8e02c69c 	lw	v0,-14692(s0)
  632dc8:	3c020076 	lui	v0,0x76
  632dcc:	8c428bf4 	lw	v0,-29708(v0)
  632dd0:	10400005 	beqz	v0,0x632de8
  632dd4:	2410ffff 	li	s0,-1
  632dd8:	0c16276a 	jal	0x589da8
  632ddc:	00000000 	nop
  632de0:	14400013 	bnez	v0,0x632e30
  632de4:	3c040071 	lui	a0,0x71
  632de8:	8fbf0024 	lw	ra,36(sp)
  632dec:	02001021 	move	v0,s0
  632df0:	8fb10020 	lw	s1,32(sp)
  632df4:	8fb0001c 	lw	s0,28(sp)
  632df8:	03e00008 	jr	ra
  632dfc:	27bd0028 	addiu	sp,sp,40
  632e00:	1040fff9 	beqz	v0,0x632de8
  632e04:	00008021 	move	s0,zero
  632e08:	0c16276a 	jal	0x589da8
  632e0c:	00000000 	nop
  632e10:	5040fff6 	beqzl	v0,0x632dec
  632e14:	8fbf0024 	lw	ra,36(sp)
  632e18:	3c040071 	lui	a0,0x71
  632e1c:	3c050071 	lui	a1,0x71
  632e20:	2484d7f0 	addiu	a0,a0,-10256
  632e24:	24a5daf0 	addiu	a1,a1,-9488
  632e28:	0818cb90 	j	0x632e40
  632e2c:	240604e4 	li	a2,1252
  632e30:	3c050071 	lui	a1,0x71
  632e34:	2484d7b4 	addiu	a0,a0,-10316
  632e38:	24a5daf0 	addiu	a1,a1,-9488
  632e3c:	240604e1 	li	a2,1249
  632e40:	0c101b74 	jal	0x406dd0
  632e44:	00000000 	nop
  632e48:	0818cb7b 	j	0x632dec
  632e4c:	8fbf0024 	lw	ra,36(sp)
  632e50:	0c16276a 	jal	0x589da8
  632e54:	00000000 	nop
  632e58:	5040ffd7 	beqzl	v0,0x632db8
  632e5c:	96240010 	lhu	a0,16(s1)
  632e60:	3c040071 	lui	a0,0x71
  632e64:	3c050071 	lui	a1,0x71
  632e68:	2484d774 	addiu	a0,a0,-10380
  632e6c:	24a5daf0 	addiu	a1,a1,-9488
  632e70:	0c101b74 	jal	0x406dd0
  632e74:	240604dd 	li	a2,1245
  632e78:	0818cb6e 	j	0x632db8
  632e7c:	96240010 	lhu	a0,16(s1)

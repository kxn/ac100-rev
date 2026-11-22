; func cw_priv_region_list_create @ 0x005babb4 size=0x204
  5babb4:	3c02007c 	lui	v0,0x7c
  5babb8:	27bdffd8 	addiu	sp,sp,-40
  5babbc:	8c425988 	lw	v0,22920(v0)
  5babc0:	afb1001c 	sw	s1,28(sp)
  5babc4:	00808821 	move	s1,a0
  5babc8:	afbf0024 	sw	ra,36(sp)
  5babcc:	afb20020 	sw	s2,32(sp)
  5babd0:	14400023 	bnez	v0,0x5bac60
  5babd4:	afb00018 	sw	s0,24(sp)
  5babd8:	24050008 	li	a1,8
  5babdc:	0c15c8cc 	jal	0x572330
  5babe0:	02202021 	move	a0,s1
  5babe4:	10400038 	beqz	v0,0x5bacc8
  5babe8:	00408021 	move	s0,v0
  5babec:	ac400004 	sw	zero,4(v0)
  5babf0:	92220000 	lbu	v0,0(s1)
  5babf4:	1040000c 	beqz	v0,0x5bac28
  5babf8:	00009021 	move	s2,zero
  5babfc:	8e220004 	lw	v0,4(s1)
  5bac00:	1040004d 	beqz	v0,0x5bad38
  5bac04:	3c020075 	lui	v0,0x75
  5bac08:	0c16ea8e 	jal	0x5baa38
  5bac0c:	02202021 	move	a0,s1
  5bac10:	8e240004 	lw	a0,4(s1)
  5bac14:	3045ffff 	andi	a1,v0,0xffff
  5bac18:	0c15c8cc 	jal	0x572330
  5bac1c:	00409021 	move	s2,v0
  5bac20:	1040004c 	beqz	v0,0x5bad54
  5bac24:	ae020004 	sw	v0,4(s0)
  5bac28:	26450001 	addiu	a1,s2,1
  5bac2c:	24040097 	li	a0,151
  5bac30:	30a5ffff 	andi	a1,a1,0xffff
  5bac34:	0c15c943 	jal	0x57250c
  5bac38:	02003021 	move	a2,s0
  5bac3c:	10400014 	beqz	v0,0x5bac90
  5bac40:	00408821 	move	s1,v0
  5bac44:	8fbf0024 	lw	ra,36(sp)
  5bac48:	02201021 	move	v0,s1
  5bac4c:	8fb20020 	lw	s2,32(sp)
  5bac50:	8fb1001c 	lw	s1,28(sp)
  5bac54:	8fb00018 	lw	s0,24(sp)
  5bac58:	03e00008 	jr	ra
  5bac5c:	27bd0028 	addiu	sp,sp,40
  5bac60:	0c16276a 	jal	0x589da8
  5bac64:	00000000 	nop
  5bac68:	5040ffdc 	beqzl	v0,0x5babdc
  5bac6c:	24050008 	li	a1,8
  5bac70:	3c04006f 	lui	a0,0x6f
  5bac74:	3c05006f 	lui	a1,0x6f
  5bac78:	2484d7e4 	addiu	a0,a0,-10268
  5bac7c:	24a5d898 	addiu	a1,a1,-10088
  5bac80:	0c101b74 	jal	0x406dd0
  5bac84:	240600f9 	li	a2,249
  5bac88:	0816eaf7 	j	0x5babdc
  5bac8c:	24050008 	li	a1,8
  5bac90:	3c020075 	lui	v0,0x75
  5bac94:	8c42cf58 	lw	v0,-12456(v0)
  5bac98:	1440001b 	bnez	v0,0x5bad08
  5bac9c:	00000000 	nop
  5baca0:	8e040004 	lw	a0,4(s0)
  5baca4:	10800004 	beqz	a0,0x5bacb8
  5baca8:	00000000 	nop
  5bacac:	0c101f7c 	jal	0x407df0
  5bacb0:	00000000 	nop
  5bacb4:	ae000004 	sw	zero,4(s0)
  5bacb8:	0c101f7c 	jal	0x407df0
  5bacbc:	02002021 	move	a0,s0
  5bacc0:	0816eb12 	j	0x5bac48
  5bacc4:	8fbf0024 	lw	ra,36(sp)
  5bacc8:	3c020075 	lui	v0,0x75
  5baccc:	8c42cf58 	lw	v0,-12456(v0)
  5bacd0:	1040ffdc 	beqz	v0,0x5bac44
  5bacd4:	00008821 	move	s1,zero
  5bacd8:	0c16276a 	jal	0x589da8
  5bacdc:	00000000 	nop
  5bace0:	5040ffd9 	beqzl	v0,0x5bac48
  5bace4:	8fbf0024 	lw	ra,36(sp)
  5bace8:	3c04006d 	lui	a0,0x6d
  5bacec:	3c05006f 	lui	a1,0x6f
  5bacf0:	248434fc 	addiu	a0,a0,13564
  5bacf4:	24a5d898 	addiu	a1,a1,-10088
  5bacf8:	0c101b74 	jal	0x406dd0
  5bacfc:	24060103 	li	a2,259
  5bad00:	0816eb12 	j	0x5bac48
  5bad04:	8fbf0024 	lw	ra,36(sp)
  5bad08:	0c16276a 	jal	0x589da8
  5bad0c:	00000000 	nop
  5bad10:	5040ffe4 	beqzl	v0,0x5baca4
  5bad14:	8e040004 	lw	a0,4(s0)
  5bad18:	3c04006d 	lui	a0,0x6d
  5bad1c:	3c05006f 	lui	a1,0x6f
  5bad20:	24843580 	addiu	a0,a0,13696
  5bad24:	24a5d898 	addiu	a1,a1,-10088
  5bad28:	0c101b74 	jal	0x406dd0
  5bad2c:	24060122 	li	a2,290
  5bad30:	0816eb29 	j	0x5baca4
  5bad34:	8e040004 	lw	a0,4(s0)
  5bad38:	8c42cf58 	lw	v0,-12456(v0)
  5bad3c:	14400015 	bnez	v0,0x5bad94
  5bad40:	00000000 	nop
  5bad44:	0c101f7c 	jal	0x407df0
  5bad48:	02002021 	move	a0,s0
  5bad4c:	0816eb11 	j	0x5bac44
  5bad50:	00008821 	move	s1,zero
  5bad54:	3c020075 	lui	v0,0x75
  5bad58:	8c42cf58 	lw	v0,-12456(v0)
  5bad5c:	1040fff9 	beqz	v0,0x5bad44
  5bad60:	00000000 	nop
  5bad64:	0c16276a 	jal	0x589da8
  5bad68:	00000000 	nop
  5bad6c:	1040fff5 	beqz	v0,0x5bad44
  5bad70:	3c04006e 	lui	a0,0x6e
  5bad74:	3c05006f 	lui	a1,0x6f
  5bad78:	24848050 	addiu	a0,a0,-32688
  5bad7c:	24a5d898 	addiu	a1,a1,-10088
  5bad80:	24060118 	li	a2,280
  5bad84:	0c101b74 	jal	0x406dd0
  5bad88:	00000000 	nop
  5bad8c:	0816eb51 	j	0x5bad44
  5bad90:	00000000 	nop
  5bad94:	0c16276a 	jal	0x589da8
  5bad98:	00000000 	nop
  5bad9c:	1040ffe9 	beqz	v0,0x5bad44
  5bada0:	3c04006e 	lui	a0,0x6e
  5bada4:	3c05006f 	lui	a1,0x6f
  5bada8:	248480d8 	addiu	a0,a0,-32552
  5badac:	24a5d898 	addiu	a1,a1,-10088
  5badb0:	0816eb61 	j	0x5bad84
  5badb4:	2406010e 	li	a2,270

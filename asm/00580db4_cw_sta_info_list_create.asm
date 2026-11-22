; func cw_sta_info_list_create @ 0x00580db4 size=0x1b8
  580db4:	27bdffd8 	addiu	sp,sp,-40
  580db8:	24050010 	li	a1,16
  580dbc:	afb10020 	sw	s1,32(sp)
  580dc0:	afb0001c 	sw	s0,28(sp)
  580dc4:	afbf0024 	sw	ra,36(sp)
  580dc8:	0c15c8cc 	jal	0x572330
  580dcc:	00808021 	move	s0,a0
  580dd0:	1040002a 	beqz	v0,0x580e7c
  580dd4:	00408821 	move	s1,v0
  580dd8:	ac40000c 	sw	zero,12(v0)
  580ddc:	8e050008 	lw	a1,8(s0)
  580de0:	50a0000a 	beqzl	a1,0x580e0c
  580de4:	8e250008 	lw	a1,8(s1)
  580de8:	8e04000c 	lw	a0,12(s0)
  580dec:	1080003f 	beqz	a0,0x580eec
  580df0:	3c020075 	lui	v0,0x75
  580df4:	00052900 	sll	a1,a1,0x4
  580df8:	0c15c8cc 	jal	0x572330
  580dfc:	30a5fff0 	andi	a1,a1,0xfff0
  580e00:	10400041 	beqz	v0,0x580f08
  580e04:	ae22000c 	sw	v0,12(s1)
  580e08:	8e250008 	lw	a1,8(s1)
  580e0c:	2402000e 	li	v0,14
  580e10:	24040034 	li	a0,52
  580e14:	02203021 	move	a2,s1
  580e18:	70a22802 	mul	a1,a1,v0
  580e1c:	24a50009 	addiu	a1,a1,9
  580e20:	0c15c943 	jal	0x57250c
  580e24:	30a5ffff 	andi	a1,a1,0xffff
  580e28:	10400007 	beqz	v0,0x580e48
  580e2c:	00408021 	move	s0,v0
  580e30:	8fbf0024 	lw	ra,36(sp)
  580e34:	02001021 	move	v0,s0
  580e38:	8fb10020 	lw	s1,32(sp)
  580e3c:	8fb0001c 	lw	s0,28(sp)
  580e40:	03e00008 	jr	ra
  580e44:	27bd0028 	addiu	sp,sp,40
  580e48:	3c020075 	lui	v0,0x75
  580e4c:	8c42cf58 	lw	v0,-12456(v0)
  580e50:	1440001a 	bnez	v0,0x580ebc
  580e54:	00000000 	nop
  580e58:	8e24000c 	lw	a0,12(s1)
  580e5c:	10800003 	beqz	a0,0x580e6c
  580e60:	00000000 	nop
  580e64:	0c101f7c 	jal	0x407df0
  580e68:	00000000 	nop
  580e6c:	0c101f7c 	jal	0x407df0
  580e70:	02202021 	move	a0,s1
  580e74:	0816038d 	j	0x580e34
  580e78:	8fbf0024 	lw	ra,36(sp)
  580e7c:	3c020075 	lui	v0,0x75
  580e80:	8c42cf58 	lw	v0,-12456(v0)
  580e84:	1040ffea 	beqz	v0,0x580e30
  580e88:	00008021 	move	s0,zero
  580e8c:	0c16276a 	jal	0x589da8
  580e90:	00000000 	nop
  580e94:	5040ffe7 	beqzl	v0,0x580e34
  580e98:	8fbf0024 	lw	ra,36(sp)
  580e9c:	3c04006d 	lui	a0,0x6d
  580ea0:	3c05006e 	lui	a1,0x6e
  580ea4:	248434fc 	addiu	a0,a0,13564
  580ea8:	24a5bd70 	addiu	a1,a1,-17040
  580eac:	0c101b74 	jal	0x406dd0
  580eb0:	240600f0 	li	a2,240
  580eb4:	0816038d 	j	0x580e34
  580eb8:	8fbf0024 	lw	ra,36(sp)
  580ebc:	0c16276a 	jal	0x589da8
  580ec0:	00000000 	nop
  580ec4:	5040ffe5 	beqzl	v0,0x580e5c
  580ec8:	8e24000c 	lw	a0,12(s1)
  580ecc:	3c04006d 	lui	a0,0x6d
  580ed0:	3c05006e 	lui	a1,0x6e
  580ed4:	248447f0 	addiu	a0,a0,18416
  580ed8:	24a5bd70 	addiu	a1,a1,-17040
  580edc:	0c101b74 	jal	0x406dd0
  580ee0:	2406010b 	li	a2,267
  580ee4:	08160397 	j	0x580e5c
  580ee8:	8e24000c 	lw	a0,12(s1)
  580eec:	8c42cf58 	lw	v0,-12456(v0)
  580ef0:	14400015 	bnez	v0,0x580f48
  580ef4:	00000000 	nop
  580ef8:	0c101f7c 	jal	0x407df0
  580efc:	02202021 	move	a0,s1
  580f00:	0816038c 	j	0x580e30
  580f04:	00008021 	move	s0,zero
  580f08:	3c020075 	lui	v0,0x75
  580f0c:	8c42cf58 	lw	v0,-12456(v0)
  580f10:	1040fff9 	beqz	v0,0x580ef8
  580f14:	00000000 	nop
  580f18:	0c16276a 	jal	0x589da8
  580f1c:	00000000 	nop
  580f20:	1040fff5 	beqz	v0,0x580ef8
  580f24:	3c04006e 	lui	a0,0x6e
  580f28:	3c05006e 	lui	a1,0x6e
  580f2c:	2484bcf0 	addiu	a0,a0,-17168
  580f30:	24a5bd70 	addiu	a1,a1,-17040
  580f34:	24060101 	li	a2,257
  580f38:	0c101b74 	jal	0x406dd0
  580f3c:	00000000 	nop
  580f40:	081603be 	j	0x580ef8
  580f44:	00000000 	nop
  580f48:	0c16276a 	jal	0x589da8
  580f4c:	00000000 	nop
  580f50:	1040ffe9 	beqz	v0,0x580ef8
  580f54:	3c04006e 	lui	a0,0x6e
  580f58:	3c05006e 	lui	a1,0x6e
  580f5c:	2484bcc8 	addiu	a0,a0,-17208
  580f60:	24a5bd70 	addiu	a1,a1,-17040
  580f64:	081603ce 	j	0x580f38
  580f68:	240600fa 	li	a2,250

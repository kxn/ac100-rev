; func cw_priv_lldp_create @ 0x005b4d94 size=0xdc
  5b4d94:	27bdffd8 	addiu	sp,sp,-40
  5b4d98:	24050004 	li	a1,4
  5b4d9c:	afb0001c 	sw	s0,28(sp)
  5b4da0:	afbf0024 	sw	ra,36(sp)
  5b4da4:	0c15c8cc 	jal	0x572330
  5b4da8:	afb10020 	sw	s1,32(sp)
  5b4dac:	1040000d 	beqz	v0,0x5b4de4
  5b4db0:	00408021 	move	s0,v0
  5b4db4:	24040067 	li	a0,103
  5b4db8:	24050004 	li	a1,4
  5b4dbc:	0c15c943 	jal	0x57250c
  5b4dc0:	00403021 	move	a2,v0
  5b4dc4:	10400017 	beqz	v0,0x5b4e24
  5b4dc8:	00408821 	move	s1,v0
  5b4dcc:	8fbf0024 	lw	ra,36(sp)
  5b4dd0:	02201021 	move	v0,s1
  5b4dd4:	8fb10020 	lw	s1,32(sp)
  5b4dd8:	8fb0001c 	lw	s0,28(sp)
  5b4ddc:	03e00008 	jr	ra
  5b4de0:	27bd0028 	addiu	sp,sp,40
  5b4de4:	3c020075 	lui	v0,0x75
  5b4de8:	8c42cf58 	lw	v0,-12456(v0)
  5b4dec:	1040fff7 	beqz	v0,0x5b4dcc
  5b4df0:	00008821 	move	s1,zero
  5b4df4:	0c16276a 	jal	0x589da8
  5b4df8:	00000000 	nop
  5b4dfc:	5040fff4 	beqzl	v0,0x5b4dd0
  5b4e00:	8fbf0024 	lw	ra,36(sp)
  5b4e04:	3c04006d 	lui	a0,0x6d
  5b4e08:	3c05006f 	lui	a1,0x6f
  5b4e0c:	248434fc 	addiu	a0,a0,13564
  5b4e10:	24a5c170 	addiu	a1,a1,-16016
  5b4e14:	0c101b74 	jal	0x406dd0
  5b4e18:	240600a1 	li	a2,161
  5b4e1c:	0816d374 	j	0x5b4dd0
  5b4e20:	8fbf0024 	lw	ra,36(sp)
  5b4e24:	3c020075 	lui	v0,0x75
  5b4e28:	8c42cf58 	lw	v0,-12456(v0)
  5b4e2c:	14400005 	bnez	v0,0x5b4e44
  5b4e30:	00000000 	nop
  5b4e34:	0c101f7c 	jal	0x407df0
  5b4e38:	02002021 	move	a0,s0
  5b4e3c:	0816d374 	j	0x5b4dd0
  5b4e40:	8fbf0024 	lw	ra,36(sp)
  5b4e44:	0c16276a 	jal	0x589da8
  5b4e48:	00000000 	nop
  5b4e4c:	1040fff9 	beqz	v0,0x5b4e34
  5b4e50:	3c04006d 	lui	a0,0x6d
  5b4e54:	3c05006f 	lui	a1,0x6f
  5b4e58:	248447f0 	addiu	a0,a0,18416
  5b4e5c:	24a5c170 	addiu	a1,a1,-16016
  5b4e60:	0c101b74 	jal	0x406dd0
  5b4e64:	240600aa 	li	a2,170
  5b4e68:	0816d38d 	j	0x5b4e34
  5b4e6c:	00000000 	nop

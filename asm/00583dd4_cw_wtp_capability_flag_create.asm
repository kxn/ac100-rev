; func cw_wtp_capability_flag_create @ 0x00583dd4 size=0xdc
  583dd4:	27bdffd8 	addiu	sp,sp,-40
  583dd8:	24050010 	li	a1,16
  583ddc:	afb0001c 	sw	s0,28(sp)
  583de0:	afbf0024 	sw	ra,36(sp)
  583de4:	0c15c8cc 	jal	0x572330
  583de8:	afb10020 	sw	s1,32(sp)
  583dec:	1040000d 	beqz	v0,0x583e24
  583df0:	00408021 	move	s0,v0
  583df4:	24040032 	li	a0,50
  583df8:	24050010 	li	a1,16
  583dfc:	0c15c943 	jal	0x57250c
  583e00:	00403021 	move	a2,v0
  583e04:	10400017 	beqz	v0,0x583e64
  583e08:	00408821 	move	s1,v0
  583e0c:	8fbf0024 	lw	ra,36(sp)
  583e10:	02201021 	move	v0,s1
  583e14:	8fb10020 	lw	s1,32(sp)
  583e18:	8fb0001c 	lw	s0,28(sp)
  583e1c:	03e00008 	jr	ra
  583e20:	27bd0028 	addiu	sp,sp,40
  583e24:	3c020075 	lui	v0,0x75
  583e28:	8c42cf58 	lw	v0,-12456(v0)
  583e2c:	1040fff7 	beqz	v0,0x583e0c
  583e30:	00008821 	move	s1,zero
  583e34:	0c16276a 	jal	0x589da8
  583e38:	00000000 	nop
  583e3c:	5040fff4 	beqzl	v0,0x583e10
  583e40:	8fbf0024 	lw	ra,36(sp)
  583e44:	3c04006d 	lui	a0,0x6d
  583e48:	3c05006e 	lui	a1,0x6e
  583e4c:	248434fc 	addiu	a0,a0,13564
  583e50:	24a5c870 	addiu	a1,a1,-14224
  583e54:	0c101b74 	jal	0x406dd0
  583e58:	240600ac 	li	a2,172
  583e5c:	08160f84 	j	0x583e10
  583e60:	8fbf0024 	lw	ra,36(sp)
  583e64:	3c020075 	lui	v0,0x75
  583e68:	8c42cf58 	lw	v0,-12456(v0)
  583e6c:	14400005 	bnez	v0,0x583e84
  583e70:	00000000 	nop
  583e74:	0c101f7c 	jal	0x407df0
  583e78:	02002021 	move	a0,s0
  583e7c:	08160f84 	j	0x583e10
  583e80:	8fbf0024 	lw	ra,36(sp)
  583e84:	0c16276a 	jal	0x589da8
  583e88:	00000000 	nop
  583e8c:	1040fff9 	beqz	v0,0x583e74
  583e90:	3c04006d 	lui	a0,0x6d
  583e94:	3c05006e 	lui	a1,0x6e
  583e98:	248447f0 	addiu	a0,a0,18416
  583e9c:	24a5c870 	addiu	a1,a1,-14224
  583ea0:	0c101b74 	jal	0x406dd0
  583ea4:	240600b4 	li	a2,180
  583ea8:	08160f9d 	j	0x583e74
  583eac:	00000000 	nop

; func cw_priv_ac_info_create @ 0x005a2cd8 size=0xdc
  5a2cd8:	27bdffd8 	addiu	sp,sp,-40
  5a2cdc:	24050006 	li	a1,6
  5a2ce0:	afb0001c 	sw	s0,28(sp)
  5a2ce4:	afbf0024 	sw	ra,36(sp)
  5a2ce8:	0c15c8cc 	jal	0x572330
  5a2cec:	afb10020 	sw	s1,32(sp)
  5a2cf0:	1040000d 	beqz	v0,0x5a2d28
  5a2cf4:	00408021 	move	s0,v0
  5a2cf8:	2404001b 	li	a0,27
  5a2cfc:	24050006 	li	a1,6
  5a2d00:	0c15c943 	jal	0x57250c
  5a2d04:	00403021 	move	a2,v0
  5a2d08:	10400017 	beqz	v0,0x5a2d68
  5a2d0c:	00408821 	move	s1,v0
  5a2d10:	8fbf0024 	lw	ra,36(sp)
  5a2d14:	02201021 	move	v0,s1
  5a2d18:	8fb10020 	lw	s1,32(sp)
  5a2d1c:	8fb0001c 	lw	s0,28(sp)
  5a2d20:	03e00008 	jr	ra
  5a2d24:	27bd0028 	addiu	sp,sp,40
  5a2d28:	3c020075 	lui	v0,0x75
  5a2d2c:	8c42cf58 	lw	v0,-12456(v0)
  5a2d30:	1040fff7 	beqz	v0,0x5a2d10
  5a2d34:	00008821 	move	s1,zero
  5a2d38:	0c16276a 	jal	0x589da8
  5a2d3c:	00000000 	nop
  5a2d40:	5040fff4 	beqzl	v0,0x5a2d14
  5a2d44:	8fbf0024 	lw	ra,36(sp)
  5a2d48:	3c04006d 	lui	a0,0x6d
  5a2d4c:	3c05006e 	lui	a1,0x6e
  5a2d50:	248434fc 	addiu	a0,a0,13564
  5a2d54:	24a56d20 	addiu	a1,a1,27936
  5a2d58:	0c101b74 	jal	0x406dd0
  5a2d5c:	240600a5 	li	a2,165
  5a2d60:	08168b45 	j	0x5a2d14
  5a2d64:	8fbf0024 	lw	ra,36(sp)
  5a2d68:	3c020075 	lui	v0,0x75
  5a2d6c:	8c42cf58 	lw	v0,-12456(v0)
  5a2d70:	14400005 	bnez	v0,0x5a2d88
  5a2d74:	00000000 	nop
  5a2d78:	0c101f7c 	jal	0x407df0
  5a2d7c:	02002021 	move	a0,s0
  5a2d80:	08168b45 	j	0x5a2d14
  5a2d84:	8fbf0024 	lw	ra,36(sp)
  5a2d88:	0c16276a 	jal	0x589da8
  5a2d8c:	00000000 	nop
  5a2d90:	1040fff9 	beqz	v0,0x5a2d78
  5a2d94:	3c04006d 	lui	a0,0x6d
  5a2d98:	3c05006e 	lui	a1,0x6e
  5a2d9c:	248447f0 	addiu	a0,a0,18416
  5a2da0:	24a56d20 	addiu	a1,a1,27936
  5a2da4:	0c101b74 	jal	0x406dd0
  5a2da8:	240600ad 	li	a2,173
  5a2dac:	08168b5e 	j	0x5a2d78
  5a2db0:	00000000 	nop

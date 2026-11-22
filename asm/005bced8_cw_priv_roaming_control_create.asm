; func cw_priv_roaming_control_create @ 0x005bced8 size=0xdc
  5bced8:	27bdffd8 	addiu	sp,sp,-40
  5bcedc:	24050024 	li	a1,36
  5bcee0:	afb0001c 	sw	s0,28(sp)
  5bcee4:	afbf0024 	sw	ra,36(sp)
  5bcee8:	0c15c8cc 	jal	0x572330
  5bceec:	afb10020 	sw	s1,32(sp)
  5bcef0:	1040000d 	beqz	v0,0x5bcf28
  5bcef4:	00408021 	move	s0,v0
  5bcef8:	24040057 	li	a0,87
  5bcefc:	24050024 	li	a1,36
  5bcf00:	0c15c943 	jal	0x57250c
  5bcf04:	00403021 	move	a2,v0
  5bcf08:	10400017 	beqz	v0,0x5bcf68
  5bcf0c:	00408821 	move	s1,v0
  5bcf10:	8fbf0024 	lw	ra,36(sp)
  5bcf14:	02201021 	move	v0,s1
  5bcf18:	8fb10020 	lw	s1,32(sp)
  5bcf1c:	8fb0001c 	lw	s0,28(sp)
  5bcf20:	03e00008 	jr	ra
  5bcf24:	27bd0028 	addiu	sp,sp,40
  5bcf28:	3c020075 	lui	v0,0x75
  5bcf2c:	8c42cf58 	lw	v0,-12456(v0)
  5bcf30:	1040fff7 	beqz	v0,0x5bcf10
  5bcf34:	00008821 	move	s1,zero
  5bcf38:	0c16276a 	jal	0x589da8
  5bcf3c:	00000000 	nop
  5bcf40:	5040fff4 	beqzl	v0,0x5bcf14
  5bcf44:	8fbf0024 	lw	ra,36(sp)
  5bcf48:	3c04006d 	lui	a0,0x6d
  5bcf4c:	3c05006f 	lui	a1,0x6f
  5bcf50:	248434fc 	addiu	a0,a0,13564
  5bcf54:	24a5e2f0 	addiu	a1,a1,-7440
  5bcf58:	0c101b74 	jal	0x406dd0
  5bcf5c:	240600e1 	li	a2,225
  5bcf60:	0816f3c5 	j	0x5bcf14
  5bcf64:	8fbf0024 	lw	ra,36(sp)
  5bcf68:	3c020075 	lui	v0,0x75
  5bcf6c:	8c42cf58 	lw	v0,-12456(v0)
  5bcf70:	14400005 	bnez	v0,0x5bcf88
  5bcf74:	00000000 	nop
  5bcf78:	0c101f7c 	jal	0x407df0
  5bcf7c:	02002021 	move	a0,s0
  5bcf80:	0816f3c5 	j	0x5bcf14
  5bcf84:	8fbf0024 	lw	ra,36(sp)
  5bcf88:	0c16276a 	jal	0x589da8
  5bcf8c:	00000000 	nop
  5bcf90:	1040fff9 	beqz	v0,0x5bcf78
  5bcf94:	3c04006d 	lui	a0,0x6d
  5bcf98:	3c05006f 	lui	a1,0x6f
  5bcf9c:	248447f0 	addiu	a0,a0,18416
  5bcfa0:	24a5e2f0 	addiu	a1,a1,-7440
  5bcfa4:	0c101b74 	jal	0x406dd0
  5bcfa8:	240600e9 	li	a2,233
  5bcfac:	0816f3de 	j	0x5bcf78
  5bcfb0:	00000000 	nop
	...

; func cw_priv_ap_offline_mngr_create @ 0x005a6c98 size=0xdc
  5a6c98:	27bdffd8 	addiu	sp,sp,-40
  5a6c9c:	24050018 	li	a1,24
  5a6ca0:	afb0001c 	sw	s0,28(sp)
  5a6ca4:	afbf0024 	sw	ra,36(sp)
  5a6ca8:	0c15c8cc 	jal	0x572330
  5a6cac:	afb10020 	sw	s1,32(sp)
  5a6cb0:	1040000d 	beqz	v0,0x5a6ce8
  5a6cb4:	00408021 	move	s0,v0
  5a6cb8:	2404003c 	li	a0,60
  5a6cbc:	24050018 	li	a1,24
  5a6cc0:	0c15c943 	jal	0x57250c
  5a6cc4:	00403021 	move	a2,v0
  5a6cc8:	10400017 	beqz	v0,0x5a6d28
  5a6ccc:	00408821 	move	s1,v0
  5a6cd0:	8fbf0024 	lw	ra,36(sp)
  5a6cd4:	02201021 	move	v0,s1
  5a6cd8:	8fb10020 	lw	s1,32(sp)
  5a6cdc:	8fb0001c 	lw	s0,28(sp)
  5a6ce0:	03e00008 	jr	ra
  5a6ce4:	27bd0028 	addiu	sp,sp,40
  5a6ce8:	3c020075 	lui	v0,0x75
  5a6cec:	8c42cf58 	lw	v0,-12456(v0)
  5a6cf0:	1040fff7 	beqz	v0,0x5a6cd0
  5a6cf4:	00008821 	move	s1,zero
  5a6cf8:	0c16276a 	jal	0x589da8
  5a6cfc:	00000000 	nop
  5a6d00:	5040fff4 	beqzl	v0,0x5a6cd4
  5a6d04:	8fbf0024 	lw	ra,36(sp)
  5a6d08:	3c04006d 	lui	a0,0x6d
  5a6d0c:	3c05006f 	lui	a1,0x6f
  5a6d10:	248434fc 	addiu	a0,a0,13564
  5a6d14:	24a580e0 	addiu	a1,a1,-32544
  5a6d18:	0c101b74 	jal	0x406dd0
  5a6d1c:	240600b6 	li	a2,182
  5a6d20:	08169b35 	j	0x5a6cd4
  5a6d24:	8fbf0024 	lw	ra,36(sp)
  5a6d28:	3c020075 	lui	v0,0x75
  5a6d2c:	8c42cf58 	lw	v0,-12456(v0)
  5a6d30:	14400005 	bnez	v0,0x5a6d48
  5a6d34:	00000000 	nop
  5a6d38:	0c101f7c 	jal	0x407df0
  5a6d3c:	02002021 	move	a0,s0
  5a6d40:	08169b35 	j	0x5a6cd4
  5a6d44:	8fbf0024 	lw	ra,36(sp)
  5a6d48:	0c16276a 	jal	0x589da8
  5a6d4c:	00000000 	nop
  5a6d50:	1040fff9 	beqz	v0,0x5a6d38
  5a6d54:	3c04006d 	lui	a0,0x6d
  5a6d58:	3c05006f 	lui	a1,0x6f
  5a6d5c:	248447f0 	addiu	a0,a0,18416
  5a6d60:	24a580e0 	addiu	a1,a1,-32544
  5a6d64:	0c101b74 	jal	0x406dd0
  5a6d68:	240600be 	li	a2,190
  5a6d6c:	08169b4e 	j	0x5a6d38
  5a6d70:	00000000 	nop
	...

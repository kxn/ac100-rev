; func cw_priv_spec_msg_sw_create @ 0x005c0e34 size=0xdc
  5c0e34:	27bdffd8 	addiu	sp,sp,-40
  5c0e38:	24050008 	li	a1,8
  5c0e3c:	afb0001c 	sw	s0,28(sp)
  5c0e40:	afbf0024 	sw	ra,36(sp)
  5c0e44:	0c15c8cc 	jal	0x572330
  5c0e48:	afb10020 	sw	s1,32(sp)
  5c0e4c:	1040000d 	beqz	v0,0x5c0e84
  5c0e50:	00408021 	move	s0,v0
  5c0e54:	24040026 	li	a0,38
  5c0e58:	24050008 	li	a1,8
  5c0e5c:	0c15c943 	jal	0x57250c
  5c0e60:	00403021 	move	a2,v0
  5c0e64:	10400017 	beqz	v0,0x5c0ec4
  5c0e68:	00408821 	move	s1,v0
  5c0e6c:	8fbf0024 	lw	ra,36(sp)
  5c0e70:	02201021 	move	v0,s1
  5c0e74:	8fb10020 	lw	s1,32(sp)
  5c0e78:	8fb0001c 	lw	s0,28(sp)
  5c0e7c:	03e00008 	jr	ra
  5c0e80:	27bd0028 	addiu	sp,sp,40
  5c0e84:	3c020075 	lui	v0,0x75
  5c0e88:	8c42cf58 	lw	v0,-12456(v0)
  5c0e8c:	1040fff7 	beqz	v0,0x5c0e6c
  5c0e90:	00008821 	move	s1,zero
  5c0e94:	0c16276a 	jal	0x589da8
  5c0e98:	00000000 	nop
  5c0e9c:	5040fff4 	beqzl	v0,0x5c0e70
  5c0ea0:	8fbf0024 	lw	ra,36(sp)
  5c0ea4:	3c04006d 	lui	a0,0x6d
  5c0ea8:	3c05006f 	lui	a1,0x6f
  5c0eac:	248434fc 	addiu	a0,a0,13564
  5c0eb0:	24a5f350 	addiu	a1,a1,-3248
  5c0eb4:	0c101b74 	jal	0x406dd0
  5c0eb8:	240600a6 	li	a2,166
  5c0ebc:	0817039c 	j	0x5c0e70
  5c0ec0:	8fbf0024 	lw	ra,36(sp)
  5c0ec4:	3c020075 	lui	v0,0x75
  5c0ec8:	8c42cf58 	lw	v0,-12456(v0)
  5c0ecc:	14400005 	bnez	v0,0x5c0ee4
  5c0ed0:	00000000 	nop
  5c0ed4:	0c101f7c 	jal	0x407df0
  5c0ed8:	02002021 	move	a0,s0
  5c0edc:	0817039c 	j	0x5c0e70
  5c0ee0:	8fbf0024 	lw	ra,36(sp)
  5c0ee4:	0c16276a 	jal	0x589da8
  5c0ee8:	00000000 	nop
  5c0eec:	1040fff9 	beqz	v0,0x5c0ed4
  5c0ef0:	3c04006d 	lui	a0,0x6d
  5c0ef4:	3c05006f 	lui	a1,0x6f
  5c0ef8:	248447f0 	addiu	a0,a0,18416
  5c0efc:	24a5f350 	addiu	a1,a1,-3248
  5c0f00:	0c101b74 	jal	0x406dd0
  5c0f04:	240600ae 	li	a2,174
  5c0f08:	081703b5 	j	0x5c0ed4
  5c0f0c:	00000000 	nop

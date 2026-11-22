; func cw_priv_ap_11ac_rate_create @ 0x005a3c2c size=0xdc
  5a3c2c:	27bdffd8 	addiu	sp,sp,-40
  5a3c30:	24050004 	li	a1,4
  5a3c34:	afb0001c 	sw	s0,28(sp)
  5a3c38:	afbf0024 	sw	ra,36(sp)
  5a3c3c:	0c15c8cc 	jal	0x572330
  5a3c40:	afb10020 	sw	s1,32(sp)
  5a3c44:	1040000d 	beqz	v0,0x5a3c7c
  5a3c48:	00408021 	move	s0,v0
  5a3c4c:	2404002b 	li	a0,43
  5a3c50:	24050004 	li	a1,4
  5a3c54:	0c15c943 	jal	0x57250c
  5a3c58:	00403021 	move	a2,v0
  5a3c5c:	10400017 	beqz	v0,0x5a3cbc
  5a3c60:	00408821 	move	s1,v0
  5a3c64:	8fbf0024 	lw	ra,36(sp)
  5a3c68:	02201021 	move	v0,s1
  5a3c6c:	8fb10020 	lw	s1,32(sp)
  5a3c70:	8fb0001c 	lw	s0,28(sp)
  5a3c74:	03e00008 	jr	ra
  5a3c78:	27bd0028 	addiu	sp,sp,40
  5a3c7c:	3c020075 	lui	v0,0x75
  5a3c80:	8c42cf58 	lw	v0,-12456(v0)
  5a3c84:	1040fff7 	beqz	v0,0x5a3c64
  5a3c88:	00008821 	move	s1,zero
  5a3c8c:	0c16276a 	jal	0x589da8
  5a3c90:	00000000 	nop
  5a3c94:	5040fff4 	beqzl	v0,0x5a3c68
  5a3c98:	8fbf0024 	lw	ra,36(sp)
  5a3c9c:	3c04006d 	lui	a0,0x6d
  5a3ca0:	3c05006e 	lui	a1,0x6e
  5a3ca4:	248434fc 	addiu	a0,a0,13564
  5a3ca8:	24a57210 	addiu	a1,a1,29200
  5a3cac:	0c101b74 	jal	0x406dd0
  5a3cb0:	240600b8 	li	a2,184
  5a3cb4:	08168f1a 	j	0x5a3c68
  5a3cb8:	8fbf0024 	lw	ra,36(sp)
  5a3cbc:	3c020075 	lui	v0,0x75
  5a3cc0:	8c42cf58 	lw	v0,-12456(v0)
  5a3cc4:	14400005 	bnez	v0,0x5a3cdc
  5a3cc8:	00000000 	nop
  5a3ccc:	0c101f7c 	jal	0x407df0
  5a3cd0:	02002021 	move	a0,s0
  5a3cd4:	08168f1a 	j	0x5a3c68
  5a3cd8:	8fbf0024 	lw	ra,36(sp)
  5a3cdc:	0c16276a 	jal	0x589da8
  5a3ce0:	00000000 	nop
  5a3ce4:	1040fff9 	beqz	v0,0x5a3ccc
  5a3ce8:	3c04006d 	lui	a0,0x6d
  5a3cec:	3c05006e 	lui	a1,0x6e
  5a3cf0:	248447f0 	addiu	a0,a0,18416
  5a3cf4:	24a57210 	addiu	a1,a1,29200
  5a3cf8:	0c101b74 	jal	0x406dd0
  5a3cfc:	240600c0 	li	a2,192
  5a3d00:	08168f33 	j	0x5a3ccc
  5a3d04:	00000000 	nop
	...

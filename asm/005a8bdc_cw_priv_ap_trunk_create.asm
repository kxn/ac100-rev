; func cw_priv_ap_trunk_create @ 0x005a8bdc size=0xdc
  5a8bdc:	27bdffd8 	addiu	sp,sp,-40
  5a8be0:	24050004 	li	a1,4
  5a8be4:	afb0001c 	sw	s0,28(sp)
  5a8be8:	afbf0024 	sw	ra,36(sp)
  5a8bec:	0c15c8cc 	jal	0x572330
  5a8bf0:	afb10020 	sw	s1,32(sp)
  5a8bf4:	1040000d 	beqz	v0,0x5a8c2c
  5a8bf8:	00408021 	move	s0,v0
  5a8bfc:	24040044 	li	a0,68
  5a8c00:	24050004 	li	a1,4
  5a8c04:	0c15c943 	jal	0x57250c
  5a8c08:	00403021 	move	a2,v0
  5a8c0c:	10400017 	beqz	v0,0x5a8c6c
  5a8c10:	00408821 	move	s1,v0
  5a8c14:	8fbf0024 	lw	ra,36(sp)
  5a8c18:	02201021 	move	v0,s1
  5a8c1c:	8fb10020 	lw	s1,32(sp)
  5a8c20:	8fb0001c 	lw	s0,28(sp)
  5a8c24:	03e00008 	jr	ra
  5a8c28:	27bd0028 	addiu	sp,sp,40
  5a8c2c:	3c020075 	lui	v0,0x75
  5a8c30:	8c42cf58 	lw	v0,-12456(v0)
  5a8c34:	1040fff7 	beqz	v0,0x5a8c14
  5a8c38:	00008821 	move	s1,zero
  5a8c3c:	0c16276a 	jal	0x589da8
  5a8c40:	00000000 	nop
  5a8c44:	5040fff4 	beqzl	v0,0x5a8c18
  5a8c48:	8fbf0024 	lw	ra,36(sp)
  5a8c4c:	3c04006d 	lui	a0,0x6d
  5a8c50:	3c05006f 	lui	a1,0x6f
  5a8c54:	248434fc 	addiu	a0,a0,13564
  5a8c58:	24a58b80 	addiu	a1,a1,-29824
  5a8c5c:	0c101b74 	jal	0x406dd0
  5a8c60:	2406009e 	li	a2,158
  5a8c64:	0816a306 	j	0x5a8c18
  5a8c68:	8fbf0024 	lw	ra,36(sp)
  5a8c6c:	3c020075 	lui	v0,0x75
  5a8c70:	8c42cf58 	lw	v0,-12456(v0)
  5a8c74:	14400005 	bnez	v0,0x5a8c8c
  5a8c78:	00000000 	nop
  5a8c7c:	0c101f7c 	jal	0x407df0
  5a8c80:	02002021 	move	a0,s0
  5a8c84:	0816a306 	j	0x5a8c18
  5a8c88:	8fbf0024 	lw	ra,36(sp)
  5a8c8c:	0c16276a 	jal	0x589da8
  5a8c90:	00000000 	nop
  5a8c94:	1040fff9 	beqz	v0,0x5a8c7c
  5a8c98:	3c04006d 	lui	a0,0x6d
  5a8c9c:	3c05006f 	lui	a1,0x6f
  5a8ca0:	248447f0 	addiu	a0,a0,18416
  5a8ca4:	24a58b80 	addiu	a1,a1,-29824
  5a8ca8:	0c101b74 	jal	0x406dd0
  5a8cac:	240600a6 	li	a2,166
  5a8cb0:	0816a31f 	j	0x5a8c7c
  5a8cb4:	00000000 	nop

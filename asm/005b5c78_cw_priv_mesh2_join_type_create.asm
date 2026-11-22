; func cw_priv_mesh2_join_type_create @ 0x005b5c78 size=0xdc
  5b5c78:	27bdffd8 	addiu	sp,sp,-40
  5b5c7c:	24050004 	li	a1,4
  5b5c80:	afb0001c 	sw	s0,28(sp)
  5b5c84:	afbf0024 	sw	ra,36(sp)
  5b5c88:	0c15c8cc 	jal	0x572330
  5b5c8c:	afb10020 	sw	s1,32(sp)
  5b5c90:	1040000d 	beqz	v0,0x5b5cc8
  5b5c94:	00408021 	move	s0,v0
  5b5c98:	2404009a 	li	a0,154
  5b5c9c:	24050004 	li	a1,4
  5b5ca0:	0c15c943 	jal	0x57250c
  5b5ca4:	00403021 	move	a2,v0
  5b5ca8:	10400017 	beqz	v0,0x5b5d08
  5b5cac:	00408821 	move	s1,v0
  5b5cb0:	8fbf0024 	lw	ra,36(sp)
  5b5cb4:	02201021 	move	v0,s1
  5b5cb8:	8fb10020 	lw	s1,32(sp)
  5b5cbc:	8fb0001c 	lw	s0,28(sp)
  5b5cc0:	03e00008 	jr	ra
  5b5cc4:	27bd0028 	addiu	sp,sp,40
  5b5cc8:	3c020075 	lui	v0,0x75
  5b5ccc:	8c42cf58 	lw	v0,-12456(v0)
  5b5cd0:	1040fff7 	beqz	v0,0x5b5cb0
  5b5cd4:	00008821 	move	s1,zero
  5b5cd8:	0c16276a 	jal	0x589da8
  5b5cdc:	00000000 	nop
  5b5ce0:	5040fff4 	beqzl	v0,0x5b5cb4
  5b5ce4:	8fbf0024 	lw	ra,36(sp)
  5b5ce8:	3c04006d 	lui	a0,0x6d
  5b5cec:	3c05006f 	lui	a1,0x6f
  5b5cf0:	248434fc 	addiu	a0,a0,13564
  5b5cf4:	24a5c460 	addiu	a1,a1,-15264
  5b5cf8:	0c101b74 	jal	0x406dd0
  5b5cfc:	240600a2 	li	a2,162
  5b5d00:	0816d72d 	j	0x5b5cb4
  5b5d04:	8fbf0024 	lw	ra,36(sp)
  5b5d08:	3c020075 	lui	v0,0x75
  5b5d0c:	8c42cf58 	lw	v0,-12456(v0)
  5b5d10:	14400005 	bnez	v0,0x5b5d28
  5b5d14:	00000000 	nop
  5b5d18:	0c101f7c 	jal	0x407df0
  5b5d1c:	02002021 	move	a0,s0
  5b5d20:	0816d72d 	j	0x5b5cb4
  5b5d24:	8fbf0024 	lw	ra,36(sp)
  5b5d28:	0c16276a 	jal	0x589da8
  5b5d2c:	00000000 	nop
  5b5d30:	1040fff9 	beqz	v0,0x5b5d18
  5b5d34:	3c04006d 	lui	a0,0x6d
  5b5d38:	3c05006f 	lui	a1,0x6f
  5b5d3c:	24843580 	addiu	a0,a0,13696
  5b5d40:	24a5c460 	addiu	a1,a1,-15264
  5b5d44:	0c101b74 	jal	0x406dd0
  5b5d48:	240600aa 	li	a2,170
  5b5d4c:	0816d746 	j	0x5b5d18
  5b5d50:	00000000 	nop

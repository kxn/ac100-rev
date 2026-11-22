; func cw_priv_sub_fireware_action_create @ 0x005c8d7c size=0xdc
  5c8d7c:	27bdffd8 	addiu	sp,sp,-40
  5c8d80:	24050008 	li	a1,8
  5c8d84:	afb0001c 	sw	s0,28(sp)
  5c8d88:	afbf0024 	sw	ra,36(sp)
  5c8d8c:	0c15c8cc 	jal	0x572330
  5c8d90:	afb10020 	sw	s1,32(sp)
  5c8d94:	1040000d 	beqz	v0,0x5c8dcc
  5c8d98:	00408021 	move	s0,v0
  5c8d9c:	240400b1 	li	a0,177
  5c8da0:	24050006 	li	a1,6
  5c8da4:	0c15c943 	jal	0x57250c
  5c8da8:	00403021 	move	a2,v0
  5c8dac:	10400017 	beqz	v0,0x5c8e0c
  5c8db0:	00408821 	move	s1,v0
  5c8db4:	8fbf0024 	lw	ra,36(sp)
  5c8db8:	02201021 	move	v0,s1
  5c8dbc:	8fb10020 	lw	s1,32(sp)
  5c8dc0:	8fb0001c 	lw	s0,28(sp)
  5c8dc4:	03e00008 	jr	ra
  5c8dc8:	27bd0028 	addiu	sp,sp,40
  5c8dcc:	3c020075 	lui	v0,0x75
  5c8dd0:	8c42cf58 	lw	v0,-12456(v0)
  5c8dd4:	1040fff7 	beqz	v0,0x5c8db4
  5c8dd8:	00008821 	move	s1,zero
  5c8ddc:	0c16276a 	jal	0x589da8
  5c8de0:	00000000 	nop
  5c8de4:	5040fff4 	beqzl	v0,0x5c8db8
  5c8de8:	8fbf0024 	lw	ra,36(sp)
  5c8dec:	3c04006d 	lui	a0,0x6d
  5c8df0:	3c05006f 	lui	a1,0x6f
  5c8df4:	248434fc 	addiu	a0,a0,13564
  5c8df8:	24a50a30 	addiu	a1,a1,2608
  5c8dfc:	0c101b74 	jal	0x406dd0
  5c8e00:	240600a8 	li	a2,168
  5c8e04:	0817236e 	j	0x5c8db8
  5c8e08:	8fbf0024 	lw	ra,36(sp)
  5c8e0c:	3c020075 	lui	v0,0x75
  5c8e10:	8c42cf58 	lw	v0,-12456(v0)
  5c8e14:	14400005 	bnez	v0,0x5c8e2c
  5c8e18:	00000000 	nop
  5c8e1c:	0c101f7c 	jal	0x407df0
  5c8e20:	02002021 	move	a0,s0
  5c8e24:	0817236e 	j	0x5c8db8
  5c8e28:	8fbf0024 	lw	ra,36(sp)
  5c8e2c:	0c16276a 	jal	0x589da8
  5c8e30:	00000000 	nop
  5c8e34:	1040fff9 	beqz	v0,0x5c8e1c
  5c8e38:	3c04006d 	lui	a0,0x6d
  5c8e3c:	3c05006f 	lui	a1,0x6f
  5c8e40:	248447f0 	addiu	a0,a0,18416
  5c8e44:	24a50a30 	addiu	a1,a1,2608
  5c8e48:	0c101b74 	jal	0x406dd0
  5c8e4c:	240600b0 	li	a2,176
  5c8e50:	08172387 	j	0x5c8e1c
  5c8e54:	00000000 	nop

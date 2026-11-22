; func cw_wtp_name_create @ 0x00585d7c size=0x170
  585d7c:	27bdffd8 	addiu	sp,sp,-40
  585d80:	24050008 	li	a1,8
  585d84:	afb10020 	sw	s1,32(sp)
  585d88:	afb0001c 	sw	s0,28(sp)
  585d8c:	afbf0024 	sw	ra,36(sp)
  585d90:	0c15c8cc 	jal	0x572330
  585d94:	00808021 	move	s0,a0
  585d98:	10400025 	beqz	v0,0x585e30
  585d9c:	00408821 	move	s1,v0
  585da0:	ac400004 	sw	zero,4(v0)
  585da4:	96050000 	lhu	a1,0(s0)
  585da8:	50a00009 	beqzl	a1,0x585dd0
  585dac:	96250000 	lhu	a1,0(s1)
  585db0:	8e040004 	lw	a0,4(s0)
  585db4:	50800006 	beqzl	a0,0x585dd0
  585db8:	96250000 	lhu	a1,0(s1)
  585dbc:	0c15c909 	jal	0x572424
  585dc0:	00000000 	nop
  585dc4:	10400036 	beqz	v0,0x585ea0
  585dc8:	ae220004 	sw	v0,4(s1)
  585dcc:	96250000 	lhu	a1,0(s1)
  585dd0:	2404002d 	li	a0,45
  585dd4:	0c15c943 	jal	0x57250c
  585dd8:	02203021 	move	a2,s1
  585ddc:	10400007 	beqz	v0,0x585dfc
  585de0:	00408021 	move	s0,v0
  585de4:	8fbf0024 	lw	ra,36(sp)
  585de8:	02001021 	move	v0,s0
  585dec:	8fb10020 	lw	s1,32(sp)
  585df0:	8fb0001c 	lw	s0,28(sp)
  585df4:	03e00008 	jr	ra
  585df8:	27bd0028 	addiu	sp,sp,40
  585dfc:	3c020075 	lui	v0,0x75
  585e00:	8c42cf58 	lw	v0,-12456(v0)
  585e04:	1440001a 	bnez	v0,0x585e70
  585e08:	00000000 	nop
  585e0c:	8e240004 	lw	a0,4(s1)
  585e10:	10800003 	beqz	a0,0x585e20
  585e14:	00000000 	nop
  585e18:	0c101f7c 	jal	0x407df0
  585e1c:	00000000 	nop
  585e20:	0c101f7c 	jal	0x407df0
  585e24:	02202021 	move	a0,s1
  585e28:	0816177a 	j	0x585de8
  585e2c:	8fbf0024 	lw	ra,36(sp)
  585e30:	3c020075 	lui	v0,0x75
  585e34:	8c42cf58 	lw	v0,-12456(v0)
  585e38:	1040ffea 	beqz	v0,0x585de4
  585e3c:	00008021 	move	s0,zero
  585e40:	0c16276a 	jal	0x589da8
  585e44:	00000000 	nop
  585e48:	5040ffe7 	beqzl	v0,0x585de8
  585e4c:	8fbf0024 	lw	ra,36(sp)
  585e50:	3c04006d 	lui	a0,0x6d
  585e54:	3c05006e 	lui	a1,0x6e
  585e58:	248434fc 	addiu	a0,a0,13564
  585e5c:	24a5d590 	addiu	a1,a1,-10864
  585e60:	0c101b74 	jal	0x406dd0
  585e64:	240600b0 	li	a2,176
  585e68:	0816177a 	j	0x585de8
  585e6c:	8fbf0024 	lw	ra,36(sp)
  585e70:	0c16276a 	jal	0x589da8
  585e74:	00000000 	nop
  585e78:	5040ffe5 	beqzl	v0,0x585e10
  585e7c:	8e240004 	lw	a0,4(s1)
  585e80:	3c04006d 	lui	a0,0x6d
  585e84:	3c05006e 	lui	a1,0x6e
  585e88:	24843580 	addiu	a0,a0,13696
  585e8c:	24a5d590 	addiu	a1,a1,-10864
  585e90:	0c101b74 	jal	0x406dd0
  585e94:	240600c4 	li	a2,196
  585e98:	08161784 	j	0x585e10
  585e9c:	8e240004 	lw	a0,4(s1)
  585ea0:	3c020075 	lui	v0,0x75
  585ea4:	8c42cf58 	lw	v0,-12456(v0)
  585ea8:	14400005 	bnez	v0,0x585ec0
  585eac:	00000000 	nop
  585eb0:	0c101f7c 	jal	0x407df0
  585eb4:	02202021 	move	a0,s1
  585eb8:	08161774 	j	0x585dd0
  585ebc:	96250000 	lhu	a1,0(s1)
  585ec0:	0c16276a 	jal	0x589da8
  585ec4:	00000000 	nop
  585ec8:	1040fff9 	beqz	v0,0x585eb0
  585ecc:	3c04006e 	lui	a0,0x6e
  585ed0:	3c05006e 	lui	a1,0x6e
  585ed4:	2484d4e8 	addiu	a0,a0,-11032
  585ed8:	24a5d590 	addiu	a1,a1,-10864
  585edc:	0c101b74 	jal	0x406dd0
  585ee0:	240600bb 	li	a2,187
  585ee4:	081617ac 	j	0x585eb0
  585ee8:	00000000 	nop

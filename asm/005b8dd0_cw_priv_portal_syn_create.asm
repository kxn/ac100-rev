; func cw_priv_portal_syn_create @ 0x005b8dd0 size=0x1ac
  5b8dd0:	27bdffd8 	addiu	sp,sp,-40
  5b8dd4:	24050008 	li	a1,8
  5b8dd8:	afb10020 	sw	s1,32(sp)
  5b8ddc:	afb0001c 	sw	s0,28(sp)
  5b8de0:	afbf0024 	sw	ra,36(sp)
  5b8de4:	0c15c8cc 	jal	0x572330
  5b8de8:	00808021 	move	s0,a0
  5b8dec:	10400027 	beqz	v0,0x5b8e8c
  5b8df0:	00408821 	move	s1,v0
  5b8df4:	ac400004 	sw	zero,4(v0)
  5b8df8:	96050000 	lhu	a1,0(s0)
  5b8dfc:	50a00009 	beqzl	a1,0x5b8e24
  5b8e00:	96250000 	lhu	a1,0(s1)
  5b8e04:	8e040004 	lw	a0,4(s0)
  5b8e08:	1080003c 	beqz	a0,0x5b8efc
  5b8e0c:	3c020075 	lui	v0,0x75
  5b8e10:	0c15c8cc 	jal	0x572330
  5b8e14:	00000000 	nop
  5b8e18:	1040003f 	beqz	v0,0x5b8f18
  5b8e1c:	ae220004 	sw	v0,4(s1)
  5b8e20:	96250000 	lhu	a1,0(s1)
  5b8e24:	2404002a 	li	a0,42
  5b8e28:	02203021 	move	a2,s1
  5b8e2c:	24a50002 	addiu	a1,a1,2
  5b8e30:	0c15c943 	jal	0x57250c
  5b8e34:	30a5ffff 	andi	a1,a1,0xffff
  5b8e38:	10400007 	beqz	v0,0x5b8e58
  5b8e3c:	00408021 	move	s0,v0
  5b8e40:	8fbf0024 	lw	ra,36(sp)
  5b8e44:	02001021 	move	v0,s0
  5b8e48:	8fb10020 	lw	s1,32(sp)
  5b8e4c:	8fb0001c 	lw	s0,28(sp)
  5b8e50:	03e00008 	jr	ra
  5b8e54:	27bd0028 	addiu	sp,sp,40
  5b8e58:	3c020075 	lui	v0,0x75
  5b8e5c:	8c42cf58 	lw	v0,-12456(v0)
  5b8e60:	1440001a 	bnez	v0,0x5b8ecc
  5b8e64:	00000000 	nop
  5b8e68:	8e240004 	lw	a0,4(s1)
  5b8e6c:	10800003 	beqz	a0,0x5b8e7c
  5b8e70:	00000000 	nop
  5b8e74:	0c101f7c 	jal	0x407df0
  5b8e78:	00000000 	nop
  5b8e7c:	0c101f7c 	jal	0x407df0
  5b8e80:	02202021 	move	a0,s1
  5b8e84:	0816e391 	j	0x5b8e44
  5b8e88:	8fbf0024 	lw	ra,36(sp)
  5b8e8c:	3c020075 	lui	v0,0x75
  5b8e90:	8c42cf58 	lw	v0,-12456(v0)
  5b8e94:	1040ffea 	beqz	v0,0x5b8e40
  5b8e98:	00008021 	move	s0,zero
  5b8e9c:	0c16276a 	jal	0x589da8
  5b8ea0:	00000000 	nop
  5b8ea4:	5040ffe7 	beqzl	v0,0x5b8e44
  5b8ea8:	8fbf0024 	lw	ra,36(sp)
  5b8eac:	3c04006d 	lui	a0,0x6d
  5b8eb0:	3c05006f 	lui	a1,0x6f
  5b8eb4:	248434fc 	addiu	a0,a0,13564
  5b8eb8:	24a5d080 	addiu	a1,a1,-12160
  5b8ebc:	0c101b74 	jal	0x406dd0
  5b8ec0:	240600b7 	li	a2,183
  5b8ec4:	0816e391 	j	0x5b8e44
  5b8ec8:	8fbf0024 	lw	ra,36(sp)
  5b8ecc:	0c16276a 	jal	0x589da8
  5b8ed0:	00000000 	nop
  5b8ed4:	5040ffe5 	beqzl	v0,0x5b8e6c
  5b8ed8:	8e240004 	lw	a0,4(s1)
  5b8edc:	3c04006d 	lui	a0,0x6d
  5b8ee0:	3c05006f 	lui	a1,0x6f
  5b8ee4:	248447f0 	addiu	a0,a0,18416
  5b8ee8:	24a5d080 	addiu	a1,a1,-12160
  5b8eec:	0c101b74 	jal	0x406dd0
  5b8ef0:	240600d2 	li	a2,210
  5b8ef4:	0816e39b 	j	0x5b8e6c
  5b8ef8:	8e240004 	lw	a0,4(s1)
  5b8efc:	8c42cf58 	lw	v0,-12456(v0)
  5b8f00:	14400015 	bnez	v0,0x5b8f58
  5b8f04:	00000000 	nop
  5b8f08:	0c101f7c 	jal	0x407df0
  5b8f0c:	02202021 	move	a0,s1
  5b8f10:	0816e390 	j	0x5b8e40
  5b8f14:	00008021 	move	s0,zero
  5b8f18:	3c020075 	lui	v0,0x75
  5b8f1c:	8c42cf58 	lw	v0,-12456(v0)
  5b8f20:	1040fff9 	beqz	v0,0x5b8f08
  5b8f24:	00000000 	nop
  5b8f28:	0c16276a 	jal	0x589da8
  5b8f2c:	00000000 	nop
  5b8f30:	1040fff5 	beqz	v0,0x5b8f08
  5b8f34:	3c04006e 	lui	a0,0x6e
  5b8f38:	3c05006f 	lui	a1,0x6f
  5b8f3c:	24848050 	addiu	a0,a0,-32688
  5b8f40:	24a5d080 	addiu	a1,a1,-12160
  5b8f44:	240600c8 	li	a2,200
  5b8f48:	0c101b74 	jal	0x406dd0
  5b8f4c:	00000000 	nop
  5b8f50:	0816e3c2 	j	0x5b8f08
  5b8f54:	00000000 	nop
  5b8f58:	0c16276a 	jal	0x589da8
  5b8f5c:	00000000 	nop
  5b8f60:	1040ffe9 	beqz	v0,0x5b8f08
  5b8f64:	3c04006e 	lui	a0,0x6e
  5b8f68:	3c05006f 	lui	a1,0x6f
  5b8f6c:	248480d8 	addiu	a0,a0,-32552
  5b8f70:	24a5d080 	addiu	a1,a1,-12160
  5b8f74:	0816e3d2 	j	0x5b8f48
  5b8f78:	240600c1 	li	a2,193

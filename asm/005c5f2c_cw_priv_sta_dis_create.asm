; func cw_priv_sta_dis_create @ 0x005c5f2c size=0xdc
  5c5f2c:	27bdffd8 	addiu	sp,sp,-40
  5c5f30:	24050008 	li	a1,8
  5c5f34:	afb0001c 	sw	s0,28(sp)
  5c5f38:	afbf0024 	sw	ra,36(sp)
  5c5f3c:	0c15c8cc 	jal	0x572330
  5c5f40:	afb10020 	sw	s1,32(sp)
  5c5f44:	1040000d 	beqz	v0,0x5c5f7c
  5c5f48:	00408021 	move	s0,v0
  5c5f4c:	2404000b 	li	a0,11
  5c5f50:	24050008 	li	a1,8
  5c5f54:	0c15c943 	jal	0x57250c
  5c5f58:	00403021 	move	a2,v0
  5c5f5c:	10400017 	beqz	v0,0x5c5fbc
  5c5f60:	00408821 	move	s1,v0
  5c5f64:	8fbf0024 	lw	ra,36(sp)
  5c5f68:	02201021 	move	v0,s1
  5c5f6c:	8fb10020 	lw	s1,32(sp)
  5c5f70:	8fb0001c 	lw	s0,28(sp)
  5c5f74:	03e00008 	jr	ra
  5c5f78:	27bd0028 	addiu	sp,sp,40
  5c5f7c:	3c020075 	lui	v0,0x75
  5c5f80:	8c42cf58 	lw	v0,-12456(v0)
  5c5f84:	1040fff7 	beqz	v0,0x5c5f64
  5c5f88:	00008821 	move	s1,zero
  5c5f8c:	0c16276a 	jal	0x589da8
  5c5f90:	00000000 	nop
  5c5f94:	5040fff4 	beqzl	v0,0x5c5f68
  5c5f98:	8fbf0024 	lw	ra,36(sp)
  5c5f9c:	3c04006d 	lui	a0,0x6d
  5c5fa0:	3c05006f 	lui	a1,0x6f
  5c5fa4:	248434fc 	addiu	a0,a0,13564
  5c5fa8:	24a5ff90 	addiu	a1,a1,-112
  5c5fac:	0c101b74 	jal	0x406dd0
  5c5fb0:	240600b4 	li	a2,180
  5c5fb4:	081717da 	j	0x5c5f68
  5c5fb8:	8fbf0024 	lw	ra,36(sp)
  5c5fbc:	3c020075 	lui	v0,0x75
  5c5fc0:	8c42cf58 	lw	v0,-12456(v0)
  5c5fc4:	14400005 	bnez	v0,0x5c5fdc
  5c5fc8:	00000000 	nop
  5c5fcc:	0c101f7c 	jal	0x407df0
  5c5fd0:	02002021 	move	a0,s0
  5c5fd4:	081717da 	j	0x5c5f68
  5c5fd8:	8fbf0024 	lw	ra,36(sp)
  5c5fdc:	0c16276a 	jal	0x589da8
  5c5fe0:	00000000 	nop
  5c5fe4:	1040fff9 	beqz	v0,0x5c5fcc
  5c5fe8:	3c04006d 	lui	a0,0x6d
  5c5fec:	3c05006f 	lui	a1,0x6f
  5c5ff0:	248447f0 	addiu	a0,a0,18416
  5c5ff4:	24a5ff90 	addiu	a1,a1,-112
  5c5ff8:	0c101b74 	jal	0x406dd0
  5c5ffc:	240600bc 	li	a2,188
  5c6000:	081717f3 	j	0x5c5fcc
  5c6004:	00000000 	nop
	...

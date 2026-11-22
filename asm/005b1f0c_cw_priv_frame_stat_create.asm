; func cw_priv_frame_stat_create @ 0x005b1f0c size=0xdc
  5b1f0c:	27bdffd8 	addiu	sp,sp,-40
  5b1f10:	2405007c 	li	a1,124
  5b1f14:	afb0001c 	sw	s0,28(sp)
  5b1f18:	afbf0024 	sw	ra,36(sp)
  5b1f1c:	0c15c8cc 	jal	0x572330
  5b1f20:	afb10020 	sw	s1,32(sp)
  5b1f24:	1040000d 	beqz	v0,0x5b1f5c
  5b1f28:	00408021 	move	s0,v0
  5b1f2c:	2404000e 	li	a0,14
  5b1f30:	2405007c 	li	a1,124
  5b1f34:	0c15c943 	jal	0x57250c
  5b1f38:	00403021 	move	a2,v0
  5b1f3c:	10400017 	beqz	v0,0x5b1f9c
  5b1f40:	00408821 	move	s1,v0
  5b1f44:	8fbf0024 	lw	ra,36(sp)
  5b1f48:	02201021 	move	v0,s1
  5b1f4c:	8fb10020 	lw	s1,32(sp)
  5b1f50:	8fb0001c 	lw	s0,28(sp)
  5b1f54:	03e00008 	jr	ra
  5b1f58:	27bd0028 	addiu	sp,sp,40
  5b1f5c:	3c020075 	lui	v0,0x75
  5b1f60:	8c42cf58 	lw	v0,-12456(v0)
  5b1f64:	1040fff7 	beqz	v0,0x5b1f44
  5b1f68:	00008821 	move	s1,zero
  5b1f6c:	0c16276a 	jal	0x589da8
  5b1f70:	00000000 	nop
  5b1f74:	5040fff4 	beqzl	v0,0x5b1f48
  5b1f78:	8fbf0024 	lw	ra,36(sp)
  5b1f7c:	3c04006d 	lui	a0,0x6d
  5b1f80:	3c05006f 	lui	a1,0x6f
  5b1f84:	248434fc 	addiu	a0,a0,13564
  5b1f88:	24a5b330 	addiu	a1,a1,-19664
  5b1f8c:	0c101b74 	jal	0x406dd0
  5b1f90:	24060127 	li	a2,295
  5b1f94:	0816c7d2 	j	0x5b1f48
  5b1f98:	8fbf0024 	lw	ra,36(sp)
  5b1f9c:	3c020075 	lui	v0,0x75
  5b1fa0:	8c42cf58 	lw	v0,-12456(v0)
  5b1fa4:	14400005 	bnez	v0,0x5b1fbc
  5b1fa8:	00000000 	nop
  5b1fac:	0c101f7c 	jal	0x407df0
  5b1fb0:	02002021 	move	a0,s0
  5b1fb4:	0816c7d2 	j	0x5b1f48
  5b1fb8:	8fbf0024 	lw	ra,36(sp)
  5b1fbc:	0c16276a 	jal	0x589da8
  5b1fc0:	00000000 	nop
  5b1fc4:	1040fff9 	beqz	v0,0x5b1fac
  5b1fc8:	3c04006d 	lui	a0,0x6d
  5b1fcc:	3c05006f 	lui	a1,0x6f
  5b1fd0:	248447f0 	addiu	a0,a0,18416
  5b1fd4:	24a5b330 	addiu	a1,a1,-19664
  5b1fd8:	0c101b74 	jal	0x406dd0
  5b1fdc:	2406012f 	li	a2,303
  5b1fe0:	0816c7eb 	j	0x5b1fac
  5b1fe4:	00000000 	nop
	...

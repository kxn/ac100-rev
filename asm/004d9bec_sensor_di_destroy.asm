; func sensor_di_destroy @ 0x004d9bec size=0x64
  4d9bec:	3c020077 	lui	v0,0x77
  4d9bf0:	27bdffe0 	addiu	sp,sp,-32
  4d9bf4:	8c4285f4 	lw	v0,-31244(v0)
  4d9bf8:	afbf001c 	sw	ra,28(sp)
  4d9bfc:	1440000c 	bnez	v0,0x4d9c30
  4d9c00:	afb00018 	sw	s0,24(sp)
  4d9c04:	3c100077 	lui	s0,0x77
  4d9c08:	8e0485e4 	lw	a0,-31260(s0)
  4d9c0c:	10800005 	beqz	a0,0x4d9c24
  4d9c10:	8fbf001c 	lw	ra,28(sp)
  4d9c14:	0c1020d8 	jal	0x408360
  4d9c18:	00000000 	nop
  4d9c1c:	ae0085e4 	sw	zero,-31260(s0)
  4d9c20:	8fbf001c 	lw	ra,28(sp)
  4d9c24:	8fb00018 	lw	s0,24(sp)
  4d9c28:	08137406 	j	0x4dd018
  4d9c2c:	27bd0020 	addiu	sp,sp,32
  4d9c30:	3c04006b 	lui	a0,0x6b
  4d9c34:	3c05006b 	lui	a1,0x6b
  4d9c38:	2484b9bc 	addiu	a0,a0,-17988
  4d9c3c:	24a5cfdc 	addiu	a1,a1,-12324
  4d9c40:	0c101b74 	jal	0x406dd0
  4d9c44:	2406077f 	li	a2,1919
  4d9c48:	08136702 	j	0x4d9c08
  4d9c4c:	3c100077 	lui	s0,0x77

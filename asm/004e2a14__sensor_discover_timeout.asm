; func _sensor_discover_timeout @ 0x004e2a14 size=0x44
  4e2a14:	27bdffe0 	addiu	sp,sp,-32
  4e2a18:	2405ffff 	li	a1,-1
  4e2a1c:	afb00018 	sw	s0,24(sp)
  4e2a20:	3c100077 	lui	s0,0x77
  4e2a24:	afbf001c 	sw	ra,28(sp)
  4e2a28:	0c1020b4 	jal	0x4082d0
  4e2a2c:	8e04862c 	lw	a0,-31188(s0)
  4e2a30:	3c020073 	lui	v0,0x73
  4e2a34:	2403ffff 	li	v1,-1
  4e2a38:	00002021 	move	a0,zero
  4e2a3c:	0c138a01 	jal	0x4e2804
  4e2a40:	ac431af8 	sw	v1,6904(v0)
  4e2a44:	8e04862c 	lw	a0,-31188(s0)
  4e2a48:	8fbf001c 	lw	ra,28(sp)
  4e2a4c:	8fb00018 	lw	s0,24(sp)
  4e2a50:	08101fcc 	j	0x407f30
  4e2a54:	27bd0020 	addiu	sp,sp,32

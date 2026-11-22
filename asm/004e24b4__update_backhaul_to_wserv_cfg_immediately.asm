; func _update_backhaul_to_wserv_cfg_immediately @ 0x004e24b4 size=0x44
  4e24b4:	27bdffe0 	addiu	sp,sp,-32
  4e24b8:	2405ffff 	li	a1,-1
  4e24bc:	afb00018 	sw	s0,24(sp)
  4e24c0:	3c100077 	lui	s0,0x77
  4e24c4:	afbf001c 	sw	ra,28(sp)
  4e24c8:	0c1020b4 	jal	0x4082d0
  4e24cc:	8e04862c 	lw	a0,-31188(s0)
  4e24d0:	0c138908 	jal	0x4e2420
  4e24d4:	00000000 	nop
  4e24d8:	0c101fcc 	jal	0x407f30
  4e24dc:	8e04862c 	lw	a0,-31188(s0)
  4e24e0:	3c04006b 	lui	a0,0x6b
  4e24e4:	8fbf001c 	lw	ra,28(sp)
  4e24e8:	8fb00018 	lw	s0,24(sp)
  4e24ec:	2484fc60 	addiu	a0,a0,-928
  4e24f0:	08101d74 	j	0x4075d0
  4e24f4:	27bd0020 	addiu	sp,sp,32

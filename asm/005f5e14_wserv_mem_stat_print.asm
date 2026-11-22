; func wserv_mem_stat_print @ 0x005f5e14 size=0x40
  5f5e14:	27bdffe0 	addiu	sp,sp,-32
  5f5e18:	afb00018 	sw	s0,24(sp)
  5f5e1c:	3c100071 	lui	s0,0x71
  5f5e20:	afbf001c 	sw	ra,28(sp)
  5f5e24:	0c101dd4 	jal	0x407750
  5f5e28:	2604f394 	addiu	a0,s0,-3180
  5f5e2c:	3c02007d 	lui	v0,0x7d
  5f5e30:	3c040070 	lui	a0,0x70
  5f5e34:	8c45bf70 	lw	a1,-16528(v0)
  5f5e38:	0c101b74 	jal	0x406dd0
  5f5e3c:	24849e7c 	addiu	a0,a0,-24964
  5f5e40:	2604f394 	addiu	a0,s0,-3180
  5f5e44:	8fbf001c 	lw	ra,28(sp)
  5f5e48:	8fb00018 	lw	s0,24(sp)
  5f5e4c:	08101dd4 	j	0x407750
  5f5e50:	27bd0020 	addiu	sp,sp,32

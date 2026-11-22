; func wserv_print_profile @ 0x005f5dd4 size=0x40
  5f5dd4:	27bdffe0 	addiu	sp,sp,-32
  5f5dd8:	afb00018 	sw	s0,24(sp)
  5f5ddc:	3c100071 	lui	s0,0x71
  5f5de0:	afbf001c 	sw	ra,28(sp)
  5f5de4:	0c101dd4 	jal	0x407750
  5f5de8:	2604f394 	addiu	a0,s0,-3180
  5f5dec:	3c02007d 	lui	v0,0x7d
  5f5df0:	3c040070 	lui	a0,0x70
  5f5df4:	8c45bee8 	lw	a1,-16664(v0)
  5f5df8:	0c101b74 	jal	0x406dd0
  5f5dfc:	24849e58 	addiu	a0,a0,-25000
  5f5e00:	2604f394 	addiu	a0,s0,-3180
  5f5e04:	8fbf001c 	lw	ra,28(sp)
  5f5e08:	8fb00018 	lw	s0,24(sp)
  5f5e0c:	08101dd4 	j	0x407750
  5f5e10:	27bd0020 	addiu	sp,sp,32

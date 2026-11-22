; func bcast_storm_ctrl_debug_help @ 0x0045f9d4 size=0x34
  45f9d4:	3c040069 	lui	a0,0x69
  45f9d8:	27bdffe0 	addiu	sp,sp,-32
  45f9dc:	afbf001c 	sw	ra,28(sp)
  45f9e0:	0c101dd4 	jal	0x407750
  45f9e4:	2484b9a0 	addiu	a0,a0,-18016
  45f9e8:	3c040069 	lui	a0,0x69
  45f9ec:	0c101dd4 	jal	0x407750
  45f9f0:	2484b9c4 	addiu	a0,a0,-17980
  45f9f4:	3c040069 	lui	a0,0x69
  45f9f8:	8fbf001c 	lw	ra,28(sp)
  45f9fc:	27bd0020 	addiu	sp,sp,32
  45fa00:	08101dd4 	j	0x407750
  45fa04:	2484b9f0 	addiu	a0,a0,-17936

; func wsta_roam_db_print_real_chnl @ 0x004837a8 size=0x50
  4837a8:	27bdffe0 	addiu	sp,sp,-32
  4837ac:	3c040069 	lui	a0,0x69
  4837b0:	afb00018 	sw	s0,24(sp)
  4837b4:	3c100076 	lui	s0,0x76
  4837b8:	24844d68 	addiu	a0,a0,19816
  4837bc:	afbf001c 	sw	ra,28(sp)
  4837c0:	8605756c 	lh	a1,30060(s0)
  4837c4:	0c101b74 	jal	0x406dd0
  4837c8:	2610756c 	addiu	s0,s0,30060
  4837cc:	3c040069 	lui	a0,0x69
  4837d0:	86050002 	lh	a1,2(s0)
  4837d4:	0c101b74 	jal	0x406dd0
  4837d8:	24844d7c 	addiu	a0,a0,19836
  4837dc:	3c040069 	lui	a0,0x69
  4837e0:	86050004 	lh	a1,4(s0)
  4837e4:	8fbf001c 	lw	ra,28(sp)
  4837e8:	24844d90 	addiu	a0,a0,19856
  4837ec:	8fb00018 	lw	s0,24(sp)
  4837f0:	08101b74 	j	0x406dd0
  4837f4:	27bd0020 	addiu	sp,sp,32
	...

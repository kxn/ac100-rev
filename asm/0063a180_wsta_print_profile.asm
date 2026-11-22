; func wsta_print_profile @ 0x0063a180 size=0x88
  63a180:	27bdffe0 	addiu	sp,sp,-32
  63a184:	afb00018 	sw	s0,24(sp)
  63a188:	3c100071 	lui	s0,0x71
  63a18c:	afbf001c 	sw	ra,28(sp)
  63a190:	0c101dd4 	jal	0x407750
  63a194:	2604f394 	addiu	a0,s0,-3180
  63a198:	0c1506a9 	jal	0x541aa4
  63a19c:	00000000 	nop
  63a1a0:	3c040071 	lui	a0,0x71
  63a1a4:	00402821 	move	a1,v0
  63a1a8:	0c101b74 	jal	0x406dd0
  63a1ac:	2484f47c 	addiu	a0,a0,-2948
  63a1b0:	3c02007d 	lui	v0,0x7d
  63a1b4:	3c040071 	lui	a0,0x71
  63a1b8:	8c45c6a8 	lw	a1,-14680(v0)
  63a1bc:	0c101b74 	jal	0x406dd0
  63a1c0:	2484f4a0 	addiu	a0,a0,-2912
  63a1c4:	0c1868f7 	jal	0x61a3dc
  63a1c8:	00000000 	nop
  63a1cc:	3c040071 	lui	a0,0x71
  63a1d0:	00402821 	move	a1,v0
  63a1d4:	0c101b74 	jal	0x406dd0
  63a1d8:	2484f4c4 	addiu	a0,a0,-2876
  63a1dc:	0c1868f4 	jal	0x61a3d0
  63a1e0:	00000000 	nop
  63a1e4:	3c040071 	lui	a0,0x71
  63a1e8:	00402821 	move	a1,v0
  63a1ec:	0c101b74 	jal	0x406dd0
  63a1f0:	2484f4e8 	addiu	a0,a0,-2840
  63a1f4:	2604f394 	addiu	a0,s0,-3180
  63a1f8:	8fbf001c 	lw	ra,28(sp)
  63a1fc:	8fb00018 	lw	s0,24(sp)
  63a200:	08101dd4 	j	0x407750
  63a204:	27bd0020 	addiu	sp,sp,32

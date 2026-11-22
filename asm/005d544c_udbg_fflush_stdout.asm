; func udbg_fflush_stdout @ 0x005d544c size=0x2c
  5d544c:	3c020076 	lui	v0,0x76
  5d5450:	27bdffe0 	addiu	sp,sp,-32
  5d5454:	8c449900 	lw	a0,-26368(v0)
  5d5458:	afbf001c 	sw	ra,28(sp)
  5d545c:	0c101c6c 	jal	0x4071b0
  5d5460:	00000000 	nop
  5d5464:	3c020076 	lui	v0,0x76
  5d5468:	8fbf001c 	lw	ra,28(sp)
  5d546c:	27bd0020 	addiu	sp,sp,32
  5d5470:	08101c6c 	j	0x4071b0
  5d5474:	8c449910 	lw	a0,-26352(v0)

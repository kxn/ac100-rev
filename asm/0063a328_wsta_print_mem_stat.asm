; func wsta_print_mem_stat @ 0x0063a328 size=0x40
  63a328:	27bdffe0 	addiu	sp,sp,-32
  63a32c:	afb00018 	sw	s0,24(sp)
  63a330:	3c100071 	lui	s0,0x71
  63a334:	afbf001c 	sw	ra,28(sp)
  63a338:	0c101dd4 	jal	0x407750
  63a33c:	2604f394 	addiu	a0,s0,-3180
  63a340:	3c02007d 	lui	v0,0x7d
  63a344:	3c040071 	lui	a0,0x71
  63a348:	8c45c6b4 	lw	a1,-14668(v0)
  63a34c:	0c101b74 	jal	0x406dd0
  63a350:	2484f560 	addiu	a0,a0,-2720
  63a354:	2604f394 	addiu	a0,s0,-3180
  63a358:	8fbf001c 	lw	ra,28(sp)
  63a35c:	8fb00018 	lw	s0,24(sp)
  63a360:	08101dd4 	j	0x407750
  63a364:	27bd0020 	addiu	sp,sp,32

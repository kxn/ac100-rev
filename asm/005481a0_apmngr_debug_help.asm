; func apmngr_debug_help @ 0x005481a0 size=0x3c
  5481a0:	3c04006d 	lui	a0,0x6d
  5481a4:	27bdffe0 	addiu	sp,sp,-32
  5481a8:	afbf001c 	sw	ra,28(sp)
  5481ac:	0c101dd4 	jal	0x407750
  5481b0:	2484d630 	addiu	a0,a0,-10704
  5481b4:	3c04006d 	lui	a0,0x6d
  5481b8:	0c101dd4 	jal	0x407750
  5481bc:	2484d648 	addiu	a0,a0,-10680
  5481c0:	0c14cdd2 	jal	0x533748
  5481c4:	00000000 	nop
  5481c8:	0c150c81 	jal	0x543204
  5481cc:	00000000 	nop
  5481d0:	8fbf001c 	lw	ra,28(sp)
  5481d4:	0815204e 	j	0x548138
  5481d8:	27bd0020 	addiu	sp,sp,32

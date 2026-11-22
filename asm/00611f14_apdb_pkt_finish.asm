; func apdb_pkt_finish @ 0x00611f14 size=0x38
  611f14:	27bdffe0 	addiu	sp,sp,-32
  611f18:	afb00018 	sw	s0,24(sp)
  611f1c:	3c10007d 	lui	s0,0x7d
  611f20:	afbf001c 	sw	ra,28(sp)
  611f24:	8e04c2d4 	lw	a0,-15660(s0)
  611f28:	10800005 	beqz	a0,0x611f40
  611f2c:	8fbf001c 	lw	ra,28(sp)
  611f30:	0c1020d8 	jal	0x408360
  611f34:	00000000 	nop
  611f38:	ae00c2d4 	sw	zero,-15660(s0)
  611f3c:	8fbf001c 	lw	ra,28(sp)
  611f40:	8fb00018 	lw	s0,24(sp)
  611f44:	03e00008 	jr	ra
  611f48:	27bd0020 	addiu	sp,sp,32

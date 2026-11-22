; func close_snapshot_file @ 0x0058f8a4 size=0x40
  58f8a4:	27bdffe0 	addiu	sp,sp,-32
  58f8a8:	afb00018 	sw	s0,24(sp)
  58f8ac:	3c10007c 	lui	s0,0x7c
  58f8b0:	afbf001c 	sw	ra,28(sp)
  58f8b4:	8e025990 	lw	v0,22928(s0)
  58f8b8:	8c44001c 	lw	a0,28(v0)
  58f8bc:	10800006 	beqz	a0,0x58f8d8
  58f8c0:	8fbf001c 	lw	ra,28(sp)
  58f8c4:	0c101e54 	jal	0x407950
  58f8c8:	00000000 	nop
  58f8cc:	8e025990 	lw	v0,22928(s0)
  58f8d0:	ac40001c 	sw	zero,28(v0)
  58f8d4:	8fbf001c 	lw	ra,28(sp)
  58f8d8:	8fb00018 	lw	s0,24(sp)
  58f8dc:	03e00008 	jr	ra
  58f8e0:	27bd0020 	addiu	sp,sp,32
	...

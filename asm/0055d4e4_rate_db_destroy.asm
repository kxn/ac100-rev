; func rate_db_destroy @ 0x0055d4e4 size=0x48
  55d4e4:	27bdffe0 	addiu	sp,sp,-32
  55d4e8:	afb00018 	sw	s0,24(sp)
  55d4ec:	3c10007c 	lui	s0,0x7c
  55d4f0:	afbf001c 	sw	ra,28(sp)
  55d4f4:	0c1579f3 	jal	0x55e7cc
  55d4f8:	8e045934 	lw	a0,22836(s0)
  55d4fc:	ae005934 	sw	zero,22836(s0)
  55d500:	3c10007c 	lui	s0,0x7c
  55d504:	8e045930 	lw	a0,22832(s0)
  55d508:	10800004 	beqz	a0,0x55d51c
  55d50c:	8fbf001c 	lw	ra,28(sp)
  55d510:	0c1020d8 	jal	0x408360
  55d514:	00000000 	nop
  55d518:	8fbf001c 	lw	ra,28(sp)
  55d51c:	ae005930 	sw	zero,22832(s0)
  55d520:	8fb00018 	lw	s0,24(sp)
  55d524:	03e00008 	jr	ra
  55d528:	27bd0020 	addiu	sp,sp,32

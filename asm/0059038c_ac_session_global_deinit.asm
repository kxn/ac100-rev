; func ac_session_global_deinit @ 0x0059038c size=0x40
  59038c:	27bdffe0 	addiu	sp,sp,-32
  590390:	afb00018 	sw	s0,24(sp)
  590394:	3c10007c 	lui	s0,0x7c
  590398:	afbf001c 	sw	ra,28(sp)
  59039c:	8e0459a0 	lw	a0,22944(s0)
  5903a0:	10800005 	beqz	a0,0x5903b8
  5903a4:	3c02007c 	lui	v0,0x7c
  5903a8:	0c1020d8 	jal	0x408360
  5903ac:	00000000 	nop
  5903b0:	ae0059a0 	sw	zero,22944(s0)
  5903b4:	3c02007c 	lui	v0,0x7c
  5903b8:	8fbf001c 	lw	ra,28(sp)
  5903bc:	8fb00018 	lw	s0,24(sp)
  5903c0:	27bd0020 	addiu	sp,sp,32
  5903c4:	03e00008 	jr	ra
  5903c8:	ac4059a4 	sw	zero,22948(v0)
  5903cc:	00000000 	nop

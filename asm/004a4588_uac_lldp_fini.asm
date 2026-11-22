; func uac_lldp_fini @ 0x004a4588 size=0x3c
  4a4588:	27bdffe0 	addiu	sp,sp,-32
  4a458c:	afb00018 	sw	s0,24(sp)
  4a4590:	afbf001c 	sw	ra,28(sp)
  4a4594:	0c129123 	jal	0x4a448c
  4a4598:	3c100076 	lui	s0,0x76
  4a459c:	8e047b38 	lw	a0,31544(s0)
  4a45a0:	10800005 	beqz	a0,0x4a45b8
  4a45a4:	8fbf001c 	lw	ra,28(sp)
  4a45a8:	0c1020d8 	jal	0x408360
  4a45ac:	00000000 	nop
  4a45b0:	ae007b38 	sw	zero,31544(s0)
  4a45b4:	8fbf001c 	lw	ra,28(sp)
  4a45b8:	8fb00018 	lw	s0,24(sp)
  4a45bc:	03e00008 	jr	ra
  4a45c0:	27bd0020 	addiu	sp,sp,32

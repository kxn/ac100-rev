; func band_navigation_db_destroy @ 0x0055fd18 size=0x48
  55fd18:	27bdffe0 	addiu	sp,sp,-32
  55fd1c:	afb00018 	sw	s0,24(sp)
  55fd20:	3c10007c 	lui	s0,0x7c
  55fd24:	afbf001c 	sw	ra,28(sp)
  55fd28:	0c158085 	jal	0x560214
  55fd2c:	8e045954 	lw	a0,22868(s0)
  55fd30:	ae005954 	sw	zero,22868(s0)
  55fd34:	3c10007c 	lui	s0,0x7c
  55fd38:	8e045950 	lw	a0,22864(s0)
  55fd3c:	10800004 	beqz	a0,0x55fd50
  55fd40:	8fbf001c 	lw	ra,28(sp)
  55fd44:	0c1020d8 	jal	0x408360
  55fd48:	00000000 	nop
  55fd4c:	8fbf001c 	lw	ra,28(sp)
  55fd50:	ae005950 	sw	zero,22864(s0)
  55fd54:	8fb00018 	lw	s0,24(sp)
  55fd58:	03e00008 	jr	ra
  55fd5c:	27bd0020 	addiu	sp,sp,32

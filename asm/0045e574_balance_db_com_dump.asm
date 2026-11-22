; func balance_db_com_dump @ 0x0045e574 size=0x40
  45e574:	3c020076 	lui	v0,0x76
  45e578:	27bdffe0 	addiu	sp,sp,-32
  45e57c:	8c427044 	lw	v0,28740(v0)
  45e580:	10400009 	beqz	v0,0x45e5a8
  45e584:	afbf001c 	sw	ra,28(sp)
  45e588:	3c040069 	lui	a0,0x69
  45e58c:	0c101dd4 	jal	0x407750
  45e590:	2484a5e0 	addiu	a0,a0,-23072
  45e594:	0c11793b 	jal	0x45e4ec
  45e598:	00000000 	nop
  45e59c:	8fbf001c 	lw	ra,28(sp)
  45e5a0:	08117955 	j	0x45e554
  45e5a4:	27bd0020 	addiu	sp,sp,32
  45e5a8:	8fbf001c 	lw	ra,28(sp)
  45e5ac:	03e00008 	jr	ra
  45e5b0:	27bd0020 	addiu	sp,sp,32

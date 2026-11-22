; func sensor_add_test @ 0x004e945c size=0x24
  4e945c:	27bdffe0 	addiu	sp,sp,-32
  4e9460:	24050001 	li	a1,1
  4e9464:	a7a40020 	sh	a0,32(sp)
  4e9468:	afbf001c 	sw	ra,28(sp)
  4e946c:	0c139ead 	jal	0x4e7ab4
  4e9470:	27a40020 	addiu	a0,sp,32
  4e9474:	8fbf001c 	lw	ra,28(sp)
  4e9478:	03e00008 	jr	ra
  4e947c:	27bd0020 	addiu	sp,sp,32

; func sensor_test_sqlite_uninit @ 0x004feaa8 size=0x3c
  4feaa8:	27bdffe0 	addiu	sp,sp,-32
  4feaac:	afb00018 	sw	s0,24(sp)
  4feab0:	3c100077 	lui	s0,0x77
  4feab4:	afbf001c 	sw	ra,28(sp)
  4feab8:	8e0488b4 	lw	a0,-30540(s0)
  4feabc:	10800005 	beqz	a0,0x4fead4
  4feac0:	8fbf001c 	lw	ra,28(sp)
  4feac4:	0c10202c 	jal	0x4080b0
  4feac8:	00000000 	nop
  4feacc:	ae0088b4 	sw	zero,-30540(s0)
  4fead0:	8fbf001c 	lw	ra,28(sp)
  4fead4:	00001021 	move	v0,zero
  4fead8:	8fb00018 	lw	s0,24(sp)
  4feadc:	03e00008 	jr	ra
  4feae0:	27bd0020 	addiu	sp,sp,32

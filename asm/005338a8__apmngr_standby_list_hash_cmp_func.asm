; func _apmngr_standby_list_hash_cmp_func @ 0x005338a8 size=0x20
  5338a8:	27bdffe0 	addiu	sp,sp,-32
  5338ac:	afbf001c 	sw	ra,28(sp)
  5338b0:	0c101e4c 	jal	0x407930
  5338b4:	24060006 	li	a2,6
  5338b8:	8fbf001c 	lw	ra,28(sp)
  5338bc:	2c420001 	sltiu	v0,v0,1
  5338c0:	03e00008 	jr	ra
  5338c4:	27bd0020 	addiu	sp,sp,32

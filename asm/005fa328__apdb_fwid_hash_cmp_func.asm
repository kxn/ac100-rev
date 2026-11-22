; func _apdb_fwid_hash_cmp_func @ 0x005fa328 size=0x20
  5fa328:	27bdffe0 	addiu	sp,sp,-32
  5fa32c:	afbf001c 	sw	ra,28(sp)
  5fa330:	0c101e4c 	jal	0x407930
  5fa334:	24060010 	li	a2,16
  5fa338:	8fbf001c 	lw	ra,28(sp)
  5fa33c:	2c420001 	sltiu	v0,v0,1
  5fa340:	03e00008 	jr	ra
  5fa344:	27bd0020 	addiu	sp,sp,32

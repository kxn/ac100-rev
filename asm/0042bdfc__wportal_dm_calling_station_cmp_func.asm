; func _wportal_dm_calling_station_cmp_func @ 0x0042bdfc size=0x20
  42bdfc:	27bdffe0 	addiu	sp,sp,-32
  42be00:	afbf001c 	sw	ra,28(sp)
  42be04:	0c101e4c 	jal	0x407930
  42be08:	24060006 	li	a2,6
  42be0c:	8fbf001c 	lw	ra,28(sp)
  42be10:	2c420001 	sltiu	v0,v0,1
  42be14:	03e00008 	jr	ra
  42be18:	27bd0020 	addiu	sp,sp,32

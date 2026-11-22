; func _sensor_scan_bssid_hash_cmp_func @ 0x004e2abc size=0x20
  4e2abc:	27bdffe0 	addiu	sp,sp,-32
  4e2ac0:	afbf001c 	sw	ra,28(sp)
  4e2ac4:	0c101e4c 	jal	0x407930
  4e2ac8:	24060006 	li	a2,6
  4e2acc:	8fbf001c 	lw	ra,28(sp)
  4e2ad0:	2c420001 	sltiu	v0,v0,1
  4e2ad4:	03e00008 	jr	ra
  4e2ad8:	27bd0020 	addiu	sp,sp,32

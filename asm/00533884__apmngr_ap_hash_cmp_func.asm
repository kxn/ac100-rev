; func _apmngr_ap_hash_cmp_func @ 0x00533884 size=0x24
  533884:	27bdffe0 	addiu	sp,sp,-32
  533888:	24840048 	addiu	a0,a0,72
  53388c:	afbf001c 	sw	ra,28(sp)
  533890:	0c101e4c 	jal	0x407930
  533894:	24060006 	li	a2,6
  533898:	8fbf001c 	lw	ra,28(sp)
  53389c:	2c420001 	sltiu	v0,v0,1
  5338a0:	03e00008 	jr	ra
  5338a4:	27bd0020 	addiu	sp,sp,32

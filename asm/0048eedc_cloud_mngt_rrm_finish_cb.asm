; func cloud_mngt_rrm_finish_cb @ 0x0048eedc size=0x2c
  48eedc:	3c020076 	lui	v0,0x76
  48eee0:	27bdffe0 	addiu	sp,sp,-32
  48eee4:	8c4277dc 	lw	v0,30684(v0)
  48eee8:	10400003 	beqz	v0,0x48eef8
  48eeec:	afbf001c 	sw	ra,28(sp)
  48eef0:	0c123b87 	jal	0x48ee1c
  48eef4:	2404000b 	li	a0,11
  48eef8:	8fbf001c 	lw	ra,28(sp)
  48eefc:	00001021 	move	v0,zero
  48ef00:	03e00008 	jr	ra
  48ef04:	27bd0020 	addiu	sp,sp,32

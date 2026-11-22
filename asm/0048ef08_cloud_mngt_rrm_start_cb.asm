; func cloud_mngt_rrm_start_cb @ 0x0048ef08 size=0x2c
  48ef08:	3c020076 	lui	v0,0x76
  48ef0c:	27bdffe0 	addiu	sp,sp,-32
  48ef10:	8c4277dc 	lw	v0,30684(v0)
  48ef14:	10400003 	beqz	v0,0x48ef24
  48ef18:	afbf001c 	sw	ra,28(sp)
  48ef1c:	0c123b87 	jal	0x48ee1c
  48ef20:	2404000a 	li	a0,10
  48ef24:	8fbf001c 	lw	ra,28(sp)
  48ef28:	00001021 	move	v0,zero
  48ef2c:	03e00008 	jr	ra
  48ef30:	27bd0020 	addiu	sp,sp,32

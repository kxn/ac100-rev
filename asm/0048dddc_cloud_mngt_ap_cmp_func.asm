; func cloud_mngt_ap_cmp_func @ 0x0048dddc size=0x30
  48dddc:	27bdffe0 	addiu	sp,sp,-32
  48dde0:	00001021 	move	v0,zero
  48dde4:	10800006 	beqz	a0,0x48de00
  48dde8:	afbf001c 	sw	ra,28(sp)
  48ddec:	10a00005 	beqz	a1,0x48de04
  48ddf0:	8fbf001c 	lw	ra,28(sp)
  48ddf4:	0c101f44 	jal	0x407d10
  48ddf8:	24840004 	addiu	a0,a0,4
  48ddfc:	2c420001 	sltiu	v0,v0,1
  48de00:	8fbf001c 	lw	ra,28(sp)
  48de04:	03e00008 	jr	ra
  48de08:	27bd0020 	addiu	sp,sp,32

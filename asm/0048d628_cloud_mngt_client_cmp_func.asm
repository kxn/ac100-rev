; func cloud_mngt_client_cmp_func @ 0x0048d628 size=0x30
  48d628:	27bdffe0 	addiu	sp,sp,-32
  48d62c:	00001021 	move	v0,zero
  48d630:	10800006 	beqz	a0,0x48d64c
  48d634:	afbf001c 	sw	ra,28(sp)
  48d638:	10a00004 	beqz	a1,0x48d64c
  48d63c:	24840004 	addiu	a0,a0,4
  48d640:	0c101e4c 	jal	0x407930
  48d644:	24060006 	li	a2,6
  48d648:	2c420001 	sltiu	v0,v0,1
  48d64c:	8fbf001c 	lw	ra,28(sp)
  48d650:	03e00008 	jr	ra
  48d654:	27bd0020 	addiu	sp,sp,32

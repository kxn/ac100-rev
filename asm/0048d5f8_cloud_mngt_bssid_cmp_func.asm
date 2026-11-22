; func cloud_mngt_bssid_cmp_func @ 0x0048d5f8 size=0x30
  48d5f8:	27bdffe0 	addiu	sp,sp,-32
  48d5fc:	00001021 	move	v0,zero
  48d600:	10800006 	beqz	a0,0x48d61c
  48d604:	afbf001c 	sw	ra,28(sp)
  48d608:	10a00004 	beqz	a1,0x48d61c
  48d60c:	24840004 	addiu	a0,a0,4
  48d610:	0c101e4c 	jal	0x407930
  48d614:	24060006 	li	a2,6
  48d618:	2c420001 	sltiu	v0,v0,1
  48d61c:	8fbf001c 	lw	ra,28(sp)
  48d620:	03e00008 	jr	ra
  48d624:	27bd0020 	addiu	sp,sp,32

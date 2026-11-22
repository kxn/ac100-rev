; func cloud_mngt_ap_key_hash_func @ 0x0048dd1c size=0x30
  48dd1c:	27bdffe0 	addiu	sp,sp,-32
  48dd20:	afb00018 	sw	s0,24(sp)
  48dd24:	afbf001c 	sw	ra,28(sp)
  48dd28:	0c101ee4 	jal	0x407b90
  48dd2c:	00808021 	move	s0,a0
  48dd30:	02002021 	move	a0,s0
  48dd34:	8fbf001c 	lw	ra,28(sp)
  48dd38:	00003021 	move	a2,zero
  48dd3c:	8fb00018 	lw	s0,24(sp)
  48dd40:	27bd0020 	addiu	sp,sp,32
  48dd44:	081020f4 	j	0x4083d0
  48dd48:	00402821 	move	a1,v0

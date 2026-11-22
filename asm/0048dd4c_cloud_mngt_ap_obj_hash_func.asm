; func cloud_mngt_ap_obj_hash_func @ 0x0048dd4c size=0x34
  48dd4c:	27bdffe0 	addiu	sp,sp,-32
  48dd50:	afb00018 	sw	s0,24(sp)
  48dd54:	24900004 	addiu	s0,a0,4
  48dd58:	afbf001c 	sw	ra,28(sp)
  48dd5c:	0c101ee4 	jal	0x407b90
  48dd60:	02002021 	move	a0,s0
  48dd64:	02002021 	move	a0,s0
  48dd68:	8fbf001c 	lw	ra,28(sp)
  48dd6c:	00003021 	move	a2,zero
  48dd70:	8fb00018 	lw	s0,24(sp)
  48dd74:	27bd0020 	addiu	sp,sp,32
  48dd78:	081020f4 	j	0x4083d0
  48dd7c:	00402821 	move	a1,v0

; func _apdb_unsupport_obj_hash_func @ 0x0060eca4 size=0x40
  60eca4:	27bdffe0 	addiu	sp,sp,-32
  60eca8:	afbf001c 	sw	ra,28(sp)
  60ecac:	afb00018 	sw	s0,24(sp)
  60ecb0:	0c101ee4 	jal	0x407b90
  60ecb4:	00808021 	move	s0,a0
  60ecb8:	00003021 	move	a2,zero
  60ecbc:	02002021 	move	a0,s0
  60ecc0:	0c1020f4 	jal	0x4083d0
  60ecc4:	00402821 	move	a1,v0
  60ecc8:	26040042 	addiu	a0,s0,66
  60eccc:	8fbf001c 	lw	ra,28(sp)
  60ecd0:	24050004 	li	a1,4
  60ecd4:	8fb00018 	lw	s0,24(sp)
  60ecd8:	27bd0020 	addiu	sp,sp,32
  60ecdc:	081020f4 	j	0x4083d0
  60ece0:	00403021 	move	a2,v0

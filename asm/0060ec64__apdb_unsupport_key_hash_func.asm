; func _apdb_unsupport_key_hash_func @ 0x0060ec64 size=0x40
  60ec64:	27bdffe0 	addiu	sp,sp,-32
  60ec68:	afbf001c 	sw	ra,28(sp)
  60ec6c:	afb00018 	sw	s0,24(sp)
  60ec70:	0c101ee4 	jal	0x407b90
  60ec74:	00808021 	move	s0,a0
  60ec78:	00003021 	move	a2,zero
  60ec7c:	02002021 	move	a0,s0
  60ec80:	0c1020f4 	jal	0x4083d0
  60ec84:	00402821 	move	a1,v0
  60ec88:	26040042 	addiu	a0,s0,66
  60ec8c:	8fbf001c 	lw	ra,28(sp)
  60ec90:	24050004 	li	a1,4
  60ec94:	8fb00018 	lw	s0,24(sp)
  60ec98:	27bd0020 	addiu	sp,sp,32
  60ec9c:	081020f4 	j	0x4083d0
  60eca0:	00403021 	move	a2,v0

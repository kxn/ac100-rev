; func _wportal_username_key_hash_func @ 0x0042c76c size=0x30
  42c76c:	27bdffe0 	addiu	sp,sp,-32
  42c770:	afb00018 	sw	s0,24(sp)
  42c774:	afbf001c 	sw	ra,28(sp)
  42c778:	0c101ee4 	jal	0x407b90
  42c77c:	00808021 	move	s0,a0
  42c780:	02002021 	move	a0,s0
  42c784:	8fbf001c 	lw	ra,28(sp)
  42c788:	00003021 	move	a2,zero
  42c78c:	8fb00018 	lw	s0,24(sp)
  42c790:	27bd0020 	addiu	sp,sp,32
  42c794:	081020f4 	j	0x4083d0
  42c798:	00402821 	move	a1,v0

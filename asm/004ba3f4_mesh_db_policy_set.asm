; func mesh_db_policy_set @ 0x004ba3f4 size=0x44
  4ba3f4:	27bdffe0 	addiu	sp,sp,-32
  4ba3f8:	2405ffff 	li	a1,-1
  4ba3fc:	afb00018 	sw	s0,24(sp)
  4ba400:	3c100076 	lui	s0,0x76
  4ba404:	afbf001c 	sw	ra,28(sp)
  4ba408:	26107eb0 	addiu	s0,s0,32432
  4ba40c:	0c1020b4 	jal	0x4082d0
  4ba410:	8e040004 	lw	a0,4(s0)
  4ba414:	24020019 	li	v0,25
  4ba418:	8e040004 	lw	a0,4(s0)
  4ba41c:	0c101fcc 	jal	0x407f30
  4ba420:	ae020100 	sw	v0,256(s0)
  4ba424:	00001021 	move	v0,zero
  4ba428:	8fbf001c 	lw	ra,28(sp)
  4ba42c:	8fb00018 	lw	s0,24(sp)
  4ba430:	03e00008 	jr	ra
  4ba434:	27bd0020 	addiu	sp,sp,32

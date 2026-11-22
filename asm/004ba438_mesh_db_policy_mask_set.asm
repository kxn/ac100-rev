; func mesh_db_policy_mask_set @ 0x004ba438 size=0x44
  4ba438:	27bdffe0 	addiu	sp,sp,-32
  4ba43c:	2405ffff 	li	a1,-1
  4ba440:	afb00018 	sw	s0,24(sp)
  4ba444:	3c100076 	lui	s0,0x76
  4ba448:	afbf001c 	sw	ra,28(sp)
  4ba44c:	26107eb0 	addiu	s0,s0,32432
  4ba450:	0c1020b4 	jal	0x4082d0
  4ba454:	8e040004 	lw	a0,4(s0)
  4ba458:	2402003f 	li	v0,63
  4ba45c:	8e040004 	lw	a0,4(s0)
  4ba460:	0c101fcc 	jal	0x407f30
  4ba464:	ae020104 	sw	v0,260(s0)
  4ba468:	00001021 	move	v0,zero
  4ba46c:	8fbf001c 	lw	ra,28(sp)
  4ba470:	8fb00018 	lw	s0,24(sp)
  4ba474:	03e00008 	jr	ra
  4ba478:	27bd0020 	addiu	sp,sp,32

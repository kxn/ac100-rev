; func rrm_group_id_set @ 0x004ae4e8 size=0x68
  4ae4e8:	2402ffff 	li	v0,-1
  4ae4ec:	7c042620 	seh	a0,a0
  4ae4f0:	50820013 	beql	a0,v0,0x4ae540
  4ae4f4:	3c040073 	lui	a0,0x73
  4ae4f8:	3082ffff 	andi	v0,a0,0xffff
  4ae4fc:	2c420200 	sltiu	v0,v0,512
  4ae500:	1040000d 	beqz	v0,0x4ae538
  4ae504:	00000000 	nop
  4ae508:	24840001 	addiu	a0,a0,1
  4ae50c:	3c020073 	lui	v0,0x73
  4ae510:	00041943 	sra	v1,a0,0x5
  4ae514:	2442191c 	addiu	v0,v0,6428
  4ae518:	24630002 	addiu	v1,v1,2
  4ae51c:	00031880 	sll	v1,v1,0x2
  4ae520:	00431021 	addu	v0,v0,v1
  4ae524:	24030001 	li	v1,1
  4ae528:	00832004 	sllv	a0,v1,a0
  4ae52c:	8c430004 	lw	v1,4(v0)
  4ae530:	00832025 	or	a0,a0,v1
  4ae534:	ac440004 	sw	a0,4(v0)
  4ae538:	03e00008 	jr	ra
  4ae53c:	00000000 	nop
  4ae540:	240500ff 	li	a1,255
  4ae544:	24841928 	addiu	a0,a0,6440
  4ae548:	08101cf0 	j	0x4073c0
  4ae54c:	24060040 	li	a2,64

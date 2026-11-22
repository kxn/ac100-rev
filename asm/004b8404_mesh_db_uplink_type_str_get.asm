; func mesh_db_uplink_type_str_get @ 0x004b8404 size=0x44
  4b8404:	3c03006a 	lui	v1,0x6a
  4b8408:	27bdffe8 	addiu	sp,sp,-24
  4b840c:	24632d14 	addiu	v1,v1,11540
  4b8410:	3c02006a 	lui	v0,0x6a
  4b8414:	afa3000c 	sw	v1,12(sp)
  4b8418:	3c03006a 	lui	v1,0x6a
  4b841c:	24428cb8 	addiu	v0,v0,-29512
  4b8420:	24632d1c 	addiu	v1,v1,11548
  4b8424:	afa20008 	sw	v0,8(sp)
  4b8428:	afa30010 	sw	v1,16(sp)
  4b842c:	2c830003 	sltiu	v1,a0,3
  4b8430:	10600003 	beqz	v1,0x4b8440
  4b8434:	00042080 	sll	a0,a0,0x2
  4b8438:	03a42021 	addu	a0,sp,a0
  4b843c:	8c820008 	lw	v0,8(a0)
  4b8440:	03e00008 	jr	ra
  4b8444:	27bd0018 	addiu	sp,sp,24

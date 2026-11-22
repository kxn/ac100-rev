; func rrm_group_id_unset @ 0x004ae550 size=0x6c
  4ae550:	2402ffff 	li	v0,-1
  4ae554:	7c042620 	seh	a0,a0
  4ae558:	50820014 	beql	a0,v0,0x4ae5ac
  4ae55c:	3c040073 	lui	a0,0x73
  4ae560:	3082ffff 	andi	v0,a0,0xffff
  4ae564:	2c420200 	sltiu	v0,v0,512
  4ae568:	1040000e 	beqz	v0,0x4ae5a4
  4ae56c:	00000000 	nop
  4ae570:	24840001 	addiu	a0,a0,1
  4ae574:	3c020073 	lui	v0,0x73
  4ae578:	00041943 	sra	v1,a0,0x5
  4ae57c:	2442191c 	addiu	v0,v0,6428
  4ae580:	24630002 	addiu	v1,v1,2
  4ae584:	00031880 	sll	v1,v1,0x2
  4ae588:	00431021 	addu	v0,v0,v1
  4ae58c:	24030001 	li	v1,1
  4ae590:	00832004 	sllv	a0,v1,a0
  4ae594:	8c430004 	lw	v1,4(v0)
  4ae598:	00042027 	nor	a0,zero,a0
  4ae59c:	00832024 	and	a0,a0,v1
  4ae5a0:	ac440004 	sw	a0,4(v0)
  4ae5a4:	03e00008 	jr	ra
  4ae5a8:	00000000 	nop
  4ae5ac:	00002821 	move	a1,zero
  4ae5b0:	24841928 	addiu	a0,a0,6440
  4ae5b4:	08101cf0 	j	0x4073c0
  4ae5b8:	24060040 	li	a2,64

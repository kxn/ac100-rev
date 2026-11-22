; func _sensor_di_db_sort_array_by_ascending_order @ 0x004dc510 size=0x5c
  4dc510:	00c7382a 	slt	a3,a2,a3
  4dc514:	10e00013 	beqz	a3,0x4dc564
  4dc518:	2402ffff 	li	v0,-1
  4dc51c:	04c00011 	bltz	a2,0x4dc564
  4dc520:	00000000 	nop
  4dc524:	10a0000f 	beqz	a1,0x4dc564
  4dc528:	00000000 	nop
  4dc52c:	00061080 	sll	v0,a2,0x2
  4dc530:	00a22821 	addu	a1,a1,v0
  4dc534:	10c0000a 	beqz	a2,0x4dc560
  4dc538:	aca40000 	sw	a0,0(a1)
  4dc53c:	8ca2fffc 	lw	v0,-4(a1)
  4dc540:	8ca30000 	lw	v1,0(a1)
  4dc544:	0062202a 	slt	a0,v1,v0
  4dc548:	10800003 	beqz	a0,0x4dc558
  4dc54c:	24c6ffff 	addiu	a2,a2,-1
  4dc550:	aca3fffc 	sw	v1,-4(a1)
  4dc554:	aca20000 	sw	v0,0(a1)
  4dc558:	14c0fff8 	bnez	a2,0x4dc53c
  4dc55c:	24a5fffc 	addiu	a1,a1,-4
  4dc560:	00001021 	move	v0,zero
  4dc564:	03e00008 	jr	ra
  4dc568:	00000000 	nop

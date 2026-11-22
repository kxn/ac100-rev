; func _udbg_thread_tnp_insert @ 0x005d3620 size=0x5c
  5d3620:	3c07007d 	lui	a3,0x7d
  5d3624:	3c06007d 	lui	a2,0x7d
  5d3628:	00001021 	move	v0,zero
  5d362c:	8ce5be68 	lw	a1,-16792(a3)
  5d3630:	08174d92 	j	0x5d3648
  5d3634:	24c3bc68 	addiu	v1,a2,-17304
  5d3638:	8c68fffc 	lw	t0,-4(v1)
  5d363c:	11040005 	beq	t0,a0,0x5d3654
  5d3640:	00000000 	nop
  5d3644:	24420001 	addiu	v0,v0,1
  5d3648:	0045402a 	slt	t0,v0,a1
  5d364c:	5500fffa 	bnezl	t0,0x5d3638
  5d3650:	24630004 	addiu	v1,v1,4
  5d3654:	10450003 	beq	v0,a1,0x5d3664
  5d3658:	00021880 	sll	v1,v0,0x2
  5d365c:	03e00008 	jr	ra
  5d3660:	00000000 	nop
  5d3664:	24c6bc68 	addiu	a2,a2,-17304
  5d3668:	24420001 	addiu	v0,v0,1
  5d366c:	00663021 	addu	a2,v1,a2
  5d3670:	ace2be68 	sw	v0,-16792(a3)
  5d3674:	03e00008 	jr	ra
  5d3678:	acc40000 	sw	a0,0(a2)

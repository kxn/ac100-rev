; func cw_priv_igmp_snooping_group_policy_length @ 0x005b3630 size=0x70
  5b3630:	10800017 	beqz	a0,0x5b3690
  5b3634:	00001021 	move	v0,zero
  5b3638:	8c850000 	lw	a1,0(a0)
  5b363c:	10a00014 	beqz	a1,0x5b3690
  5b3640:	24020004 	li	v0,4
  5b3644:	00001821 	move	v1,zero
  5b3648:	24090018 	li	t1,24
  5b364c:	24080001 	li	t0,1
  5b3650:	0816cd9b 	j	0x5b366c
  5b3654:	24070002 	li	a3,2
  5b3658:	50c7000f 	beql	a2,a3,0x5b3698
  5b365c:	24420012 	addiu	v0,v0,18
  5b3660:	24630001 	addiu	v1,v1,1
  5b3664:	1065000a 	beq	v1,a1,0x5b3690
  5b3668:	00000000 	nop
  5b366c:	70693002 	mul	a2,v1,t1
  5b3670:	8c8a0004 	lw	t2,4(a0)
  5b3674:	01463021 	addu	a2,t2,a2
  5b3678:	90c60004 	lbu	a2,4(a2)
  5b367c:	14c8fff6 	bne	a2,t0,0x5b3658
  5b3680:	00000000 	nop
  5b3684:	24420006 	addiu	v0,v0,6
  5b3688:	0816cd98 	j	0x5b3660
  5b368c:	3042ffff 	andi	v0,v0,0xffff
  5b3690:	03e00008 	jr	ra
  5b3694:	00000000 	nop
  5b3698:	0816cd98 	j	0x5b3660
  5b369c:	3042ffff 	andi	v0,v0,0xffff

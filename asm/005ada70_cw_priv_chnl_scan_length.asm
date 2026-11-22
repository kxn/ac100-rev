; func cw_priv_chnl_scan_length @ 0x005ada70 size=0x54
  5ada70:	10800005 	beqz	a0,0x5ada88
  5ada74:	00001021 	move	v0,zero
  5ada78:	90850001 	lbu	a1,1(a0)
  5ada7c:	24020002 	li	v0,2
  5ada80:	14a0000b 	bnez	a1,0x5adab0
  5ada84:	00001821 	move	v1,zero
  5ada88:	03e00008 	jr	ra
  5ada8c:	00000000 	nop
  5ada90:	10c0000a 	beqz	a2,0x5adabc
  5ada94:	00000000 	nop
  5ada98:	000338c0 	sll	a3,v1,0x3
  5ada9c:	24630001 	addiu	v1,v1,1
  5adaa0:	00c73021 	addu	a2,a2,a3
  5adaa4:	90c60001 	lbu	a2,1(a2)
  5adaa8:	24c60002 	addiu	a2,a2,2
  5adaac:	00461021 	addu	v0,v0,a2
  5adab0:	0065302a 	slt	a2,v1,a1
  5adab4:	54c0fff6 	bnezl	a2,0x5ada90
  5adab8:	8c860004 	lw	a2,4(a0)
  5adabc:	03e00008 	jr	ra
  5adac0:	3042ffff 	andi	v0,v0,0xffff

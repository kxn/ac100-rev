; func cw_priv_ap_statistics_length @ 0x005a7500 size=0x30
  5a7500:	10800009 	beqz	a0,0x5a7528
  5a7504:	00001021 	move	v0,zero
  5a7508:	90830000 	lbu	v1,0(a0)
  5a750c:	2402001c 	li	v0,28
  5a7510:	90840001 	lbu	a0,1(a0)
  5a7514:	00031940 	sll	v1,v1,0x5
  5a7518:	70821002 	mul	v0,a0,v0
  5a751c:	00621021 	addu	v0,v1,v0
  5a7520:	2442002a 	addiu	v0,v0,42
  5a7524:	3042ffff 	andi	v0,v0,0xffff
  5a7528:	03e00008 	jr	ra
  5a752c:	00000000 	nop

; func cw_priv_sta_assoc_req_length @ 0x005c12d0 size=0x30
  5c12d0:	10800009 	beqz	a0,0x5c12f8
  5c12d4:	00001021 	move	v0,zero
  5c12d8:	8c850008 	lw	a1,8(a0)
  5c12dc:	24030010 	li	v1,16
  5c12e0:	2402000c 	li	v0,12
  5c12e4:	28a50000 	slti	a1,a1,0
  5c12e8:	0065100b 	movn	v0,v1,a1
  5c12ec:	8c83000c 	lw	v1,12(a0)
  5c12f0:	00431021 	addu	v0,v0,v1
  5c12f4:	3042ffff 	andi	v0,v0,0xffff
  5c12f8:	03e00008 	jr	ra
  5c12fc:	00000000 	nop

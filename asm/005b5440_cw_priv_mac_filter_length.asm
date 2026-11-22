; func cw_priv_mac_filter_length @ 0x005b5440 size=0x28
  5b5440:	10800007 	beqz	a0,0x5b5460
  5b5444:	00001021 	move	v0,zero
  5b5448:	90820004 	lbu	v0,4(a0)
  5b544c:	8c830000 	lw	v1,0(a0)
  5b5450:	000210c2 	srl	v0,v0,0x3
  5b5454:	70431002 	mul	v0,v0,v1
  5b5458:	24420008 	addiu	v0,v0,8
  5b545c:	3042ffff 	andi	v0,v0,0xffff
  5b5460:	03e00008 	jr	ra
  5b5464:	00000000 	nop

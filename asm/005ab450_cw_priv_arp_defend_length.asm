; func cw_priv_arp_defend_length @ 0x005ab450 size=0x24
  5ab450:	10800006 	beqz	a0,0x5ab46c
  5ab454:	00001021 	move	v0,zero
  5ab458:	8c830004 	lw	v1,4(a0)
  5ab45c:	2402000a 	li	v0,10
  5ab460:	70621002 	mul	v0,v1,v0
  5ab464:	24420006 	addiu	v0,v0,6
  5ab468:	3042ffff 	andi	v0,v0,0xffff
  5ab46c:	03e00008 	jr	ra
  5ab470:	00000000 	nop

; func cw_priv_sniffing_statistics_length @ 0x005c0480 size=0x24
  5c0480:	10800006 	beqz	a0,0x5c049c
  5c0484:	00001021 	move	v0,zero
  5c0488:	8c830000 	lw	v1,0(a0)
  5c048c:	2402000e 	li	v0,14
  5c0490:	70621002 	mul	v0,v1,v0
  5c0494:	24420004 	addiu	v0,v0,4
  5c0498:	3042ffff 	andi	v0,v0,0xffff
  5c049c:	03e00008 	jr	ra
  5c04a0:	00000000 	nop

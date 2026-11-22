; func band_navigation_config_state_get @ 0x005602fc size=0x24
  5602fc:	10800006 	beqz	a0,0x560318
  560300:	2402ffff 	li	v0,-1
  560304:	10a00004 	beqz	a1,0x560318
  560308:	00000000 	nop
  56030c:	8c820004 	lw	v0,4(a0)
  560310:	aca20000 	sw	v0,0(a1)
  560314:	00001021 	move	v0,zero
  560318:	03e00008 	jr	ra
  56031c:	00000000 	nop

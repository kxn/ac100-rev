; func band_navigation_config_users_threshold_set @ 0x0056035c size=0x18
  56035c:	10800003 	beqz	a0,0x56036c
  560360:	2402ffff 	li	v0,-1
  560364:	00001021 	move	v0,zero
  560368:	ac850008 	sw	a1,8(a0)
  56036c:	03e00008 	jr	ra
  560370:	00000000 	nop

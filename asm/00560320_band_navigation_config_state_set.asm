; func band_navigation_config_state_set @ 0x00560320 size=0x18
  560320:	10800003 	beqz	a0,0x560330
  560324:	2402ffff 	li	v0,-1
  560328:	00001021 	move	v0,zero
  56032c:	ac850004 	sw	a1,4(a0)
  560330:	03e00008 	jr	ra
  560334:	00000000 	nop

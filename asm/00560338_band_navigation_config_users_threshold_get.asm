; func band_navigation_config_users_threshold_get @ 0x00560338 size=0x24
  560338:	10800006 	beqz	a0,0x560354
  56033c:	2402ffff 	li	v0,-1
  560340:	10a00004 	beqz	a1,0x560354
  560344:	00000000 	nop
  560348:	8c820008 	lw	v0,8(a0)
  56034c:	aca20000 	sw	v0,0(a1)
  560350:	00001021 	move	v0,zero
  560354:	03e00008 	jr	ra
  560358:	00000000 	nop

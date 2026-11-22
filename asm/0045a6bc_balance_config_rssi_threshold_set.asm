; func balance_config_rssi_threshold_set @ 0x0045a6bc size=0x18
  45a6bc:	10800003 	beqz	a0,0x45a6cc
  45a6c0:	2402ffff 	li	v0,-1
  45a6c4:	00001021 	move	v0,zero
  45a6c8:	ac850014 	sw	a1,20(a0)
  45a6cc:	03e00008 	jr	ra
  45a6d0:	00000000 	nop

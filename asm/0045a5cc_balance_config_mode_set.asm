; func balance_config_mode_set @ 0x0045a5cc size=0x18
  45a5cc:	10800003 	beqz	a0,0x45a5dc
  45a5d0:	2402ffff 	li	v0,-1
  45a5d4:	00001021 	move	v0,zero
  45a5d8:	ac850004 	sw	a1,4(a0)
  45a5dc:	03e00008 	jr	ra
  45a5e0:	00000000 	nop

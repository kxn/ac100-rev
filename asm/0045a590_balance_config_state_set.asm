; func balance_config_state_set @ 0x0045a590 size=0x18
  45a590:	10800003 	beqz	a0,0x45a5a0
  45a594:	2402ffff 	li	v0,-1
  45a598:	00001021 	move	v0,zero
  45a59c:	ac850000 	sw	a1,0(a0)
  45a5a0:	03e00008 	jr	ra
  45a5a4:	00000000 	nop

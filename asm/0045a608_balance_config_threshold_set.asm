; func balance_config_threshold_set @ 0x0045a608 size=0x18
  45a608:	10800003 	beqz	a0,0x45a618
  45a60c:	2402ffff 	li	v0,-1
  45a610:	00001021 	move	v0,zero
  45a614:	ac850008 	sw	a1,8(a0)
  45a618:	03e00008 	jr	ra
  45a61c:	00000000 	nop

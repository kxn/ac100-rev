; func balance_config_dif_threshold_set @ 0x0045a644 size=0x18
  45a644:	10800003 	beqz	a0,0x45a654
  45a648:	2402ffff 	li	v0,-1
  45a64c:	00001021 	move	v0,zero
  45a650:	ac85000c 	sw	a1,12(a0)
  45a654:	03e00008 	jr	ra
  45a658:	00000000 	nop

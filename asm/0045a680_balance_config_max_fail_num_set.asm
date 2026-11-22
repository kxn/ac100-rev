; func balance_config_max_fail_num_set @ 0x0045a680 size=0x18
  45a680:	10800003 	beqz	a0,0x45a690
  45a684:	2402ffff 	li	v0,-1
  45a688:	00001021 	move	v0,zero
  45a68c:	ac850010 	sw	a1,16(a0)
  45a690:	03e00008 	jr	ra
  45a694:	00000000 	nop

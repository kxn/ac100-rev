; func rrc_11a_multicast_rate_set @ 0x0055eed0 size=0x18
  55eed0:	10800003 	beqz	a0,0x55eee0
  55eed4:	2402ffff 	li	v0,-1
  55eed8:	00001021 	move	v0,zero
  55eedc:	ac850084 	sw	a1,132(a0)
  55eee0:	03e00008 	jr	ra
  55eee4:	00000000 	nop

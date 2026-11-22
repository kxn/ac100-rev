; func rrc_11b_multicast_rate_set @ 0x0055ef0c size=0x18
  55ef0c:	10800003 	beqz	a0,0x55ef1c
  55ef10:	2402ffff 	li	v0,-1
  55ef14:	00001021 	move	v0,zero
  55ef18:	ac850108 	sw	a1,264(a0)
  55ef1c:	03e00008 	jr	ra
  55ef20:	00000000 	nop

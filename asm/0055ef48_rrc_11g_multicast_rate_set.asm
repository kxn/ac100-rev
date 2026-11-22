; func rrc_11g_multicast_rate_set @ 0x0055ef48 size=0x18
  55ef48:	10800003 	beqz	a0,0x55ef58
  55ef4c:	2402ffff 	li	v0,-1
  55ef50:	00001021 	move	v0,zero
  55ef54:	ac85018c 	sw	a1,396(a0)
  55ef58:	03e00008 	jr	ra
  55ef5c:	00000000 	nop

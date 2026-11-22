; func rrc_11a_multicast_rate_get @ 0x0055eee8 size=0x24
  55eee8:	10800006 	beqz	a0,0x55ef04
  55eeec:	2402ffff 	li	v0,-1
  55eef0:	10a00004 	beqz	a1,0x55ef04
  55eef4:	00000000 	nop
  55eef8:	8c820084 	lw	v0,132(a0)
  55eefc:	aca20000 	sw	v0,0(a1)
  55ef00:	00001021 	move	v0,zero
  55ef04:	03e00008 	jr	ra
  55ef08:	00000000 	nop

; func band_navigation_config_max_failures_set @ 0x005603d4 size=0x18
  5603d4:	10800003 	beqz	a0,0x5603e4
  5603d8:	2402ffff 	li	v0,-1
  5603dc:	00001021 	move	v0,zero
  5603e0:	ac850010 	sw	a1,16(a0)
  5603e4:	03e00008 	jr	ra
  5603e8:	00000000 	nop
  5603ec:	00000000 	nop

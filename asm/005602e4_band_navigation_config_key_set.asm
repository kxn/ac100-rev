; func band_navigation_config_key_set @ 0x005602e4 size=0x18
  5602e4:	10800003 	beqz	a0,0x5602f4
  5602e8:	2402ffff 	li	v0,-1
  5602ec:	00001021 	move	v0,zero
  5602f0:	ac850000 	sw	a1,0(a0)
  5602f4:	03e00008 	jr	ra
  5602f8:	00000000 	nop

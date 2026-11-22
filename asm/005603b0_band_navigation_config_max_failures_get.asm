; func band_navigation_config_max_failures_get @ 0x005603b0 size=0x24
  5603b0:	10800006 	beqz	a0,0x5603cc
  5603b4:	2402ffff 	li	v0,-1
  5603b8:	10a00004 	beqz	a1,0x5603cc
  5603bc:	00000000 	nop
  5603c0:	8c820010 	lw	v0,16(a0)
  5603c4:	aca20000 	sw	v0,0(a1)
  5603c8:	00001021 	move	v0,zero
  5603cc:	03e00008 	jr	ra
  5603d0:	00000000 	nop

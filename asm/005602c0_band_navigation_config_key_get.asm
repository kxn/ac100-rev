; func band_navigation_config_key_get @ 0x005602c0 size=0x24
  5602c0:	10800006 	beqz	a0,0x5602dc
  5602c4:	2402ffff 	li	v0,-1
  5602c8:	10a00004 	beqz	a1,0x5602dc
  5602cc:	00000000 	nop
  5602d0:	8c820000 	lw	v0,0(a0)
  5602d4:	aca20000 	sw	v0,0(a1)
  5602d8:	00001021 	move	v0,zero
  5602dc:	03e00008 	jr	ra
  5602e0:	00000000 	nop

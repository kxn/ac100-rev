; func balance_config_threshold_get @ 0x0045a5e4 size=0x24
  45a5e4:	10800006 	beqz	a0,0x45a600
  45a5e8:	2402ffff 	li	v0,-1
  45a5ec:	10a00004 	beqz	a1,0x45a600
  45a5f0:	00000000 	nop
  45a5f4:	8c820008 	lw	v0,8(a0)
  45a5f8:	aca20000 	sw	v0,0(a1)
  45a5fc:	00001021 	move	v0,zero
  45a600:	03e00008 	jr	ra
  45a604:	00000000 	nop

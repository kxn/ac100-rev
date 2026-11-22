; func balance_config_mode_get @ 0x0045a5a8 size=0x24
  45a5a8:	10800006 	beqz	a0,0x45a5c4
  45a5ac:	2402ffff 	li	v0,-1
  45a5b0:	10a00004 	beqz	a1,0x45a5c4
  45a5b4:	00000000 	nop
  45a5b8:	8c820004 	lw	v0,4(a0)
  45a5bc:	aca20000 	sw	v0,0(a1)
  45a5c0:	00001021 	move	v0,zero
  45a5c4:	03e00008 	jr	ra
  45a5c8:	00000000 	nop

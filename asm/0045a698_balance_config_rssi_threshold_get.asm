; func balance_config_rssi_threshold_get @ 0x0045a698 size=0x24
  45a698:	10800006 	beqz	a0,0x45a6b4
  45a69c:	2402ffff 	li	v0,-1
  45a6a0:	10a00004 	beqz	a1,0x45a6b4
  45a6a4:	00000000 	nop
  45a6a8:	8c820014 	lw	v0,20(a0)
  45a6ac:	aca20000 	sw	v0,0(a1)
  45a6b0:	00001021 	move	v0,zero
  45a6b4:	03e00008 	jr	ra
  45a6b8:	00000000 	nop

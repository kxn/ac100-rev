; func balance_config_state_get @ 0x0045a56c size=0x24
  45a56c:	10800006 	beqz	a0,0x45a588
  45a570:	2402ffff 	li	v0,-1
  45a574:	10a00004 	beqz	a1,0x45a588
  45a578:	00000000 	nop
  45a57c:	8c820000 	lw	v0,0(a0)
  45a580:	aca20000 	sw	v0,0(a1)
  45a584:	00001021 	move	v0,zero
  45a588:	03e00008 	jr	ra
  45a58c:	00000000 	nop

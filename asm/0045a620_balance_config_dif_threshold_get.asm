; func balance_config_dif_threshold_get @ 0x0045a620 size=0x24
  45a620:	10800006 	beqz	a0,0x45a63c
  45a624:	2402ffff 	li	v0,-1
  45a628:	10a00004 	beqz	a1,0x45a63c
  45a62c:	00000000 	nop
  45a630:	8c82000c 	lw	v0,12(a0)
  45a634:	aca20000 	sw	v0,0(a1)
  45a638:	00001021 	move	v0,zero
  45a63c:	03e00008 	jr	ra
  45a640:	00000000 	nop

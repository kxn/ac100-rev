; func balance_config_max_fail_num_get @ 0x0045a65c size=0x24
  45a65c:	10800006 	beqz	a0,0x45a678
  45a660:	2402ffff 	li	v0,-1
  45a664:	10a00004 	beqz	a1,0x45a678
  45a668:	00000000 	nop
  45a66c:	8c820010 	lw	v0,16(a0)
  45a670:	aca20000 	sw	v0,0(a1)
  45a674:	00001021 	move	v0,zero
  45a678:	03e00008 	jr	ra
  45a67c:	00000000 	nop

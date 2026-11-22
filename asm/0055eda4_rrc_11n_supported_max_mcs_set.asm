; func rrc_11n_supported_max_mcs_set @ 0x0055eda4 size=0x18
  55eda4:	10800003 	beqz	a0,0x55edb4
  55eda8:	2402ffff 	li	v0,-1
  55edac:	00001021 	move	v0,zero
  55edb0:	ac850194 	sw	a1,404(a0)
  55edb4:	03e00008 	jr	ra
  55edb8:	00000000 	nop

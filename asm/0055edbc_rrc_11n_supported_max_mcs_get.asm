; func rrc_11n_supported_max_mcs_get @ 0x0055edbc size=0x24
  55edbc:	10800006 	beqz	a0,0x55edd8
  55edc0:	2402ffff 	li	v0,-1
  55edc4:	10a00004 	beqz	a1,0x55edd8
  55edc8:	00000000 	nop
  55edcc:	8c820194 	lw	v0,404(a0)
  55edd0:	aca20000 	sw	v0,0(a1)
  55edd4:	00001021 	move	v0,zero
  55edd8:	03e00008 	jr	ra
  55eddc:	00000000 	nop

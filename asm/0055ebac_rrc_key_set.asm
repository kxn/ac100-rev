; func rrc_key_set @ 0x0055ebac size=0x18
  55ebac:	10800003 	beqz	a0,0x55ebbc
  55ebb0:	2402ffff 	li	v0,-1
  55ebb4:	00001021 	move	v0,zero
  55ebb8:	ac850000 	sw	a1,0(a0)
  55ebbc:	03e00008 	jr	ra
  55ebc0:	00000000 	nop

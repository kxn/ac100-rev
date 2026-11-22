; func rrc_11b_supported_rate_set_set @ 0x0055eca8 size=0x20
  55eca8:	10800005 	beqz	a0,0x55ecc0
  55ecac:	00000000 	nop
  55ecb0:	10a00003 	beqz	a1,0x55ecc0
  55ecb4:	00000000 	nop
  55ecb8:	081579b5 	j	0x55e6d4
  55ecbc:	248400c8 	addiu	a0,a0,200
  55ecc0:	03e00008 	jr	ra
  55ecc4:	2402ffff 	li	v0,-1

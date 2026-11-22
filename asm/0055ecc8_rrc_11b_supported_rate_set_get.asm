; func rrc_11b_supported_rate_set_get @ 0x0055ecc8 size=0x20
  55ecc8:	10800005 	beqz	a0,0x55ece0
  55eccc:	00000000 	nop
  55ecd0:	10a00003 	beqz	a1,0x55ece0
  55ecd4:	00000000 	nop
  55ecd8:	08157968 	j	0x55e5a0
  55ecdc:	248400c8 	addiu	a0,a0,200
  55ece0:	03e00008 	jr	ra
  55ece4:	2402ffff 	li	v0,-1

; func rrc_11g_supported_rate_set_set @ 0x0055ed28 size=0x20
  55ed28:	10800005 	beqz	a0,0x55ed40
  55ed2c:	00000000 	nop
  55ed30:	10a00003 	beqz	a1,0x55ed40
  55ed34:	00000000 	nop
  55ed38:	081579b5 	j	0x55e6d4
  55ed3c:	2484014c 	addiu	a0,a0,332
  55ed40:	03e00008 	jr	ra
  55ed44:	2402ffff 	li	v0,-1

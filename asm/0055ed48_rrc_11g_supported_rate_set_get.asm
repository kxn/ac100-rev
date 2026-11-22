; func rrc_11g_supported_rate_set_get @ 0x0055ed48 size=0x20
  55ed48:	10800005 	beqz	a0,0x55ed60
  55ed4c:	00000000 	nop
  55ed50:	10a00003 	beqz	a1,0x55ed60
  55ed54:	00000000 	nop
  55ed58:	08157968 	j	0x55e5a0
  55ed5c:	2484014c 	addiu	a0,a0,332
  55ed60:	03e00008 	jr	ra
  55ed64:	2402ffff 	li	v0,-1

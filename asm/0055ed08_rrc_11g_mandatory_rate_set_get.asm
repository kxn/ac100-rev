; func rrc_11g_mandatory_rate_set_get @ 0x0055ed08 size=0x20
  55ed08:	10800005 	beqz	a0,0x55ed20
  55ed0c:	00000000 	nop
  55ed10:	10a00003 	beqz	a1,0x55ed20
  55ed14:	00000000 	nop
  55ed18:	08157968 	j	0x55e5a0
  55ed1c:	2484010c 	addiu	a0,a0,268
  55ed20:	03e00008 	jr	ra
  55ed24:	2402ffff 	li	v0,-1

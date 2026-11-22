; func rrc_11a_mandatory_rate_set_get @ 0x0055ec08 size=0x20
  55ec08:	10800005 	beqz	a0,0x55ec20
  55ec0c:	00000000 	nop
  55ec10:	10a00003 	beqz	a1,0x55ec20
  55ec14:	00000000 	nop
  55ec18:	08157968 	j	0x55e5a0
  55ec1c:	24840004 	addiu	a0,a0,4
  55ec20:	03e00008 	jr	ra
  55ec24:	2402ffff 	li	v0,-1

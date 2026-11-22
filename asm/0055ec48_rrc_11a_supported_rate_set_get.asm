; func rrc_11a_supported_rate_set_get @ 0x0055ec48 size=0x20
  55ec48:	10800005 	beqz	a0,0x55ec60
  55ec4c:	00000000 	nop
  55ec50:	10a00003 	beqz	a1,0x55ec60
  55ec54:	00000000 	nop
  55ec58:	08157968 	j	0x55e5a0
  55ec5c:	24840044 	addiu	a0,a0,68
  55ec60:	03e00008 	jr	ra
  55ec64:	2402ffff 	li	v0,-1

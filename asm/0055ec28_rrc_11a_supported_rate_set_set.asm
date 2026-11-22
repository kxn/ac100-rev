; func rrc_11a_supported_rate_set_set @ 0x0055ec28 size=0x20
  55ec28:	10800005 	beqz	a0,0x55ec40
  55ec2c:	00000000 	nop
  55ec30:	10a00003 	beqz	a1,0x55ec40
  55ec34:	00000000 	nop
  55ec38:	081579b5 	j	0x55e6d4
  55ec3c:	24840044 	addiu	a0,a0,68
  55ec40:	03e00008 	jr	ra
  55ec44:	2402ffff 	li	v0,-1

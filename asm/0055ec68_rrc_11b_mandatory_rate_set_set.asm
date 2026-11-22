; func rrc_11b_mandatory_rate_set_set @ 0x0055ec68 size=0x20
  55ec68:	10800005 	beqz	a0,0x55ec80
  55ec6c:	00000000 	nop
  55ec70:	10a00003 	beqz	a1,0x55ec80
  55ec74:	00000000 	nop
  55ec78:	081579b5 	j	0x55e6d4
  55ec7c:	24840088 	addiu	a0,a0,136
  55ec80:	03e00008 	jr	ra
  55ec84:	2402ffff 	li	v0,-1

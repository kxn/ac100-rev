; func rrc_11ac_supported_max_nss_get @ 0x0055ee34 size=0x24
  55ee34:	10800006 	beqz	a0,0x55ee50
  55ee38:	2402ffff 	li	v0,-1
  55ee3c:	10a00004 	beqz	a1,0x55ee50
  55ee40:	00000000 	nop
  55ee44:	8c8201a0 	lw	v0,416(a0)
  55ee48:	aca20000 	sw	v0,0(a1)
  55ee4c:	00001021 	move	v0,zero
  55ee50:	03e00008 	jr	ra
  55ee54:	00000000 	nop

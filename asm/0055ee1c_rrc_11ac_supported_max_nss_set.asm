; func rrc_11ac_supported_max_nss_set @ 0x0055ee1c size=0x18
  55ee1c:	10800003 	beqz	a0,0x55ee2c
  55ee20:	2402ffff 	li	v0,-1
  55ee24:	00001021 	move	v0,zero
  55ee28:	ac8501a0 	sw	a1,416(a0)
  55ee2c:	03e00008 	jr	ra
  55ee30:	00000000 	nop

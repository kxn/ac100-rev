; func rrc_11ax_supported_max_nss_set @ 0x0055ee94 size=0x18
  55ee94:	10800003 	beqz	a0,0x55eea4
  55ee98:	2402ffff 	li	v0,-1
  55ee9c:	00001021 	move	v0,zero
  55eea0:	ac8501ac 	sw	a1,428(a0)
  55eea4:	03e00008 	jr	ra
  55eea8:	00000000 	nop

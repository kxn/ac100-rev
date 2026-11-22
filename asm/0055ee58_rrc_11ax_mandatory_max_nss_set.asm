; func rrc_11ax_mandatory_max_nss_set @ 0x0055ee58 size=0x18
  55ee58:	10800003 	beqz	a0,0x55ee68
  55ee5c:	2402ffff 	li	v0,-1
  55ee60:	00001021 	move	v0,zero
  55ee64:	ac8501a8 	sw	a1,424(a0)
  55ee68:	03e00008 	jr	ra
  55ee6c:	00000000 	nop

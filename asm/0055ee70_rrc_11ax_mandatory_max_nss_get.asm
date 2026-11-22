; func rrc_11ax_mandatory_max_nss_get @ 0x0055ee70 size=0x24
  55ee70:	10800006 	beqz	a0,0x55ee8c
  55ee74:	2402ffff 	li	v0,-1
  55ee78:	10a00004 	beqz	a1,0x55ee8c
  55ee7c:	00000000 	nop
  55ee80:	8c8201a8 	lw	v0,424(a0)
  55ee84:	aca20000 	sw	v0,0(a1)
  55ee88:	00001021 	move	v0,zero
  55ee8c:	03e00008 	jr	ra
  55ee90:	00000000 	nop

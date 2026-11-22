; func rrc_11ac_mandatory_max_nss_get @ 0x0055edf8 size=0x24
  55edf8:	10800006 	beqz	a0,0x55ee14
  55edfc:	2402ffff 	li	v0,-1
  55ee00:	10a00004 	beqz	a1,0x55ee14
  55ee04:	00000000 	nop
  55ee08:	8c82019c 	lw	v0,412(a0)
  55ee0c:	aca20000 	sw	v0,0(a1)
  55ee10:	00001021 	move	v0,zero
  55ee14:	03e00008 	jr	ra
  55ee18:	00000000 	nop

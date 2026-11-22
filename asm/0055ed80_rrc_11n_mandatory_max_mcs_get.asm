; func rrc_11n_mandatory_max_mcs_get @ 0x0055ed80 size=0x24
  55ed80:	10800006 	beqz	a0,0x55ed9c
  55ed84:	2402ffff 	li	v0,-1
  55ed88:	10a00004 	beqz	a1,0x55ed9c
  55ed8c:	00000000 	nop
  55ed90:	8c820190 	lw	v0,400(a0)
  55ed94:	aca20000 	sw	v0,0(a1)
  55ed98:	00001021 	move	v0,zero
  55ed9c:	03e00008 	jr	ra
  55eda0:	00000000 	nop

; func rrc_11n_mandatory_max_mcs_set @ 0x0055ed68 size=0x18
  55ed68:	10800003 	beqz	a0,0x55ed78
  55ed6c:	2402ffff 	li	v0,-1
  55ed70:	00001021 	move	v0,zero
  55ed74:	ac850190 	sw	a1,400(a0)
  55ed78:	03e00008 	jr	ra
  55ed7c:	00000000 	nop

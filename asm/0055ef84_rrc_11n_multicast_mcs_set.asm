; func rrc_11n_multicast_mcs_set @ 0x0055ef84 size=0x18
  55ef84:	10800003 	beqz	a0,0x55ef94
  55ef88:	2402ffff 	li	v0,-1
  55ef8c:	00001021 	move	v0,zero
  55ef90:	ac850198 	sw	a1,408(a0)
  55ef94:	03e00008 	jr	ra
  55ef98:	00000000 	nop

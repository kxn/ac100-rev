; func rrc_11n_multicast_mcs_get @ 0x0055ef9c size=0x24
  55ef9c:	10800006 	beqz	a0,0x55efb8
  55efa0:	2402ffff 	li	v0,-1
  55efa4:	10a00004 	beqz	a1,0x55efb8
  55efa8:	00000000 	nop
  55efac:	8c820198 	lw	v0,408(a0)
  55efb0:	aca20000 	sw	v0,0(a1)
  55efb4:	00001021 	move	v0,zero
  55efb8:	03e00008 	jr	ra
  55efbc:	00000000 	nop

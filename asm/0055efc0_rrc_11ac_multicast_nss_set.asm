; func rrc_11ac_multicast_nss_set @ 0x0055efc0 size=0x18
  55efc0:	10800003 	beqz	a0,0x55efd0
  55efc4:	2402ffff 	li	v0,-1
  55efc8:	00001021 	move	v0,zero
  55efcc:	ac8501a4 	sw	a1,420(a0)
  55efd0:	03e00008 	jr	ra
  55efd4:	00000000 	nop

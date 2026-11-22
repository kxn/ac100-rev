; func rrc_11ac_multicast_nss_get @ 0x0055efd8 size=0x24
  55efd8:	10800006 	beqz	a0,0x55eff4
  55efdc:	2402ffff 	li	v0,-1
  55efe0:	10a00004 	beqz	a1,0x55eff4
  55efe4:	00000000 	nop
  55efe8:	8c8201a4 	lw	v0,420(a0)
  55efec:	aca20000 	sw	v0,0(a1)
  55eff0:	00001021 	move	v0,zero
  55eff4:	03e00008 	jr	ra
  55eff8:	00000000 	nop

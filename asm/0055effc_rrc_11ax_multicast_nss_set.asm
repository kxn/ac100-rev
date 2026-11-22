; func rrc_11ax_multicast_nss_set @ 0x0055effc size=0x18
  55effc:	10800003 	beqz	a0,0x55f00c
  55f000:	2402ffff 	li	v0,-1
  55f004:	00001021 	move	v0,zero
  55f008:	ac8501b0 	sw	a1,432(a0)
  55f00c:	03e00008 	jr	ra
  55f010:	00000000 	nop

; func rrc_11ax_multicast_nss_get @ 0x0055f014 size=0x24
  55f014:	10800006 	beqz	a0,0x55f030
  55f018:	2402ffff 	li	v0,-1
  55f01c:	10a00004 	beqz	a1,0x55f030
  55f020:	00000000 	nop
  55f024:	8c8201b0 	lw	v0,432(a0)
  55f028:	aca20000 	sw	v0,0(a1)
  55f02c:	00001021 	move	v0,zero
  55f030:	03e00008 	jr	ra
  55f034:	00000000 	nop
	...

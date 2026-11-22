; func rrc_11b_multicast_rate_get @ 0x0055ef24 size=0x24
  55ef24:	10800006 	beqz	a0,0x55ef40
  55ef28:	2402ffff 	li	v0,-1
  55ef2c:	10a00004 	beqz	a1,0x55ef40
  55ef30:	00000000 	nop
  55ef34:	8c820108 	lw	v0,264(a0)
  55ef38:	aca20000 	sw	v0,0(a1)
  55ef3c:	00001021 	move	v0,zero
  55ef40:	03e00008 	jr	ra
  55ef44:	00000000 	nop

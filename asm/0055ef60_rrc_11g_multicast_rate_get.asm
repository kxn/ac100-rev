; func rrc_11g_multicast_rate_get @ 0x0055ef60 size=0x24
  55ef60:	10800006 	beqz	a0,0x55ef7c
  55ef64:	2402ffff 	li	v0,-1
  55ef68:	10a00004 	beqz	a1,0x55ef7c
  55ef6c:	00000000 	nop
  55ef70:	8c82018c 	lw	v0,396(a0)
  55ef74:	aca20000 	sw	v0,0(a1)
  55ef78:	00001021 	move	v0,zero
  55ef7c:	03e00008 	jr	ra
  55ef80:	00000000 	nop

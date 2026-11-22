; func rrc_11ac_mandatory_max_nss_set @ 0x0055ede0 size=0x18
  55ede0:	10800003 	beqz	a0,0x55edf0
  55ede4:	2402ffff 	li	v0,-1
  55ede8:	00001021 	move	v0,zero
  55edec:	ac85019c 	sw	a1,412(a0)
  55edf0:	03e00008 	jr	ra
  55edf4:	00000000 	nop

; func cw_priv_sta_assoc_rslt_new_length @ 0x005c34f0 size=0x1c
  5c34f0:	10800004 	beqz	a0,0x5c3504
  5c34f4:	00001021 	move	v0,zero
  5c34f8:	8c820010 	lw	v0,16(a0)
  5c34fc:	24420011 	addiu	v0,v0,17
  5c3500:	3042ffff 	andi	v0,v0,0xffff
  5c3504:	03e00008 	jr	ra
  5c3508:	00000000 	nop

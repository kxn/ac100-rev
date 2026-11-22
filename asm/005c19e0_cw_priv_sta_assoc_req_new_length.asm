; func cw_priv_sta_assoc_req_new_length @ 0x005c19e0 size=0x1c
  5c19e0:	10800004 	beqz	a0,0x5c19f4
  5c19e4:	00001021 	move	v0,zero
  5c19e8:	8c820010 	lw	v0,16(a0)
  5c19ec:	24420011 	addiu	v0,v0,17
  5c19f0:	3042ffff 	andi	v0,v0,0xffff
  5c19f4:	03e00008 	jr	ra
  5c19f8:	00000000 	nop

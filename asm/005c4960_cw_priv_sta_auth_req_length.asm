; func cw_priv_sta_auth_req_length @ 0x005c4960 size=0x1c
  5c4960:	10800004 	beqz	a0,0x5c4974
  5c4964:	00001021 	move	v0,zero
  5c4968:	8c820008 	lw	v0,8(a0)
  5c496c:	2442000c 	addiu	v0,v0,12
  5c4970:	3042ffff 	andi	v0,v0,0xffff
  5c4974:	03e00008 	jr	ra
  5c4978:	00000000 	nop

; func cw_priv_two_way_passthrough_general_info_request_length @ 0x005c9ef0 size=0x1c
  5c9ef0:	10800004 	beqz	a0,0x5c9f04
  5c9ef4:	00001021 	move	v0,zero
  5c9ef8:	8c820008 	lw	v0,8(a0)
  5c9efc:	2442000c 	addiu	v0,v0,12
  5c9f00:	3042ffff 	andi	v0,v0,0xffff
  5c9f04:	03e00008 	jr	ra
  5c9f08:	00000000 	nop

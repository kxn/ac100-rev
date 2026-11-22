; func cw_priv_sta_list_length @ 0x005c66b0 size=0x24
  5c66b0:	10800006 	beqz	a0,0x5c66cc
  5c66b4:	00001021 	move	v0,zero
  5c66b8:	8c820004 	lw	v0,4(a0)
  5c66bc:	24030006 	li	v1,6
  5c66c0:	24420001 	addiu	v0,v0,1
  5c66c4:	70431002 	mul	v0,v0,v1
  5c66c8:	3042ffff 	andi	v0,v0,0xffff
  5c66cc:	03e00008 	jr	ra
  5c66d0:	00000000 	nop

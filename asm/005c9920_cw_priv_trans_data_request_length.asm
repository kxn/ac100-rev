; func cw_priv_trans_data_request_length @ 0x005c9920 size=0x1c
  5c9920:	10800004 	beqz	a0,0x5c9934
  5c9924:	00001021 	move	v0,zero
  5c9928:	8c820004 	lw	v0,4(a0)
  5c992c:	24420004 	addiu	v0,v0,4
  5c9930:	3042ffff 	andi	v0,v0,0xffff
  5c9934:	03e00008 	jr	ra
  5c9938:	00000000 	nop

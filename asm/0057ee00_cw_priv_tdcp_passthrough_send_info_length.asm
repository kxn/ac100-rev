; func cw_priv_tdcp_passthrough_send_info_length @ 0x0057ee00 size=0x1c
  57ee00:	10800004 	beqz	a0,0x57ee14
  57ee04:	00001021 	move	v0,zero
  57ee08:	8c820004 	lw	v0,4(a0)
  57ee0c:	24420009 	addiu	v0,v0,9
  57ee10:	3042ffff 	andi	v0,v0,0xffff
  57ee14:	03e00008 	jr	ra
  57ee18:	00000000 	nop

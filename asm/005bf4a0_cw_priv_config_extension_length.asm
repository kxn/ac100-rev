; func cw_priv_config_extension_length @ 0x005bf4a0 size=0x1c
  5bf4a0:	10800004 	beqz	a0,0x5bf4b4
  5bf4a4:	00001021 	move	v0,zero
  5bf4a8:	8c820004 	lw	v0,4(a0)
  5bf4ac:	24420005 	addiu	v0,v0,5
  5bf4b0:	3042ffff 	andi	v0,v0,0xffff
  5bf4b4:	03e00008 	jr	ra
  5bf4b8:	00000000 	nop

; func cw_priv_apdb_info_length @ 0x005aaed0 size=0x14
  5aaed0:	10800002 	beqz	a0,0x5aaedc
  5aaed4:	00001021 	move	v0,zero
  5aaed8:	94820000 	lhu	v0,0(a0)
  5aaedc:	03e00008 	jr	ra
  5aaee0:	00000000 	nop

; func cw_priv_ndp_para_length @ 0x005b7820 size=0x18
  5b7820:	10800003 	beqz	a0,0x5b7830
  5b7824:	00001021 	move	v0,zero
  5b7828:	90820013 	lbu	v0,19(a0)
  5b782c:	24420014 	addiu	v0,v0,20
  5b7830:	03e00008 	jr	ra
  5b7834:	00000000 	nop

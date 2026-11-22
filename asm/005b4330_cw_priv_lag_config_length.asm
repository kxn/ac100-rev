; func cw_priv_lag_config_length @ 0x005b4330 size=0x18
  5b4330:	10800003 	beqz	a0,0x5b4340
  5b4334:	00001021 	move	v0,zero
  5b4338:	90820002 	lbu	v0,2(a0)
  5b433c:	24420003 	addiu	v0,v0,3
  5b4340:	03e00008 	jr	ra
  5b4344:	00000000 	nop

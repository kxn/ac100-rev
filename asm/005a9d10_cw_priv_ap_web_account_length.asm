; func cw_priv_ap_web_account_length @ 0x005a9d10 size=0x20
  5a9d10:	10800005 	beqz	a0,0x5a9d28
  5a9d14:	00001021 	move	v0,zero
  5a9d18:	90820002 	lbu	v0,2(a0)
  5a9d1c:	90830003 	lbu	v1,3(a0)
  5a9d20:	24420004 	addiu	v0,v0,4
  5a9d24:	00431021 	addu	v0,v0,v1
  5a9d28:	03e00008 	jr	ra
  5a9d2c:	00000000 	nop

; func cw_priv_sta_auth_rslt_length @ 0x005c5050 size=0x1c
  5c5050:	10800004 	beqz	a0,0x5c5064
  5c5054:	00001021 	move	v0,zero
  5c5058:	8c82000c 	lw	v0,12(a0)
  5c505c:	24420010 	addiu	v0,v0,16
  5c5060:	3042ffff 	andi	v0,v0,0xffff
  5c5064:	03e00008 	jr	ra
  5c5068:	00000000 	nop

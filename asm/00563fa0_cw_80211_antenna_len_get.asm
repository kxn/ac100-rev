; func cw_80211_antenna_len_get @ 0x00563fa0 size=0x18
  563fa0:	10800003 	beqz	a0,0x563fb0
  563fa4:	00001021 	move	v0,zero
  563fa8:	90820003 	lbu	v0,3(a0)
  563fac:	24420004 	addiu	v0,v0,4
  563fb0:	03e00008 	jr	ra
  563fb4:	00000000 	nop

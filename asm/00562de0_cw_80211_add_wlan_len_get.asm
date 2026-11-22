; func cw_80211_add_wlan_len_get @ 0x00562de0 size=0x24
  562de0:	10800006 	beqz	a0,0x562dfc
  562de4:	00001021 	move	v0,zero
  562de8:	94830006 	lhu	v1,6(a0)
  562dec:	94820018 	lhu	v0,24(a0)
  562df0:	00621021 	addu	v0,v1,v0
  562df4:	24420013 	addiu	v0,v0,19
  562df8:	3042ffff 	andi	v0,v0,0xffff
  562dfc:	03e00008 	jr	ra
  562e00:	00000000 	nop

; func cw_80211_station_session_key_len_get @ 0x00568d70 size=0x1c
  568d70:	10800004 	beqz	a0,0x568d84
  568d74:	00001021 	move	v0,zero
  568d78:	94820014 	lhu	v0,20(a0)
  568d7c:	24420014 	addiu	v0,v0,20
  568d80:	3042ffff 	andi	v0,v0,0xffff
  568d84:	03e00008 	jr	ra
  568d88:	00000000 	nop

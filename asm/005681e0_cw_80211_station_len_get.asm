; func cw_80211_station_len_get @ 0x005681e0 size=0x18
  5681e0:	10800003 	beqz	a0,0x5681f0
  5681e4:	00001021 	move	v0,zero
  5681e8:	9082000f 	lbu	v0,15(a0)
  5681ec:	2442000d 	addiu	v0,v0,13
  5681f0:	03e00008 	jr	ra
  5681f4:	00000000 	nop

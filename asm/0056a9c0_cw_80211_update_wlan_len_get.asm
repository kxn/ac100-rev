; func cw_80211_update_wlan_len_get @ 0x0056a9c0 size=0x1c
  56a9c0:	10800004 	beqz	a0,0x56a9d4
  56a9c4:	00001021 	move	v0,zero
  56a9c8:	94820006 	lhu	v0,6(a0)
  56a9cc:	24420008 	addiu	v0,v0,8
  56a9d0:	3042ffff 	andi	v0,v0,0xffff
  56a9d4:	03e00008 	jr	ra
  56a9d8:	00000000 	nop

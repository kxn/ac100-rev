; func cw_80211_information_element_len_get @ 0x00565990 size=0x1c
  565990:	10800004 	beqz	a0,0x5659a4
  565994:	00001021 	move	v0,zero
  565998:	94820004 	lhu	v0,4(a0)
  56599c:	24420003 	addiu	v0,v0,3
  5659a0:	3042ffff 	andi	v0,v0,0xffff
  5659a4:	03e00008 	jr	ra
  5659a8:	00000000 	nop

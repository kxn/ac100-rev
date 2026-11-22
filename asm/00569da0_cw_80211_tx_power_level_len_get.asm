; func cw_80211_tx_power_level_len_get @ 0x00569da0 size=0x1c
  569da0:	10800004 	beqz	a0,0x569db4
  569da4:	00001021 	move	v0,zero
  569da8:	90820001 	lbu	v0,1(a0)
  569dac:	24420001 	addiu	v0,v0,1
  569db0:	00021040 	sll	v0,v0,0x1
  569db4:	03e00008 	jr	ra
  569db8:	00000000 	nop

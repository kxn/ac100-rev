; func cw_priv_delete_implicitly_leave_station_len_get @ 0x005af0f0 size=0x18
  5af0f0:	10800003 	beqz	a0,0x5af100
  5af0f4:	00001021 	move	v0,zero
  5af0f8:	90820001 	lbu	v0,1(a0)
  5af0fc:	24420002 	addiu	v0,v0,2
  5af100:	03e00008 	jr	ra
  5af104:	00000000 	nop

; func cw_delete_station_len_get @ 0x00574680 size=0x18
  574680:	10800003 	beqz	a0,0x574690
  574684:	00001021 	move	v0,zero
  574688:	90820001 	lbu	v0,1(a0)
  57468c:	24420002 	addiu	v0,v0,2
  574690:	03e00008 	jr	ra
  574694:	00000000 	nop

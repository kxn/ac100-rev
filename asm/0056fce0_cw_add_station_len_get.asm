; func cw_add_station_len_get @ 0x0056fce0 size=0x24
  56fce0:	10800006 	beqz	a0,0x56fcfc
  56fce4:	00001021 	move	v0,zero
  56fce8:	94820008 	lhu	v0,8(a0)
  56fcec:	90830001 	lbu	v1,1(a0)
  56fcf0:	24420002 	addiu	v0,v0,2
  56fcf4:	00431021 	addu	v0,v0,v1
  56fcf8:	3042ffff 	andi	v0,v0,0xffff
  56fcfc:	03e00008 	jr	ra
  56fd00:	00000000 	nop

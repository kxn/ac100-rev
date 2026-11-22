; func cw_priv_sta_assoc_rslt_length @ 0x005c2de0 size=0x1c
  5c2de0:	10800004 	beqz	a0,0x5c2df4
  5c2de4:	00001021 	move	v0,zero
  5c2de8:	8c82000c 	lw	v0,12(a0)
  5c2dec:	24420010 	addiu	v0,v0,16
  5c2df0:	3042ffff 	andi	v0,v0,0xffff
  5c2df4:	03e00008 	jr	ra
  5c2df8:	00000000 	nop

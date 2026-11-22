; func wips_status2str @ 0x004ca084 size=0x20
  4ca084:	24020001 	li	v0,1
  4ca088:	50820004 	beql	a0,v0,0x4ca09c
  4ca08c:	3c020069 	lui	v0,0x69
  4ca090:	3c02006c 	lui	v0,0x6c
  4ca094:	03e00008 	jr	ra
  4ca098:	244207e4 	addiu	v0,v0,2020
  4ca09c:	03e00008 	jr	ra
  4ca0a0:	2442badc 	addiu	v0,v0,-17700

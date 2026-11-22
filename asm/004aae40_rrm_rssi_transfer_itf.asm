; func rrm_rssi_transfer_itf @ 0x004aae40 size=0x24
  4aae40:	7c041c20 	seb	v1,a0
  4aae44:	24630064 	addiu	v1,v1,100
  4aae48:	24020064 	li	v0,100
  4aae4c:	70631802 	mul	v1,v1,v1
  4aae50:	004001f4 	teq	v0,zero,0x7
  4aae54:	0062001a 	div	zero,v1,v0
  4aae58:	00001012 	mflo	v0
  4aae5c:	03e00008 	jr	ra
  4aae60:	3042ffff 	andi	v0,v0,0xffff

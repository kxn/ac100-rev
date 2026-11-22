; func is_same_vendor @ 0x006022b0 size=0x18
  6022b0:	3c020075 	lui	v0,0x75
  6022b4:	308400ff 	andi	a0,a0,0xff
  6022b8:	8c42fe88 	lw	v0,-376(v0)
  6022bc:	00821026 	xor	v0,a0,v0
  6022c0:	03e00008 	jr	ra
  6022c4:	2c420001 	sltiu	v0,v0,1

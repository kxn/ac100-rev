; func cw_ac_packet_bitmap_enable @ 0x0058d2dc size=0x28
  58d2dc:	2c820020 	sltiu	v0,a0,32
  58d2e0:	10400006 	beqz	v0,0x58d2fc
  58d2e4:	3c020075 	lui	v0,0x75
  58d2e8:	24030001 	li	v1,1
  58d2ec:	00832004 	sllv	a0,v1,a0
  58d2f0:	8c43cf50 	lw	v1,-12464(v0)
  58d2f4:	00832025 	or	a0,a0,v1
  58d2f8:	ac44cf50 	sw	a0,-12464(v0)
  58d2fc:	03e00008 	jr	ra
  58d300:	00000000 	nop

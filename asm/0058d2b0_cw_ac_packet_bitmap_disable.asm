; func cw_ac_packet_bitmap_disable @ 0x0058d2b0 size=0x2c
  58d2b0:	2c820020 	sltiu	v0,a0,32
  58d2b4:	10400007 	beqz	v0,0x58d2d4
  58d2b8:	3c020075 	lui	v0,0x75
  58d2bc:	24030001 	li	v1,1
  58d2c0:	00832004 	sllv	a0,v1,a0
  58d2c4:	8c43cf50 	lw	v1,-12464(v0)
  58d2c8:	00042027 	nor	a0,zero,a0
  58d2cc:	00832024 	and	a0,a0,v1
  58d2d0:	ac44cf50 	sw	a0,-12464(v0)
  58d2d4:	03e00008 	jr	ra
  58d2d8:	00000000 	nop

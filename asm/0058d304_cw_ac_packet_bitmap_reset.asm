; func cw_ac_packet_bitmap_reset @ 0x0058d304 size=0x14
  58d304:	3c020075 	lui	v0,0x75
  58d308:	3c030fff 	lui	v1,0xfff
  58d30c:	3463ffff 	ori	v1,v1,0xffff
  58d310:	03e00008 	jr	ra
  58d314:	ac43cf50 	sw	v1,-12464(v0)

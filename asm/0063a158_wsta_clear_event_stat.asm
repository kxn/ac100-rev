; func wsta_clear_event_stat @ 0x0063a158 size=0x28
  63a158:	3c02007d 	lui	v0,0x7d
  63a15c:	ac40c730 	sw	zero,-14544(v0)
  63a160:	2442c730 	addiu	v0,v0,-14544
  63a164:	ac400004 	sw	zero,4(v0)
  63a168:	ac400008 	sw	zero,8(v0)
  63a16c:	ac40000c 	sw	zero,12(v0)
  63a170:	ac400010 	sw	zero,16(v0)
  63a174:	ac400014 	sw	zero,20(v0)
  63a178:	03e00008 	jr	ra
  63a17c:	ac400018 	sw	zero,24(v0)

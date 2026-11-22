; func wsta_roam_clear_pkt_info_stat @ 0x0048a380 size=0x28
  48a380:	3c020076 	lui	v0,0x76
  48a384:	ac4075c8 	sw	zero,30152(v0)
  48a388:	244275c8 	addiu	v0,v0,30152
  48a38c:	ac400004 	sw	zero,4(v0)
  48a390:	ac400008 	sw	zero,8(v0)
  48a394:	ac40000c 	sw	zero,12(v0)
  48a398:	ac400010 	sw	zero,16(v0)
  48a39c:	ac400014 	sw	zero,20(v0)
  48a3a0:	03e00008 	jr	ra
  48a3a4:	ac400018 	sw	zero,24(v0)

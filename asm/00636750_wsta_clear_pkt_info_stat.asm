; func wsta_clear_pkt_info_stat @ 0x00636750 size=0x24
  636750:	3c02007d 	lui	v0,0x7d
  636754:	ac40c670 	sw	zero,-14736(v0)
  636758:	2442c670 	addiu	v0,v0,-14736
  63675c:	ac400004 	sw	zero,4(v0)
  636760:	ac400008 	sw	zero,8(v0)
  636764:	ac40000c 	sw	zero,12(v0)
  636768:	ac400010 	sw	zero,16(v0)
  63676c:	03e00008 	jr	ra
  636770:	ac400014 	sw	zero,20(v0)

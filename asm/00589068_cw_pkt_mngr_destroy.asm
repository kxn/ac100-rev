; func cw_pkt_mngr_destroy @ 0x00589068 size=0x24
  589068:	10800006 	beqz	a0,0x589084
  58906c:	00000000 	nop
  589070:	ac800000 	sw	zero,0(a0)
  589074:	ac800004 	sw	zero,4(a0)
  589078:	ac800008 	sw	zero,8(a0)
  58907c:	ac80000c 	sw	zero,12(a0)
  589080:	ac800010 	sw	zero,16(a0)
  589084:	08101f7c 	j	0x407df0
  589088:	00000000 	nop

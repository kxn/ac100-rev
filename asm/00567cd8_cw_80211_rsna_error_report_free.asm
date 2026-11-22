; func cw_80211_rsna_error_report_free @ 0x00567cd8 size=0x3c
  567cd8:	27bdffe0 	addiu	sp,sp,-32
  567cdc:	afb00018 	sw	s0,24(sp)
  567ce0:	00808021 	move	s0,a0
  567ce4:	afbf001c 	sw	ra,28(sp)
  567ce8:	8c840010 	lw	a0,16(a0)
  567cec:	10800005 	beqz	a0,0x567d04
  567cf0:	8fbf001c 	lw	ra,28(sp)
  567cf4:	0c101f7c 	jal	0x407df0
  567cf8:	00000000 	nop
  567cfc:	ae000010 	sw	zero,16(s0)
  567d00:	8fbf001c 	lw	ra,28(sp)
  567d04:	00001021 	move	v0,zero
  567d08:	8fb00018 	lw	s0,24(sp)
  567d0c:	03e00008 	jr	ra
  567d10:	27bd0020 	addiu	sp,sp,32

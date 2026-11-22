; func cw_80211_assigned_wtp_bssid_free @ 0x005649b0 size=0x3c
  5649b0:	27bdffe0 	addiu	sp,sp,-32
  5649b4:	afb00018 	sw	s0,24(sp)
  5649b8:	00808021 	move	s0,a0
  5649bc:	afbf001c 	sw	ra,28(sp)
  5649c0:	8c840010 	lw	a0,16(a0)
  5649c4:	10800005 	beqz	a0,0x5649dc
  5649c8:	8fbf001c 	lw	ra,28(sp)
  5649cc:	0c101f7c 	jal	0x407df0
  5649d0:	00000000 	nop
  5649d4:	ae000010 	sw	zero,16(s0)
  5649d8:	8fbf001c 	lw	ra,28(sp)
  5649dc:	00001021 	move	v0,zero
  5649e0:	8fb00018 	lw	s0,24(sp)
  5649e4:	03e00008 	jr	ra
  5649e8:	27bd0020 	addiu	sp,sp,32

; func cw_80211_update_station_qos_free @ 0x0056a4e4 size=0x3c
  56a4e4:	27bdffe0 	addiu	sp,sp,-32
  56a4e8:	afb00018 	sw	s0,24(sp)
  56a4ec:	00808021 	move	s0,a0
  56a4f0:	afbf001c 	sw	ra,28(sp)
  56a4f4:	8c840010 	lw	a0,16(a0)
  56a4f8:	10800005 	beqz	a0,0x56a510
  56a4fc:	8fbf001c 	lw	ra,28(sp)
  56a500:	0c101f7c 	jal	0x407df0
  56a504:	00000000 	nop
  56a508:	ae000010 	sw	zero,16(s0)
  56a50c:	8fbf001c 	lw	ra,28(sp)
  56a510:	00001021 	move	v0,zero
  56a514:	8fb00018 	lw	s0,24(sp)
  56a518:	03e00008 	jr	ra
  56a51c:	27bd0020 	addiu	sp,sp,32

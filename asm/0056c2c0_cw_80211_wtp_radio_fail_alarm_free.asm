; func cw_80211_wtp_radio_fail_alarm_free @ 0x0056c2c0 size=0x3c
  56c2c0:	27bdffe0 	addiu	sp,sp,-32
  56c2c4:	afb00018 	sw	s0,24(sp)
  56c2c8:	00808021 	move	s0,a0
  56c2cc:	afbf001c 	sw	ra,28(sp)
  56c2d0:	8c840010 	lw	a0,16(a0)
  56c2d4:	10800005 	beqz	a0,0x56c2ec
  56c2d8:	8fbf001c 	lw	ra,28(sp)
  56c2dc:	0c101f7c 	jal	0x407df0
  56c2e0:	00000000 	nop
  56c2e4:	ae000010 	sw	zero,16(s0)
  56c2e8:	8fbf001c 	lw	ra,28(sp)
  56c2ec:	00001021 	move	v0,zero
  56c2f0:	8fb00018 	lw	s0,24(sp)
  56c2f4:	03e00008 	jr	ra
  56c2f8:	27bd0020 	addiu	sp,sp,32

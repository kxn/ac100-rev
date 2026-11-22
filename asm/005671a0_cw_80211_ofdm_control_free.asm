; func cw_80211_ofdm_control_free @ 0x005671a0 size=0x40
  5671a0:	27bdffe0 	addiu	sp,sp,-32
  5671a4:	afb00018 	sw	s0,24(sp)
  5671a8:	00808021 	move	s0,a0
  5671ac:	10800007 	beqz	a0,0x5671cc
  5671b0:	afbf001c 	sw	ra,28(sp)
  5671b4:	8c840010 	lw	a0,16(a0)
  5671b8:	10800005 	beqz	a0,0x5671d0
  5671bc:	8fbf001c 	lw	ra,28(sp)
  5671c0:	0c101f7c 	jal	0x407df0
  5671c4:	00000000 	nop
  5671c8:	ae000010 	sw	zero,16(s0)
  5671cc:	8fbf001c 	lw	ra,28(sp)
  5671d0:	00001021 	move	v0,zero
  5671d4:	8fb00018 	lw	s0,24(sp)
  5671d8:	03e00008 	jr	ra
  5671dc:	27bd0020 	addiu	sp,sp,32

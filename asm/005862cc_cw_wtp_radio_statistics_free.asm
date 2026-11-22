; func cw_wtp_radio_statistics_free @ 0x005862cc size=0x3c
  5862cc:	27bdffe0 	addiu	sp,sp,-32
  5862d0:	afb00018 	sw	s0,24(sp)
  5862d4:	00808021 	move	s0,a0
  5862d8:	afbf001c 	sw	ra,28(sp)
  5862dc:	8c840010 	lw	a0,16(a0)
  5862e0:	10800005 	beqz	a0,0x5862f8
  5862e4:	8fbf001c 	lw	ra,28(sp)
  5862e8:	0c101f7c 	jal	0x407df0
  5862ec:	00000000 	nop
  5862f0:	ae000010 	sw	zero,16(s0)
  5862f4:	8fbf001c 	lw	ra,28(sp)
  5862f8:	00001021 	move	v0,zero
  5862fc:	8fb00018 	lw	s0,24(sp)
  586300:	03e00008 	jr	ra
  586304:	27bd0020 	addiu	sp,sp,32

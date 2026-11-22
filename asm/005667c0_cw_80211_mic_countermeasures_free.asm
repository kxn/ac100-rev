; func cw_80211_mic_countermeasures_free @ 0x005667c0 size=0x3c
  5667c0:	27bdffe0 	addiu	sp,sp,-32
  5667c4:	afb00018 	sw	s0,24(sp)
  5667c8:	00808021 	move	s0,a0
  5667cc:	afbf001c 	sw	ra,28(sp)
  5667d0:	8c840010 	lw	a0,16(a0)
  5667d4:	10800005 	beqz	a0,0x5667ec
  5667d8:	8fbf001c 	lw	ra,28(sp)
  5667dc:	0c101f7c 	jal	0x407df0
  5667e0:	00000000 	nop
  5667e4:	ae000010 	sw	zero,16(s0)
  5667e8:	8fbf001c 	lw	ra,28(sp)
  5667ec:	00001021 	move	v0,zero
  5667f0:	8fb00018 	lw	s0,24(sp)
  5667f4:	03e00008 	jr	ra
  5667f8:	27bd0020 	addiu	sp,sp,32

; func cw_80211_wtp_radio_information_free @ 0x0056c880 size=0x3c
  56c880:	27bdffe0 	addiu	sp,sp,-32
  56c884:	afb00018 	sw	s0,24(sp)
  56c888:	00808021 	move	s0,a0
  56c88c:	afbf001c 	sw	ra,28(sp)
  56c890:	8c840010 	lw	a0,16(a0)
  56c894:	10800005 	beqz	a0,0x56c8ac
  56c898:	8fbf001c 	lw	ra,28(sp)
  56c89c:	0c101f7c 	jal	0x407df0
  56c8a0:	00000000 	nop
  56c8a4:	ae000010 	sw	zero,16(s0)
  56c8a8:	8fbf001c 	lw	ra,28(sp)
  56c8ac:	00001021 	move	v0,zero
  56c8b0:	8fb00018 	lw	s0,24(sp)
  56c8b4:	03e00008 	jr	ra
  56c8b8:	27bd0020 	addiu	sp,sp,32

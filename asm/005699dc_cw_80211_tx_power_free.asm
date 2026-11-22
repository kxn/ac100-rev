; func cw_80211_tx_power_free @ 0x005699dc size=0x3c
  5699dc:	27bdffe0 	addiu	sp,sp,-32
  5699e0:	afb00018 	sw	s0,24(sp)
  5699e4:	00808021 	move	s0,a0
  5699e8:	afbf001c 	sw	ra,28(sp)
  5699ec:	8c840010 	lw	a0,16(a0)
  5699f0:	10800005 	beqz	a0,0x569a08
  5699f4:	8fbf001c 	lw	ra,28(sp)
  5699f8:	0c101f7c 	jal	0x407df0
  5699fc:	00000000 	nop
  569a00:	ae000010 	sw	zero,16(s0)
  569a04:	8fbf001c 	lw	ra,28(sp)
  569a08:	00001021 	move	v0,zero
  569a0c:	8fb00018 	lw	s0,24(sp)
  569a10:	03e00008 	jr	ra
  569a14:	27bd0020 	addiu	sp,sp,32

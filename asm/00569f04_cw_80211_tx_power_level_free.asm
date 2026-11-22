; func cw_80211_tx_power_level_free @ 0x00569f04 size=0x3c
  569f04:	27bdffe0 	addiu	sp,sp,-32
  569f08:	afb00018 	sw	s0,24(sp)
  569f0c:	00808021 	move	s0,a0
  569f10:	afbf001c 	sw	ra,28(sp)
  569f14:	8c840010 	lw	a0,16(a0)
  569f18:	10800005 	beqz	a0,0x569f30
  569f1c:	8fbf001c 	lw	ra,28(sp)
  569f20:	0c101f7c 	jal	0x407df0
  569f24:	00000000 	nop
  569f28:	ae000010 	sw	zero,16(s0)
  569f2c:	8fbf001c 	lw	ra,28(sp)
  569f30:	00001021 	move	v0,zero
  569f34:	8fb00018 	lw	s0,24(sp)
  569f38:	03e00008 	jr	ra
  569f3c:	27bd0020 	addiu	sp,sp,32

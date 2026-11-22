; func cw_80211_supported_rates_free @ 0x0056956c size=0x3c
  56956c:	27bdffe0 	addiu	sp,sp,-32
  569570:	afb00018 	sw	s0,24(sp)
  569574:	00808021 	move	s0,a0
  569578:	afbf001c 	sw	ra,28(sp)
  56957c:	8c840010 	lw	a0,16(a0)
  569580:	10800005 	beqz	a0,0x569598
  569584:	8fbf001c 	lw	ra,28(sp)
  569588:	0c101f7c 	jal	0x407df0
  56958c:	00000000 	nop
  569590:	ae000010 	sw	zero,16(s0)
  569594:	8fbf001c 	lw	ra,28(sp)
  569598:	00001021 	move	v0,zero
  56959c:	8fb00018 	lw	s0,24(sp)
  5695a0:	03e00008 	jr	ra
  5695a4:	27bd0020 	addiu	sp,sp,32

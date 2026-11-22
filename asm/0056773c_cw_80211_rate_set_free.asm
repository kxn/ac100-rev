; func cw_80211_rate_set_free @ 0x0056773c size=0x3c
  56773c:	27bdffe0 	addiu	sp,sp,-32
  567740:	afb00018 	sw	s0,24(sp)
  567744:	00808021 	move	s0,a0
  567748:	afbf001c 	sw	ra,28(sp)
  56774c:	8c840010 	lw	a0,16(a0)
  567750:	10800005 	beqz	a0,0x567768
  567754:	8fbf001c 	lw	ra,28(sp)
  567758:	0c101f7c 	jal	0x407df0
  56775c:	00000000 	nop
  567760:	ae000010 	sw	zero,16(s0)
  567764:	8fbf001c 	lw	ra,28(sp)
  567768:	00001021 	move	v0,zero
  56776c:	8fb00018 	lw	s0,24(sp)
  567770:	03e00008 	jr	ra
  567774:	27bd0020 	addiu	sp,sp,32

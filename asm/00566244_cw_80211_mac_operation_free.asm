; func cw_80211_mac_operation_free @ 0x00566244 size=0x3c
  566244:	27bdffe0 	addiu	sp,sp,-32
  566248:	afb00018 	sw	s0,24(sp)
  56624c:	00808021 	move	s0,a0
  566250:	afbf001c 	sw	ra,28(sp)
  566254:	8c840010 	lw	a0,16(a0)
  566258:	10800005 	beqz	a0,0x566270
  56625c:	8fbf001c 	lw	ra,28(sp)
  566260:	0c101f7c 	jal	0x407df0
  566264:	00000000 	nop
  566268:	ae000010 	sw	zero,16(s0)
  56626c:	8fbf001c 	lw	ra,28(sp)
  566270:	00001021 	move	v0,zero
  566274:	8fb00018 	lw	s0,24(sp)
  566278:	03e00008 	jr	ra
  56627c:	27bd0020 	addiu	sp,sp,32

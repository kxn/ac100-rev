; func cw_80211_multidomain_capability_free @ 0x00566c98 size=0x3c
  566c98:	27bdffe0 	addiu	sp,sp,-32
  566c9c:	afb00018 	sw	s0,24(sp)
  566ca0:	00808021 	move	s0,a0
  566ca4:	afbf001c 	sw	ra,28(sp)
  566ca8:	8c840010 	lw	a0,16(a0)
  566cac:	10800005 	beqz	a0,0x566cc4
  566cb0:	8fbf001c 	lw	ra,28(sp)
  566cb4:	0c101f7c 	jal	0x407df0
  566cb8:	00000000 	nop
  566cbc:	ae000010 	sw	zero,16(s0)
  566cc0:	8fbf001c 	lw	ra,28(sp)
  566cc4:	00001021 	move	v0,zero
  566cc8:	8fb00018 	lw	s0,24(sp)
  566ccc:	03e00008 	jr	ra
  566cd0:	27bd0020 	addiu	sp,sp,32

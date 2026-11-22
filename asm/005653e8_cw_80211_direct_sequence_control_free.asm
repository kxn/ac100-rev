; func cw_80211_direct_sequence_control_free @ 0x005653e8 size=0x3c
  5653e8:	27bdffe0 	addiu	sp,sp,-32
  5653ec:	afb00018 	sw	s0,24(sp)
  5653f0:	00808021 	move	s0,a0
  5653f4:	afbf001c 	sw	ra,28(sp)
  5653f8:	8c840010 	lw	a0,16(a0)
  5653fc:	10800005 	beqz	a0,0x565414
  565400:	8fbf001c 	lw	ra,28(sp)
  565404:	0c101f7c 	jal	0x407df0
  565408:	00000000 	nop
  56540c:	ae000010 	sw	zero,16(s0)
  565410:	8fbf001c 	lw	ra,28(sp)
  565414:	00001021 	move	v0,zero
  565418:	8fb00018 	lw	s0,24(sp)
  56541c:	03e00008 	jr	ra
  565420:	27bd0020 	addiu	sp,sp,32

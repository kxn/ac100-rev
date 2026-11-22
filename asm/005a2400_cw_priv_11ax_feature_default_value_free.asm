; func cw_priv_11ax_feature_default_value_free @ 0x005a2400 size=0x3c
  5a2400:	27bdffe0 	addiu	sp,sp,-32
  5a2404:	afb00018 	sw	s0,24(sp)
  5a2408:	00808021 	move	s0,a0
  5a240c:	afbf001c 	sw	ra,28(sp)
  5a2410:	8c840010 	lw	a0,16(a0)
  5a2414:	10800005 	beqz	a0,0x5a242c
  5a2418:	8fbf001c 	lw	ra,28(sp)
  5a241c:	0c101f7c 	jal	0x407df0
  5a2420:	00000000 	nop
  5a2424:	ae000010 	sw	zero,16(s0)
  5a2428:	8fbf001c 	lw	ra,28(sp)
  5a242c:	00001021 	move	v0,zero
  5a2430:	8fb00018 	lw	s0,24(sp)
  5a2434:	03e00008 	jr	ra
  5a2438:	27bd0020 	addiu	sp,sp,32

; func cw_priv_clr_stat_free @ 0x005ae51c size=0x3c
  5ae51c:	27bdffe0 	addiu	sp,sp,-32
  5ae520:	afb00018 	sw	s0,24(sp)
  5ae524:	00808021 	move	s0,a0
  5ae528:	afbf001c 	sw	ra,28(sp)
  5ae52c:	8c840010 	lw	a0,16(a0)
  5ae530:	10800005 	beqz	a0,0x5ae548
  5ae534:	8fbf001c 	lw	ra,28(sp)
  5ae538:	0c101f7c 	jal	0x407df0
  5ae53c:	00000000 	nop
  5ae540:	ae000010 	sw	zero,16(s0)
  5ae544:	8fbf001c 	lw	ra,28(sp)
  5ae548:	00001021 	move	v0,zero
  5ae54c:	8fb00018 	lw	s0,24(sp)
  5ae550:	03e00008 	jr	ra
  5ae554:	27bd0020 	addiu	sp,sp,32

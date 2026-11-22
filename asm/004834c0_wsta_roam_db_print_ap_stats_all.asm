; func wsta_roam_db_print_ap_stats_all @ 0x004834c0 size=0x40
  4834c0:	27bdffe0 	addiu	sp,sp,-32
  4834c4:	afb00018 	sw	s0,24(sp)
  4834c8:	00008021 	move	s0,zero
  4834cc:	08120d37 	j	0x4834dc
  4834d0:	afbf001c 	sw	ra,28(sp)
  4834d4:	0c120cf7 	jal	0x4833dc
  4834d8:	26100001 	addiu	s0,s0,1
  4834dc:	0c1506a9 	jal	0x541aa4
  4834e0:	00000000 	nop
  4834e4:	0202102a 	slt	v0,s0,v0
  4834e8:	1440fffa 	bnez	v0,0x4834d4
  4834ec:	3204ffff 	andi	a0,s0,0xffff
  4834f0:	8fbf001c 	lw	ra,28(sp)
  4834f4:	8fb00018 	lw	s0,24(sp)
  4834f8:	03e00008 	jr	ra
  4834fc:	27bd0020 	addiu	sp,sp,32

; func _clear_backhaul_wserv_cfg @ 0x004e2420 size=0x94
  4e2420:	27bdffd8 	addiu	sp,sp,-40
  4e2424:	3c020077 	lui	v0,0x77
  4e2428:	afb10020 	sw	s1,32(sp)
  4e242c:	3c110073 	lui	s1,0x73
  4e2430:	afb0001c 	sw	s0,28(sp)
  4e2434:	2410ffff 	li	s0,-1
  4e2438:	afbf0024 	sw	ra,36(sp)
  4e243c:	ac408658 	sw	zero,-31144(v0)
  4e2440:	8e241b00 	lw	a0,6912(s1)
  4e2444:	50900005 	beql	a0,s0,0x4e245c
  4e2448:	3c100077 	lui	s0,0x77
  4e244c:	0c102018 	jal	0x408060
  4e2450:	00000000 	nop
  4e2454:	ae301b00 	sw	s0,6912(s1)
  4e2458:	3c100077 	lui	s0,0x77
  4e245c:	8e048660 	lw	a0,-31136(s0)
  4e2460:	50800005 	beqzl	a0,0x4e2478
  4e2464:	3c100077 	lui	s0,0x77
  4e2468:	0c101f7c 	jal	0x407df0
  4e246c:	00000000 	nop
  4e2470:	ae008660 	sw	zero,-31136(s0)
  4e2474:	3c100077 	lui	s0,0x77
  4e2478:	8e04865c 	lw	a0,-31140(s0)
  4e247c:	10800005 	beqz	a0,0x4e2494
  4e2480:	3c020077 	lui	v0,0x77
  4e2484:	0c101f7c 	jal	0x407df0
  4e2488:	00000000 	nop
  4e248c:	ae00865c 	sw	zero,-31140(s0)
  4e2490:	3c020077 	lui	v0,0x77
  4e2494:	8fbf0024 	lw	ra,36(sp)
  4e2498:	8fb10020 	lw	s1,32(sp)
  4e249c:	8fb0001c 	lw	s0,28(sp)
  4e24a0:	27bd0028 	addiu	sp,sp,40
  4e24a4:	ac408668 	sw	zero,-31128(v0)
  4e24a8:	3c020077 	lui	v0,0x77
  4e24ac:	03e00008 	jr	ra
  4e24b0:	ac408664 	sw	zero,-31132(v0)

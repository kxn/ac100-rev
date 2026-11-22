; func cw_priv_igmp_query_config_by_ssid_create @ 0x005b24ac size=0x1b4
  5b24ac:	27bdffd8 	addiu	sp,sp,-40
  5b24b0:	24050008 	li	a1,8
  5b24b4:	afb10020 	sw	s1,32(sp)
  5b24b8:	afb0001c 	sw	s0,28(sp)
  5b24bc:	afbf0024 	sw	ra,36(sp)
  5b24c0:	0c15c8cc 	jal	0x572330
  5b24c4:	00808021 	move	s0,a0
  5b24c8:	10400029 	beqz	v0,0x5b2570
  5b24cc:	00408821 	move	s1,v0
  5b24d0:	ac400004 	sw	zero,4(v0)
  5b24d4:	8e020000 	lw	v0,0(s0)
  5b24d8:	1040000a 	beqz	v0,0x5b2504
  5b24dc:	00000000 	nop
  5b24e0:	8e040004 	lw	a0,4(s0)
  5b24e4:	5080003e 	beqzl	a0,0x5b25e0
  5b24e8:	3c020075 	lui	v0,0x75
  5b24ec:	24050003 	li	a1,3
  5b24f0:	70452802 	mul	a1,v0,a1
  5b24f4:	0c15c8cc 	jal	0x572330
  5b24f8:	30a5ffff 	andi	a1,a1,0xffff
  5b24fc:	1040003f 	beqz	v0,0x5b25fc
  5b2500:	ae220004 	sw	v0,4(s1)
  5b2504:	0c16c8b4 	jal	0x5b22d0
  5b2508:	02202021 	move	a0,s1
  5b250c:	24040073 	li	a0,115
  5b2510:	00402821 	move	a1,v0
  5b2514:	0c15c943 	jal	0x57250c
  5b2518:	02203021 	move	a2,s1
  5b251c:	10400007 	beqz	v0,0x5b253c
  5b2520:	00408021 	move	s0,v0
  5b2524:	8fbf0024 	lw	ra,36(sp)
  5b2528:	02001021 	move	v0,s0
  5b252c:	8fb10020 	lw	s1,32(sp)
  5b2530:	8fb0001c 	lw	s0,28(sp)
  5b2534:	03e00008 	jr	ra
  5b2538:	27bd0028 	addiu	sp,sp,40
  5b253c:	3c020075 	lui	v0,0x75
  5b2540:	8c42cf58 	lw	v0,-12456(v0)
  5b2544:	1440001a 	bnez	v0,0x5b25b0
  5b2548:	00000000 	nop
  5b254c:	8e240004 	lw	a0,4(s1)
  5b2550:	10800003 	beqz	a0,0x5b2560
  5b2554:	00000000 	nop
  5b2558:	0c101f7c 	jal	0x407df0
  5b255c:	00000000 	nop
  5b2560:	0c101f7c 	jal	0x407df0
  5b2564:	02202021 	move	a0,s1
  5b2568:	0816c94a 	j	0x5b2528
  5b256c:	8fbf0024 	lw	ra,36(sp)
  5b2570:	3c020075 	lui	v0,0x75
  5b2574:	8c42cf58 	lw	v0,-12456(v0)
  5b2578:	1040ffea 	beqz	v0,0x5b2524
  5b257c:	00008021 	move	s0,zero
  5b2580:	0c16276a 	jal	0x589da8
  5b2584:	00000000 	nop
  5b2588:	5040ffe7 	beqzl	v0,0x5b2528
  5b258c:	8fbf0024 	lw	ra,36(sp)
  5b2590:	3c04006d 	lui	a0,0x6d
  5b2594:	3c05006f 	lui	a1,0x6f
  5b2598:	248434fc 	addiu	a0,a0,13564
  5b259c:	24a5b610 	addiu	a1,a1,-18928
  5b25a0:	0c101b74 	jal	0x406dd0
  5b25a4:	240600d8 	li	a2,216
  5b25a8:	0816c94a 	j	0x5b2528
  5b25ac:	8fbf0024 	lw	ra,36(sp)
  5b25b0:	0c16276a 	jal	0x589da8
  5b25b4:	00000000 	nop
  5b25b8:	5040ffe5 	beqzl	v0,0x5b2550
  5b25bc:	8e240004 	lw	a0,4(s1)
  5b25c0:	3c04006d 	lui	a0,0x6d
  5b25c4:	3c05006f 	lui	a1,0x6f
  5b25c8:	248447f0 	addiu	a0,a0,18416
  5b25cc:	24a5b610 	addiu	a1,a1,-18928
  5b25d0:	0c101b74 	jal	0x406dd0
  5b25d4:	240600f3 	li	a2,243
  5b25d8:	0816c954 	j	0x5b2550
  5b25dc:	8e240004 	lw	a0,4(s1)
  5b25e0:	8c42cf58 	lw	v0,-12456(v0)
  5b25e4:	14400015 	bnez	v0,0x5b263c
  5b25e8:	00000000 	nop
  5b25ec:	0c101f7c 	jal	0x407df0
  5b25f0:	02202021 	move	a0,s1
  5b25f4:	0816c949 	j	0x5b2524
  5b25f8:	00008021 	move	s0,zero
  5b25fc:	3c020075 	lui	v0,0x75
  5b2600:	8c42cf58 	lw	v0,-12456(v0)
  5b2604:	1040fff9 	beqz	v0,0x5b25ec
  5b2608:	00000000 	nop
  5b260c:	0c16276a 	jal	0x589da8
  5b2610:	00000000 	nop
  5b2614:	1040fff5 	beqz	v0,0x5b25ec
  5b2618:	3c04006f 	lui	a0,0x6f
  5b261c:	3c05006f 	lui	a1,0x6f
  5b2620:	248488e4 	addiu	a0,a0,-30492
  5b2624:	24a5b610 	addiu	a1,a1,-18928
  5b2628:	240600e9 	li	a2,233
  5b262c:	0c101b74 	jal	0x406dd0
  5b2630:	00000000 	nop
  5b2634:	0816c97b 	j	0x5b25ec
  5b2638:	00000000 	nop
  5b263c:	0c16276a 	jal	0x589da8
  5b2640:	00000000 	nop
  5b2644:	1040ffe9 	beqz	v0,0x5b25ec
  5b2648:	3c04006f 	lui	a0,0x6f
  5b264c:	3c05006f 	lui	a1,0x6f
  5b2650:	24848824 	addiu	a0,a0,-30684
  5b2654:	24a5b610 	addiu	a1,a1,-18928
  5b2658:	0816c98b 	j	0x5b262c
  5b265c:	240600e2 	li	a2,226

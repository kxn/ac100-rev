; func cw_priv_11ax_feature_default_value_create @ 0x005a2638 size=0xdc
  5a2638:	27bdffd8 	addiu	sp,sp,-40
  5a263c:	24050009 	li	a1,9
  5a2640:	afb0001c 	sw	s0,28(sp)
  5a2644:	afbf0024 	sw	ra,36(sp)
  5a2648:	0c15c8cc 	jal	0x572330
  5a264c:	afb10020 	sw	s1,32(sp)
  5a2650:	1040000d 	beqz	v0,0x5a2688
  5a2654:	00408021 	move	s0,v0
  5a2658:	240400b2 	li	a0,178
  5a265c:	24050004 	li	a1,4
  5a2660:	0c15c943 	jal	0x57250c
  5a2664:	00403021 	move	a2,v0
  5a2668:	10400017 	beqz	v0,0x5a26c8
  5a266c:	00408821 	move	s1,v0
  5a2670:	8fbf0024 	lw	ra,36(sp)
  5a2674:	02201021 	move	v0,s1
  5a2678:	8fb10020 	lw	s1,32(sp)
  5a267c:	8fb0001c 	lw	s0,28(sp)
  5a2680:	03e00008 	jr	ra
  5a2684:	27bd0028 	addiu	sp,sp,40
  5a2688:	3c020075 	lui	v0,0x75
  5a268c:	8c42cf58 	lw	v0,-12456(v0)
  5a2690:	1040fff7 	beqz	v0,0x5a2670
  5a2694:	00008821 	move	s1,zero
  5a2698:	0c16276a 	jal	0x589da8
  5a269c:	00000000 	nop
  5a26a0:	5040fff4 	beqzl	v0,0x5a2674
  5a26a4:	8fbf0024 	lw	ra,36(sp)
  5a26a8:	3c04006d 	lui	a0,0x6d
  5a26ac:	3c05006e 	lui	a1,0x6e
  5a26b0:	248434fc 	addiu	a0,a0,13564
  5a26b4:	24a56b40 	addiu	a1,a1,27456
  5a26b8:	0c101b74 	jal	0x406dd0
  5a26bc:	240600b8 	li	a2,184
  5a26c0:	0816899d 	j	0x5a2674
  5a26c4:	8fbf0024 	lw	ra,36(sp)
  5a26c8:	3c020075 	lui	v0,0x75
  5a26cc:	8c42cf58 	lw	v0,-12456(v0)
  5a26d0:	14400005 	bnez	v0,0x5a26e8
  5a26d4:	00000000 	nop
  5a26d8:	0c101f7c 	jal	0x407df0
  5a26dc:	02002021 	move	a0,s0
  5a26e0:	0816899d 	j	0x5a2674
  5a26e4:	8fbf0024 	lw	ra,36(sp)
  5a26e8:	0c16276a 	jal	0x589da8
  5a26ec:	00000000 	nop
  5a26f0:	1040fff9 	beqz	v0,0x5a26d8
  5a26f4:	3c04006d 	lui	a0,0x6d
  5a26f8:	3c05006e 	lui	a1,0x6e
  5a26fc:	248447f0 	addiu	a0,a0,18416
  5a2700:	24a56b40 	addiu	a1,a1,27456
  5a2704:	0c101b74 	jal	0x406dd0
  5a2708:	240600c0 	li	a2,192
  5a270c:	081689b6 	j	0x5a26d8
  5a2710:	00000000 	nop
	...

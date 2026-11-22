; func cw_priv_ap_tx_stat_create @ 0x005a9588 size=0xdc
  5a9588:	27bdffd8 	addiu	sp,sp,-40
  5a958c:	24050210 	li	a1,528
  5a9590:	afb0001c 	sw	s0,28(sp)
  5a9594:	afbf0024 	sw	ra,36(sp)
  5a9598:	0c15c8cc 	jal	0x572330
  5a959c:	afb10020 	sw	s1,32(sp)
  5a95a0:	1040000d 	beqz	v0,0x5a95d8
  5a95a4:	00408021 	move	s0,v0
  5a95a8:	2404002e 	li	a0,46
  5a95ac:	24050208 	li	a1,520
  5a95b0:	0c15c943 	jal	0x57250c
  5a95b4:	00403021 	move	a2,v0
  5a95b8:	10400017 	beqz	v0,0x5a9618
  5a95bc:	00408821 	move	s1,v0
  5a95c0:	8fbf0024 	lw	ra,36(sp)
  5a95c4:	02201021 	move	v0,s1
  5a95c8:	8fb10020 	lw	s1,32(sp)
  5a95cc:	8fb0001c 	lw	s0,28(sp)
  5a95d0:	03e00008 	jr	ra
  5a95d4:	27bd0028 	addiu	sp,sp,40
  5a95d8:	3c020075 	lui	v0,0x75
  5a95dc:	8c42cf58 	lw	v0,-12456(v0)
  5a95e0:	1040fff7 	beqz	v0,0x5a95c0
  5a95e4:	00008821 	move	s1,zero
  5a95e8:	0c16276a 	jal	0x589da8
  5a95ec:	00000000 	nop
  5a95f0:	5040fff4 	beqzl	v0,0x5a95c4
  5a95f4:	8fbf0024 	lw	ra,36(sp)
  5a95f8:	3c04006d 	lui	a0,0x6d
  5a95fc:	3c05006f 	lui	a1,0x6f
  5a9600:	248434fc 	addiu	a0,a0,13564
  5a9604:	24a58e10 	addiu	a1,a1,-29168
  5a9608:	0c101b74 	jal	0x406dd0
  5a960c:	2406012a 	li	a2,298
  5a9610:	0816a571 	j	0x5a95c4
  5a9614:	8fbf0024 	lw	ra,36(sp)
  5a9618:	3c020075 	lui	v0,0x75
  5a961c:	8c42cf58 	lw	v0,-12456(v0)
  5a9620:	14400005 	bnez	v0,0x5a9638
  5a9624:	00000000 	nop
  5a9628:	0c101f7c 	jal	0x407df0
  5a962c:	02002021 	move	a0,s0
  5a9630:	0816a571 	j	0x5a95c4
  5a9634:	8fbf0024 	lw	ra,36(sp)
  5a9638:	0c16276a 	jal	0x589da8
  5a963c:	00000000 	nop
  5a9640:	1040fff9 	beqz	v0,0x5a9628
  5a9644:	3c04006d 	lui	a0,0x6d
  5a9648:	3c05006f 	lui	a1,0x6f
  5a964c:	248447f0 	addiu	a0,a0,18416
  5a9650:	24a58e10 	addiu	a1,a1,-29168
  5a9654:	0c101b74 	jal	0x406dd0
  5a9658:	24060132 	li	a2,306
  5a965c:	0816a58a 	j	0x5a9628
  5a9660:	00000000 	nop
	...

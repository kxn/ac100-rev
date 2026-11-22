; func cw_priv_ap_led_status_create @ 0x005a5624 size=0xdc
  5a5624:	27bdffd8 	addiu	sp,sp,-40
  5a5628:	24050004 	li	a1,4
  5a562c:	afb0001c 	sw	s0,28(sp)
  5a5630:	afbf0024 	sw	ra,36(sp)
  5a5634:	0c15c8cc 	jal	0x572330
  5a5638:	afb10020 	sw	s1,32(sp)
  5a563c:	1040000d 	beqz	v0,0x5a5674
  5a5640:	00408021 	move	s0,v0
  5a5644:	24040038 	li	a0,56
  5a5648:	24050004 	li	a1,4
  5a564c:	0c15c943 	jal	0x57250c
  5a5650:	00403021 	move	a2,v0
  5a5654:	10400017 	beqz	v0,0x5a56b4
  5a5658:	00408821 	move	s1,v0
  5a565c:	8fbf0024 	lw	ra,36(sp)
  5a5660:	02201021 	move	v0,s1
  5a5664:	8fb10020 	lw	s1,32(sp)
  5a5668:	8fb0001c 	lw	s0,28(sp)
  5a566c:	03e00008 	jr	ra
  5a5670:	27bd0028 	addiu	sp,sp,40
  5a5674:	3c020075 	lui	v0,0x75
  5a5678:	8c42cf58 	lw	v0,-12456(v0)
  5a567c:	1040fff7 	beqz	v0,0x5a565c
  5a5680:	00008821 	move	s1,zero
  5a5684:	0c16276a 	jal	0x589da8
  5a5688:	00000000 	nop
  5a568c:	5040fff4 	beqzl	v0,0x5a5660
  5a5690:	8fbf0024 	lw	ra,36(sp)
  5a5694:	3c04006d 	lui	a0,0x6d
  5a5698:	3c05006e 	lui	a1,0x6e
  5a569c:	248434fc 	addiu	a0,a0,13564
  5a56a0:	24a57a70 	addiu	a1,a1,31344
  5a56a4:	0c101b74 	jal	0x406dd0
  5a56a8:	240600a2 	li	a2,162
  5a56ac:	08169598 	j	0x5a5660
  5a56b0:	8fbf0024 	lw	ra,36(sp)
  5a56b4:	3c020075 	lui	v0,0x75
  5a56b8:	8c42cf58 	lw	v0,-12456(v0)
  5a56bc:	14400005 	bnez	v0,0x5a56d4
  5a56c0:	00000000 	nop
  5a56c4:	0c101f7c 	jal	0x407df0
  5a56c8:	02002021 	move	a0,s0
  5a56cc:	08169598 	j	0x5a5660
  5a56d0:	8fbf0024 	lw	ra,36(sp)
  5a56d4:	0c16276a 	jal	0x589da8
  5a56d8:	00000000 	nop
  5a56dc:	1040fff9 	beqz	v0,0x5a56c4
  5a56e0:	3c04006d 	lui	a0,0x6d
  5a56e4:	3c05006e 	lui	a1,0x6e
  5a56e8:	248447f0 	addiu	a0,a0,18416
  5a56ec:	24a57a70 	addiu	a1,a1,31344
  5a56f0:	0c101b74 	jal	0x406dd0
  5a56f4:	240600aa 	li	a2,170
  5a56f8:	081695b1 	j	0x5a56c4
  5a56fc:	00000000 	nop

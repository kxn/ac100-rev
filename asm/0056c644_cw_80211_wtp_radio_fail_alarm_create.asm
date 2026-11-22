; func cw_80211_wtp_radio_fail_alarm_create @ 0x0056c644 size=0xdc
  56c644:	27bdffd8 	addiu	sp,sp,-40
  56c648:	24050004 	li	a1,4
  56c64c:	afb0001c 	sw	s0,28(sp)
  56c650:	afbf0024 	sw	ra,36(sp)
  56c654:	0c15c8cc 	jal	0x572330
  56c658:	afb10020 	sw	s1,32(sp)
  56c65c:	1040000d 	beqz	v0,0x56c694
  56c660:	00408021 	move	s0,v0
  56c664:	24040417 	li	a0,1047
  56c668:	24050004 	li	a1,4
  56c66c:	0c15c943 	jal	0x57250c
  56c670:	00403021 	move	a2,v0
  56c674:	10400017 	beqz	v0,0x56c6d4
  56c678:	00408821 	move	s1,v0
  56c67c:	8fbf0024 	lw	ra,36(sp)
  56c680:	02201021 	move	v0,s1
  56c684:	8fb10020 	lw	s1,32(sp)
  56c688:	8fb0001c 	lw	s0,28(sp)
  56c68c:	03e00008 	jr	ra
  56c690:	27bd0028 	addiu	sp,sp,40
  56c694:	3c020075 	lui	v0,0x75
  56c698:	8c42cf58 	lw	v0,-12456(v0)
  56c69c:	1040fff7 	beqz	v0,0x56c67c
  56c6a0:	00008821 	move	s1,zero
  56c6a4:	0c16276a 	jal	0x589da8
  56c6a8:	00000000 	nop
  56c6ac:	5040fff4 	beqzl	v0,0x56c680
  56c6b0:	8fbf0024 	lw	ra,36(sp)
  56c6b4:	3c04006d 	lui	a0,0x6d
  56c6b8:	3c05006d 	lui	a1,0x6d
  56c6bc:	248434fc 	addiu	a0,a0,13564
  56c6c0:	24a56080 	addiu	a1,a1,24704
  56c6c4:	0c101b74 	jal	0x406dd0
  56c6c8:	240600cc 	li	a2,204
  56c6cc:	0815b1a0 	j	0x56c680
  56c6d0:	8fbf0024 	lw	ra,36(sp)
  56c6d4:	3c020075 	lui	v0,0x75
  56c6d8:	8c42cf58 	lw	v0,-12456(v0)
  56c6dc:	14400005 	bnez	v0,0x56c6f4
  56c6e0:	00000000 	nop
  56c6e4:	0c101f7c 	jal	0x407df0
  56c6e8:	02002021 	move	a0,s0
  56c6ec:	0815b1a0 	j	0x56c680
  56c6f0:	8fbf0024 	lw	ra,36(sp)
  56c6f4:	0c16276a 	jal	0x589da8
  56c6f8:	00000000 	nop
  56c6fc:	1040fff9 	beqz	v0,0x56c6e4
  56c700:	3c04006d 	lui	a0,0x6d
  56c704:	3c05006d 	lui	a1,0x6d
  56c708:	248447f0 	addiu	a0,a0,18416
  56c70c:	24a56080 	addiu	a1,a1,24704
  56c710:	0c101b74 	jal	0x406dd0
  56c714:	240600d4 	li	a2,212
  56c718:	0815b1b9 	j	0x56c6e4
  56c71c:	00000000 	nop

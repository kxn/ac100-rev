; func apupd_update_wtp_entry_delete_only @ 0x0064c520 size=0x150
  64c520:	27bdffd8 	addiu	sp,sp,-40
  64c524:	3c02007d 	lui	v0,0x7d
  64c528:	afb10020 	sw	s1,32(sp)
  64c52c:	00808821 	move	s1,a0
  64c530:	afbf0024 	sw	ra,36(sp)
  64c534:	02202821 	move	a1,s1
  64c538:	afb0001c 	sw	s0,28(sp)
  64c53c:	0c101fd0 	jal	0x407f40
  64c540:	8c44c7a8 	lw	a0,-14424(v0)
  64c544:	5040000f 	beqzl	v0,0x64c584
  64c548:	8e240028 	lw	a0,40(s1)
  64c54c:	3c020076 	lui	v0,0x76
  64c550:	8c428c08 	lw	v0,-29688(v0)
  64c554:	10400005 	beqz	v0,0x64c56c
  64c558:	2410ffff 	li	s0,-1
  64c55c:	0c16276a 	jal	0x589da8
  64c560:	00000000 	nop
  64c564:	1440002f 	bnez	v0,0x64c624
  64c568:	3c040071 	lui	a0,0x71
  64c56c:	8fbf0024 	lw	ra,36(sp)
  64c570:	02001021 	move	v0,s0
  64c574:	8fb10020 	lw	s1,32(sp)
  64c578:	8fb0001c 	lw	s0,28(sp)
  64c57c:	03e00008 	jr	ra
  64c580:	27bd0028 	addiu	sp,sp,40
  64c584:	2410ffff 	li	s0,-1
  64c588:	50900005 	beql	a0,s0,0x64c5a0
  64c58c:	8e220038 	lw	v0,56(s1)
  64c590:	0c102018 	jal	0x408060
  64c594:	00000000 	nop
  64c598:	ae300028 	sw	s0,40(s1)
  64c59c:	8e220038 	lw	v0,56(s1)
  64c5a0:	10400012 	beqz	v0,0x64c5ec
  64c5a4:	00000000 	nop
  64c5a8:	8c440004 	lw	a0,4(v0)
  64c5ac:	1080000c 	beqz	a0,0x64c5e0
  64c5b0:	00000000 	nop
  64c5b4:	0c101f7c 	jal	0x407df0
  64c5b8:	3c10007d 	lui	s0,0x7d
  64c5bc:	8e220038 	lw	v0,56(s1)
  64c5c0:	ac400004 	sw	zero,4(v0)
  64c5c4:	8e02c7dc 	lw	v0,-14372(s0)
  64c5c8:	2442ffff 	addiu	v0,v0,-1
  64c5cc:	ae02c7dc 	sw	v0,-14372(s0)
  64c5d0:	3c02007d 	lui	v0,0x7d
  64c5d4:	8c42c758 	lw	v0,-14504(v0)
  64c5d8:	14400019 	bnez	v0,0x64c640
  64c5dc:	00000000 	nop
  64c5e0:	0c101f7c 	jal	0x407df0
  64c5e4:	8e240038 	lw	a0,56(s1)
  64c5e8:	ae200038 	sw	zero,56(s1)
  64c5ec:	0c102140 	jal	0x408500
  64c5f0:	02202021 	move	a0,s1
  64c5f4:	2624000c 	addiu	a0,s1,12
  64c5f8:	0c102140 	jal	0x408500
  64c5fc:	00008021 	move	s0,zero
  64c600:	02202021 	move	a0,s1
  64c604:	8e220030 	lw	v0,48(s1)
  64c608:	8c420050 	lw	v0,80(v0)
  64c60c:	8c430144 	lw	v1,324(v0)
  64c610:	2463ffff 	addiu	v1,v1,-1
  64c614:	0c101f7c 	jal	0x407df0
  64c618:	ac430144 	sw	v1,324(v0)
  64c61c:	0819315c 	j	0x64c570
  64c620:	8fbf0024 	lw	ra,36(sp)
  64c624:	3c050072 	lui	a1,0x72
  64c628:	24844b78 	addiu	a0,a0,19320
  64c62c:	24a59e8c 	addiu	a1,a1,-24948
  64c630:	0c101b74 	jal	0x406dd0
  64c634:	240604fe 	li	a2,1278
  64c638:	0819315c 	j	0x64c570
  64c63c:	8fbf0024 	lw	ra,36(sp)
  64c640:	0c16276a 	jal	0x589da8
  64c644:	00000000 	nop
  64c648:	1040ffe5 	beqz	v0,0x64c5e0
  64c64c:	3c040071 	lui	a0,0x71
  64c650:	8e07c7dc 	lw	a3,-14372(s0)
  64c654:	3c050072 	lui	a1,0x72
  64c658:	24844bb8 	addiu	a0,a0,19384
  64c65c:	24a59e8c 	addiu	a1,a1,-24948
  64c660:	0c101b74 	jal	0x406dd0
  64c664:	2406050f 	li	a2,1295
  64c668:	08193178 	j	0x64c5e0
  64c66c:	00000000 	nop

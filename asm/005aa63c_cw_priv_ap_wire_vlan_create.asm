; func cw_priv_ap_wire_vlan_create @ 0x005aa63c size=0xdc
  5aa63c:	27bdffd8 	addiu	sp,sp,-40
  5aa640:	24050004 	li	a1,4
  5aa644:	afb0001c 	sw	s0,28(sp)
  5aa648:	afbf0024 	sw	ra,36(sp)
  5aa64c:	0c15c8cc 	jal	0x572330
  5aa650:	afb10020 	sw	s1,32(sp)
  5aa654:	1040000d 	beqz	v0,0x5aa68c
  5aa658:	00408021 	move	s0,v0
  5aa65c:	24040030 	li	a0,48
  5aa660:	24050004 	li	a1,4
  5aa664:	0c15c943 	jal	0x57250c
  5aa668:	00403021 	move	a2,v0
  5aa66c:	10400017 	beqz	v0,0x5aa6cc
  5aa670:	00408821 	move	s1,v0
  5aa674:	8fbf0024 	lw	ra,36(sp)
  5aa678:	02201021 	move	v0,s1
  5aa67c:	8fb10020 	lw	s1,32(sp)
  5aa680:	8fb0001c 	lw	s0,28(sp)
  5aa684:	03e00008 	jr	ra
  5aa688:	27bd0028 	addiu	sp,sp,40
  5aa68c:	3c020075 	lui	v0,0x75
  5aa690:	8c42cf58 	lw	v0,-12456(v0)
  5aa694:	1040fff7 	beqz	v0,0x5aa674
  5aa698:	00008821 	move	s1,zero
  5aa69c:	0c16276a 	jal	0x589da8
  5aa6a0:	00000000 	nop
  5aa6a4:	5040fff4 	beqzl	v0,0x5aa678
  5aa6a8:	8fbf0024 	lw	ra,36(sp)
  5aa6ac:	3c04006d 	lui	a0,0x6d
  5aa6b0:	3c05006f 	lui	a1,0x6f
  5aa6b4:	248434fc 	addiu	a0,a0,13564
  5aa6b8:	24a59400 	addiu	a1,a1,-27648
  5aa6bc:	0c101b74 	jal	0x406dd0
  5aa6c0:	240600a1 	li	a2,161
  5aa6c4:	0816a99e 	j	0x5aa678
  5aa6c8:	8fbf0024 	lw	ra,36(sp)
  5aa6cc:	3c020075 	lui	v0,0x75
  5aa6d0:	8c42cf58 	lw	v0,-12456(v0)
  5aa6d4:	14400005 	bnez	v0,0x5aa6ec
  5aa6d8:	00000000 	nop
  5aa6dc:	0c101f7c 	jal	0x407df0
  5aa6e0:	02002021 	move	a0,s0
  5aa6e4:	0816a99e 	j	0x5aa678
  5aa6e8:	8fbf0024 	lw	ra,36(sp)
  5aa6ec:	0c16276a 	jal	0x589da8
  5aa6f0:	00000000 	nop
  5aa6f4:	1040fff9 	beqz	v0,0x5aa6dc
  5aa6f8:	3c04006d 	lui	a0,0x6d
  5aa6fc:	3c05006f 	lui	a1,0x6f
  5aa700:	248447f0 	addiu	a0,a0,18416
  5aa704:	24a59400 	addiu	a1,a1,-27648
  5aa708:	0c101b74 	jal	0x406dd0
  5aa70c:	240600a9 	li	a2,169
  5aa710:	0816a9b7 	j	0x5aa6dc
  5aa714:	00000000 	nop

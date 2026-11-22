; func arp_defend_db_uninit @ 0x0047e5c4 size=0xd8
  47e5c4:	27bdffd8 	addiu	sp,sp,-40
  47e5c8:	afb10020 	sw	s1,32(sp)
  47e5cc:	3c110076 	lui	s1,0x76
  47e5d0:	afb0001c 	sw	s0,28(sp)
  47e5d4:	263070f4 	addiu	s0,s1,28916
  47e5d8:	afbf0024 	sw	ra,36(sp)
  47e5dc:	8e040004 	lw	a0,4(s0)
  47e5e0:	50800006 	beqzl	a0,0x47e5fc
  47e5e4:	8e040008 	lw	a0,8(s0)
  47e5e8:	0c101fcc 	jal	0x407f30
  47e5ec:	00000000 	nop
  47e5f0:	ae000004 	sw	zero,4(s0)
  47e5f4:	263070f4 	addiu	s0,s1,28916
  47e5f8:	8e040008 	lw	a0,8(s0)
  47e5fc:	50800005 	beqzl	a0,0x47e614
  47e600:	263070f4 	addiu	s0,s1,28916
  47e604:	0c101fcc 	jal	0x407f30
  47e608:	00000000 	nop
  47e60c:	ae000008 	sw	zero,8(s0)
  47e610:	263070f4 	addiu	s0,s1,28916
  47e614:	8e04000c 	lw	a0,12(s0)
  47e618:	50800005 	beqzl	a0,0x47e630
  47e61c:	263070f4 	addiu	s0,s1,28916
  47e620:	0c102058 	jal	0x408160
  47e624:	00000000 	nop
  47e628:	ae00000c 	sw	zero,12(s0)
  47e62c:	263070f4 	addiu	s0,s1,28916
  47e630:	8e040010 	lw	a0,16(s0)
  47e634:	50800005 	beqzl	a0,0x47e64c
  47e638:	263070f4 	addiu	s0,s1,28916
  47e63c:	0c101f7c 	jal	0x407df0
  47e640:	00000000 	nop
  47e644:	ae000010 	sw	zero,16(s0)
  47e648:	263070f4 	addiu	s0,s1,28916
  47e64c:	8e040018 	lw	a0,24(s0)
  47e650:	50800005 	beqzl	a0,0x47e668
  47e654:	3c100076 	lui	s0,0x76
  47e658:	0c101f7c 	jal	0x407df0
  47e65c:	00000000 	nop
  47e660:	ae000018 	sw	zero,24(s0)
  47e664:	3c100076 	lui	s0,0x76
  47e668:	8e047114 	lw	a0,28948(s0)
  47e66c:	10800005 	beqz	a0,0x47e684
  47e670:	8fbf0024 	lw	ra,36(sp)
  47e674:	0c10202c 	jal	0x4080b0
  47e678:	00000000 	nop
  47e67c:	ae007114 	sw	zero,28948(s0)
  47e680:	8fbf0024 	lw	ra,36(sp)
  47e684:	00001021 	move	v0,zero
  47e688:	8fb0001c 	lw	s0,28(sp)
  47e68c:	ae2070f4 	sw	zero,28916(s1)
  47e690:	8fb10020 	lw	s1,32(sp)
  47e694:	03e00008 	jr	ra
  47e698:	27bd0028 	addiu	sp,sp,40

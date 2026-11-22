; func cw_priv_arp_defend_create @ 0x005ab664 size=0x1bc
  5ab664:	27bdffd8 	addiu	sp,sp,-40
  5ab668:	2405000c 	li	a1,12
  5ab66c:	afb10020 	sw	s1,32(sp)
  5ab670:	afb0001c 	sw	s0,28(sp)
  5ab674:	afbf0024 	sw	ra,36(sp)
  5ab678:	0c15c8cc 	jal	0x572330
  5ab67c:	00808021 	move	s0,a0
  5ab680:	1040002b 	beqz	v0,0x5ab730
  5ab684:	00408821 	move	s1,v0
  5ab688:	ac400008 	sw	zero,8(v0)
  5ab68c:	8e020004 	lw	v0,4(s0)
  5ab690:	5040000b 	beqzl	v0,0x5ab6c0
  5ab694:	8e250004 	lw	a1,4(s1)
  5ab698:	8e040008 	lw	a0,8(s0)
  5ab69c:	50800040 	beqzl	a0,0x5ab7a0
  5ab6a0:	3c020075 	lui	v0,0x75
  5ab6a4:	2405000c 	li	a1,12
  5ab6a8:	70452802 	mul	a1,v0,a1
  5ab6ac:	0c15c8cc 	jal	0x572330
  5ab6b0:	30a5fffc 	andi	a1,a1,0xfffc
  5ab6b4:	10400041 	beqz	v0,0x5ab7bc
  5ab6b8:	ae220008 	sw	v0,8(s1)
  5ab6bc:	8e250004 	lw	a1,4(s1)
  5ab6c0:	2402000a 	li	v0,10
  5ab6c4:	24040048 	li	a0,72
  5ab6c8:	02203021 	move	a2,s1
  5ab6cc:	70a22802 	mul	a1,a1,v0
  5ab6d0:	24a50006 	addiu	a1,a1,6
  5ab6d4:	0c15c943 	jal	0x57250c
  5ab6d8:	30a5fffe 	andi	a1,a1,0xfffe
  5ab6dc:	10400007 	beqz	v0,0x5ab6fc
  5ab6e0:	00408021 	move	s0,v0
  5ab6e4:	8fbf0024 	lw	ra,36(sp)
  5ab6e8:	02001021 	move	v0,s0
  5ab6ec:	8fb10020 	lw	s1,32(sp)
  5ab6f0:	8fb0001c 	lw	s0,28(sp)
  5ab6f4:	03e00008 	jr	ra
  5ab6f8:	27bd0028 	addiu	sp,sp,40
  5ab6fc:	3c020075 	lui	v0,0x75
  5ab700:	8c42cf58 	lw	v0,-12456(v0)
  5ab704:	1440001a 	bnez	v0,0x5ab770
  5ab708:	00000000 	nop
  5ab70c:	8e240008 	lw	a0,8(s1)
  5ab710:	10800003 	beqz	a0,0x5ab720
  5ab714:	00000000 	nop
  5ab718:	0c101f7c 	jal	0x407df0
  5ab71c:	00000000 	nop
  5ab720:	0c101f7c 	jal	0x407df0
  5ab724:	02202021 	move	a0,s1
  5ab728:	0816adba 	j	0x5ab6e8
  5ab72c:	8fbf0024 	lw	ra,36(sp)
  5ab730:	3c020075 	lui	v0,0x75
  5ab734:	8c42cf58 	lw	v0,-12456(v0)
  5ab738:	1040ffea 	beqz	v0,0x5ab6e4
  5ab73c:	00008021 	move	s0,zero
  5ab740:	0c16276a 	jal	0x589da8
  5ab744:	00000000 	nop
  5ab748:	5040ffe7 	beqzl	v0,0x5ab6e8
  5ab74c:	8fbf0024 	lw	ra,36(sp)
  5ab750:	3c04006d 	lui	a0,0x6d
  5ab754:	3c05006f 	lui	a1,0x6f
  5ab758:	248434fc 	addiu	a0,a0,13564
  5ab75c:	24a598c0 	addiu	a1,a1,-26432
  5ab760:	0c101b74 	jal	0x406dd0
  5ab764:	240600db 	li	a2,219
  5ab768:	0816adba 	j	0x5ab6e8
  5ab76c:	8fbf0024 	lw	ra,36(sp)
  5ab770:	0c16276a 	jal	0x589da8
  5ab774:	00000000 	nop
  5ab778:	5040ffe5 	beqzl	v0,0x5ab710
  5ab77c:	8e240008 	lw	a0,8(s1)
  5ab780:	3c04006d 	lui	a0,0x6d
  5ab784:	3c05006f 	lui	a1,0x6f
  5ab788:	248447f0 	addiu	a0,a0,18416
  5ab78c:	24a598c0 	addiu	a1,a1,-26432
  5ab790:	0c101b74 	jal	0x406dd0
  5ab794:	240600f5 	li	a2,245
  5ab798:	0816adc4 	j	0x5ab710
  5ab79c:	8e240008 	lw	a0,8(s1)
  5ab7a0:	8c42cf58 	lw	v0,-12456(v0)
  5ab7a4:	14400015 	bnez	v0,0x5ab7fc
  5ab7a8:	00000000 	nop
  5ab7ac:	0c101f7c 	jal	0x407df0
  5ab7b0:	02202021 	move	a0,s1
  5ab7b4:	0816adb9 	j	0x5ab6e4
  5ab7b8:	00008021 	move	s0,zero
  5ab7bc:	3c020075 	lui	v0,0x75
  5ab7c0:	8c42cf58 	lw	v0,-12456(v0)
  5ab7c4:	1040fff9 	beqz	v0,0x5ab7ac
  5ab7c8:	00000000 	nop
  5ab7cc:	0c16276a 	jal	0x589da8
  5ab7d0:	00000000 	nop
  5ab7d4:	1040fff5 	beqz	v0,0x5ab7ac
  5ab7d8:	3c04006f 	lui	a0,0x6f
  5ab7dc:	3c05006f 	lui	a1,0x6f
  5ab7e0:	24849844 	addiu	a0,a0,-26556
  5ab7e4:	24a598c0 	addiu	a1,a1,-26432
  5ab7e8:	240600eb 	li	a2,235
  5ab7ec:	0c101b74 	jal	0x406dd0
  5ab7f0:	00000000 	nop
  5ab7f4:	0816adeb 	j	0x5ab7ac
  5ab7f8:	00000000 	nop
  5ab7fc:	0c16276a 	jal	0x589da8
  5ab800:	00000000 	nop
  5ab804:	1040ffe9 	beqz	v0,0x5ab7ac
  5ab808:	3c04006f 	lui	a0,0x6f
  5ab80c:	3c05006f 	lui	a1,0x6f
  5ab810:	2484981c 	addiu	a0,a0,-26596
  5ab814:	24a598c0 	addiu	a1,a1,-26432
  5ab818:	0816adfb 	j	0x5ab7ec
  5ab81c:	240600e4 	li	a2,228

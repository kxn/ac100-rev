; func cw_priv_mac_filter_create @ 0x005b56fc size=0x1c4
  5b56fc:	27bdffd8 	addiu	sp,sp,-40
  5b5700:	2405000c 	li	a1,12
  5b5704:	afb10020 	sw	s1,32(sp)
  5b5708:	afb0001c 	sw	s0,28(sp)
  5b570c:	afbf0024 	sw	ra,36(sp)
  5b5710:	0c15c8cc 	jal	0x572330
  5b5714:	00808021 	move	s0,a0
  5b5718:	1040002d 	beqz	v0,0x5b57d0
  5b571c:	00408821 	move	s1,v0
  5b5720:	ac400008 	sw	zero,8(v0)
  5b5724:	8e020000 	lw	v0,0(s0)
  5b5728:	5040000c 	beqzl	v0,0x5b575c
  5b572c:	92250004 	lbu	a1,4(s1)
  5b5730:	8e040008 	lw	a0,8(s0)
  5b5734:	50800042 	beqzl	a0,0x5b5840
  5b5738:	3c020075 	lui	v0,0x75
  5b573c:	92050004 	lbu	a1,4(s0)
  5b5740:	000528c2 	srl	a1,a1,0x3
  5b5744:	70a22802 	mul	a1,a1,v0
  5b5748:	0c15c8cc 	jal	0x572330
  5b574c:	30a5ffff 	andi	a1,a1,0xffff
  5b5750:	10400042 	beqz	v0,0x5b585c
  5b5754:	ae220008 	sw	v0,8(s1)
  5b5758:	92250004 	lbu	a1,4(s1)
  5b575c:	2404003f 	li	a0,63
  5b5760:	8e220000 	lw	v0,0(s1)
  5b5764:	02203021 	move	a2,s1
  5b5768:	000528c2 	srl	a1,a1,0x3
  5b576c:	70a22802 	mul	a1,a1,v0
  5b5770:	24a50008 	addiu	a1,a1,8
  5b5774:	0c15c943 	jal	0x57250c
  5b5778:	30a5ffff 	andi	a1,a1,0xffff
  5b577c:	10400007 	beqz	v0,0x5b579c
  5b5780:	00408021 	move	s0,v0
  5b5784:	8fbf0024 	lw	ra,36(sp)
  5b5788:	02001021 	move	v0,s0
  5b578c:	8fb10020 	lw	s1,32(sp)
  5b5790:	8fb0001c 	lw	s0,28(sp)
  5b5794:	03e00008 	jr	ra
  5b5798:	27bd0028 	addiu	sp,sp,40
  5b579c:	3c020075 	lui	v0,0x75
  5b57a0:	8c42cf58 	lw	v0,-12456(v0)
  5b57a4:	1440001a 	bnez	v0,0x5b5810
  5b57a8:	00000000 	nop
  5b57ac:	8e240008 	lw	a0,8(s1)
  5b57b0:	10800003 	beqz	a0,0x5b57c0
  5b57b4:	00000000 	nop
  5b57b8:	0c101f7c 	jal	0x407df0
  5b57bc:	00000000 	nop
  5b57c0:	0c101f7c 	jal	0x407df0
  5b57c4:	02202021 	move	a0,s1
  5b57c8:	0816d5e2 	j	0x5b5788
  5b57cc:	8fbf0024 	lw	ra,36(sp)
  5b57d0:	3c020075 	lui	v0,0x75
  5b57d4:	8c42cf58 	lw	v0,-12456(v0)
  5b57d8:	1040ffea 	beqz	v0,0x5b5784
  5b57dc:	00008021 	move	s0,zero
  5b57e0:	0c16276a 	jal	0x589da8
  5b57e4:	00000000 	nop
  5b57e8:	5040ffe7 	beqzl	v0,0x5b5788
  5b57ec:	8fbf0024 	lw	ra,36(sp)
  5b57f0:	3c04006d 	lui	a0,0x6d
  5b57f4:	3c05006f 	lui	a1,0x6f
  5b57f8:	248434fc 	addiu	a0,a0,13564
  5b57fc:	24a5c360 	addiu	a1,a1,-15520
  5b5800:	0c101b74 	jal	0x406dd0
  5b5804:	240600c7 	li	a2,199
  5b5808:	0816d5e2 	j	0x5b5788
  5b580c:	8fbf0024 	lw	ra,36(sp)
  5b5810:	0c16276a 	jal	0x589da8
  5b5814:	00000000 	nop
  5b5818:	5040ffe5 	beqzl	v0,0x5b57b0
  5b581c:	8e240008 	lw	a0,8(s1)
  5b5820:	3c04006d 	lui	a0,0x6d
  5b5824:	3c05006f 	lui	a1,0x6f
  5b5828:	248447f0 	addiu	a0,a0,18416
  5b582c:	24a5c360 	addiu	a1,a1,-15520
  5b5830:	0c101b74 	jal	0x406dd0
  5b5834:	240600e2 	li	a2,226
  5b5838:	0816d5ec 	j	0x5b57b0
  5b583c:	8e240008 	lw	a0,8(s1)
  5b5840:	8c42cf58 	lw	v0,-12456(v0)
  5b5844:	14400015 	bnez	v0,0x5b589c
  5b5848:	00000000 	nop
  5b584c:	0c101f7c 	jal	0x407df0
  5b5850:	02202021 	move	a0,s1
  5b5854:	0816d5e1 	j	0x5b5784
  5b5858:	00008021 	move	s0,zero
  5b585c:	3c020075 	lui	v0,0x75
  5b5860:	8c42cf58 	lw	v0,-12456(v0)
  5b5864:	1040fff9 	beqz	v0,0x5b584c
  5b5868:	00000000 	nop
  5b586c:	0c16276a 	jal	0x589da8
  5b5870:	00000000 	nop
  5b5874:	1040fff5 	beqz	v0,0x5b584c
  5b5878:	3c04006e 	lui	a0,0x6e
  5b587c:	3c05006f 	lui	a1,0x6f
  5b5880:	24848050 	addiu	a0,a0,-32688
  5b5884:	24a5c360 	addiu	a1,a1,-15520
  5b5888:	240600d8 	li	a2,216
  5b588c:	0c101b74 	jal	0x406dd0
  5b5890:	00000000 	nop
  5b5894:	0816d613 	j	0x5b584c
  5b5898:	00000000 	nop
  5b589c:	0c16276a 	jal	0x589da8
  5b58a0:	00000000 	nop
  5b58a4:	1040ffe9 	beqz	v0,0x5b584c
  5b58a8:	3c04006e 	lui	a0,0x6e
  5b58ac:	3c05006f 	lui	a1,0x6f
  5b58b0:	248480d8 	addiu	a0,a0,-32552
  5b58b4:	24a5c360 	addiu	a1,a1,-15520
  5b58b8:	0816d623 	j	0x5b588c
  5b58bc:	240600d1 	li	a2,209

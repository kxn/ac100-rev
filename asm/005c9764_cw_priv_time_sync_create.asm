; func cw_priv_time_sync_create @ 0x005c9764 size=0xdc
  5c9764:	27bdffd8 	addiu	sp,sp,-40
  5c9768:	24050008 	li	a1,8
  5c976c:	afb0001c 	sw	s0,28(sp)
  5c9770:	afbf0024 	sw	ra,36(sp)
  5c9774:	0c15c8cc 	jal	0x572330
  5c9778:	afb10020 	sw	s1,32(sp)
  5c977c:	1040000d 	beqz	v0,0x5c97b4
  5c9780:	00408021 	move	s0,v0
  5c9784:	2404008d 	li	a0,141
  5c9788:	24050008 	li	a1,8
  5c978c:	0c15c943 	jal	0x57250c
  5c9790:	00403021 	move	a2,v0
  5c9794:	10400017 	beqz	v0,0x5c97f4
  5c9798:	00408821 	move	s1,v0
  5c979c:	8fbf0024 	lw	ra,36(sp)
  5c97a0:	02201021 	move	v0,s1
  5c97a4:	8fb10020 	lw	s1,32(sp)
  5c97a8:	8fb0001c 	lw	s0,28(sp)
  5c97ac:	03e00008 	jr	ra
  5c97b0:	27bd0028 	addiu	sp,sp,40
  5c97b4:	3c020075 	lui	v0,0x75
  5c97b8:	8c42cf58 	lw	v0,-12456(v0)
  5c97bc:	1040fff7 	beqz	v0,0x5c979c
  5c97c0:	00008821 	move	s1,zero
  5c97c4:	0c16276a 	jal	0x589da8
  5c97c8:	00000000 	nop
  5c97cc:	5040fff4 	beqzl	v0,0x5c97a0
  5c97d0:	8fbf0024 	lw	ra,36(sp)
  5c97d4:	3c04006d 	lui	a0,0x6d
  5c97d8:	3c05006f 	lui	a1,0x6f
  5c97dc:	248434fc 	addiu	a0,a0,13564
  5c97e0:	24a50ce0 	addiu	a1,a1,3296
  5c97e4:	0c101b74 	jal	0x406dd0
  5c97e8:	240600a2 	li	a2,162
  5c97ec:	081725e8 	j	0x5c97a0
  5c97f0:	8fbf0024 	lw	ra,36(sp)
  5c97f4:	3c020075 	lui	v0,0x75
  5c97f8:	8c42cf58 	lw	v0,-12456(v0)
  5c97fc:	14400005 	bnez	v0,0x5c9814
  5c9800:	00000000 	nop
  5c9804:	0c101f7c 	jal	0x407df0
  5c9808:	02002021 	move	a0,s0
  5c980c:	081725e8 	j	0x5c97a0
  5c9810:	8fbf0024 	lw	ra,36(sp)
  5c9814:	0c16276a 	jal	0x589da8
  5c9818:	00000000 	nop
  5c981c:	1040fff9 	beqz	v0,0x5c9804
  5c9820:	3c04006d 	lui	a0,0x6d
  5c9824:	3c05006f 	lui	a1,0x6f
  5c9828:	248447f0 	addiu	a0,a0,18416
  5c982c:	24a50ce0 	addiu	a1,a1,3296
  5c9830:	0c101b74 	jal	0x406dd0
  5c9834:	240600aa 	li	a2,170
  5c9838:	08172601 	j	0x5c9804
  5c983c:	00000000 	nop

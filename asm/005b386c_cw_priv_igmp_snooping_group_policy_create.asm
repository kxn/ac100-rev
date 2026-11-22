; func cw_priv_igmp_snooping_group_policy_create @ 0x005b386c size=0x1b4
  5b386c:	27bdffd8 	addiu	sp,sp,-40
  5b3870:	24050008 	li	a1,8
  5b3874:	afb10020 	sw	s1,32(sp)
  5b3878:	afb0001c 	sw	s0,28(sp)
  5b387c:	afbf0024 	sw	ra,36(sp)
  5b3880:	0c15c8cc 	jal	0x572330
  5b3884:	00808021 	move	s0,a0
  5b3888:	10400029 	beqz	v0,0x5b3930
  5b388c:	00408821 	move	s1,v0
  5b3890:	ac400004 	sw	zero,4(v0)
  5b3894:	8e020000 	lw	v0,0(s0)
  5b3898:	1040000a 	beqz	v0,0x5b38c4
  5b389c:	00000000 	nop
  5b38a0:	8e040004 	lw	a0,4(s0)
  5b38a4:	5080003e 	beqzl	a0,0x5b39a0
  5b38a8:	3c020075 	lui	v0,0x75
  5b38ac:	24050018 	li	a1,24
  5b38b0:	70452802 	mul	a1,v0,a1
  5b38b4:	0c15c8cc 	jal	0x572330
  5b38b8:	30a5fff8 	andi	a1,a1,0xfff8
  5b38bc:	1040003f 	beqz	v0,0x5b39bc
  5b38c0:	ae220004 	sw	v0,4(s1)
  5b38c4:	0c16cd8c 	jal	0x5b3630
  5b38c8:	02202021 	move	a0,s1
  5b38cc:	24040074 	li	a0,116
  5b38d0:	00402821 	move	a1,v0
  5b38d4:	0c15c943 	jal	0x57250c
  5b38d8:	02203021 	move	a2,s1
  5b38dc:	10400007 	beqz	v0,0x5b38fc
  5b38e0:	00408021 	move	s0,v0
  5b38e4:	8fbf0024 	lw	ra,36(sp)
  5b38e8:	02001021 	move	v0,s0
  5b38ec:	8fb10020 	lw	s1,32(sp)
  5b38f0:	8fb0001c 	lw	s0,28(sp)
  5b38f4:	03e00008 	jr	ra
  5b38f8:	27bd0028 	addiu	sp,sp,40
  5b38fc:	3c020075 	lui	v0,0x75
  5b3900:	8c42cf58 	lw	v0,-12456(v0)
  5b3904:	1440001a 	bnez	v0,0x5b3970
  5b3908:	00000000 	nop
  5b390c:	8e240004 	lw	a0,4(s1)
  5b3910:	10800003 	beqz	a0,0x5b3920
  5b3914:	00000000 	nop
  5b3918:	0c101f7c 	jal	0x407df0
  5b391c:	00000000 	nop
  5b3920:	0c101f7c 	jal	0x407df0
  5b3924:	02202021 	move	a0,s1
  5b3928:	0816ce3a 	j	0x5b38e8
  5b392c:	8fbf0024 	lw	ra,36(sp)
  5b3930:	3c020075 	lui	v0,0x75
  5b3934:	8c42cf58 	lw	v0,-12456(v0)
  5b3938:	1040ffea 	beqz	v0,0x5b38e4
  5b393c:	00008021 	move	s0,zero
  5b3940:	0c16276a 	jal	0x589da8
  5b3944:	00000000 	nop
  5b3948:	5040ffe7 	beqzl	v0,0x5b38e8
  5b394c:	8fbf0024 	lw	ra,36(sp)
  5b3950:	3c04006d 	lui	a0,0x6d
  5b3954:	3c05006f 	lui	a1,0x6f
  5b3958:	248434fc 	addiu	a0,a0,13564
  5b395c:	24a5bb70 	addiu	a1,a1,-17552
  5b3960:	0c101b74 	jal	0x406dd0
  5b3964:	240600e4 	li	a2,228
  5b3968:	0816ce3a 	j	0x5b38e8
  5b396c:	8fbf0024 	lw	ra,36(sp)
  5b3970:	0c16276a 	jal	0x589da8
  5b3974:	00000000 	nop
  5b3978:	5040ffe5 	beqzl	v0,0x5b3910
  5b397c:	8e240004 	lw	a0,4(s1)
  5b3980:	3c04006d 	lui	a0,0x6d
  5b3984:	3c05006f 	lui	a1,0x6f
  5b3988:	248447f0 	addiu	a0,a0,18416
  5b398c:	24a5bb70 	addiu	a1,a1,-17552
  5b3990:	0c101b74 	jal	0x406dd0
  5b3994:	240600ff 	li	a2,255
  5b3998:	0816ce44 	j	0x5b3910
  5b399c:	8e240004 	lw	a0,4(s1)
  5b39a0:	8c42cf58 	lw	v0,-12456(v0)
  5b39a4:	14400015 	bnez	v0,0x5b39fc
  5b39a8:	00000000 	nop
  5b39ac:	0c101f7c 	jal	0x407df0
  5b39b0:	02202021 	move	a0,s1
  5b39b4:	0816ce39 	j	0x5b38e4
  5b39b8:	00008021 	move	s0,zero
  5b39bc:	3c020075 	lui	v0,0x75
  5b39c0:	8c42cf58 	lw	v0,-12456(v0)
  5b39c4:	1040fff9 	beqz	v0,0x5b39ac
  5b39c8:	00000000 	nop
  5b39cc:	0c16276a 	jal	0x589da8
  5b39d0:	00000000 	nop
  5b39d4:	1040fff5 	beqz	v0,0x5b39ac
  5b39d8:	3c04006f 	lui	a0,0x6f
  5b39dc:	3c05006f 	lui	a1,0x6f
  5b39e0:	2484bab0 	addiu	a0,a0,-17744
  5b39e4:	24a5bb70 	addiu	a1,a1,-17552
  5b39e8:	240600f5 	li	a2,245
  5b39ec:	0c101b74 	jal	0x406dd0
  5b39f0:	00000000 	nop
  5b39f4:	0816ce6b 	j	0x5b39ac
  5b39f8:	00000000 	nop
  5b39fc:	0c16276a 	jal	0x589da8
  5b3a00:	00000000 	nop
  5b3a04:	1040ffe9 	beqz	v0,0x5b39ac
  5b3a08:	3c04006f 	lui	a0,0x6f
  5b3a0c:	3c05006f 	lui	a1,0x6f
  5b3a10:	2484ba88 	addiu	a0,a0,-17784
  5b3a14:	24a5bb70 	addiu	a1,a1,-17552
  5b3a18:	0816ce7b 	j	0x5b39ec
  5b3a1c:	240600ee 	li	a2,238

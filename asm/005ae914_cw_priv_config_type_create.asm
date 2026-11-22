; func cw_priv_config_type_create @ 0x005ae914 size=0xdc
  5ae914:	27bdffd8 	addiu	sp,sp,-40
  5ae918:	24050004 	li	a1,4
  5ae91c:	afb0001c 	sw	s0,28(sp)
  5ae920:	afbf0024 	sw	ra,36(sp)
  5ae924:	0c15c8cc 	jal	0x572330
  5ae928:	afb10020 	sw	s1,32(sp)
  5ae92c:	1040000d 	beqz	v0,0x5ae964
  5ae930:	00408021 	move	s0,v0
  5ae934:	24040027 	li	a0,39
  5ae938:	24050004 	li	a1,4
  5ae93c:	0c15c943 	jal	0x57250c
  5ae940:	00403021 	move	a2,v0
  5ae944:	10400017 	beqz	v0,0x5ae9a4
  5ae948:	00408821 	move	s1,v0
  5ae94c:	8fbf0024 	lw	ra,36(sp)
  5ae950:	02201021 	move	v0,s1
  5ae954:	8fb10020 	lw	s1,32(sp)
  5ae958:	8fb0001c 	lw	s0,28(sp)
  5ae95c:	03e00008 	jr	ra
  5ae960:	27bd0028 	addiu	sp,sp,40
  5ae964:	3c020075 	lui	v0,0x75
  5ae968:	8c42cf58 	lw	v0,-12456(v0)
  5ae96c:	1040fff7 	beqz	v0,0x5ae94c
  5ae970:	00008821 	move	s1,zero
  5ae974:	0c16276a 	jal	0x589da8
  5ae978:	00000000 	nop
  5ae97c:	5040fff4 	beqzl	v0,0x5ae950
  5ae980:	8fbf0024 	lw	ra,36(sp)
  5ae984:	3c04006d 	lui	a0,0x6d
  5ae988:	3c05006f 	lui	a1,0x6f
  5ae98c:	248434fc 	addiu	a0,a0,13564
  5ae990:	24a5a530 	addiu	a1,a1,-23248
  5ae994:	0c101b74 	jal	0x406dd0
  5ae998:	240600a2 	li	a2,162
  5ae99c:	0816ba54 	j	0x5ae950
  5ae9a0:	8fbf0024 	lw	ra,36(sp)
  5ae9a4:	3c020075 	lui	v0,0x75
  5ae9a8:	8c42cf58 	lw	v0,-12456(v0)
  5ae9ac:	14400005 	bnez	v0,0x5ae9c4
  5ae9b0:	00000000 	nop
  5ae9b4:	0c101f7c 	jal	0x407df0
  5ae9b8:	02002021 	move	a0,s0
  5ae9bc:	0816ba54 	j	0x5ae950
  5ae9c0:	8fbf0024 	lw	ra,36(sp)
  5ae9c4:	0c16276a 	jal	0x589da8
  5ae9c8:	00000000 	nop
  5ae9cc:	1040fff9 	beqz	v0,0x5ae9b4
  5ae9d0:	3c04006d 	lui	a0,0x6d
  5ae9d4:	3c05006f 	lui	a1,0x6f
  5ae9d8:	248447f0 	addiu	a0,a0,18416
  5ae9dc:	24a5a530 	addiu	a1,a1,-23248
  5ae9e0:	0c101b74 	jal	0x406dd0
  5ae9e4:	240600aa 	li	a2,170
  5ae9e8:	0816ba6d 	j	0x5ae9b4
  5ae9ec:	00000000 	nop

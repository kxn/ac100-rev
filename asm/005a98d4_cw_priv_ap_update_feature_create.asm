; func cw_priv_ap_update_feature_create @ 0x005a98d4 size=0xdc
  5a98d4:	27bdffd8 	addiu	sp,sp,-40
  5a98d8:	24050008 	li	a1,8
  5a98dc:	afb0001c 	sw	s0,28(sp)
  5a98e0:	afbf0024 	sw	ra,36(sp)
  5a98e4:	0c15c8cc 	jal	0x572330
  5a98e8:	afb10020 	sw	s1,32(sp)
  5a98ec:	1040000d 	beqz	v0,0x5a9924
  5a98f0:	00408021 	move	s0,v0
  5a98f4:	240400b5 	li	a0,181
  5a98f8:	24050008 	li	a1,8
  5a98fc:	0c15c943 	jal	0x57250c
  5a9900:	00403021 	move	a2,v0
  5a9904:	10400017 	beqz	v0,0x5a9964
  5a9908:	00408821 	move	s1,v0
  5a990c:	8fbf0024 	lw	ra,36(sp)
  5a9910:	02201021 	move	v0,s1
  5a9914:	8fb10020 	lw	s1,32(sp)
  5a9918:	8fb0001c 	lw	s0,28(sp)
  5a991c:	03e00008 	jr	ra
  5a9920:	27bd0028 	addiu	sp,sp,40
  5a9924:	3c020075 	lui	v0,0x75
  5a9928:	8c42cf58 	lw	v0,-12456(v0)
  5a992c:	1040fff7 	beqz	v0,0x5a990c
  5a9930:	00008821 	move	s1,zero
  5a9934:	0c16276a 	jal	0x589da8
  5a9938:	00000000 	nop
  5a993c:	5040fff4 	beqzl	v0,0x5a9910
  5a9940:	8fbf0024 	lw	ra,36(sp)
  5a9944:	3c04006d 	lui	a0,0x6d
  5a9948:	3c05006f 	lui	a1,0x6f
  5a994c:	248434fc 	addiu	a0,a0,13564
  5a9950:	24a58f00 	addiu	a1,a1,-28928
  5a9954:	0c101b74 	jal	0x406dd0
  5a9958:	240600a9 	li	a2,169
  5a995c:	0816a644 	j	0x5a9910
  5a9960:	8fbf0024 	lw	ra,36(sp)
  5a9964:	3c020075 	lui	v0,0x75
  5a9968:	8c42cf58 	lw	v0,-12456(v0)
  5a996c:	14400005 	bnez	v0,0x5a9984
  5a9970:	00000000 	nop
  5a9974:	0c101f7c 	jal	0x407df0
  5a9978:	02002021 	move	a0,s0
  5a997c:	0816a644 	j	0x5a9910
  5a9980:	8fbf0024 	lw	ra,36(sp)
  5a9984:	0c16276a 	jal	0x589da8
  5a9988:	00000000 	nop
  5a998c:	1040fff9 	beqz	v0,0x5a9974
  5a9990:	3c04006d 	lui	a0,0x6d
  5a9994:	3c05006f 	lui	a1,0x6f
  5a9998:	248447f0 	addiu	a0,a0,18416
  5a999c:	24a58f00 	addiu	a1,a1,-28928
  5a99a0:	0c101b74 	jal	0x406dd0
  5a99a4:	240600b1 	li	a2,177
  5a99a8:	0816a65d 	j	0x5a9974
  5a99ac:	00000000 	nop

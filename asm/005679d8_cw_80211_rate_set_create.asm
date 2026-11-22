; func cw_80211_rate_set_create @ 0x005679d8 size=0xe0
  5679d8:	27bdffd8 	addiu	sp,sp,-40
  5679dc:	2405000a 	li	a1,10
  5679e0:	afb0001c 	sw	s0,28(sp)
  5679e4:	afbf0024 	sw	ra,36(sp)
  5679e8:	0c15c8cc 	jal	0x572330
  5679ec:	afb10020 	sw	s1,32(sp)
  5679f0:	1040000e 	beqz	v0,0x567a2c
  5679f4:	00408021 	move	s0,v0
  5679f8:	90450001 	lbu	a1,1(v0)
  5679fc:	2404040a 	li	a0,1034
  567a00:	00403021 	move	a2,v0
  567a04:	0c15c943 	jal	0x57250c
  567a08:	24a50001 	addiu	a1,a1,1
  567a0c:	10400017 	beqz	v0,0x567a6c
  567a10:	00408821 	move	s1,v0
  567a14:	8fbf0024 	lw	ra,36(sp)
  567a18:	02201021 	move	v0,s1
  567a1c:	8fb10020 	lw	s1,32(sp)
  567a20:	8fb0001c 	lw	s0,28(sp)
  567a24:	03e00008 	jr	ra
  567a28:	27bd0028 	addiu	sp,sp,40
  567a2c:	3c020075 	lui	v0,0x75
  567a30:	8c42cf58 	lw	v0,-12456(v0)
  567a34:	1040fff7 	beqz	v0,0x567a14
  567a38:	00008821 	move	s1,zero
  567a3c:	0c16276a 	jal	0x589da8
  567a40:	00000000 	nop
  567a44:	5040fff4 	beqzl	v0,0x567a18
  567a48:	8fbf0024 	lw	ra,36(sp)
  567a4c:	3c04006d 	lui	a0,0x6d
  567a50:	3c05006d 	lui	a1,0x6d
  567a54:	248434fc 	addiu	a0,a0,13564
  567a58:	24a54d90 	addiu	a1,a1,19856
  567a5c:	0c101b74 	jal	0x406dd0
  567a60:	240600b0 	li	a2,176
  567a64:	08159e86 	j	0x567a18
  567a68:	8fbf0024 	lw	ra,36(sp)
  567a6c:	3c020075 	lui	v0,0x75
  567a70:	8c42cf58 	lw	v0,-12456(v0)
  567a74:	14400005 	bnez	v0,0x567a8c
  567a78:	00000000 	nop
  567a7c:	0c101f7c 	jal	0x407df0
  567a80:	02002021 	move	a0,s0
  567a84:	08159e86 	j	0x567a18
  567a88:	8fbf0024 	lw	ra,36(sp)
  567a8c:	0c16276a 	jal	0x589da8
  567a90:	00000000 	nop
  567a94:	1040fff9 	beqz	v0,0x567a7c
  567a98:	3c04006d 	lui	a0,0x6d
  567a9c:	3c05006d 	lui	a1,0x6d
  567aa0:	248447f0 	addiu	a0,a0,18416
  567aa4:	24a54d90 	addiu	a1,a1,19856
  567aa8:	0c101b74 	jal	0x406dd0
  567aac:	240600b8 	li	a2,184
  567ab0:	08159e9f 	j	0x567a7c
  567ab4:	00000000 	nop
	...

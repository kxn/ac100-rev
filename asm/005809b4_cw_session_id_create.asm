; func cw_session_id_create @ 0x005809b4 size=0xdc
  5809b4:	27bdffd8 	addiu	sp,sp,-40
  5809b8:	24050010 	li	a1,16
  5809bc:	afb0001c 	sw	s0,28(sp)
  5809c0:	afbf0024 	sw	ra,36(sp)
  5809c4:	0c15c8cc 	jal	0x572330
  5809c8:	afb10020 	sw	s1,32(sp)
  5809cc:	1040000d 	beqz	v0,0x580a04
  5809d0:	00408021 	move	s0,v0
  5809d4:	24040023 	li	a0,35
  5809d8:	24050010 	li	a1,16
  5809dc:	0c15c943 	jal	0x57250c
  5809e0:	00403021 	move	a2,v0
  5809e4:	10400017 	beqz	v0,0x580a44
  5809e8:	00408821 	move	s1,v0
  5809ec:	8fbf0024 	lw	ra,36(sp)
  5809f0:	02201021 	move	v0,s1
  5809f4:	8fb10020 	lw	s1,32(sp)
  5809f8:	8fb0001c 	lw	s0,28(sp)
  5809fc:	03e00008 	jr	ra
  580a00:	27bd0028 	addiu	sp,sp,40
  580a04:	3c020075 	lui	v0,0x75
  580a08:	8c42cf58 	lw	v0,-12456(v0)
  580a0c:	1040fff7 	beqz	v0,0x5809ec
  580a10:	00008821 	move	s1,zero
  580a14:	0c16276a 	jal	0x589da8
  580a18:	00000000 	nop
  580a1c:	5040fff4 	beqzl	v0,0x5809f0
  580a20:	8fbf0024 	lw	ra,36(sp)
  580a24:	3c04006d 	lui	a0,0x6d
  580a28:	3c05006e 	lui	a1,0x6e
  580a2c:	248434fc 	addiu	a0,a0,13564
  580a30:	24a5bbb0 	addiu	a1,a1,-17488
  580a34:	0c101b74 	jal	0x406dd0
  580a38:	240600a9 	li	a2,169
  580a3c:	0816027c 	j	0x5809f0
  580a40:	8fbf0024 	lw	ra,36(sp)
  580a44:	3c020075 	lui	v0,0x75
  580a48:	8c42cf58 	lw	v0,-12456(v0)
  580a4c:	14400005 	bnez	v0,0x580a64
  580a50:	00000000 	nop
  580a54:	0c101f7c 	jal	0x407df0
  580a58:	02002021 	move	a0,s0
  580a5c:	0816027c 	j	0x5809f0
  580a60:	8fbf0024 	lw	ra,36(sp)
  580a64:	0c16276a 	jal	0x589da8
  580a68:	00000000 	nop
  580a6c:	1040fff9 	beqz	v0,0x580a54
  580a70:	3c04006d 	lui	a0,0x6d
  580a74:	3c05006e 	lui	a1,0x6e
  580a78:	248447f0 	addiu	a0,a0,18416
  580a7c:	24a5bbb0 	addiu	a1,a1,-17488
  580a80:	0c101b74 	jal	0x406dd0
  580a84:	240600b1 	li	a2,177
  580a88:	08160295 	j	0x580a54
  580a8c:	00000000 	nop

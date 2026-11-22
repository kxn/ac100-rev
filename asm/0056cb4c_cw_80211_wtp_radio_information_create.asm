; func cw_80211_wtp_radio_information_create @ 0x0056cb4c size=0xdc
  56cb4c:	27bdffd8 	addiu	sp,sp,-40
  56cb50:	24050008 	li	a1,8
  56cb54:	afb0001c 	sw	s0,28(sp)
  56cb58:	afbf0024 	sw	ra,36(sp)
  56cb5c:	0c15c8cc 	jal	0x572330
  56cb60:	afb10020 	sw	s1,32(sp)
  56cb64:	1040000d 	beqz	v0,0x56cb9c
  56cb68:	00408021 	move	s0,v0
  56cb6c:	24040418 	li	a0,1048
  56cb70:	24050005 	li	a1,5
  56cb74:	0c15c943 	jal	0x57250c
  56cb78:	00403021 	move	a2,v0
  56cb7c:	10400017 	beqz	v0,0x56cbdc
  56cb80:	00408821 	move	s1,v0
  56cb84:	8fbf0024 	lw	ra,36(sp)
  56cb88:	02201021 	move	v0,s1
  56cb8c:	8fb10020 	lw	s1,32(sp)
  56cb90:	8fb0001c 	lw	s0,28(sp)
  56cb94:	03e00008 	jr	ra
  56cb98:	27bd0028 	addiu	sp,sp,40
  56cb9c:	3c020075 	lui	v0,0x75
  56cba0:	8c42cf58 	lw	v0,-12456(v0)
  56cba4:	1040fff7 	beqz	v0,0x56cb84
  56cba8:	00008821 	move	s1,zero
  56cbac:	0c16276a 	jal	0x589da8
  56cbb0:	00000000 	nop
  56cbb4:	5040fff4 	beqzl	v0,0x56cb88
  56cbb8:	8fbf0024 	lw	ra,36(sp)
  56cbbc:	3c04006d 	lui	a0,0x6d
  56cbc0:	3c05006d 	lui	a1,0x6d
  56cbc4:	248434fc 	addiu	a0,a0,13564
  56cbc8:	24a56308 	addiu	a1,a1,25352
  56cbcc:	0c101b74 	jal	0x406dd0
  56cbd0:	240600c5 	li	a2,197
  56cbd4:	0815b2e2 	j	0x56cb88
  56cbd8:	8fbf0024 	lw	ra,36(sp)
  56cbdc:	3c020075 	lui	v0,0x75
  56cbe0:	8c42cf58 	lw	v0,-12456(v0)
  56cbe4:	14400005 	bnez	v0,0x56cbfc
  56cbe8:	00000000 	nop
  56cbec:	0c101f7c 	jal	0x407df0
  56cbf0:	02002021 	move	a0,s0
  56cbf4:	0815b2e2 	j	0x56cb88
  56cbf8:	8fbf0024 	lw	ra,36(sp)
  56cbfc:	0c16276a 	jal	0x589da8
  56cc00:	00000000 	nop
  56cc04:	1040fff9 	beqz	v0,0x56cbec
  56cc08:	3c04006d 	lui	a0,0x6d
  56cc0c:	3c05006d 	lui	a1,0x6d
  56cc10:	248447f0 	addiu	a0,a0,18416
  56cc14:	24a56308 	addiu	a1,a1,25352
  56cc18:	0c101b74 	jal	0x406dd0
  56cc1c:	240600cd 	li	a2,205
  56cc20:	0815b2fb 	j	0x56cbec
  56cc24:	00000000 	nop
	...

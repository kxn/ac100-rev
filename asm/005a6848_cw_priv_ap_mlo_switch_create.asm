; func cw_priv_ap_mlo_switch_create @ 0x005a6848 size=0xdc
  5a6848:	27bdffd8 	addiu	sp,sp,-40
  5a684c:	24050001 	li	a1,1
  5a6850:	afb0001c 	sw	s0,28(sp)
  5a6854:	afbf0024 	sw	ra,36(sp)
  5a6858:	0c15c8cc 	jal	0x572330
  5a685c:	afb10020 	sw	s1,32(sp)
  5a6860:	1040000d 	beqz	v0,0x5a6898
  5a6864:	00408021 	move	s0,v0
  5a6868:	240400b6 	li	a0,182
  5a686c:	24050001 	li	a1,1
  5a6870:	0c15c943 	jal	0x57250c
  5a6874:	00403021 	move	a2,v0
  5a6878:	10400017 	beqz	v0,0x5a68d8
  5a687c:	00408821 	move	s1,v0
  5a6880:	8fbf0024 	lw	ra,36(sp)
  5a6884:	02201021 	move	v0,s1
  5a6888:	8fb10020 	lw	s1,32(sp)
  5a688c:	8fb0001c 	lw	s0,28(sp)
  5a6890:	03e00008 	jr	ra
  5a6894:	27bd0028 	addiu	sp,sp,40
  5a6898:	3c020075 	lui	v0,0x75
  5a689c:	8c42cf58 	lw	v0,-12456(v0)
  5a68a0:	1040fff7 	beqz	v0,0x5a6880
  5a68a4:	00008821 	move	s1,zero
  5a68a8:	0c16276a 	jal	0x589da8
  5a68ac:	00000000 	nop
  5a68b0:	5040fff4 	beqzl	v0,0x5a6884
  5a68b4:	8fbf0024 	lw	ra,36(sp)
  5a68b8:	3c04006d 	lui	a0,0x6d
  5a68bc:	3c05006e 	lui	a1,0x6e
  5a68c0:	248434fc 	addiu	a0,a0,13564
  5a68c4:	24a57fe0 	addiu	a1,a1,32736
  5a68c8:	0c101b74 	jal	0x406dd0
  5a68cc:	240600a6 	li	a2,166
  5a68d0:	08169a21 	j	0x5a6884
  5a68d4:	8fbf0024 	lw	ra,36(sp)
  5a68d8:	3c020075 	lui	v0,0x75
  5a68dc:	8c42cf58 	lw	v0,-12456(v0)
  5a68e0:	14400005 	bnez	v0,0x5a68f8
  5a68e4:	00000000 	nop
  5a68e8:	0c101f7c 	jal	0x407df0
  5a68ec:	02002021 	move	a0,s0
  5a68f0:	08169a21 	j	0x5a6884
  5a68f4:	8fbf0024 	lw	ra,36(sp)
  5a68f8:	0c16276a 	jal	0x589da8
  5a68fc:	00000000 	nop
  5a6900:	1040fff9 	beqz	v0,0x5a68e8
  5a6904:	3c04006d 	lui	a0,0x6d
  5a6908:	3c05006e 	lui	a1,0x6e
  5a690c:	248447f0 	addiu	a0,a0,18416
  5a6910:	24a57fe0 	addiu	a1,a1,32736
  5a6914:	0c101b74 	jal	0x406dd0
  5a6918:	240600ae 	li	a2,174
  5a691c:	08169a3a 	j	0x5a68e8
  5a6920:	00000000 	nop

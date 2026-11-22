; func cw_priv_ap_config_checksum_create @ 0x005a4794 size=0xdc
  5a4794:	27bdffd8 	addiu	sp,sp,-40
  5a4798:	24050010 	li	a1,16
  5a479c:	afb0001c 	sw	s0,28(sp)
  5a47a0:	afbf0024 	sw	ra,36(sp)
  5a47a4:	0c15c8cc 	jal	0x572330
  5a47a8:	afb10020 	sw	s1,32(sp)
  5a47ac:	1040000d 	beqz	v0,0x5a47e4
  5a47b0:	00408021 	move	s0,v0
  5a47b4:	24040041 	li	a0,65
  5a47b8:	24050010 	li	a1,16
  5a47bc:	0c15c943 	jal	0x57250c
  5a47c0:	00403021 	move	a2,v0
  5a47c4:	10400017 	beqz	v0,0x5a4824
  5a47c8:	00408821 	move	s1,v0
  5a47cc:	8fbf0024 	lw	ra,36(sp)
  5a47d0:	02201021 	move	v0,s1
  5a47d4:	8fb10020 	lw	s1,32(sp)
  5a47d8:	8fb0001c 	lw	s0,28(sp)
  5a47dc:	03e00008 	jr	ra
  5a47e0:	27bd0028 	addiu	sp,sp,40
  5a47e4:	3c020075 	lui	v0,0x75
  5a47e8:	8c42cf58 	lw	v0,-12456(v0)
  5a47ec:	1040fff7 	beqz	v0,0x5a47cc
  5a47f0:	00008821 	move	s1,zero
  5a47f4:	0c16276a 	jal	0x589da8
  5a47f8:	00000000 	nop
  5a47fc:	5040fff4 	beqzl	v0,0x5a47d0
  5a4800:	8fbf0024 	lw	ra,36(sp)
  5a4804:	3c04006d 	lui	a0,0x6d
  5a4808:	3c05006e 	lui	a1,0x6e
  5a480c:	248434fc 	addiu	a0,a0,13564
  5a4810:	24a57630 	addiu	a1,a1,30256
  5a4814:	0c101b74 	jal	0x406dd0
  5a4818:	240600a8 	li	a2,168
  5a481c:	081691f4 	j	0x5a47d0
  5a4820:	8fbf0024 	lw	ra,36(sp)
  5a4824:	3c020075 	lui	v0,0x75
  5a4828:	8c42cf58 	lw	v0,-12456(v0)
  5a482c:	14400005 	bnez	v0,0x5a4844
  5a4830:	00000000 	nop
  5a4834:	0c101f7c 	jal	0x407df0
  5a4838:	02002021 	move	a0,s0
  5a483c:	081691f4 	j	0x5a47d0
  5a4840:	8fbf0024 	lw	ra,36(sp)
  5a4844:	0c16276a 	jal	0x589da8
  5a4848:	00000000 	nop
  5a484c:	1040fff9 	beqz	v0,0x5a4834
  5a4850:	3c04006d 	lui	a0,0x6d
  5a4854:	3c05006e 	lui	a1,0x6e
  5a4858:	248447f0 	addiu	a0,a0,18416
  5a485c:	24a57630 	addiu	a1,a1,30256
  5a4860:	0c101b74 	jal	0x406dd0
  5a4864:	240600b0 	li	a2,176
  5a4868:	0816920d 	j	0x5a4834
  5a486c:	00000000 	nop

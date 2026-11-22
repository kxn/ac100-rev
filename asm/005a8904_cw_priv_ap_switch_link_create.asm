; func cw_priv_ap_switch_link_create @ 0x005a8904 size=0xdc
  5a8904:	27bdffd8 	addiu	sp,sp,-40
  5a8908:	24050004 	li	a1,4
  5a890c:	afb0001c 	sw	s0,28(sp)
  5a8910:	afbf0024 	sw	ra,36(sp)
  5a8914:	0c15c8cc 	jal	0x572330
  5a8918:	afb10020 	sw	s1,32(sp)
  5a891c:	1040000d 	beqz	v0,0x5a8954
  5a8920:	00408021 	move	s0,v0
  5a8924:	24040040 	li	a0,64
  5a8928:	24050004 	li	a1,4
  5a892c:	0c15c943 	jal	0x57250c
  5a8930:	00403021 	move	a2,v0
  5a8934:	10400017 	beqz	v0,0x5a8994
  5a8938:	00408821 	move	s1,v0
  5a893c:	8fbf0024 	lw	ra,36(sp)
  5a8940:	02201021 	move	v0,s1
  5a8944:	8fb10020 	lw	s1,32(sp)
  5a8948:	8fb0001c 	lw	s0,28(sp)
  5a894c:	03e00008 	jr	ra
  5a8950:	27bd0028 	addiu	sp,sp,40
  5a8954:	3c020075 	lui	v0,0x75
  5a8958:	8c42cf58 	lw	v0,-12456(v0)
  5a895c:	1040fff7 	beqz	v0,0x5a893c
  5a8960:	00008821 	move	s1,zero
  5a8964:	0c16276a 	jal	0x589da8
  5a8968:	00000000 	nop
  5a896c:	5040fff4 	beqzl	v0,0x5a8940
  5a8970:	8fbf0024 	lw	ra,36(sp)
  5a8974:	3c04006d 	lui	a0,0x6d
  5a8978:	3c05006f 	lui	a1,0x6f
  5a897c:	248434fc 	addiu	a0,a0,13564
  5a8980:	24a58ab4 	addiu	a1,a1,-30028
  5a8984:	0c101b74 	jal	0x406dd0
  5a8988:	240600a2 	li	a2,162
  5a898c:	0816a250 	j	0x5a8940
  5a8990:	8fbf0024 	lw	ra,36(sp)
  5a8994:	3c020075 	lui	v0,0x75
  5a8998:	8c42cf58 	lw	v0,-12456(v0)
  5a899c:	14400005 	bnez	v0,0x5a89b4
  5a89a0:	00000000 	nop
  5a89a4:	0c101f7c 	jal	0x407df0
  5a89a8:	02002021 	move	a0,s0
  5a89ac:	0816a250 	j	0x5a8940
  5a89b0:	8fbf0024 	lw	ra,36(sp)
  5a89b4:	0c16276a 	jal	0x589da8
  5a89b8:	00000000 	nop
  5a89bc:	1040fff9 	beqz	v0,0x5a89a4
  5a89c0:	3c04006d 	lui	a0,0x6d
  5a89c4:	3c05006f 	lui	a1,0x6f
  5a89c8:	248447f0 	addiu	a0,a0,18416
  5a89cc:	24a58ab4 	addiu	a1,a1,-30028
  5a89d0:	0c101b74 	jal	0x406dd0
  5a89d4:	240600aa 	li	a2,170
  5a89d8:	0816a269 	j	0x5a89a4
  5a89dc:	00000000 	nop

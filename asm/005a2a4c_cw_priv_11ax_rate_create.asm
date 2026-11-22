; func cw_priv_11ax_rate_create @ 0x005a2a4c size=0xdc
  5a2a4c:	27bdffd8 	addiu	sp,sp,-40
  5a2a50:	24050004 	li	a1,4
  5a2a54:	afb0001c 	sw	s0,28(sp)
  5a2a58:	afbf0024 	sw	ra,36(sp)
  5a2a5c:	0c15c8cc 	jal	0x572330
  5a2a60:	afb10020 	sw	s1,32(sp)
  5a2a64:	1040000d 	beqz	v0,0x5a2a9c
  5a2a68:	00408021 	move	s0,v0
  5a2a6c:	240400a0 	li	a0,160
  5a2a70:	24050004 	li	a1,4
  5a2a74:	0c15c943 	jal	0x57250c
  5a2a78:	00403021 	move	a2,v0
  5a2a7c:	10400017 	beqz	v0,0x5a2adc
  5a2a80:	00408821 	move	s1,v0
  5a2a84:	8fbf0024 	lw	ra,36(sp)
  5a2a88:	02201021 	move	v0,s1
  5a2a8c:	8fb10020 	lw	s1,32(sp)
  5a2a90:	8fb0001c 	lw	s0,28(sp)
  5a2a94:	03e00008 	jr	ra
  5a2a98:	27bd0028 	addiu	sp,sp,40
  5a2a9c:	3c020075 	lui	v0,0x75
  5a2aa0:	8c42cf58 	lw	v0,-12456(v0)
  5a2aa4:	1040fff7 	beqz	v0,0x5a2a84
  5a2aa8:	00008821 	move	s1,zero
  5a2aac:	0c16276a 	jal	0x589da8
  5a2ab0:	00000000 	nop
  5a2ab4:	5040fff4 	beqzl	v0,0x5a2a88
  5a2ab8:	8fbf0024 	lw	ra,36(sp)
  5a2abc:	3c04006d 	lui	a0,0x6d
  5a2ac0:	3c05006e 	lui	a1,0x6e
  5a2ac4:	248434fc 	addiu	a0,a0,13564
  5a2ac8:	24a56c50 	addiu	a1,a1,27728
  5a2acc:	0c101b74 	jal	0x406dd0
  5a2ad0:	240600b1 	li	a2,177
  5a2ad4:	08168aa2 	j	0x5a2a88
  5a2ad8:	8fbf0024 	lw	ra,36(sp)
  5a2adc:	3c020075 	lui	v0,0x75
  5a2ae0:	8c42cf58 	lw	v0,-12456(v0)
  5a2ae4:	14400005 	bnez	v0,0x5a2afc
  5a2ae8:	00000000 	nop
  5a2aec:	0c101f7c 	jal	0x407df0
  5a2af0:	02002021 	move	a0,s0
  5a2af4:	08168aa2 	j	0x5a2a88
  5a2af8:	8fbf0024 	lw	ra,36(sp)
  5a2afc:	0c16276a 	jal	0x589da8
  5a2b00:	00000000 	nop
  5a2b04:	1040fff9 	beqz	v0,0x5a2aec
  5a2b08:	3c04006d 	lui	a0,0x6d
  5a2b0c:	3c05006e 	lui	a1,0x6e
  5a2b10:	248447f0 	addiu	a0,a0,18416
  5a2b14:	24a56c50 	addiu	a1,a1,27728
  5a2b18:	0c101b74 	jal	0x406dd0
  5a2b1c:	240600b9 	li	a2,185
  5a2b20:	08168abb 	j	0x5a2aec
  5a2b24:	00000000 	nop
	...

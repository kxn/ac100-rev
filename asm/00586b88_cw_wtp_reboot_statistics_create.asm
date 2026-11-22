; func cw_wtp_reboot_statistics_create @ 0x00586b88 size=0xdc
  586b88:	27bdffd8 	addiu	sp,sp,-40
  586b8c:	24050010 	li	a1,16
  586b90:	afb0001c 	sw	s0,28(sp)
  586b94:	afbf0024 	sw	ra,36(sp)
  586b98:	0c15c8cc 	jal	0x572330
  586b9c:	afb10020 	sw	s1,32(sp)
  586ba0:	1040000d 	beqz	v0,0x586bd8
  586ba4:	00408021 	move	s0,v0
  586ba8:	24040030 	li	a0,48
  586bac:	2405000f 	li	a1,15
  586bb0:	0c15c943 	jal	0x57250c
  586bb4:	00403021 	move	a2,v0
  586bb8:	10400017 	beqz	v0,0x586c18
  586bbc:	00408821 	move	s1,v0
  586bc0:	8fbf0024 	lw	ra,36(sp)
  586bc4:	02201021 	move	v0,s1
  586bc8:	8fb10020 	lw	s1,32(sp)
  586bcc:	8fb0001c 	lw	s0,28(sp)
  586bd0:	03e00008 	jr	ra
  586bd4:	27bd0028 	addiu	sp,sp,40
  586bd8:	3c020075 	lui	v0,0x75
  586bdc:	8c42cf58 	lw	v0,-12456(v0)
  586be0:	1040fff7 	beqz	v0,0x586bc0
  586be4:	00008821 	move	s1,zero
  586be8:	0c16276a 	jal	0x589da8
  586bec:	00000000 	nop
  586bf0:	5040fff4 	beqzl	v0,0x586bc4
  586bf4:	8fbf0024 	lw	ra,36(sp)
  586bf8:	3c04006d 	lui	a0,0x6d
  586bfc:	3c05006e 	lui	a1,0x6e
  586c00:	248434fc 	addiu	a0,a0,13564
  586c04:	24a5da68 	addiu	a1,a1,-9624
  586c08:	0c101b74 	jal	0x406dd0
  586c0c:	240600d6 	li	a2,214
  586c10:	08161af1 	j	0x586bc4
  586c14:	8fbf0024 	lw	ra,36(sp)
  586c18:	3c020075 	lui	v0,0x75
  586c1c:	8c42cf58 	lw	v0,-12456(v0)
  586c20:	14400005 	bnez	v0,0x586c38
  586c24:	00000000 	nop
  586c28:	0c101f7c 	jal	0x407df0
  586c2c:	02002021 	move	a0,s0
  586c30:	08161af1 	j	0x586bc4
  586c34:	8fbf0024 	lw	ra,36(sp)
  586c38:	0c16276a 	jal	0x589da8
  586c3c:	00000000 	nop
  586c40:	1040fff9 	beqz	v0,0x586c28
  586c44:	3c04006d 	lui	a0,0x6d
  586c48:	3c05006e 	lui	a1,0x6e
  586c4c:	248447f0 	addiu	a0,a0,18416
  586c50:	24a5da68 	addiu	a1,a1,-9624
  586c54:	0c101b74 	jal	0x406dd0
  586c58:	240600de 	li	a2,222
  586c5c:	08161b0a 	j	0x586c28
  586c60:	00000000 	nop
	...

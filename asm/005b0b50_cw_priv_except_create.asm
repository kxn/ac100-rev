; func cw_priv_except_create @ 0x005b0b50 size=0xdc
  5b0b50:	27bdffd8 	addiu	sp,sp,-40
  5b0b54:	2405001c 	li	a1,28
  5b0b58:	afb0001c 	sw	s0,28(sp)
  5b0b5c:	afbf0024 	sw	ra,36(sp)
  5b0b60:	0c15c8cc 	jal	0x572330
  5b0b64:	afb10020 	sw	s1,32(sp)
  5b0b68:	1040000d 	beqz	v0,0x5b0ba0
  5b0b6c:	00408021 	move	s0,v0
  5b0b70:	2404001a 	li	a0,26
  5b0b74:	24050018 	li	a1,24
  5b0b78:	0c15c943 	jal	0x57250c
  5b0b7c:	00403021 	move	a2,v0
  5b0b80:	10400017 	beqz	v0,0x5b0be0
  5b0b84:	00408821 	move	s1,v0
  5b0b88:	8fbf0024 	lw	ra,36(sp)
  5b0b8c:	02201021 	move	v0,s1
  5b0b90:	8fb10020 	lw	s1,32(sp)
  5b0b94:	8fb0001c 	lw	s0,28(sp)
  5b0b98:	03e00008 	jr	ra
  5b0b9c:	27bd0028 	addiu	sp,sp,40
  5b0ba0:	3c020075 	lui	v0,0x75
  5b0ba4:	8c42cf58 	lw	v0,-12456(v0)
  5b0ba8:	1040fff7 	beqz	v0,0x5b0b88
  5b0bac:	00008821 	move	s1,zero
  5b0bb0:	0c16276a 	jal	0x589da8
  5b0bb4:	00000000 	nop
  5b0bb8:	5040fff4 	beqzl	v0,0x5b0b8c
  5b0bbc:	8fbf0024 	lw	ra,36(sp)
  5b0bc0:	3c04006d 	lui	a0,0x6d
  5b0bc4:	3c05006f 	lui	a1,0x6f
  5b0bc8:	248434fc 	addiu	a0,a0,13564
  5b0bcc:	24a5ac40 	addiu	a1,a1,-21440
  5b0bd0:	0c101b74 	jal	0x406dd0
  5b0bd4:	240600b3 	li	a2,179
  5b0bd8:	0816c2e3 	j	0x5b0b8c
  5b0bdc:	8fbf0024 	lw	ra,36(sp)
  5b0be0:	3c020075 	lui	v0,0x75
  5b0be4:	8c42cf58 	lw	v0,-12456(v0)
  5b0be8:	14400005 	bnez	v0,0x5b0c00
  5b0bec:	00000000 	nop
  5b0bf0:	0c101f7c 	jal	0x407df0
  5b0bf4:	02002021 	move	a0,s0
  5b0bf8:	0816c2e3 	j	0x5b0b8c
  5b0bfc:	8fbf0024 	lw	ra,36(sp)
  5b0c00:	0c16276a 	jal	0x589da8
  5b0c04:	00000000 	nop
  5b0c08:	1040fff9 	beqz	v0,0x5b0bf0
  5b0c0c:	3c04006d 	lui	a0,0x6d
  5b0c10:	3c05006f 	lui	a1,0x6f
  5b0c14:	248447f0 	addiu	a0,a0,18416
  5b0c18:	24a5ac40 	addiu	a1,a1,-21440
  5b0c1c:	0c101b74 	jal	0x406dd0
  5b0c20:	240600bb 	li	a2,187
  5b0c24:	0816c2fc 	j	0x5b0bf0
  5b0c28:	00000000 	nop
  5b0c2c:	00000000 	nop

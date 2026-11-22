; func cw_wtp_mac_type_create @ 0x00585b38 size=0xdc
  585b38:	27bdffd8 	addiu	sp,sp,-40
  585b3c:	24050001 	li	a1,1
  585b40:	afb0001c 	sw	s0,28(sp)
  585b44:	afbf0024 	sw	ra,36(sp)
  585b48:	0c15c8cc 	jal	0x572330
  585b4c:	afb10020 	sw	s1,32(sp)
  585b50:	1040000d 	beqz	v0,0x585b88
  585b54:	00408021 	move	s0,v0
  585b58:	2404002c 	li	a0,44
  585b5c:	24050001 	li	a1,1
  585b60:	0c15c943 	jal	0x57250c
  585b64:	00403021 	move	a2,v0
  585b68:	10400017 	beqz	v0,0x585bc8
  585b6c:	00408821 	move	s1,v0
  585b70:	8fbf0024 	lw	ra,36(sp)
  585b74:	02201021 	move	v0,s1
  585b78:	8fb10020 	lw	s1,32(sp)
  585b7c:	8fb0001c 	lw	s0,28(sp)
  585b80:	03e00008 	jr	ra
  585b84:	27bd0028 	addiu	sp,sp,40
  585b88:	3c020075 	lui	v0,0x75
  585b8c:	8c42cf58 	lw	v0,-12456(v0)
  585b90:	1040fff7 	beqz	v0,0x585b70
  585b94:	00008821 	move	s1,zero
  585b98:	0c16276a 	jal	0x589da8
  585b9c:	00000000 	nop
  585ba0:	5040fff4 	beqzl	v0,0x585b74
  585ba4:	8fbf0024 	lw	ra,36(sp)
  585ba8:	3c04006d 	lui	a0,0x6d
  585bac:	3c05006e 	lui	a1,0x6e
  585bb0:	248434fc 	addiu	a0,a0,13564
  585bb4:	24a5d41c 	addiu	a1,a1,-11236
  585bb8:	0c101b74 	jal	0x406dd0
  585bbc:	240600bd 	li	a2,189
  585bc0:	081616dd 	j	0x585b74
  585bc4:	8fbf0024 	lw	ra,36(sp)
  585bc8:	3c020075 	lui	v0,0x75
  585bcc:	8c42cf58 	lw	v0,-12456(v0)
  585bd0:	14400005 	bnez	v0,0x585be8
  585bd4:	00000000 	nop
  585bd8:	0c101f7c 	jal	0x407df0
  585bdc:	02002021 	move	a0,s0
  585be0:	081616dd 	j	0x585b74
  585be4:	8fbf0024 	lw	ra,36(sp)
  585be8:	0c16276a 	jal	0x589da8
  585bec:	00000000 	nop
  585bf0:	1040fff9 	beqz	v0,0x585bd8
  585bf4:	3c04006d 	lui	a0,0x6d
  585bf8:	3c05006e 	lui	a1,0x6e
  585bfc:	248447f0 	addiu	a0,a0,18416
  585c00:	24a5d41c 	addiu	a1,a1,-11236
  585c04:	0c101b74 	jal	0x406dd0
  585c08:	240600c5 	li	a2,197
  585c0c:	081616f6 	j	0x585bd8
  585c10:	00000000 	nop
	...

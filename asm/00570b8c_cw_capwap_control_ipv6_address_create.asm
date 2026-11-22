; func cw_capwap_control_ipv6_address_create @ 0x00570b8c size=0xdc
  570b8c:	27bdffd8 	addiu	sp,sp,-40
  570b90:	24050012 	li	a1,18
  570b94:	afb0001c 	sw	s0,28(sp)
  570b98:	afbf0024 	sw	ra,36(sp)
  570b9c:	0c15c8cc 	jal	0x572330
  570ba0:	afb10020 	sw	s1,32(sp)
  570ba4:	1040000d 	beqz	v0,0x570bdc
  570ba8:	00408021 	move	s0,v0
  570bac:	2404000b 	li	a0,11
  570bb0:	24050012 	li	a1,18
  570bb4:	0c15c943 	jal	0x57250c
  570bb8:	00403021 	move	a2,v0
  570bbc:	10400017 	beqz	v0,0x570c1c
  570bc0:	00408821 	move	s1,v0
  570bc4:	8fbf0024 	lw	ra,36(sp)
  570bc8:	02201021 	move	v0,s1
  570bcc:	8fb10020 	lw	s1,32(sp)
  570bd0:	8fb0001c 	lw	s0,28(sp)
  570bd4:	03e00008 	jr	ra
  570bd8:	27bd0028 	addiu	sp,sp,40
  570bdc:	3c020075 	lui	v0,0x75
  570be0:	8c42cf58 	lw	v0,-12456(v0)
  570be4:	1040fff7 	beqz	v0,0x570bc4
  570be8:	00008821 	move	s1,zero
  570bec:	0c16276a 	jal	0x589da8
  570bf0:	00000000 	nop
  570bf4:	5040fff4 	beqzl	v0,0x570bc8
  570bf8:	8fbf0024 	lw	ra,36(sp)
  570bfc:	3c04006d 	lui	a0,0x6d
  570c00:	3c05006d 	lui	a1,0x6d
  570c04:	24847098 	addiu	a0,a0,28824
  570c08:	24a57980 	addiu	a1,a1,31104
  570c0c:	0c101b74 	jal	0x406dd0
  570c10:	240600a3 	li	a2,163
  570c14:	0815c2f2 	j	0x570bc8
  570c18:	8fbf0024 	lw	ra,36(sp)
  570c1c:	3c020075 	lui	v0,0x75
  570c20:	8c42cf58 	lw	v0,-12456(v0)
  570c24:	14400005 	bnez	v0,0x570c3c
  570c28:	00000000 	nop
  570c2c:	0c101f7c 	jal	0x407df0
  570c30:	02002021 	move	a0,s0
  570c34:	0815c2f2 	j	0x570bc8
  570c38:	8fbf0024 	lw	ra,36(sp)
  570c3c:	0c16276a 	jal	0x589da8
  570c40:	00000000 	nop
  570c44:	1040fff9 	beqz	v0,0x570c2c
  570c48:	3c04006d 	lui	a0,0x6d
  570c4c:	3c05006d 	lui	a1,0x6d
  570c50:	248447f0 	addiu	a0,a0,18416
  570c54:	24a57980 	addiu	a1,a1,31104
  570c58:	0c101b74 	jal	0x406dd0
  570c5c:	240600ab 	li	a2,171
  570c60:	0815c30b 	j	0x570c2c
  570c64:	00000000 	nop

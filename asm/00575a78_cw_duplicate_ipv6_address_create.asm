; func cw_duplicate_ipv6_address_create @ 0x00575a78 size=0x180
  575a78:	27bdffd8 	addiu	sp,sp,-40
  575a7c:	24050018 	li	a1,24
  575a80:	afb10020 	sw	s1,32(sp)
  575a84:	afb0001c 	sw	s0,28(sp)
  575a88:	afbf0024 	sw	ra,36(sp)
  575a8c:	0c15c8cc 	jal	0x572330
  575a90:	00808821 	move	s1,a0
  575a94:	10400031 	beqz	v0,0x575b5c
  575a98:	00408021 	move	s0,v0
  575a9c:	ac400014 	sw	zero,20(v0)
  575aa0:	24020006 	li	v0,6
  575aa4:	92250011 	lbu	a1,17(s1)
  575aa8:	10a20010 	beq	a1,v0,0x575aec
  575aac:	24020008 	li	v0,8
  575ab0:	50a2000f 	beql	a1,v0,0x575af0
  575ab4:	8e240014 	lw	a0,20(s1)
  575ab8:	92050011 	lbu	a1,17(s0)
  575abc:	24040016 	li	a0,22
  575ac0:	02003021 	move	a2,s0
  575ac4:	0c15c943 	jal	0x57250c
  575ac8:	24a50012 	addiu	a1,a1,18
  575acc:	10400016 	beqz	v0,0x575b28
  575ad0:	00408821 	move	s1,v0
  575ad4:	8fbf0024 	lw	ra,36(sp)
  575ad8:	02201021 	move	v0,s1
  575adc:	8fb10020 	lw	s1,32(sp)
  575ae0:	8fb0001c 	lw	s0,28(sp)
  575ae4:	03e00008 	jr	ra
  575ae8:	27bd0028 	addiu	sp,sp,40
  575aec:	8e240014 	lw	a0,20(s1)
  575af0:	5080fff2 	beqzl	a0,0x575abc
  575af4:	92050011 	lbu	a1,17(s0)
  575af8:	0c15c8cc 	jal	0x572330
  575afc:	00000000 	nop
  575b00:	1440ffed 	bnez	v0,0x575ab8
  575b04:	ae020014 	sw	v0,20(s0)
  575b08:	3c020075 	lui	v0,0x75
  575b0c:	8c42cf58 	lw	v0,-12456(v0)
  575b10:	1440002e 	bnez	v0,0x575bcc
  575b14:	00000000 	nop
  575b18:	0c101f7c 	jal	0x407df0
  575b1c:	02002021 	move	a0,s0
  575b20:	0815d6b5 	j	0x575ad4
  575b24:	00008821 	move	s1,zero
  575b28:	3c020075 	lui	v0,0x75
  575b2c:	8c42cf58 	lw	v0,-12456(v0)
  575b30:	1440001a 	bnez	v0,0x575b9c
  575b34:	00000000 	nop
  575b38:	8e040014 	lw	a0,20(s0)
  575b3c:	10800003 	beqz	a0,0x575b4c
  575b40:	00000000 	nop
  575b44:	0c101f7c 	jal	0x407df0
  575b48:	00000000 	nop
  575b4c:	0c101f7c 	jal	0x407df0
  575b50:	02002021 	move	a0,s0
  575b54:	0815d6b6 	j	0x575ad8
  575b58:	8fbf0024 	lw	ra,36(sp)
  575b5c:	3c020075 	lui	v0,0x75
  575b60:	8c42cf58 	lw	v0,-12456(v0)
  575b64:	1040ffdb 	beqz	v0,0x575ad4
  575b68:	00008821 	move	s1,zero
  575b6c:	0c16276a 	jal	0x589da8
  575b70:	00000000 	nop
  575b74:	5040ffd8 	beqzl	v0,0x575ad8
  575b78:	8fbf0024 	lw	ra,36(sp)
  575b7c:	3c04006d 	lui	a0,0x6d
  575b80:	3c05006e 	lui	a1,0x6e
  575b84:	248434fc 	addiu	a0,a0,13564
  575b88:	24a58b00 	addiu	a1,a1,-29952
  575b8c:	0c101b74 	jal	0x406dd0
  575b90:	240600db 	li	a2,219
  575b94:	0815d6b6 	j	0x575ad8
  575b98:	8fbf0024 	lw	ra,36(sp)
  575b9c:	0c16276a 	jal	0x589da8
  575ba0:	00000000 	nop
  575ba4:	5040ffe5 	beqzl	v0,0x575b3c
  575ba8:	8e040014 	lw	a0,20(s0)
  575bac:	3c04006e 	lui	a0,0x6e
  575bb0:	3c05006e 	lui	a1,0x6e
  575bb4:	24848aa4 	addiu	a0,a0,-30044
  575bb8:	24a58b00 	addiu	a1,a1,-29952
  575bbc:	0c101b74 	jal	0x406dd0
  575bc0:	240600f0 	li	a2,240
  575bc4:	0815d6cf 	j	0x575b3c
  575bc8:	8e040014 	lw	a0,20(s0)
  575bcc:	0c16276a 	jal	0x589da8
  575bd0:	00000000 	nop
  575bd4:	1040ffd0 	beqz	v0,0x575b18
  575bd8:	3c04006d 	lui	a0,0x6d
  575bdc:	3c05006e 	lui	a1,0x6e
  575be0:	248473e8 	addiu	a0,a0,29672
  575be4:	24a58b00 	addiu	a1,a1,-29952
  575be8:	0c101b74 	jal	0x406dd0
  575bec:	240600e6 	li	a2,230
  575bf0:	0815d6c6 	j	0x575b18
  575bf4:	00000000 	nop

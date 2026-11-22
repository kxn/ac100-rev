; func cw_delete_station_parse @ 0x00574b4c size=0x218
  574b4c:	27bdffd0 	addiu	sp,sp,-48
  574b50:	afb20024 	sw	s2,36(sp)
  574b54:	00a09021 	move	s2,a1
  574b58:	afb10020 	sw	s1,32(sp)
  574b5c:	24050065 	li	a1,101
  574b60:	afb0001c 	sw	s0,28(sp)
  574b64:	00808821 	move	s1,a0
  574b68:	afbf002c 	sw	ra,44(sp)
  574b6c:	afb30028 	sw	s3,40(sp)
  574b70:	94930006 	lhu	s3,6(a0)
  574b74:	0c102114 	jal	0x408450
  574b78:	24040008 	li	a0,8
  574b7c:	1040002c 	beqz	v0,0x574c30
  574b80:	00408021 	move	s0,v0
  574b84:	00002821 	move	a1,zero
  574b88:	24060008 	li	a2,8
  574b8c:	0c101cf0 	jal	0x4073c0
  574b90:	00402021 	move	a0,v0
  574b94:	0c15c5b0 	jal	0x5716c0
  574b98:	02202021 	move	a0,s1
  574b9c:	a2020000 	sb	v0,0(s0)
  574ba0:	2c420020 	sltiu	v0,v0,32
  574ba4:	10400039 	beqz	v0,0x574c8c
  574ba8:	3c020075 	lui	v0,0x75
  574bac:	0c15c5b0 	jal	0x5716c0
  574bb0:	02202021 	move	a0,s1
  574bb4:	24030006 	li	v1,6
  574bb8:	10430004 	beq	v0,v1,0x574bcc
  574bbc:	a2020001 	sb	v0,1(s0)
  574bc0:	24030008 	li	v1,8
  574bc4:	5443003e 	bnel	v0,v1,0x574cc0
  574bc8:	3c020075 	lui	v0,0x75
  574bcc:	9643000e 	lhu	v1,14(s2)
  574bd0:	2463fffe 	addiu	v1,v1,-2
  574bd4:	54620026 	bnel	v1,v0,0x574c70
  574bd8:	3c020075 	lui	v0,0x75
  574bdc:	02202021 	move	a0,s1
  574be0:	0c15c6bc 	jal	0x571af0
  574be4:	00402821 	move	a1,v0
  574be8:	1040004f 	beqz	v0,0x574d28
  574bec:	ae020004 	sw	v0,4(s0)
  574bf0:	9642000e 	lhu	v0,14(s2)
  574bf4:	ae500010 	sw	s0,16(s2)
  574bf8:	96300006 	lhu	s0,6(s1)
  574bfc:	02138023 	subu	s0,s0,s3
  574c00:	02028026 	xor	s0,s0,v0
  574c04:	2402ffff 	li	v0,-1
  574c08:	0010100a 	movz	v0,zero,s0
  574c0c:	00408021 	move	s0,v0
  574c10:	8fbf002c 	lw	ra,44(sp)
  574c14:	02001021 	move	v0,s0
  574c18:	8fb30028 	lw	s3,40(sp)
  574c1c:	8fb20024 	lw	s2,36(sp)
  574c20:	8fb10020 	lw	s1,32(sp)
  574c24:	8fb0001c 	lw	s0,28(sp)
  574c28:	03e00008 	jr	ra
  574c2c:	27bd0030 	addiu	sp,sp,48
  574c30:	3c020075 	lui	v0,0x75
  574c34:	8c42cf58 	lw	v0,-12456(v0)
  574c38:	1040fff5 	beqz	v0,0x574c10
  574c3c:	2410ffff 	li	s0,-1
  574c40:	0c16276a 	jal	0x589da8
  574c44:	00000000 	nop
  574c48:	5040fff2 	beqzl	v0,0x574c14
  574c4c:	8fbf002c 	lw	ra,44(sp)
  574c50:	3c04006d 	lui	a0,0x6d
  574c54:	3c05006e 	lui	a1,0x6e
  574c58:	2484381c 	addiu	a0,a0,14364
  574c5c:	24a58768 	addiu	a1,a1,-30872
  574c60:	0c101b74 	jal	0x406dd0
  574c64:	24060068 	li	a2,104
  574c68:	0815d305 	j	0x574c14
  574c6c:	8fbf002c 	lw	ra,44(sp)
  574c70:	8c42cf58 	lw	v0,-12456(v0)
  574c74:	14400022 	bnez	v0,0x574d00
  574c78:	00000000 	nop
  574c7c:	0c101f7c 	jal	0x407df0
  574c80:	02002021 	move	a0,s0
  574c84:	0815d304 	j	0x574c10
  574c88:	2410ffff 	li	s0,-1
  574c8c:	8c42cf58 	lw	v0,-12456(v0)
  574c90:	1040fffa 	beqz	v0,0x574c7c
  574c94:	00000000 	nop
  574c98:	0c16276a 	jal	0x589da8
  574c9c:	00000000 	nop
  574ca0:	1040fff6 	beqz	v0,0x574c7c
  574ca4:	3c04006d 	lui	a0,0x6d
  574ca8:	92070000 	lbu	a3,0(s0)
  574cac:	3c05006e 	lui	a1,0x6e
  574cb0:	24843f08 	addiu	a0,a0,16136
  574cb4:	24a58768 	addiu	a1,a1,-30872
  574cb8:	0815d33c 	j	0x574cf0
  574cbc:	24060071 	li	a2,113
  574cc0:	8c42cf58 	lw	v0,-12456(v0)
  574cc4:	1040ffed 	beqz	v0,0x574c7c
  574cc8:	00000000 	nop
  574ccc:	0c16276a 	jal	0x589da8
  574cd0:	00000000 	nop
  574cd4:	1040ffe9 	beqz	v0,0x574c7c
  574cd8:	3c04006d 	lui	a0,0x6d
  574cdc:	92070001 	lbu	a3,1(s0)
  574ce0:	3c05006e 	lui	a1,0x6e
  574ce4:	24847450 	addiu	a0,a0,29776
  574ce8:	24a58768 	addiu	a1,a1,-30872
  574cec:	2406007a 	li	a2,122
  574cf0:	0c101b74 	jal	0x406dd0
  574cf4:	00000000 	nop
  574cf8:	0815d31f 	j	0x574c7c
  574cfc:	00000000 	nop
  574d00:	0c16276a 	jal	0x589da8
  574d04:	00000000 	nop
  574d08:	1040ffdc 	beqz	v0,0x574c7c
  574d0c:	3c04006d 	lui	a0,0x6d
  574d10:	9647000e 	lhu	a3,14(s2)
  574d14:	3c05006e 	lui	a1,0x6e
  574d18:	24846dec 	addiu	a0,a0,28140
  574d1c:	24a58768 	addiu	a1,a1,-30872
  574d20:	0815d33c 	j	0x574cf0
  574d24:	24060082 	li	a2,130
  574d28:	3c020075 	lui	v0,0x75
  574d2c:	8c42cf58 	lw	v0,-12456(v0)
  574d30:	1040ffd2 	beqz	v0,0x574c7c
  574d34:	00000000 	nop
  574d38:	0c16276a 	jal	0x589da8
  574d3c:	00000000 	nop
  574d40:	1040ffce 	beqz	v0,0x574c7c
  574d44:	3c04006d 	lui	a0,0x6d
  574d48:	3c05006e 	lui	a1,0x6e
  574d4c:	24847500 	addiu	a0,a0,29952
  574d50:	24a58768 	addiu	a1,a1,-30872
  574d54:	0c101b74 	jal	0x406dd0
  574d58:	24060089 	li	a2,137
  574d5c:	0815d31f 	j	0x574c7c
  574d60:	00000000 	nop
	...

; func cw_duplicate_ipv6_address_parse @ 0x00575d80 size=0x228
  575d80:	27bdffd0 	addiu	sp,sp,-48
  575d84:	afb20024 	sw	s2,36(sp)
  575d88:	00a09021 	move	s2,a1
  575d8c:	afb10020 	sw	s1,32(sp)
  575d90:	2405006d 	li	a1,109
  575d94:	afb0001c 	sw	s0,28(sp)
  575d98:	00808821 	move	s1,a0
  575d9c:	afbf002c 	sw	ra,44(sp)
  575da0:	afb30028 	sw	s3,40(sp)
  575da4:	94930006 	lhu	s3,6(a0)
  575da8:	0c102114 	jal	0x408450
  575dac:	24040018 	li	a0,24
  575db0:	10400030 	beqz	v0,0x575e74
  575db4:	00408021 	move	s0,v0
  575db8:	00002821 	move	a1,zero
  575dbc:	24060018 	li	a2,24
  575dc0:	0c101cf0 	jal	0x4073c0
  575dc4:	00402021 	move	a0,v0
  575dc8:	24060010 	li	a2,16
  575dcc:	02202021 	move	a0,s1
  575dd0:	0c15c702 	jal	0x571c08
  575dd4:	02002821 	move	a1,s0
  575dd8:	0c15c5b0 	jal	0x5716c0
  575ddc:	02202021 	move	a0,s1
  575de0:	a2020010 	sb	v0,16(s0)
  575de4:	2c420002 	sltiu	v0,v0,2
  575de8:	10400039 	beqz	v0,0x575ed0
  575dec:	3c020075 	lui	v0,0x75
  575df0:	0c15c5b0 	jal	0x5716c0
  575df4:	02202021 	move	a0,s1
  575df8:	24030006 	li	v1,6
  575dfc:	10430004 	beq	v0,v1,0x575e10
  575e00:	a2020011 	sb	v0,17(s0)
  575e04:	24030008 	li	v1,8
  575e08:	5443003e 	bnel	v0,v1,0x575f04
  575e0c:	3c020075 	lui	v0,0x75
  575e10:	9643000e 	lhu	v1,14(s2)
  575e14:	2463ffee 	addiu	v1,v1,-18
  575e18:	54620026 	bnel	v1,v0,0x575eb4
  575e1c:	3c020075 	lui	v0,0x75
  575e20:	02202021 	move	a0,s1
  575e24:	0c15c6bc 	jal	0x571af0
  575e28:	00402821 	move	a1,v0
  575e2c:	1040004f 	beqz	v0,0x575f6c
  575e30:	ae020014 	sw	v0,20(s0)
  575e34:	9642000e 	lhu	v0,14(s2)
  575e38:	ae500010 	sw	s0,16(s2)
  575e3c:	96300006 	lhu	s0,6(s1)
  575e40:	02138023 	subu	s0,s0,s3
  575e44:	02028026 	xor	s0,s0,v0
  575e48:	2402ffff 	li	v0,-1
  575e4c:	0010100a 	movz	v0,zero,s0
  575e50:	00408021 	move	s0,v0
  575e54:	8fbf002c 	lw	ra,44(sp)
  575e58:	02001021 	move	v0,s0
  575e5c:	8fb30028 	lw	s3,40(sp)
  575e60:	8fb20024 	lw	s2,36(sp)
  575e64:	8fb10020 	lw	s1,32(sp)
  575e68:	8fb0001c 	lw	s0,28(sp)
  575e6c:	03e00008 	jr	ra
  575e70:	27bd0030 	addiu	sp,sp,48
  575e74:	3c020075 	lui	v0,0x75
  575e78:	8c42cf58 	lw	v0,-12456(v0)
  575e7c:	1040fff5 	beqz	v0,0x575e54
  575e80:	2410ffff 	li	s0,-1
  575e84:	0c16276a 	jal	0x589da8
  575e88:	00000000 	nop
  575e8c:	5040fff2 	beqzl	v0,0x575e58
  575e90:	8fbf002c 	lw	ra,44(sp)
  575e94:	3c04006d 	lui	a0,0x6d
  575e98:	3c05006e 	lui	a1,0x6e
  575e9c:	2484381c 	addiu	a0,a0,14364
  575ea0:	24a58b48 	addiu	a1,a1,-29880
  575ea4:	0c101b74 	jal	0x406dd0
  575ea8:	24060070 	li	a2,112
  575eac:	0815d796 	j	0x575e58
  575eb0:	8fbf002c 	lw	ra,44(sp)
  575eb4:	8c42cf58 	lw	v0,-12456(v0)
  575eb8:	14400022 	bnez	v0,0x575f44
  575ebc:	00000000 	nop
  575ec0:	0c101f7c 	jal	0x407df0
  575ec4:	02002021 	move	a0,s0
  575ec8:	0815d795 	j	0x575e54
  575ecc:	2410ffff 	li	s0,-1
  575ed0:	8c42cf58 	lw	v0,-12456(v0)
  575ed4:	1040fffa 	beqz	v0,0x575ec0
  575ed8:	00000000 	nop
  575edc:	0c16276a 	jal	0x589da8
  575ee0:	00000000 	nop
  575ee4:	1040fff6 	beqz	v0,0x575ec0
  575ee8:	3c04006d 	lui	a0,0x6d
  575eec:	92070010 	lbu	a3,16(s0)
  575ef0:	3c05006e 	lui	a1,0x6e
  575ef4:	24846050 	addiu	a0,a0,24656
  575ef8:	24a58b48 	addiu	a1,a1,-29880
  575efc:	0815d7cd 	j	0x575f34
  575f00:	2406007c 	li	a2,124
  575f04:	8c42cf58 	lw	v0,-12456(v0)
  575f08:	1040ffed 	beqz	v0,0x575ec0
  575f0c:	00000000 	nop
  575f10:	0c16276a 	jal	0x589da8
  575f14:	00000000 	nop
  575f18:	1040ffe9 	beqz	v0,0x575ec0
  575f1c:	3c04006d 	lui	a0,0x6d
  575f20:	92070011 	lbu	a3,17(s0)
  575f24:	3c05006e 	lui	a1,0x6e
  575f28:	24847450 	addiu	a0,a0,29776
  575f2c:	24a58b48 	addiu	a1,a1,-29880
  575f30:	24060085 	li	a2,133
  575f34:	0c101b74 	jal	0x406dd0
  575f38:	00000000 	nop
  575f3c:	0815d7b0 	j	0x575ec0
  575f40:	00000000 	nop
  575f44:	0c16276a 	jal	0x589da8
  575f48:	00000000 	nop
  575f4c:	1040ffdc 	beqz	v0,0x575ec0
  575f50:	3c04006d 	lui	a0,0x6d
  575f54:	9647000e 	lhu	a3,14(s2)
  575f58:	3c05006e 	lui	a1,0x6e
  575f5c:	24846dec 	addiu	a0,a0,28140
  575f60:	24a58b48 	addiu	a1,a1,-29880
  575f64:	0815d7cd 	j	0x575f34
  575f68:	2406008d 	li	a2,141
  575f6c:	3c020075 	lui	v0,0x75
  575f70:	8c42cf58 	lw	v0,-12456(v0)
  575f74:	1040ffd2 	beqz	v0,0x575ec0
  575f78:	00000000 	nop
  575f7c:	0c16276a 	jal	0x589da8
  575f80:	00000000 	nop
  575f84:	1040ffce 	beqz	v0,0x575ec0
  575f88:	3c04006d 	lui	a0,0x6d
  575f8c:	3c05006e 	lui	a1,0x6e
  575f90:	24847500 	addiu	a0,a0,29952
  575f94:	24a58b48 	addiu	a1,a1,-29880
  575f98:	0c101b74 	jal	0x406dd0
  575f9c:	24060094 	li	a2,148
  575fa0:	0815d7b0 	j	0x575ec0
  575fa4:	00000000 	nop
	...

; func cw_priv_capwap_retrans_para_assemble @ 0x005ace9c size=0xd8
  5ace9c:	27bdffd0 	addiu	sp,sp,-48
  5acea0:	afb20024 	sw	s2,36(sp)
  5acea4:	00a09021 	move	s2,a1
  5acea8:	afb0001c 	sw	s0,28(sp)
  5aceac:	00808021 	move	s0,a0
  5aceb0:	afbf002c 	sw	ra,44(sp)
  5aceb4:	afb30028 	sw	s3,40(sp)
  5aceb8:	afb10020 	sw	s1,32(sp)
  5acebc:	8cb10010 	lw	s1,16(a1)
  5acec0:	92250000 	lbu	a1,0(s1)
  5acec4:	10a00017 	beqz	a1,0x5acf24
  5acec8:	94930004 	lhu	s3,4(a0)
  5acecc:	0c15c799 	jal	0x571e64
  5aced0:	00000000 	nop
  5aced4:	02002021 	move	a0,s0
  5aced8:	0c15c7be 	jal	0x571ef8
  5acedc:	96250002 	lhu	a1,2(s1)
  5acee0:	02002021 	move	a0,s0
  5acee4:	0c15c799 	jal	0x571e64
  5acee8:	92250004 	lbu	a1,4(s1)
  5aceec:	96020004 	lhu	v0,4(s0)
  5acef0:	9643000e 	lhu	v1,14(s2)
  5acef4:	00531023 	subu	v0,v0,s3
  5acef8:	00431026 	xor	v0,v0,v1
  5acefc:	2403ffff 	li	v1,-1
  5acf00:	0002180a 	movz	v1,zero,v0
  5acf04:	00601021 	move	v0,v1
  5acf08:	8fbf002c 	lw	ra,44(sp)
  5acf0c:	8fb30028 	lw	s3,40(sp)
  5acf10:	8fb20024 	lw	s2,36(sp)
  5acf14:	8fb10020 	lw	s1,32(sp)
  5acf18:	8fb0001c 	lw	s0,28(sp)
  5acf1c:	03e00008 	jr	ra
  5acf20:	27bd0030 	addiu	sp,sp,48
  5acf24:	3c020075 	lui	v0,0x75
  5acf28:	8c42cf58 	lw	v0,-12456(v0)
  5acf2c:	14400005 	bnez	v0,0x5acf44
  5acf30:	00000000 	nop
  5acf34:	0c101f7c 	jal	0x407df0
  5acf38:	02202021 	move	a0,s1
  5acf3c:	0816b3c2 	j	0x5acf08
  5acf40:	2402ffff 	li	v0,-1
  5acf44:	0c16276a 	jal	0x589da8
  5acf48:	00000000 	nop
  5acf4c:	1040fff9 	beqz	v0,0x5acf34
  5acf50:	3c04006f 	lui	a0,0x6f
  5acf54:	92270000 	lbu	a3,0(s1)
  5acf58:	3c05006f 	lui	a1,0x6f
  5acf5c:	24849e9c 	addiu	a0,a0,-24932
  5acf60:	24a59f24 	addiu	a1,a1,-24796
  5acf64:	0c101b74 	jal	0x406dd0
  5acf68:	24060096 	li	a2,150
  5acf6c:	0816b3cd 	j	0x5acf34
  5acf70:	00000000 	nop

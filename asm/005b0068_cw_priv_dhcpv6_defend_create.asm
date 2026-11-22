; func cw_priv_dhcpv6_defend_create @ 0x005b0068 size=0x1bc
  5b0068:	27bdffd8 	addiu	sp,sp,-40
  5b006c:	2405000c 	li	a1,12
  5b0070:	afb10020 	sw	s1,32(sp)
  5b0074:	afb0001c 	sw	s0,28(sp)
  5b0078:	afbf0024 	sw	ra,36(sp)
  5b007c:	0c15c8cc 	jal	0x572330
  5b0080:	00808021 	move	s0,a0
  5b0084:	1040002b 	beqz	v0,0x5b0134
  5b0088:	00408821 	move	s1,v0
  5b008c:	ac400008 	sw	zero,8(v0)
  5b0090:	8e020004 	lw	v0,4(s0)
  5b0094:	5040000b 	beqzl	v0,0x5b00c4
  5b0098:	8e250004 	lw	a1,4(s1)
  5b009c:	8e040008 	lw	a0,8(s0)
  5b00a0:	50800040 	beqzl	a0,0x5b01a4
  5b00a4:	3c020075 	lui	v0,0x75
  5b00a8:	24050011 	li	a1,17
  5b00ac:	70452802 	mul	a1,v0,a1
  5b00b0:	0c15c8cc 	jal	0x572330
  5b00b4:	30a5ffff 	andi	a1,a1,0xffff
  5b00b8:	10400041 	beqz	v0,0x5b01c0
  5b00bc:	ae220008 	sw	v0,8(s1)
  5b00c0:	8e250004 	lw	a1,4(s1)
  5b00c4:	24020011 	li	v0,17
  5b00c8:	24040061 	li	a0,97
  5b00cc:	02203021 	move	a2,s1
  5b00d0:	70a22802 	mul	a1,a1,v0
  5b00d4:	24a50006 	addiu	a1,a1,6
  5b00d8:	0c15c943 	jal	0x57250c
  5b00dc:	30a5ffff 	andi	a1,a1,0xffff
  5b00e0:	10400007 	beqz	v0,0x5b0100
  5b00e4:	00408021 	move	s0,v0
  5b00e8:	8fbf0024 	lw	ra,36(sp)
  5b00ec:	02001021 	move	v0,s0
  5b00f0:	8fb10020 	lw	s1,32(sp)
  5b00f4:	8fb0001c 	lw	s0,28(sp)
  5b00f8:	03e00008 	jr	ra
  5b00fc:	27bd0028 	addiu	sp,sp,40
  5b0100:	3c020075 	lui	v0,0x75
  5b0104:	8c42cf58 	lw	v0,-12456(v0)
  5b0108:	1440001a 	bnez	v0,0x5b0174
  5b010c:	00000000 	nop
  5b0110:	8e240008 	lw	a0,8(s1)
  5b0114:	10800003 	beqz	a0,0x5b0124
  5b0118:	00000000 	nop
  5b011c:	0c101f7c 	jal	0x407df0
  5b0120:	00000000 	nop
  5b0124:	0c101f7c 	jal	0x407df0
  5b0128:	02202021 	move	a0,s1
  5b012c:	0816c03b 	j	0x5b00ec
  5b0130:	8fbf0024 	lw	ra,36(sp)
  5b0134:	3c020075 	lui	v0,0x75
  5b0138:	8c42cf58 	lw	v0,-12456(v0)
  5b013c:	1040ffea 	beqz	v0,0x5b00e8
  5b0140:	00008021 	move	s0,zero
  5b0144:	0c16276a 	jal	0x589da8
  5b0148:	00000000 	nop
  5b014c:	5040ffe7 	beqzl	v0,0x5b00ec
  5b0150:	8fbf0024 	lw	ra,36(sp)
  5b0154:	3c04006d 	lui	a0,0x6d
  5b0158:	3c05006f 	lui	a1,0x6f
  5b015c:	248434fc 	addiu	a0,a0,13564
  5b0160:	24a5aad0 	addiu	a1,a1,-21808
  5b0164:	0c101b74 	jal	0x406dd0
  5b0168:	240600eb 	li	a2,235
  5b016c:	0816c03b 	j	0x5b00ec
  5b0170:	8fbf0024 	lw	ra,36(sp)
  5b0174:	0c16276a 	jal	0x589da8
  5b0178:	00000000 	nop
  5b017c:	5040ffe5 	beqzl	v0,0x5b0114
  5b0180:	8e240008 	lw	a0,8(s1)
  5b0184:	3c04006d 	lui	a0,0x6d
  5b0188:	3c05006f 	lui	a1,0x6f
  5b018c:	248447f0 	addiu	a0,a0,18416
  5b0190:	24a5aad0 	addiu	a1,a1,-21808
  5b0194:	0c101b74 	jal	0x406dd0
  5b0198:	24060106 	li	a2,262
  5b019c:	0816c045 	j	0x5b0114
  5b01a0:	8e240008 	lw	a0,8(s1)
  5b01a4:	8c42cf58 	lw	v0,-12456(v0)
  5b01a8:	14400015 	bnez	v0,0x5b0200
  5b01ac:	00000000 	nop
  5b01b0:	0c101f7c 	jal	0x407df0
  5b01b4:	02202021 	move	a0,s1
  5b01b8:	0816c03a 	j	0x5b00e8
  5b01bc:	00008021 	move	s0,zero
  5b01c0:	3c020075 	lui	v0,0x75
  5b01c4:	8c42cf58 	lw	v0,-12456(v0)
  5b01c8:	1040fff9 	beqz	v0,0x5b01b0
  5b01cc:	00000000 	nop
  5b01d0:	0c16276a 	jal	0x589da8
  5b01d4:	00000000 	nop
  5b01d8:	1040fff5 	beqz	v0,0x5b01b0
  5b01dc:	3c04006f 	lui	a0,0x6f
  5b01e0:	3c05006f 	lui	a1,0x6f
  5b01e4:	2484a82c 	addiu	a0,a0,-22484
  5b01e8:	24a5aad0 	addiu	a1,a1,-21808
  5b01ec:	240600fc 	li	a2,252
  5b01f0:	0c101b74 	jal	0x406dd0
  5b01f4:	00000000 	nop
  5b01f8:	0816c06c 	j	0x5b01b0
  5b01fc:	00000000 	nop
  5b0200:	0c16276a 	jal	0x589da8
  5b0204:	00000000 	nop
  5b0208:	1040ffe9 	beqz	v0,0x5b01b0
  5b020c:	3c04006f 	lui	a0,0x6f
  5b0210:	3c05006f 	lui	a1,0x6f
  5b0214:	2484a800 	addiu	a0,a0,-22528
  5b0218:	24a5aad0 	addiu	a1,a1,-21808
  5b021c:	0816c07c 	j	0x5b01f0
  5b0220:	240600f5 	li	a2,245

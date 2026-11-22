; func cw_priv_chnl_scan_report_create @ 0x005adf38 size=0x1c4
  5adf38:	27bdffd8 	addiu	sp,sp,-40
  5adf3c:	afb0001c 	sw	s0,28(sp)
  5adf40:	afbf0024 	sw	ra,36(sp)
  5adf44:	afb10020 	sw	s1,32(sp)
  5adf48:	90820000 	lbu	v0,0(a0)
  5adf4c:	10400004 	beqz	v0,0x5adf60
  5adf50:	00808021 	move	s0,a0
  5adf54:	8c820004 	lw	v0,4(a0)
  5adf58:	1040003c 	beqz	v0,0x5ae04c
  5adf5c:	3c020075 	lui	v0,0x75
  5adf60:	24050008 	li	a1,8
  5adf64:	0c15c8cc 	jal	0x572330
  5adf68:	02002021 	move	a0,s0
  5adf6c:	10400019 	beqz	v0,0x5adfd4
  5adf70:	00408821 	move	s1,v0
  5adf74:	92020000 	lbu	v0,0(s0)
  5adf78:	a2220000 	sb	v0,0(s1)
  5adf7c:	24020009 	li	v0,9
  5adf80:	92050000 	lbu	a1,0(s0)
  5adf84:	8e040004 	lw	a0,4(s0)
  5adf88:	70a22802 	mul	a1,a1,v0
  5adf8c:	0c15c8cc 	jal	0x572330
  5adf90:	30a5ffff 	andi	a1,a1,0xffff
  5adf94:	10400046 	beqz	v0,0x5ae0b0
  5adf98:	ae220004 	sw	v0,4(s1)
  5adf9c:	92250000 	lbu	a1,0(s1)
  5adfa0:	24020009 	li	v0,9
  5adfa4:	2404009c 	li	a0,156
  5adfa8:	02203021 	move	a2,s1
  5adfac:	0c15c943 	jal	0x57250c
  5adfb0:	70a22802 	mul	a1,a1,v0
  5adfb4:	10400018 	beqz	v0,0x5ae018
  5adfb8:	00408021 	move	s0,v0
  5adfbc:	8fbf0024 	lw	ra,36(sp)
  5adfc0:	02001021 	move	v0,s0
  5adfc4:	8fb10020 	lw	s1,32(sp)
  5adfc8:	8fb0001c 	lw	s0,28(sp)
  5adfcc:	03e00008 	jr	ra
  5adfd0:	27bd0028 	addiu	sp,sp,40
  5adfd4:	3c020075 	lui	v0,0x75
  5adfd8:	8c42cf58 	lw	v0,-12456(v0)
  5adfdc:	1040fff7 	beqz	v0,0x5adfbc
  5adfe0:	00008021 	move	s0,zero
  5adfe4:	0c16276a 	jal	0x589da8
  5adfe8:	00000000 	nop
  5adfec:	5040fff4 	beqzl	v0,0x5adfc0
  5adff0:	8fbf0024 	lw	ra,36(sp)
  5adff4:	3c04006d 	lui	a0,0x6d
  5adff8:	3c05006f 	lui	a1,0x6f
  5adffc:	248434fc 	addiu	a0,a0,13564
  5ae000:	24a5a340 	addiu	a1,a1,-23744
  5ae004:	240600e0 	li	a2,224
  5ae008:	0c101b74 	jal	0x406dd0
  5ae00c:	00000000 	nop
  5ae010:	0816b7f0 	j	0x5adfc0
  5ae014:	8fbf0024 	lw	ra,36(sp)
  5ae018:	3c020075 	lui	v0,0x75
  5ae01c:	8c42cf58 	lw	v0,-12456(v0)
  5ae020:	14400017 	bnez	v0,0x5ae080
  5ae024:	00000000 	nop
  5ae028:	8e240004 	lw	a0,4(s1)
  5ae02c:	10800003 	beqz	a0,0x5ae03c
  5ae030:	00000000 	nop
  5ae034:	0c101f7c 	jal	0x407df0
  5ae038:	00000000 	nop
  5ae03c:	0c101f7c 	jal	0x407df0
  5ae040:	02202021 	move	a0,s1
  5ae044:	0816b7f0 	j	0x5adfc0
  5ae048:	8fbf0024 	lw	ra,36(sp)
  5ae04c:	8c42cf58 	lw	v0,-12456(v0)
  5ae050:	1040ffda 	beqz	v0,0x5adfbc
  5ae054:	00008021 	move	s0,zero
  5ae058:	0c16276a 	jal	0x589da8
  5ae05c:	00000000 	nop
  5ae060:	5040ffd7 	beqzl	v0,0x5adfc0
  5ae064:	8fbf0024 	lw	ra,36(sp)
  5ae068:	3c04006f 	lui	a0,0x6f
  5ae06c:	3c05006f 	lui	a1,0x6f
  5ae070:	2484a2c0 	addiu	a0,a0,-23872
  5ae074:	24a5a340 	addiu	a1,a1,-23744
  5ae078:	0816b802 	j	0x5ae008
  5ae07c:	240600d9 	li	a2,217
  5ae080:	0c16276a 	jal	0x589da8
  5ae084:	00000000 	nop
  5ae088:	5040ffe8 	beqzl	v0,0x5ae02c
  5ae08c:	8e240004 	lw	a0,4(s1)
  5ae090:	3c04006d 	lui	a0,0x6d
  5ae094:	3c05006f 	lui	a1,0x6f
  5ae098:	248447f0 	addiu	a0,a0,18416
  5ae09c:	24a5a340 	addiu	a1,a1,-23744
  5ae0a0:	0c101b74 	jal	0x406dd0
  5ae0a4:	240600f2 	li	a2,242
  5ae0a8:	0816b80b 	j	0x5ae02c
  5ae0ac:	8e240004 	lw	a0,4(s1)
  5ae0b0:	3c020075 	lui	v0,0x75
  5ae0b4:	8c42cf58 	lw	v0,-12456(v0)
  5ae0b8:	14400005 	bnez	v0,0x5ae0d0
  5ae0bc:	00000000 	nop
  5ae0c0:	0c101f7c 	jal	0x407df0
  5ae0c4:	02202021 	move	a0,s1
  5ae0c8:	0816b7ef 	j	0x5adfbc
  5ae0cc:	00008021 	move	s0,zero
  5ae0d0:	0c16276a 	jal	0x589da8
  5ae0d4:	00000000 	nop
  5ae0d8:	1040fff9 	beqz	v0,0x5ae0c0
  5ae0dc:	3c04006f 	lui	a0,0x6f
  5ae0e0:	3c05006f 	lui	a1,0x6f
  5ae0e4:	2484a2e8 	addiu	a0,a0,-23832
  5ae0e8:	24a5a340 	addiu	a1,a1,-23744
  5ae0ec:	0c101b74 	jal	0x406dd0
  5ae0f0:	240600e8 	li	a2,232
  5ae0f4:	0816b830 	j	0x5ae0c0
  5ae0f8:	00000000 	nop

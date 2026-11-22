; func cw_ac_name_create @ 0x0056ea6c size=0x170
  56ea6c:	27bdffd8 	addiu	sp,sp,-40
  56ea70:	24050008 	li	a1,8
  56ea74:	afb10020 	sw	s1,32(sp)
  56ea78:	afb0001c 	sw	s0,28(sp)
  56ea7c:	afbf0024 	sw	ra,36(sp)
  56ea80:	0c15c8cc 	jal	0x572330
  56ea84:	00808021 	move	s0,a0
  56ea88:	10400025 	beqz	v0,0x56eb20
  56ea8c:	00408821 	move	s1,v0
  56ea90:	ac400004 	sw	zero,4(v0)
  56ea94:	96050000 	lhu	a1,0(s0)
  56ea98:	50a00009 	beqzl	a1,0x56eac0
  56ea9c:	96250000 	lhu	a1,0(s1)
  56eaa0:	8e040004 	lw	a0,4(s0)
  56eaa4:	50800006 	beqzl	a0,0x56eac0
  56eaa8:	96250000 	lhu	a1,0(s1)
  56eaac:	0c15c909 	jal	0x572424
  56eab0:	00000000 	nop
  56eab4:	10400036 	beqz	v0,0x56eb90
  56eab8:	ae220004 	sw	v0,4(s1)
  56eabc:	96250000 	lhu	a1,0(s1)
  56eac0:	24040004 	li	a0,4
  56eac4:	0c15c943 	jal	0x57250c
  56eac8:	02203021 	move	a2,s1
  56eacc:	10400007 	beqz	v0,0x56eaec
  56ead0:	00408021 	move	s0,v0
  56ead4:	8fbf0024 	lw	ra,36(sp)
  56ead8:	02001021 	move	v0,s0
  56eadc:	8fb10020 	lw	s1,32(sp)
  56eae0:	8fb0001c 	lw	s0,28(sp)
  56eae4:	03e00008 	jr	ra
  56eae8:	27bd0028 	addiu	sp,sp,40
  56eaec:	3c020075 	lui	v0,0x75
  56eaf0:	8c42cf58 	lw	v0,-12456(v0)
  56eaf4:	1440001a 	bnez	v0,0x56eb60
  56eaf8:	00000000 	nop
  56eafc:	8e240004 	lw	a0,4(s1)
  56eb00:	10800003 	beqz	a0,0x56eb10
  56eb04:	00000000 	nop
  56eb08:	0c101f7c 	jal	0x407df0
  56eb0c:	00000000 	nop
  56eb10:	0c101f7c 	jal	0x407df0
  56eb14:	02202021 	move	a0,s1
  56eb18:	0815bab6 	j	0x56ead8
  56eb1c:	8fbf0024 	lw	ra,36(sp)
  56eb20:	3c020075 	lui	v0,0x75
  56eb24:	8c42cf58 	lw	v0,-12456(v0)
  56eb28:	1040ffea 	beqz	v0,0x56ead4
  56eb2c:	00008021 	move	s0,zero
  56eb30:	0c16276a 	jal	0x589da8
  56eb34:	00000000 	nop
  56eb38:	5040ffe7 	beqzl	v0,0x56ead8
  56eb3c:	8fbf0024 	lw	ra,36(sp)
  56eb40:	3c04006d 	lui	a0,0x6d
  56eb44:	3c05006d 	lui	a1,0x6d
  56eb48:	248434fc 	addiu	a0,a0,13564
  56eb4c:	24a57120 	addiu	a1,a1,28960
  56eb50:	0c101b74 	jal	0x406dd0
  56eb54:	240600a6 	li	a2,166
  56eb58:	0815bab6 	j	0x56ead8
  56eb5c:	8fbf0024 	lw	ra,36(sp)
  56eb60:	0c16276a 	jal	0x589da8
  56eb64:	00000000 	nop
  56eb68:	5040ffe5 	beqzl	v0,0x56eb00
  56eb6c:	8e240004 	lw	a0,4(s1)
  56eb70:	3c04006d 	lui	a0,0x6d
  56eb74:	3c05006d 	lui	a1,0x6d
  56eb78:	24847098 	addiu	a0,a0,28824
  56eb7c:	24a57120 	addiu	a1,a1,28960
  56eb80:	0c101b74 	jal	0x406dd0
  56eb84:	240600bb 	li	a2,187
  56eb88:	0815bac0 	j	0x56eb00
  56eb8c:	8e240004 	lw	a0,4(s1)
  56eb90:	3c020075 	lui	v0,0x75
  56eb94:	8c42cf58 	lw	v0,-12456(v0)
  56eb98:	14400005 	bnez	v0,0x56ebb0
  56eb9c:	00000000 	nop
  56eba0:	0c101f7c 	jal	0x407df0
  56eba4:	02202021 	move	a0,s1
  56eba8:	0815bab5 	j	0x56ead4
  56ebac:	00008021 	move	s0,zero
  56ebb0:	0c16276a 	jal	0x589da8
  56ebb4:	00000000 	nop
  56ebb8:	1040fff9 	beqz	v0,0x56eba0
  56ebbc:	3c04006d 	lui	a0,0x6d
  56ebc0:	3c05006d 	lui	a1,0x6d
  56ebc4:	24847068 	addiu	a0,a0,28776
  56ebc8:	24a57120 	addiu	a1,a1,28960
  56ebcc:	0c101b74 	jal	0x406dd0
  56ebd0:	240600b1 	li	a2,177
  56ebd4:	0815bae8 	j	0x56eba0
  56ebd8:	00000000 	nop

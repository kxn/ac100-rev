; func cw_priv_rpt_para_create @ 0x005be03c size=0xdc
  5be03c:	27bdffd8 	addiu	sp,sp,-40
  5be040:	24050010 	li	a1,16
  5be044:	afb0001c 	sw	s0,28(sp)
  5be048:	afbf0024 	sw	ra,36(sp)
  5be04c:	0c15c8cc 	jal	0x572330
  5be050:	afb10020 	sw	s1,32(sp)
  5be054:	1040000d 	beqz	v0,0x5be08c
  5be058:	00408021 	move	s0,v0
  5be05c:	2404002f 	li	a0,47
  5be060:	2405000d 	li	a1,13
  5be064:	0c15c943 	jal	0x57250c
  5be068:	00403021 	move	a2,v0
  5be06c:	10400017 	beqz	v0,0x5be0cc
  5be070:	00408821 	move	s1,v0
  5be074:	8fbf0024 	lw	ra,36(sp)
  5be078:	02201021 	move	v0,s1
  5be07c:	8fb10020 	lw	s1,32(sp)
  5be080:	8fb0001c 	lw	s0,28(sp)
  5be084:	03e00008 	jr	ra
  5be088:	27bd0028 	addiu	sp,sp,40
  5be08c:	3c020075 	lui	v0,0x75
  5be090:	8c42cf58 	lw	v0,-12456(v0)
  5be094:	1040fff7 	beqz	v0,0x5be074
  5be098:	00008821 	move	s1,zero
  5be09c:	0c16276a 	jal	0x589da8
  5be0a0:	00000000 	nop
  5be0a4:	5040fff4 	beqzl	v0,0x5be078
  5be0a8:	8fbf0024 	lw	ra,36(sp)
  5be0ac:	3c04006d 	lui	a0,0x6d
  5be0b0:	3c05006f 	lui	a1,0x6f
  5be0b4:	248434fc 	addiu	a0,a0,13564
  5be0b8:	24a5e760 	addiu	a1,a1,-6304
  5be0bc:	0c101b74 	jal	0x406dd0
  5be0c0:	240600af 	li	a2,175
  5be0c4:	0816f81e 	j	0x5be078
  5be0c8:	8fbf0024 	lw	ra,36(sp)
  5be0cc:	3c020075 	lui	v0,0x75
  5be0d0:	8c42cf58 	lw	v0,-12456(v0)
  5be0d4:	14400005 	bnez	v0,0x5be0ec
  5be0d8:	00000000 	nop
  5be0dc:	0c101f7c 	jal	0x407df0
  5be0e0:	02002021 	move	a0,s0
  5be0e4:	0816f81e 	j	0x5be078
  5be0e8:	8fbf0024 	lw	ra,36(sp)
  5be0ec:	0c16276a 	jal	0x589da8
  5be0f0:	00000000 	nop
  5be0f4:	1040fff9 	beqz	v0,0x5be0dc
  5be0f8:	3c04006d 	lui	a0,0x6d
  5be0fc:	3c05006f 	lui	a1,0x6f
  5be100:	248447f0 	addiu	a0,a0,18416
  5be104:	24a5e760 	addiu	a1,a1,-6304
  5be108:	0c101b74 	jal	0x406dd0
  5be10c:	240600b7 	li	a2,183
  5be110:	0816f837 	j	0x5be0dc
  5be114:	00000000 	nop
	...

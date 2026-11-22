; func cw_priv_capwap_retrans_para_create @ 0x005ad0bc size=0xdc
  5ad0bc:	27bdffd8 	addiu	sp,sp,-40
  5ad0c0:	24050006 	li	a1,6
  5ad0c4:	afb0001c 	sw	s0,28(sp)
  5ad0c8:	afbf0024 	sw	ra,36(sp)
  5ad0cc:	0c15c8cc 	jal	0x572330
  5ad0d0:	afb10020 	sw	s1,32(sp)
  5ad0d4:	1040000d 	beqz	v0,0x5ad10c
  5ad0d8:	00408021 	move	s0,v0
  5ad0dc:	24040086 	li	a0,134
  5ad0e0:	24050004 	li	a1,4
  5ad0e4:	0c15c943 	jal	0x57250c
  5ad0e8:	00403021 	move	a2,v0
  5ad0ec:	10400017 	beqz	v0,0x5ad14c
  5ad0f0:	00408821 	move	s1,v0
  5ad0f4:	8fbf0024 	lw	ra,36(sp)
  5ad0f8:	02201021 	move	v0,s1
  5ad0fc:	8fb10020 	lw	s1,32(sp)
  5ad100:	8fb0001c 	lw	s0,28(sp)
  5ad104:	03e00008 	jr	ra
  5ad108:	27bd0028 	addiu	sp,sp,40
  5ad10c:	3c020075 	lui	v0,0x75
  5ad110:	8c42cf58 	lw	v0,-12456(v0)
  5ad114:	1040fff7 	beqz	v0,0x5ad0f4
  5ad118:	00008821 	move	s1,zero
  5ad11c:	0c16276a 	jal	0x589da8
  5ad120:	00000000 	nop
  5ad124:	5040fff4 	beqzl	v0,0x5ad0f8
  5ad128:	8fbf0024 	lw	ra,36(sp)
  5ad12c:	3c04006d 	lui	a0,0x6d
  5ad130:	3c05006f 	lui	a1,0x6f
  5ad134:	248434fc 	addiu	a0,a0,13564
  5ad138:	24a59f00 	addiu	a1,a1,-24832
  5ad13c:	0c101b74 	jal	0x406dd0
  5ad140:	240600b2 	li	a2,178
  5ad144:	0816b43e 	j	0x5ad0f8
  5ad148:	8fbf0024 	lw	ra,36(sp)
  5ad14c:	3c020075 	lui	v0,0x75
  5ad150:	8c42cf58 	lw	v0,-12456(v0)
  5ad154:	14400005 	bnez	v0,0x5ad16c
  5ad158:	00000000 	nop
  5ad15c:	0c101f7c 	jal	0x407df0
  5ad160:	02002021 	move	a0,s0
  5ad164:	0816b43e 	j	0x5ad0f8
  5ad168:	8fbf0024 	lw	ra,36(sp)
  5ad16c:	0c16276a 	jal	0x589da8
  5ad170:	00000000 	nop
  5ad174:	1040fff9 	beqz	v0,0x5ad15c
  5ad178:	3c04006d 	lui	a0,0x6d
  5ad17c:	3c05006f 	lui	a1,0x6f
  5ad180:	248447f0 	addiu	a0,a0,18416
  5ad184:	24a59f00 	addiu	a1,a1,-24832
  5ad188:	0c101b74 	jal	0x406dd0
  5ad18c:	240600ba 	li	a2,186
  5ad190:	0816b457 	j	0x5ad15c
  5ad194:	00000000 	nop
	...

; func cw_priv_igmp_query_config_create @ 0x005b2130 size=0xdc
  5b2130:	27bdffd8 	addiu	sp,sp,-40
  5b2134:	24050004 	li	a1,4
  5b2138:	afb0001c 	sw	s0,28(sp)
  5b213c:	afbf0024 	sw	ra,36(sp)
  5b2140:	0c15c8cc 	jal	0x572330
  5b2144:	afb10020 	sw	s1,32(sp)
  5b2148:	1040000d 	beqz	v0,0x5b2180
  5b214c:	00408021 	move	s0,v0
  5b2150:	24040072 	li	a0,114
  5b2154:	24050003 	li	a1,3
  5b2158:	0c15c943 	jal	0x57250c
  5b215c:	00403021 	move	a2,v0
  5b2160:	10400017 	beqz	v0,0x5b21c0
  5b2164:	00408821 	move	s1,v0
  5b2168:	8fbf0024 	lw	ra,36(sp)
  5b216c:	02201021 	move	v0,s1
  5b2170:	8fb10020 	lw	s1,32(sp)
  5b2174:	8fb0001c 	lw	s0,28(sp)
  5b2178:	03e00008 	jr	ra
  5b217c:	27bd0028 	addiu	sp,sp,40
  5b2180:	3c020075 	lui	v0,0x75
  5b2184:	8c42cf58 	lw	v0,-12456(v0)
  5b2188:	1040fff7 	beqz	v0,0x5b2168
  5b218c:	00008821 	move	s1,zero
  5b2190:	0c16276a 	jal	0x589da8
  5b2194:	00000000 	nop
  5b2198:	5040fff4 	beqzl	v0,0x5b216c
  5b219c:	8fbf0024 	lw	ra,36(sp)
  5b21a0:	3c04006d 	lui	a0,0x6d
  5b21a4:	3c05006f 	lui	a1,0x6f
  5b21a8:	248434fc 	addiu	a0,a0,13564
  5b21ac:	24a5b450 	addiu	a1,a1,-19376
  5b21b0:	0c101b74 	jal	0x406dd0
  5b21b4:	240600a6 	li	a2,166
  5b21b8:	0816c85b 	j	0x5b216c
  5b21bc:	8fbf0024 	lw	ra,36(sp)
  5b21c0:	3c020075 	lui	v0,0x75
  5b21c4:	8c42cf58 	lw	v0,-12456(v0)
  5b21c8:	14400005 	bnez	v0,0x5b21e0
  5b21cc:	00000000 	nop
  5b21d0:	0c101f7c 	jal	0x407df0
  5b21d4:	02002021 	move	a0,s0
  5b21d8:	0816c85b 	j	0x5b216c
  5b21dc:	8fbf0024 	lw	ra,36(sp)
  5b21e0:	0c16276a 	jal	0x589da8
  5b21e4:	00000000 	nop
  5b21e8:	1040fff9 	beqz	v0,0x5b21d0
  5b21ec:	3c04006d 	lui	a0,0x6d
  5b21f0:	3c05006f 	lui	a1,0x6f
  5b21f4:	248447f0 	addiu	a0,a0,18416
  5b21f8:	24a5b450 	addiu	a1,a1,-19376
  5b21fc:	0c101b74 	jal	0x406dd0
  5b2200:	240600ae 	li	a2,174
  5b2204:	0816c874 	j	0x5b21d0
  5b2208:	00000000 	nop

; func cw_priv_join_request_transmit_create @ 0x005b4170 size=0xdc
  5b4170:	27bdffd8 	addiu	sp,sp,-40
  5b4174:	24050004 	li	a1,4
  5b4178:	afb0001c 	sw	s0,28(sp)
  5b417c:	afbf0024 	sw	ra,36(sp)
  5b4180:	0c15c8cc 	jal	0x572330
  5b4184:	afb10020 	sw	s1,32(sp)
  5b4188:	1040000d 	beqz	v0,0x5b41c0
  5b418c:	00408021 	move	s0,v0
  5b4190:	24040096 	li	a0,150
  5b4194:	24050004 	li	a1,4
  5b4198:	0c15c943 	jal	0x57250c
  5b419c:	00403021 	move	a2,v0
  5b41a0:	10400017 	beqz	v0,0x5b4200
  5b41a4:	00408821 	move	s1,v0
  5b41a8:	8fbf0024 	lw	ra,36(sp)
  5b41ac:	02201021 	move	v0,s1
  5b41b0:	8fb10020 	lw	s1,32(sp)
  5b41b4:	8fb0001c 	lw	s0,28(sp)
  5b41b8:	03e00008 	jr	ra
  5b41bc:	27bd0028 	addiu	sp,sp,40
  5b41c0:	3c020075 	lui	v0,0x75
  5b41c4:	8c42cf58 	lw	v0,-12456(v0)
  5b41c8:	1040fff7 	beqz	v0,0x5b41a8
  5b41cc:	00008821 	move	s1,zero
  5b41d0:	0c16276a 	jal	0x589da8
  5b41d4:	00000000 	nop
  5b41d8:	5040fff4 	beqzl	v0,0x5b41ac
  5b41dc:	8fbf0024 	lw	ra,36(sp)
  5b41e0:	3c04006d 	lui	a0,0x6d
  5b41e4:	3c05006f 	lui	a1,0x6f
  5b41e8:	248434fc 	addiu	a0,a0,13564
  5b41ec:	24a5be40 	addiu	a1,a1,-16832
  5b41f0:	0c101b74 	jal	0x406dd0
  5b41f4:	2406009e 	li	a2,158
  5b41f8:	0816d06b 	j	0x5b41ac
  5b41fc:	8fbf0024 	lw	ra,36(sp)
  5b4200:	3c020075 	lui	v0,0x75
  5b4204:	8c42cf58 	lw	v0,-12456(v0)
  5b4208:	14400005 	bnez	v0,0x5b4220
  5b420c:	00000000 	nop
  5b4210:	0c101f7c 	jal	0x407df0
  5b4214:	02002021 	move	a0,s0
  5b4218:	0816d06b 	j	0x5b41ac
  5b421c:	8fbf0024 	lw	ra,36(sp)
  5b4220:	0c16276a 	jal	0x589da8
  5b4224:	00000000 	nop
  5b4228:	1040fff9 	beqz	v0,0x5b4210
  5b422c:	3c04006d 	lui	a0,0x6d
  5b4230:	3c05006f 	lui	a1,0x6f
  5b4234:	24843580 	addiu	a0,a0,13696
  5b4238:	24a5be40 	addiu	a1,a1,-16832
  5b423c:	0c101b74 	jal	0x406dd0
  5b4240:	240600a6 	li	a2,166
  5b4244:	0816d084 	j	0x5b4210
  5b4248:	00000000 	nop

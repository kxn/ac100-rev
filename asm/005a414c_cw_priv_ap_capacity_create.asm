; func cw_priv_ap_capacity_create @ 0x005a414c size=0xdc
  5a414c:	27bdffd8 	addiu	sp,sp,-40
  5a4150:	24050004 	li	a1,4
  5a4154:	afb0001c 	sw	s0,28(sp)
  5a4158:	afbf0024 	sw	ra,36(sp)
  5a415c:	0c15c8cc 	jal	0x572330
  5a4160:	afb10020 	sw	s1,32(sp)
  5a4164:	1040000d 	beqz	v0,0x5a419c
  5a4168:	00408021 	move	s0,v0
  5a416c:	2404002c 	li	a0,44
  5a4170:	24050004 	li	a1,4
  5a4174:	0c15c943 	jal	0x57250c
  5a4178:	00403021 	move	a2,v0
  5a417c:	10400017 	beqz	v0,0x5a41dc
  5a4180:	00408821 	move	s1,v0
  5a4184:	8fbf0024 	lw	ra,36(sp)
  5a4188:	02201021 	move	v0,s1
  5a418c:	8fb10020 	lw	s1,32(sp)
  5a4190:	8fb0001c 	lw	s0,28(sp)
  5a4194:	03e00008 	jr	ra
  5a4198:	27bd0028 	addiu	sp,sp,40
  5a419c:	3c020075 	lui	v0,0x75
  5a41a0:	8c42cf58 	lw	v0,-12456(v0)
  5a41a4:	1040fff7 	beqz	v0,0x5a4184
  5a41a8:	00008821 	move	s1,zero
  5a41ac:	0c16276a 	jal	0x589da8
  5a41b0:	00000000 	nop
  5a41b4:	5040fff4 	beqzl	v0,0x5a4188
  5a41b8:	8fbf0024 	lw	ra,36(sp)
  5a41bc:	3c04006d 	lui	a0,0x6d
  5a41c0:	3c05006e 	lui	a1,0x6e
  5a41c4:	248434fc 	addiu	a0,a0,13564
  5a41c8:	24a57430 	addiu	a1,a1,29744
  5a41cc:	0c101b74 	jal	0x406dd0
  5a41d0:	240600a3 	li	a2,163
  5a41d4:	08169062 	j	0x5a4188
  5a41d8:	8fbf0024 	lw	ra,36(sp)
  5a41dc:	3c020075 	lui	v0,0x75
  5a41e0:	8c42cf58 	lw	v0,-12456(v0)
  5a41e4:	14400005 	bnez	v0,0x5a41fc
  5a41e8:	00000000 	nop
  5a41ec:	0c101f7c 	jal	0x407df0
  5a41f0:	02002021 	move	a0,s0
  5a41f4:	08169062 	j	0x5a4188
  5a41f8:	8fbf0024 	lw	ra,36(sp)
  5a41fc:	0c16276a 	jal	0x589da8
  5a4200:	00000000 	nop
  5a4204:	1040fff9 	beqz	v0,0x5a41ec
  5a4208:	3c04006d 	lui	a0,0x6d
  5a420c:	3c05006e 	lui	a1,0x6e
  5a4210:	248447f0 	addiu	a0,a0,18416
  5a4214:	24a57430 	addiu	a1,a1,29744
  5a4218:	0c101b74 	jal	0x406dd0
  5a421c:	240600ab 	li	a2,171
  5a4220:	0816907b 	j	0x5a41ec
  5a4224:	00000000 	nop

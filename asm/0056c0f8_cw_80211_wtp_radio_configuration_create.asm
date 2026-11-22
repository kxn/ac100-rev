; func cw_80211_wtp_radio_configuration_create @ 0x0056c0f8 size=0xdc
  56c0f8:	27bdffd8 	addiu	sp,sp,-40
  56c0fc:	24050010 	li	a1,16
  56c100:	afb0001c 	sw	s0,28(sp)
  56c104:	afbf0024 	sw	ra,36(sp)
  56c108:	0c15c8cc 	jal	0x572330
  56c10c:	afb10020 	sw	s1,32(sp)
  56c110:	1040000d 	beqz	v0,0x56c148
  56c114:	00408021 	move	s0,v0
  56c118:	24040416 	li	a0,1046
  56c11c:	24050010 	li	a1,16
  56c120:	0c15c943 	jal	0x57250c
  56c124:	00403021 	move	a2,v0
  56c128:	10400017 	beqz	v0,0x56c188
  56c12c:	00408821 	move	s1,v0
  56c130:	8fbf0024 	lw	ra,36(sp)
  56c134:	02201021 	move	v0,s1
  56c138:	8fb10020 	lw	s1,32(sp)
  56c13c:	8fb0001c 	lw	s0,28(sp)
  56c140:	03e00008 	jr	ra
  56c144:	27bd0028 	addiu	sp,sp,40
  56c148:	3c020075 	lui	v0,0x75
  56c14c:	8c42cf58 	lw	v0,-12456(v0)
  56c150:	1040fff7 	beqz	v0,0x56c130
  56c154:	00008821 	move	s1,zero
  56c158:	0c16276a 	jal	0x589da8
  56c15c:	00000000 	nop
  56c160:	5040fff4 	beqzl	v0,0x56c134
  56c164:	8fbf0024 	lw	ra,36(sp)
  56c168:	3c04006d 	lui	a0,0x6d
  56c16c:	3c05006d 	lui	a1,0x6d
  56c170:	248434fc 	addiu	a0,a0,13564
  56c174:	24a55ef0 	addiu	a1,a1,24304
  56c178:	0c101b74 	jal	0x406dd0
  56c17c:	240600ca 	li	a2,202
  56c180:	0815b04d 	j	0x56c134
  56c184:	8fbf0024 	lw	ra,36(sp)
  56c188:	3c020075 	lui	v0,0x75
  56c18c:	8c42cf58 	lw	v0,-12456(v0)
  56c190:	14400005 	bnez	v0,0x56c1a8
  56c194:	00000000 	nop
  56c198:	0c101f7c 	jal	0x407df0
  56c19c:	02002021 	move	a0,s0
  56c1a0:	0815b04d 	j	0x56c134
  56c1a4:	8fbf0024 	lw	ra,36(sp)
  56c1a8:	0c16276a 	jal	0x589da8
  56c1ac:	00000000 	nop
  56c1b0:	1040fff9 	beqz	v0,0x56c198
  56c1b4:	3c04006d 	lui	a0,0x6d
  56c1b8:	3c05006d 	lui	a1,0x6d
  56c1bc:	248447f0 	addiu	a0,a0,18416
  56c1c0:	24a55ef0 	addiu	a1,a1,24304
  56c1c4:	0c101b74 	jal	0x406dd0
  56c1c8:	240600d2 	li	a2,210
  56c1cc:	0815b066 	j	0x56c198
  56c1d0:	00000000 	nop
	...

; func cw_priv_nd_defend_create @ 0x005b712c size=0x1bc
  5b712c:	27bdffd8 	addiu	sp,sp,-40
  5b7130:	2405000c 	li	a1,12
  5b7134:	afb10020 	sw	s1,32(sp)
  5b7138:	afb0001c 	sw	s0,28(sp)
  5b713c:	afbf0024 	sw	ra,36(sp)
  5b7140:	0c15c8cc 	jal	0x572330
  5b7144:	00808021 	move	s0,a0
  5b7148:	1040002b 	beqz	v0,0x5b71f8
  5b714c:	00408821 	move	s1,v0
  5b7150:	ac400008 	sw	zero,8(v0)
  5b7154:	8e020004 	lw	v0,4(s0)
  5b7158:	5040000b 	beqzl	v0,0x5b7188
  5b715c:	8e250004 	lw	a1,4(s1)
  5b7160:	8e040008 	lw	a0,8(s0)
  5b7164:	50800040 	beqzl	a0,0x5b7268
  5b7168:	3c020075 	lui	v0,0x75
  5b716c:	24050016 	li	a1,22
  5b7170:	70452802 	mul	a1,v0,a1
  5b7174:	0c15c8cc 	jal	0x572330
  5b7178:	30a5fffe 	andi	a1,a1,0xfffe
  5b717c:	10400041 	beqz	v0,0x5b7284
  5b7180:	ae220008 	sw	v0,8(s1)
  5b7184:	8e250004 	lw	a1,4(s1)
  5b7188:	24020016 	li	v0,22
  5b718c:	24040062 	li	a0,98
  5b7190:	02203021 	move	a2,s1
  5b7194:	70a22802 	mul	a1,a1,v0
  5b7198:	24a50006 	addiu	a1,a1,6
  5b719c:	0c15c943 	jal	0x57250c
  5b71a0:	30a5fffe 	andi	a1,a1,0xfffe
  5b71a4:	10400007 	beqz	v0,0x5b71c4
  5b71a8:	00408021 	move	s0,v0
  5b71ac:	8fbf0024 	lw	ra,36(sp)
  5b71b0:	02001021 	move	v0,s0
  5b71b4:	8fb10020 	lw	s1,32(sp)
  5b71b8:	8fb0001c 	lw	s0,28(sp)
  5b71bc:	03e00008 	jr	ra
  5b71c0:	27bd0028 	addiu	sp,sp,40
  5b71c4:	3c020075 	lui	v0,0x75
  5b71c8:	8c42cf58 	lw	v0,-12456(v0)
  5b71cc:	1440001a 	bnez	v0,0x5b7238
  5b71d0:	00000000 	nop
  5b71d4:	8e240008 	lw	a0,8(s1)
  5b71d8:	10800003 	beqz	a0,0x5b71e8
  5b71dc:	00000000 	nop
  5b71e0:	0c101f7c 	jal	0x407df0
  5b71e4:	00000000 	nop
  5b71e8:	0c101f7c 	jal	0x407df0
  5b71ec:	02202021 	move	a0,s1
  5b71f0:	0816dc6c 	j	0x5b71b0
  5b71f4:	8fbf0024 	lw	ra,36(sp)
  5b71f8:	3c020075 	lui	v0,0x75
  5b71fc:	8c42cf58 	lw	v0,-12456(v0)
  5b7200:	1040ffea 	beqz	v0,0x5b71ac
  5b7204:	00008021 	move	s0,zero
  5b7208:	0c16276a 	jal	0x589da8
  5b720c:	00000000 	nop
  5b7210:	5040ffe7 	beqzl	v0,0x5b71b0
  5b7214:	8fbf0024 	lw	ra,36(sp)
  5b7218:	3c04006d 	lui	a0,0x6d
  5b721c:	3c05006f 	lui	a1,0x6f
  5b7220:	248434fc 	addiu	a0,a0,13564
  5b7224:	24a5c970 	addiu	a1,a1,-13968
  5b7228:	0c101b74 	jal	0x406dd0
  5b722c:	240600e1 	li	a2,225
  5b7230:	0816dc6c 	j	0x5b71b0
  5b7234:	8fbf0024 	lw	ra,36(sp)
  5b7238:	0c16276a 	jal	0x589da8
  5b723c:	00000000 	nop
  5b7240:	5040ffe5 	beqzl	v0,0x5b71d8
  5b7244:	8e240008 	lw	a0,8(s1)
  5b7248:	3c04006d 	lui	a0,0x6d
  5b724c:	3c05006f 	lui	a1,0x6f
  5b7250:	248447f0 	addiu	a0,a0,18416
  5b7254:	24a5c970 	addiu	a1,a1,-13968
  5b7258:	0c101b74 	jal	0x406dd0
  5b725c:	240600fb 	li	a2,251
  5b7260:	0816dc76 	j	0x5b71d8
  5b7264:	8e240008 	lw	a0,8(s1)
  5b7268:	8c42cf58 	lw	v0,-12456(v0)
  5b726c:	14400015 	bnez	v0,0x5b72c4
  5b7270:	00000000 	nop
  5b7274:	0c101f7c 	jal	0x407df0
  5b7278:	02202021 	move	a0,s1
  5b727c:	0816dc6b 	j	0x5b71ac
  5b7280:	00008021 	move	s0,zero
  5b7284:	3c020075 	lui	v0,0x75
  5b7288:	8c42cf58 	lw	v0,-12456(v0)
  5b728c:	1040fff9 	beqz	v0,0x5b7274
  5b7290:	00000000 	nop
  5b7294:	0c16276a 	jal	0x589da8
  5b7298:	00000000 	nop
  5b729c:	1040fff5 	beqz	v0,0x5b7274
  5b72a0:	3c04006f 	lui	a0,0x6f
  5b72a4:	3c05006f 	lui	a1,0x6f
  5b72a8:	2484c868 	addiu	a0,a0,-14232
  5b72ac:	24a5c970 	addiu	a1,a1,-13968
  5b72b0:	240600f1 	li	a2,241
  5b72b4:	0c101b74 	jal	0x406dd0
  5b72b8:	00000000 	nop
  5b72bc:	0816dc9d 	j	0x5b7274
  5b72c0:	00000000 	nop
  5b72c4:	0c16276a 	jal	0x589da8
  5b72c8:	00000000 	nop
  5b72cc:	1040ffe9 	beqz	v0,0x5b7274
  5b72d0:	3c04006f 	lui	a0,0x6f
  5b72d4:	3c05006f 	lui	a1,0x6f
  5b72d8:	2484c840 	addiu	a0,a0,-14272
  5b72dc:	24a5c970 	addiu	a1,a1,-13968
  5b72e0:	0816dcad 	j	0x5b72b4
  5b72e4:	240600ea 	li	a2,234

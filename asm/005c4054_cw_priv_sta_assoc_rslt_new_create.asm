; func cw_priv_sta_assoc_rslt_new_create @ 0x005c4054 size=0x380
  5c4054:	27bdffc0 	addiu	sp,sp,-64
  5c4058:	24050020 	li	a1,32
  5c405c:	afb10020 	sw	s1,32(sp)
  5c4060:	afb0001c 	sw	s0,28(sp)
  5c4064:	00808021 	move	s0,a0
  5c4068:	afbf003c 	sw	ra,60(sp)
  5c406c:	afb70038 	sw	s7,56(sp)
  5c4070:	afb60034 	sw	s6,52(sp)
  5c4074:	afb50030 	sw	s5,48(sp)
  5c4078:	afb4002c 	sw	s4,44(sp)
  5c407c:	afb30028 	sw	s3,40(sp)
  5c4080:	0c15c8cc 	jal	0x572330
  5c4084:	afb20024 	sw	s2,36(sp)
  5c4088:	10400092 	beqz	v0,0x5c42d4
  5c408c:	00408821 	move	s1,v0
  5c4090:	24550014 	addiu	s5,v0,20
  5c4094:	3c16006f 	lui	s6,0x6f
  5c4098:	0c146b62 	jal	0x51ad88
  5c409c:	02a02021 	move	a0,s5
  5c40a0:	26040014 	addiu	a0,s0,20
  5c40a4:	0c10206c 	jal	0x4081b0
  5c40a8:	3c17006f 	lui	s7,0x6f
  5c40ac:	3c14007c 	lui	s4,0x7c
  5c40b0:	00408021 	move	s0,v0
  5c40b4:	26d6fae0 	addiu	s6,s6,-1312
  5c40b8:	1200001e 	beqz	s0,0x5c4134
  5c40bc:	26f7fb8c 	addiu	s7,s7,-1140
  5c40c0:	24050014 	li	a1,20
  5c40c4:	0c15c8cc 	jal	0x572330
  5c40c8:	02002021 	move	a0,s0
  5c40cc:	10400076 	beqz	v0,0x5c42a8
  5c40d0:	00409821 	move	s3,v0
  5c40d4:	00402821 	move	a1,v0
  5c40d8:	ac400010 	sw	zero,16(v0)
  5c40dc:	0c1021ac 	jal	0x4086b0
  5c40e0:	02a02021 	move	a0,s5
  5c40e4:	24030001 	li	v1,1
  5c40e8:	9602000c 	lhu	v0,12(s0)
  5c40ec:	10430040 	beq	v0,v1,0x5c41f0
  5c40f0:	9605000e 	lhu	a1,14(s0)
  5c40f4:	14400023 	bnez	v0,0x5c4184
  5c40f8:	24030002 	li	v1,2
  5c40fc:	10a00008 	beqz	a1,0x5c4120
  5c4100:	00000000 	nop
  5c4104:	8e040010 	lw	a0,16(s0)
  5c4108:	10800005 	beqz	a0,0x5c4120
  5c410c:	00000000 	nop
  5c4110:	0c15c8cc 	jal	0x572330
  5c4114:	24050002 	li	a1,2
  5c4118:	104000a1 	beqz	v0,0x5c43a0
  5c411c:	ae620010 	sw	v0,16(s3)
  5c4120:	0c1021a0 	jal	0x408680
  5c4124:	02002021 	move	a0,s0
  5c4128:	00408021 	move	s0,v0
  5c412c:	5600ffe5 	bnezl	s0,0x5c40c4
  5c4130:	24050014 	li	a1,20
  5c4134:	8e250010 	lw	a1,16(s1)
  5c4138:	2404008b 	li	a0,139
  5c413c:	02203021 	move	a2,s1
  5c4140:	24a50011 	addiu	a1,a1,17
  5c4144:	0c15c943 	jal	0x57250c
  5c4148:	30a5ffff 	andi	a1,a1,0xffff
  5c414c:	1040007a 	beqz	v0,0x5c4338
  5c4150:	00408021 	move	s0,v0
  5c4154:	8fbf003c 	lw	ra,60(sp)
  5c4158:	02001021 	move	v0,s0
  5c415c:	8fb70038 	lw	s7,56(sp)
  5c4160:	8fb60034 	lw	s6,52(sp)
  5c4164:	8fb50030 	lw	s5,48(sp)
  5c4168:	8fb4002c 	lw	s4,44(sp)
  5c416c:	8fb30028 	lw	s3,40(sp)
  5c4170:	8fb20024 	lw	s2,36(sp)
  5c4174:	8fb10020 	lw	s1,32(sp)
  5c4178:	8fb0001c 	lw	s0,28(sp)
  5c417c:	03e00008 	jr	ra
  5c4180:	27bd0040 	addiu	sp,sp,64
  5c4184:	1043003a 	beq	v0,v1,0x5c4270
  5c4188:	00000000 	nop
  5c418c:	10a0ffe4 	beqz	a1,0x5c4120
  5c4190:	00000000 	nop
  5c4194:	8e040010 	lw	a0,16(s0)
  5c4198:	1080ffe1 	beqz	a0,0x5c4120
  5c419c:	00000000 	nop
  5c41a0:	0c15c8cc 	jal	0x572330
  5c41a4:	00000000 	nop
  5c41a8:	1440ffdd 	bnez	v0,0x5c4120
  5c41ac:	ae620010 	sw	v0,16(s3)
  5c41b0:	3c020075 	lui	v0,0x75
  5c41b4:	8c42cf58 	lw	v0,-12456(v0)
  5c41b8:	1040003f 	beqz	v0,0x5c42b8
  5c41bc:	00000000 	nop
  5c41c0:	0c16276a 	jal	0x589da8
  5c41c4:	00000000 	nop
  5c41c8:	1040003b 	beqz	v0,0x5c42b8
  5c41cc:	3c04006d 	lui	a0,0x6d
  5c41d0:	3c05006f 	lui	a1,0x6f
  5c41d4:	248467c4 	addiu	a0,a0,26564
  5c41d8:	24a5fb8c 	addiu	a1,a1,-1140
  5c41dc:	240601ea 	li	a2,490
  5c41e0:	0c101b74 	jal	0x406dd0
  5c41e4:	00000000 	nop
  5c41e8:	081710ae 	j	0x5c42b8
  5c41ec:	00000000 	nop
  5c41f0:	10a0ffcb 	beqz	a1,0x5c4120
  5c41f4:	00000000 	nop
  5c41f8:	8e040010 	lw	a0,16(s0)
  5c41fc:	1080ffc8 	beqz	a0,0x5c4120
  5c4200:	00000000 	nop
  5c4204:	0c15c8cc 	jal	0x572330
  5c4208:	24050008 	li	a1,8
  5c420c:	00409021 	move	s2,v0
  5c4210:	10400056 	beqz	v0,0x5c436c
  5c4214:	ae620010 	sw	v0,16(s3)
  5c4218:	8e450000 	lw	a1,0(s2)
  5c421c:	8e020010 	lw	v0,16(s0)
  5c4220:	10a0ffbf 	beqz	a1,0x5c4120
  5c4224:	ae400004 	sw	zero,4(s2)
  5c4228:	8c440004 	lw	a0,4(v0)
  5c422c:	0c15c8cc 	jal	0x572330
  5c4230:	30a5ffff 	andi	a1,a1,0xffff
  5c4234:	1440ffba 	bnez	v0,0x5c4120
  5c4238:	ae420004 	sw	v0,4(s2)
  5c423c:	3c020075 	lui	v0,0x75
  5c4240:	8c42cf58 	lw	v0,-12456(v0)
  5c4244:	1040001c 	beqz	v0,0x5c42b8
  5c4248:	00000000 	nop
  5c424c:	0c16276a 	jal	0x589da8
  5c4250:	00000000 	nop
  5c4254:	10400018 	beqz	v0,0x5c42b8
  5c4258:	3c04006d 	lui	a0,0x6d
  5c425c:	3c05006f 	lui	a1,0x6f
  5c4260:	248467c4 	addiu	a0,a0,26564
  5c4264:	24a5fb8c 	addiu	a1,a1,-1140
  5c4268:	08171078 	j	0x5c41e0
  5c426c:	240601d6 	li	a2,470
  5c4270:	10a0ffab 	beqz	a1,0x5c4120
  5c4274:	8e825984 	lw	v0,22916(s4)
  5c4278:	1040ffa9 	beqz	v0,0x5c4120
  5c427c:	00000000 	nop
  5c4280:	0c16276a 	jal	0x589da8
  5c4284:	00000000 	nop
  5c4288:	1040ffa5 	beqz	v0,0x5c4120
  5c428c:	240601df 	li	a2,479
  5c4290:	9607000e 	lhu	a3,14(s0)
  5c4294:	02c02021 	move	a0,s6
  5c4298:	0c101b74 	jal	0x406dd0
  5c429c:	02e02821 	move	a1,s7
  5c42a0:	08171048 	j	0x5c4120
  5c42a4:	00000000 	nop
  5c42a8:	3c020075 	lui	v0,0x75
  5c42ac:	8c42cf58 	lw	v0,-12456(v0)
  5c42b0:	14400018 	bnez	v0,0x5c4314
  5c42b4:	00000000 	nop
  5c42b8:	0c170fdb 	jal	0x5c3f6c
  5c42bc:	02202021 	move	a0,s1
  5c42c0:	02202021 	move	a0,s1
  5c42c4:	0c101f7c 	jal	0x407df0
  5c42c8:	00008021 	move	s0,zero
  5c42cc:	08171056 	j	0x5c4158
  5c42d0:	8fbf003c 	lw	ra,60(sp)
  5c42d4:	3c020075 	lui	v0,0x75
  5c42d8:	8c42cf58 	lw	v0,-12456(v0)
  5c42dc:	1040ff9d 	beqz	v0,0x5c4154
  5c42e0:	00008021 	move	s0,zero
  5c42e4:	0c16276a 	jal	0x589da8
  5c42e8:	00000000 	nop
  5c42ec:	5040ff9a 	beqzl	v0,0x5c4158
  5c42f0:	8fbf003c 	lw	ra,60(sp)
  5c42f4:	3c04006d 	lui	a0,0x6d
  5c42f8:	3c05006f 	lui	a1,0x6f
  5c42fc:	248434fc 	addiu	a0,a0,13564
  5c4300:	24a5fb8c 	addiu	a1,a1,-1140
  5c4304:	0c101b74 	jal	0x406dd0
  5c4308:	2406019c 	li	a2,412
  5c430c:	08171056 	j	0x5c4158
  5c4310:	8fbf003c 	lw	ra,60(sp)
  5c4314:	0c16276a 	jal	0x589da8
  5c4318:	00000000 	nop
  5c431c:	1040ffe6 	beqz	v0,0x5c42b8
  5c4320:	3c04006e 	lui	a0,0x6e
  5c4324:	3c05006f 	lui	a1,0x6f
  5c4328:	2484c618 	addiu	a0,a0,-14824
  5c432c:	24a5fb8c 	addiu	a1,a1,-1140
  5c4330:	08171078 	j	0x5c41e0
  5c4334:	240601aa 	li	a2,426
  5c4338:	3c020075 	lui	v0,0x75
  5c433c:	8c42cf58 	lw	v0,-12456(v0)
  5c4340:	1040ffdd 	beqz	v0,0x5c42b8
  5c4344:	00000000 	nop
  5c4348:	0c16276a 	jal	0x589da8
  5c434c:	00000000 	nop
  5c4350:	1040ffd9 	beqz	v0,0x5c42b8
  5c4354:	3c04006d 	lui	a0,0x6d
  5c4358:	3c05006f 	lui	a1,0x6f
  5c435c:	248447f0 	addiu	a0,a0,18416
  5c4360:	24a5fb8c 	addiu	a1,a1,-1140
  5c4364:	08171078 	j	0x5c41e0
  5c4368:	240601f6 	li	a2,502
  5c436c:	3c020075 	lui	v0,0x75
  5c4370:	8c42cf58 	lw	v0,-12456(v0)
  5c4374:	1040ffd0 	beqz	v0,0x5c42b8
  5c4378:	00000000 	nop
  5c437c:	0c16276a 	jal	0x589da8
  5c4380:	00000000 	nop
  5c4384:	1040ffcc 	beqz	v0,0x5c42b8
  5c4388:	3c04006e 	lui	a0,0x6e
  5c438c:	3c05006f 	lui	a1,0x6f
  5c4390:	24849cf4 	addiu	a0,a0,-25356
  5c4394:	24a5fb8c 	addiu	a1,a1,-1140
  5c4398:	08171078 	j	0x5c41e0
  5c439c:	240601cb 	li	a2,459
  5c43a0:	3c020075 	lui	v0,0x75
  5c43a4:	8c42cf58 	lw	v0,-12456(v0)
  5c43a8:	1040ffc3 	beqz	v0,0x5c42b8
  5c43ac:	00000000 	nop
  5c43b0:	0c16276a 	jal	0x589da8
  5c43b4:	00000000 	nop
  5c43b8:	1040ffbf 	beqz	v0,0x5c42b8
  5c43bc:	3c04006e 	lui	a0,0x6e
  5c43c0:	3c05006f 	lui	a1,0x6f
  5c43c4:	24849cf4 	addiu	a0,a0,-25356
  5c43c8:	24a5fb8c 	addiu	a1,a1,-1140
  5c43cc:	08171078 	j	0x5c41e0
  5c43d0:	240601bc 	li	a2,444

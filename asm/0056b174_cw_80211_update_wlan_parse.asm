; func cw_80211_update_wlan_parse @ 0x0056b174 size=0x29c
  56b174:	27bdffd0 	addiu	sp,sp,-48
  56b178:	afb20024 	sw	s2,36(sp)
  56b17c:	00a09021 	move	s2,a1
  56b180:	afb10020 	sw	s1,32(sp)
  56b184:	2405006f 	li	a1,111
  56b188:	afb0001c 	sw	s0,28(sp)
  56b18c:	00808821 	move	s1,a0
  56b190:	afbf002c 	sw	ra,44(sp)
  56b194:	afb30028 	sw	s3,40(sp)
  56b198:	94930006 	lhu	s3,6(a0)
  56b19c:	0c102114 	jal	0x408450
  56b1a0:	2404000c 	li	a0,12
  56b1a4:	1040003c 	beqz	v0,0x56b298
  56b1a8:	00408021 	move	s0,v0
  56b1ac:	00002821 	move	a1,zero
  56b1b0:	2406000c 	li	a2,12
  56b1b4:	0c101cf0 	jal	0x4073c0
  56b1b8:	00402021 	move	a0,v0
  56b1bc:	0c15c5b0 	jal	0x5716c0
  56b1c0:	02202021 	move	a0,s1
  56b1c4:	a2020000 	sb	v0,0(s0)
  56b1c8:	2c420020 	sltiu	v0,v0,32
  56b1cc:	1040005c 	beqz	v0,0x56b340
  56b1d0:	3c020075 	lui	v0,0x75
  56b1d4:	0c15c5b0 	jal	0x5716c0
  56b1d8:	02202021 	move	a0,s1
  56b1dc:	a2020001 	sb	v0,1(s0)
  56b1e0:	2c420011 	sltiu	v0,v0,17
  56b1e4:	10400063 	beqz	v0,0x56b374
  56b1e8:	3c020075 	lui	v0,0x75
  56b1ec:	0c15c5d4 	jal	0x571750
  56b1f0:	02202021 	move	a0,s1
  56b1f4:	02202021 	move	a0,s1
  56b1f8:	0c15c5b0 	jal	0x5716c0
  56b1fc:	a6020002 	sh	v0,2(s0)
  56b200:	02202021 	move	a0,s1
  56b204:	0c15c5b0 	jal	0x5716c0
  56b208:	a2020004 	sb	v0,4(s0)
  56b20c:	a2020005 	sb	v0,5(s0)
  56b210:	2c420004 	sltiu	v0,v0,4
  56b214:	10400064 	beqz	v0,0x56b3a8
  56b218:	3c020075 	lui	v0,0x75
  56b21c:	0c15c5d4 	jal	0x571750
  56b220:	02202021 	move	a0,s1
  56b224:	a6020006 	sh	v0,6(s0)
  56b228:	96240004 	lhu	a0,4(s1)
  56b22c:	96230006 	lhu	v1,6(s1)
  56b230:	00831823 	subu	v1,a0,v1
  56b234:	0062182a 	slt	v1,v1,v0
  56b238:	54600027 	bnezl	v1,0x56b2d8
  56b23c:	3c020075 	lui	v0,0x75
  56b240:	9645000e 	lhu	a1,14(s2)
  56b244:	24a5fff8 	addiu	a1,a1,-8
  56b248:	14a20023 	bne	a1,v0,0x56b2d8
  56b24c:	3c020075 	lui	v0,0x75
  56b250:	14a00028 	bnez	a1,0x56b2f4
  56b254:	00000000 	nop
  56b258:	9642000e 	lhu	v0,14(s2)
  56b25c:	ae500010 	sw	s0,16(s2)
  56b260:	96300006 	lhu	s0,6(s1)
  56b264:	02138023 	subu	s0,s0,s3
  56b268:	02028026 	xor	s0,s0,v0
  56b26c:	2402ffff 	li	v0,-1
  56b270:	0010100a 	movz	v0,zero,s0
  56b274:	00408021 	move	s0,v0
  56b278:	8fbf002c 	lw	ra,44(sp)
  56b27c:	02001021 	move	v0,s0
  56b280:	8fb30028 	lw	s3,40(sp)
  56b284:	8fb20024 	lw	s2,36(sp)
  56b288:	8fb10020 	lw	s1,32(sp)
  56b28c:	8fb0001c 	lw	s0,28(sp)
  56b290:	03e00008 	jr	ra
  56b294:	27bd0030 	addiu	sp,sp,48
  56b298:	3c020075 	lui	v0,0x75
  56b29c:	8c42cf58 	lw	v0,-12456(v0)
  56b2a0:	1040fff5 	beqz	v0,0x56b278
  56b2a4:	2410ffff 	li	s0,-1
  56b2a8:	0c16276a 	jal	0x589da8
  56b2ac:	00000000 	nop
  56b2b0:	5040fff2 	beqzl	v0,0x56b27c
  56b2b4:	8fbf002c 	lw	ra,44(sp)
  56b2b8:	3c04006d 	lui	a0,0x6d
  56b2bc:	3c05006d 	lui	a1,0x6d
  56b2c0:	2484381c 	addiu	a0,a0,14364
  56b2c4:	24a55b84 	addiu	a1,a1,23428
  56b2c8:	0c101b74 	jal	0x406dd0
  56b2cc:	24060072 	li	a2,114
  56b2d0:	0815ac9f 	j	0x56b27c
  56b2d4:	8fbf002c 	lw	ra,44(sp)
  56b2d8:	8c42cf58 	lw	v0,-12456(v0)
  56b2dc:	1440003f 	bnez	v0,0x56b3dc
  56b2e0:	00000000 	nop
  56b2e4:	0c101f7c 	jal	0x407df0
  56b2e8:	02002021 	move	a0,s0
  56b2ec:	0815ac9e 	j	0x56b278
  56b2f0:	2410ffff 	li	s0,-1
  56b2f4:	0c15c6bc 	jal	0x571af0
  56b2f8:	02202021 	move	a0,s1
  56b2fc:	1440ffd6 	bnez	v0,0x56b258
  56b300:	ae020008 	sw	v0,8(s0)
  56b304:	3c020075 	lui	v0,0x75
  56b308:	8c42cf58 	lw	v0,-12456(v0)
  56b30c:	1040fff5 	beqz	v0,0x56b2e4
  56b310:	00000000 	nop
  56b314:	0c16276a 	jal	0x589da8
  56b318:	00000000 	nop
  56b31c:	1040fff1 	beqz	v0,0x56b2e4
  56b320:	3c04006d 	lui	a0,0x6d
  56b324:	3c05006d 	lui	a1,0x6d
  56b328:	24845454 	addiu	a0,a0,21588
  56b32c:	24a55b84 	addiu	a1,a1,23428
  56b330:	0c101b74 	jal	0x406dd0
  56b334:	240600a5 	li	a2,165
  56b338:	0815acb9 	j	0x56b2e4
  56b33c:	00000000 	nop
  56b340:	8c42cf58 	lw	v0,-12456(v0)
  56b344:	1040ffe7 	beqz	v0,0x56b2e4
  56b348:	00000000 	nop
  56b34c:	0c16276a 	jal	0x589da8
  56b350:	00000000 	nop
  56b354:	1040ffe3 	beqz	v0,0x56b2e4
  56b358:	3c04006d 	lui	a0,0x6d
  56b35c:	92070000 	lbu	a3,0(s0)
  56b360:	3c05006d 	lui	a1,0x6d
  56b364:	24843f08 	addiu	a0,a0,16136
  56b368:	24a55b84 	addiu	a1,a1,23428
  56b36c:	0815ad00 	j	0x56b400
  56b370:	2406007b 	li	a2,123
  56b374:	8c42cf58 	lw	v0,-12456(v0)
  56b378:	1040ffda 	beqz	v0,0x56b2e4
  56b37c:	00000000 	nop
  56b380:	0c16276a 	jal	0x589da8
  56b384:	00000000 	nop
  56b388:	1040ffd6 	beqz	v0,0x56b2e4
  56b38c:	3c04006d 	lui	a0,0x6d
  56b390:	92070001 	lbu	a3,1(s0)
  56b394:	3c05006d 	lui	a1,0x6d
  56b398:	24843f34 	addiu	a0,a0,16180
  56b39c:	24a55b84 	addiu	a1,a1,23428
  56b3a0:	0815ad00 	j	0x56b400
  56b3a4:	24060084 	li	a2,132
  56b3a8:	8c42cf58 	lw	v0,-12456(v0)
  56b3ac:	1040ffcd 	beqz	v0,0x56b2e4
  56b3b0:	00000000 	nop
  56b3b4:	0c16276a 	jal	0x589da8
  56b3b8:	00000000 	nop
  56b3bc:	1040ffc9 	beqz	v0,0x56b2e4
  56b3c0:	3c04006d 	lui	a0,0x6d
  56b3c4:	92070005 	lbu	a3,5(s0)
  56b3c8:	3c05006d 	lui	a1,0x6d
  56b3cc:	24845ac8 	addiu	a0,a0,23240
  56b3d0:	24a55b84 	addiu	a1,a1,23428
  56b3d4:	0815ad00 	j	0x56b400
  56b3d8:	24060092 	li	a2,146
  56b3dc:	0c16276a 	jal	0x589da8
  56b3e0:	00000000 	nop
  56b3e4:	1040ffbf 	beqz	v0,0x56b2e4
  56b3e8:	3c04006d 	lui	a0,0x6d
  56b3ec:	96070006 	lhu	a3,6(s0)
  56b3f0:	3c05006d 	lui	a1,0x6d
  56b3f4:	24845af8 	addiu	a0,a0,23288
  56b3f8:	24a55b84 	addiu	a1,a1,23428
  56b3fc:	2406009a 	li	a2,154
  56b400:	0c101b74 	jal	0x406dd0
  56b404:	00000000 	nop
  56b408:	0815acb9 	j	0x56b2e4
  56b40c:	00000000 	nop

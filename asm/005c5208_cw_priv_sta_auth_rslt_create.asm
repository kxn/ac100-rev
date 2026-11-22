; func cw_priv_sta_auth_rslt_create @ 0x005c5208 size=0x184
  5c5208:	27bdffd8 	addiu	sp,sp,-40
  5c520c:	24050014 	li	a1,20
  5c5210:	afb10020 	sw	s1,32(sp)
  5c5214:	afb0001c 	sw	s0,28(sp)
  5c5218:	afbf0024 	sw	ra,36(sp)
  5c521c:	0c15c8cc 	jal	0x572330
  5c5220:	00808021 	move	s0,a0
  5c5224:	1040002a 	beqz	v0,0x5c52d0
  5c5228:	00408821 	move	s1,v0
  5c522c:	ac40000c 	sw	zero,12(v0)
  5c5230:	ac400010 	sw	zero,16(v0)
  5c5234:	8e02000c 	lw	v0,12(s0)
  5c5238:	5040000b 	beqzl	v0,0x5c5268
  5c523c:	8e25000c 	lw	a1,12(s1)
  5c5240:	8e030010 	lw	v1,16(s0)
  5c5244:	50600008 	beqzl	v1,0x5c5268
  5c5248:	8e25000c 	lw	a1,12(s1)
  5c524c:	ae22000c 	sw	v0,12(s1)
  5c5250:	8e040010 	lw	a0,16(s0)
  5c5254:	0c15c8cc 	jal	0x572330
  5c5258:	9605000e 	lhu	a1,14(s0)
  5c525c:	10400038 	beqz	v0,0x5c5340
  5c5260:	ae220010 	sw	v0,16(s1)
  5c5264:	8e25000c 	lw	a1,12(s1)
  5c5268:	24040013 	li	a0,19
  5c526c:	02203021 	move	a2,s1
  5c5270:	24a50010 	addiu	a1,a1,16
  5c5274:	0c15c943 	jal	0x57250c
  5c5278:	30a5ffff 	andi	a1,a1,0xffff
  5c527c:	10400007 	beqz	v0,0x5c529c
  5c5280:	00408021 	move	s0,v0
  5c5284:	8fbf0024 	lw	ra,36(sp)
  5c5288:	02001021 	move	v0,s0
  5c528c:	8fb10020 	lw	s1,32(sp)
  5c5290:	8fb0001c 	lw	s0,28(sp)
  5c5294:	03e00008 	jr	ra
  5c5298:	27bd0028 	addiu	sp,sp,40
  5c529c:	3c020075 	lui	v0,0x75
  5c52a0:	8c42cf58 	lw	v0,-12456(v0)
  5c52a4:	1440001a 	bnez	v0,0x5c5310
  5c52a8:	00000000 	nop
  5c52ac:	8e240010 	lw	a0,16(s1)
  5c52b0:	10800003 	beqz	a0,0x5c52c0
  5c52b4:	00000000 	nop
  5c52b8:	0c101f7c 	jal	0x407df0
  5c52bc:	00000000 	nop
  5c52c0:	0c101f7c 	jal	0x407df0
  5c52c4:	02202021 	move	a0,s1
  5c52c8:	081714a2 	j	0x5c5288
  5c52cc:	8fbf0024 	lw	ra,36(sp)
  5c52d0:	3c020075 	lui	v0,0x75
  5c52d4:	8c42cf58 	lw	v0,-12456(v0)
  5c52d8:	1040ffea 	beqz	v0,0x5c5284
  5c52dc:	00008021 	move	s0,zero
  5c52e0:	0c16276a 	jal	0x589da8
  5c52e4:	00000000 	nop
  5c52e8:	5040ffe7 	beqzl	v0,0x5c5288
  5c52ec:	8fbf0024 	lw	ra,36(sp)
  5c52f0:	3c04006d 	lui	a0,0x6d
  5c52f4:	3c05006f 	lui	a1,0x6f
  5c52f8:	248434fc 	addiu	a0,a0,13564
  5c52fc:	24a5fdb0 	addiu	a1,a1,-592
  5c5300:	0c101b74 	jal	0x406dd0
  5c5304:	240600f7 	li	a2,247
  5c5308:	081714a2 	j	0x5c5288
  5c530c:	8fbf0024 	lw	ra,36(sp)
  5c5310:	0c16276a 	jal	0x589da8
  5c5314:	00000000 	nop
  5c5318:	5040ffe5 	beqzl	v0,0x5c52b0
  5c531c:	8e240010 	lw	a0,16(s1)
  5c5320:	3c04006d 	lui	a0,0x6d
  5c5324:	3c05006f 	lui	a1,0x6f
  5c5328:	248447f0 	addiu	a0,a0,18416
  5c532c:	24a5fdb0 	addiu	a1,a1,-592
  5c5330:	0c101b74 	jal	0x406dd0
  5c5334:	2406010e 	li	a2,270
  5c5338:	081714ac 	j	0x5c52b0
  5c533c:	8e240010 	lw	a0,16(s1)
  5c5340:	3c020075 	lui	v0,0x75
  5c5344:	8c42cf58 	lw	v0,-12456(v0)
  5c5348:	14400005 	bnez	v0,0x5c5360
  5c534c:	00000000 	nop
  5c5350:	0c101f7c 	jal	0x407df0
  5c5354:	02202021 	move	a0,s1
  5c5358:	081714a1 	j	0x5c5284
  5c535c:	00008021 	move	s0,zero
  5c5360:	0c16276a 	jal	0x589da8
  5c5364:	00000000 	nop
  5c5368:	1040fff9 	beqz	v0,0x5c5350
  5c536c:	3c04006f 	lui	a0,0x6f
  5c5370:	3c05006f 	lui	a1,0x6f
  5c5374:	2484f510 	addiu	a0,a0,-2800
  5c5378:	24a5fdb0 	addiu	a1,a1,-592
  5c537c:	0c101b74 	jal	0x406dd0
  5c5380:	24060104 	li	a2,260
  5c5384:	081714d4 	j	0x5c5350
  5c5388:	00000000 	nop

; func cw_priv_fail_station_create @ 0x005b127c size=0x20c
  5b127c:	27bdffd8 	addiu	sp,sp,-40
  5b1280:	afb00018 	sw	s0,24(sp)
  5b1284:	afbf0024 	sw	ra,36(sp)
  5b1288:	afb20020 	sw	s2,32(sp)
  5b128c:	afb1001c 	sw	s1,28(sp)
  5b1290:	8c820000 	lw	v0,0(a0)
  5b1294:	2c4300c9 	sltiu	v1,v0,201
  5b1298:	14600010 	bnez	v1,0x5b12dc
  5b129c:	00808021 	move	s0,a0
  5b12a0:	3c020075 	lui	v0,0x75
  5b12a4:	8c42cf58 	lw	v0,-12456(v0)
  5b12a8:	10400005 	beqz	v0,0x5b12c0
  5b12ac:	00009021 	move	s2,zero
  5b12b0:	0c16276a 	jal	0x589da8
  5b12b4:	00000000 	nop
  5b12b8:	14400032 	bnez	v0,0x5b1384
  5b12bc:	3c04006f 	lui	a0,0x6f
  5b12c0:	8fbf0024 	lw	ra,36(sp)
  5b12c4:	02401021 	move	v0,s2
  5b12c8:	8fb20020 	lw	s2,32(sp)
  5b12cc:	8fb1001c 	lw	s1,28(sp)
  5b12d0:	8fb00018 	lw	s0,24(sp)
  5b12d4:	03e00008 	jr	ra
  5b12d8:	27bd0028 	addiu	sp,sp,40
  5b12dc:	10400004 	beqz	v0,0x5b12f0
  5b12e0:	24050008 	li	a1,8
  5b12e4:	8c820004 	lw	v0,4(a0)
  5b12e8:	1040003c 	beqz	v0,0x5b13dc
  5b12ec:	3c020075 	lui	v0,0x75
  5b12f0:	0c15c8cc 	jal	0x572330
  5b12f4:	02002021 	move	a0,s0
  5b12f8:	1040002a 	beqz	v0,0x5b13a4
  5b12fc:	00408821 	move	s1,v0
  5b1300:	ac400004 	sw	zero,4(v0)
  5b1304:	8e020000 	lw	v0,0(s0)
  5b1308:	10400009 	beqz	v0,0x5b1330
  5b130c:	00000000 	nop
  5b1310:	8e040004 	lw	a0,4(s0)
  5b1314:	10800006 	beqz	a0,0x5b1330
  5b1318:	24050014 	li	a1,20
  5b131c:	70452802 	mul	a1,v0,a1
  5b1320:	0c15c8cc 	jal	0x572330
  5b1324:	30a5fffc 	andi	a1,a1,0xfffc
  5b1328:	1040003c 	beqz	v0,0x5b141c
  5b132c:	ae220004 	sw	v0,4(s1)
  5b1330:	0c16c30c 	jal	0x5b0c30
  5b1334:	02202021 	move	a0,s1
  5b1338:	24040056 	li	a0,86
  5b133c:	00402821 	move	a1,v0
  5b1340:	0c15c943 	jal	0x57250c
  5b1344:	02203021 	move	a2,s1
  5b1348:	1440ffdd 	bnez	v0,0x5b12c0
  5b134c:	00409021 	move	s2,v0
  5b1350:	3c020075 	lui	v0,0x75
  5b1354:	8c42cf58 	lw	v0,-12456(v0)
  5b1358:	14400041 	bnez	v0,0x5b1460
  5b135c:	00000000 	nop
  5b1360:	8e240004 	lw	a0,4(s1)
  5b1364:	10800003 	beqz	a0,0x5b1374
  5b1368:	00000000 	nop
  5b136c:	0c101f7c 	jal	0x407df0
  5b1370:	00000000 	nop
  5b1374:	0c101f7c 	jal	0x407df0
  5b1378:	02202021 	move	a0,s1
  5b137c:	0816c4b0 	j	0x5b12c0
  5b1380:	00009021 	move	s2,zero
  5b1384:	8e070000 	lw	a3,0(s0)
  5b1388:	3c05006f 	lui	a1,0x6f
  5b138c:	24848880 	addiu	a0,a0,-30592
  5b1390:	24a5ae20 	addiu	a1,a1,-20960
  5b1394:	0c101b74 	jal	0x406dd0
  5b1398:	240600f9 	li	a2,249
  5b139c:	0816c4b1 	j	0x5b12c4
  5b13a0:	8fbf0024 	lw	ra,36(sp)
  5b13a4:	3c020075 	lui	v0,0x75
  5b13a8:	8c42cf58 	lw	v0,-12456(v0)
  5b13ac:	1040ffc4 	beqz	v0,0x5b12c0
  5b13b0:	00009021 	move	s2,zero
  5b13b4:	0c16276a 	jal	0x589da8
  5b13b8:	00000000 	nop
  5b13bc:	5040ffc1 	beqzl	v0,0x5b12c4
  5b13c0:	8fbf0024 	lw	ra,36(sp)
  5b13c4:	3c04006d 	lui	a0,0x6d
  5b13c8:	3c05006f 	lui	a1,0x6f
  5b13cc:	248434fc 	addiu	a0,a0,13564
  5b13d0:	24a5ae20 	addiu	a1,a1,-20960
  5b13d4:	0816c503 	j	0x5b140c
  5b13d8:	24060107 	li	a2,263
  5b13dc:	8c42cf58 	lw	v0,-12456(v0)
  5b13e0:	1040ffb7 	beqz	v0,0x5b12c0
  5b13e4:	00009021 	move	s2,zero
  5b13e8:	0c16276a 	jal	0x589da8
  5b13ec:	00000000 	nop
  5b13f0:	5040ffb4 	beqzl	v0,0x5b12c4
  5b13f4:	8fbf0024 	lw	ra,36(sp)
  5b13f8:	3c04006f 	lui	a0,0x6f
  5b13fc:	3c05006f 	lui	a1,0x6f
  5b1400:	2484ad9c 	addiu	a0,a0,-21092
  5b1404:	24a5ae20 	addiu	a1,a1,-20960
  5b1408:	240600ff 	li	a2,255
  5b140c:	0c101b74 	jal	0x406dd0
  5b1410:	00000000 	nop
  5b1414:	0816c4b1 	j	0x5b12c4
  5b1418:	8fbf0024 	lw	ra,36(sp)
  5b141c:	3c020075 	lui	v0,0x75
  5b1420:	8c42cf58 	lw	v0,-12456(v0)
  5b1424:	5040ffcf 	beqzl	v0,0x5b1364
  5b1428:	8e240004 	lw	a0,4(s1)
  5b142c:	0c16276a 	jal	0x589da8
  5b1430:	00000000 	nop
  5b1434:	5040ffcb 	beqzl	v0,0x5b1364
  5b1438:	8e240004 	lw	a0,4(s1)
  5b143c:	3c04006f 	lui	a0,0x6f
  5b1440:	3c05006f 	lui	a1,0x6f
  5b1444:	2484adc8 	addiu	a0,a0,-21048
  5b1448:	24a5ae20 	addiu	a1,a1,-20960
  5b144c:	24060112 	li	a2,274
  5b1450:	0c101b74 	jal	0x406dd0
  5b1454:	00000000 	nop
  5b1458:	0816c4d9 	j	0x5b1364
  5b145c:	8e240004 	lw	a0,4(s1)
  5b1460:	0c16276a 	jal	0x589da8
  5b1464:	00000000 	nop
  5b1468:	5040ffbe 	beqzl	v0,0x5b1364
  5b146c:	8e240004 	lw	a0,4(s1)
  5b1470:	3c04006d 	lui	a0,0x6d
  5b1474:	3c05006f 	lui	a1,0x6f
  5b1478:	248447f0 	addiu	a0,a0,18416
  5b147c:	24a5ae20 	addiu	a1,a1,-20960
  5b1480:	0816c514 	j	0x5b1450
  5b1484:	2406011b 	li	a2,283
	...

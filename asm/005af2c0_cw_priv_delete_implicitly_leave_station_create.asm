; func cw_priv_delete_implicitly_leave_station_create @ 0x005af2c0 size=0x180
  5af2c0:	27bdffd8 	addiu	sp,sp,-40
  5af2c4:	24050008 	li	a1,8
  5af2c8:	afb10020 	sw	s1,32(sp)
  5af2cc:	afb0001c 	sw	s0,28(sp)
  5af2d0:	afbf0024 	sw	ra,36(sp)
  5af2d4:	0c15c8cc 	jal	0x572330
  5af2d8:	00808821 	move	s1,a0
  5af2dc:	10400031 	beqz	v0,0x5af3a4
  5af2e0:	00408021 	move	s0,v0
  5af2e4:	ac400004 	sw	zero,4(v0)
  5af2e8:	24020006 	li	v0,6
  5af2ec:	92250001 	lbu	a1,1(s1)
  5af2f0:	10a20010 	beq	a1,v0,0x5af334
  5af2f4:	24020008 	li	v0,8
  5af2f8:	50a2000f 	beql	a1,v0,0x5af338
  5af2fc:	8e240004 	lw	a0,4(s1)
  5af300:	92050001 	lbu	a1,1(s0)
  5af304:	2404005a 	li	a0,90
  5af308:	02003021 	move	a2,s0
  5af30c:	0c15c943 	jal	0x57250c
  5af310:	24a50002 	addiu	a1,a1,2
  5af314:	10400016 	beqz	v0,0x5af370
  5af318:	00408821 	move	s1,v0
  5af31c:	8fbf0024 	lw	ra,36(sp)
  5af320:	02201021 	move	v0,s1
  5af324:	8fb10020 	lw	s1,32(sp)
  5af328:	8fb0001c 	lw	s0,28(sp)
  5af32c:	03e00008 	jr	ra
  5af330:	27bd0028 	addiu	sp,sp,40
  5af334:	8e240004 	lw	a0,4(s1)
  5af338:	5080fff2 	beqzl	a0,0x5af304
  5af33c:	92050001 	lbu	a1,1(s0)
  5af340:	0c15c8cc 	jal	0x572330
  5af344:	00000000 	nop
  5af348:	1440ffed 	bnez	v0,0x5af300
  5af34c:	ae020004 	sw	v0,4(s0)
  5af350:	3c020075 	lui	v0,0x75
  5af354:	8c42cf58 	lw	v0,-12456(v0)
  5af358:	1440002e 	bnez	v0,0x5af414
  5af35c:	00000000 	nop
  5af360:	0c101f7c 	jal	0x407df0
  5af364:	02002021 	move	a0,s0
  5af368:	0816bcc1 	j	0x5af304
  5af36c:	92050001 	lbu	a1,1(s0)
  5af370:	3c020075 	lui	v0,0x75
  5af374:	8c42cf58 	lw	v0,-12456(v0)
  5af378:	1440001a 	bnez	v0,0x5af3e4
  5af37c:	00000000 	nop
  5af380:	8e040004 	lw	a0,4(s0)
  5af384:	10800003 	beqz	a0,0x5af394
  5af388:	00000000 	nop
  5af38c:	0c101f7c 	jal	0x407df0
  5af390:	00000000 	nop
  5af394:	0c101f7c 	jal	0x407df0
  5af398:	02002021 	move	a0,s0
  5af39c:	0816bcc8 	j	0x5af320
  5af3a0:	8fbf0024 	lw	ra,36(sp)
  5af3a4:	3c020075 	lui	v0,0x75
  5af3a8:	8c42cf58 	lw	v0,-12456(v0)
  5af3ac:	1040ffdb 	beqz	v0,0x5af31c
  5af3b0:	00008821 	move	s1,zero
  5af3b4:	0c16276a 	jal	0x589da8
  5af3b8:	00000000 	nop
  5af3bc:	5040ffd8 	beqzl	v0,0x5af320
  5af3c0:	8fbf0024 	lw	ra,36(sp)
  5af3c4:	3c04006d 	lui	a0,0x6d
  5af3c8:	3c05006f 	lui	a1,0x6f
  5af3cc:	248434fc 	addiu	a0,a0,13564
  5af3d0:	24a5a760 	addiu	a1,a1,-22688
  5af3d4:	0c101b74 	jal	0x406dd0
  5af3d8:	240600ce 	li	a2,206
  5af3dc:	0816bcc8 	j	0x5af320
  5af3e0:	8fbf0024 	lw	ra,36(sp)
  5af3e4:	0c16276a 	jal	0x589da8
  5af3e8:	00000000 	nop
  5af3ec:	5040ffe5 	beqzl	v0,0x5af384
  5af3f0:	8e040004 	lw	a0,4(s0)
  5af3f4:	3c04006d 	lui	a0,0x6d
  5af3f8:	3c05006f 	lui	a1,0x6f
  5af3fc:	24843580 	addiu	a0,a0,13696
  5af400:	24a5a760 	addiu	a1,a1,-22688
  5af404:	0c101b74 	jal	0x406dd0
  5af408:	240600e2 	li	a2,226
  5af40c:	0816bce1 	j	0x5af384
  5af410:	8e040004 	lw	a0,4(s0)
  5af414:	0c16276a 	jal	0x589da8
  5af418:	00000000 	nop
  5af41c:	1040ffd0 	beqz	v0,0x5af360
  5af420:	3c04006d 	lui	a0,0x6d
  5af424:	3c05006f 	lui	a1,0x6f
  5af428:	248473e8 	addiu	a0,a0,29672
  5af42c:	24a5a760 	addiu	a1,a1,-22688
  5af430:	0c101b74 	jal	0x406dd0
  5af434:	240600d9 	li	a2,217
  5af438:	0816bcd8 	j	0x5af360
  5af43c:	00000000 	nop

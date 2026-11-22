; func cw_sta_assoc_req_sub_ele_free @ 0x005c23f8 size=0xbc
  5c23f8:	27bdffd0 	addiu	sp,sp,-48
  5c23fc:	afbf002c 	sw	ra,44(sp)
  5c2400:	afb30028 	sw	s3,40(sp)
  5c2404:	afb20024 	sw	s2,36(sp)
  5c2408:	afb10020 	sw	s1,32(sp)
  5c240c:	10800022 	beqz	a0,0x5c2498
  5c2410:	afb0001c 	sw	s0,28(sp)
  5c2414:	24920014 	addiu	s2,a0,20
  5c2418:	08170911 	j	0x5c2444
  5c241c:	24130001 	li	s3,1
  5c2420:	10800004 	beqz	a0,0x5c2434
  5c2424:	00000000 	nop
  5c2428:	0c101f7c 	jal	0x407df0
  5c242c:	00000000 	nop
  5c2430:	ae200004 	sw	zero,4(s1)
  5c2434:	0c101f7c 	jal	0x407df0
  5c2438:	8e040010 	lw	a0,16(s0)
  5c243c:	0c101f7c 	jal	0x407df0
  5c2440:	02002021 	move	a0,s0
  5c2444:	0c10206c 	jal	0x4081b0
  5c2448:	02402021 	move	a0,s2
  5c244c:	10400012 	beqz	v0,0x5c2498
  5c2450:	00408021 	move	s0,v0
  5c2454:	0c102140 	jal	0x408500
  5c2458:	02002021 	move	a0,s0
  5c245c:	8e110010 	lw	s1,16(s0)
  5c2460:	1220fff6 	beqz	s1,0x5c243c
  5c2464:	00000000 	nop
  5c2468:	9602000c 	lhu	v0,12(s0)
  5c246c:	5040ffec 	beqzl	v0,0x5c2420
  5c2470:	8e240004 	lw	a0,4(s1)
  5c2474:	1453ffef 	bne	v0,s3,0x5c2434
  5c2478:	00000000 	nop
  5c247c:	8e24000c 	lw	a0,12(s1)
  5c2480:	1080ffec 	beqz	a0,0x5c2434
  5c2484:	00000000 	nop
  5c2488:	0c101f7c 	jal	0x407df0
  5c248c:	00000000 	nop
  5c2490:	0817090d 	j	0x5c2434
  5c2494:	ae20000c 	sw	zero,12(s1)
  5c2498:	8fbf002c 	lw	ra,44(sp)
  5c249c:	8fb30028 	lw	s3,40(sp)
  5c24a0:	8fb20024 	lw	s2,36(sp)
  5c24a4:	8fb10020 	lw	s1,32(sp)
  5c24a8:	8fb0001c 	lw	s0,28(sp)
  5c24ac:	03e00008 	jr	ra
  5c24b0:	27bd0030 	addiu	sp,sp,48

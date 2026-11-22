; func ucl_auth_report_thread @ 0x004a72f8 size=0x1f4
  4a72f8:	3c1c002c 	lui	gp,0x2c
  4a72fc:	279c9e08 	addiu	gp,gp,-25080
  4a7300:	0399e021 	addu	gp,gp,t9
  4a7304:	27bdffd0 	addiu	sp,sp,-48
  4a7308:	afbc0010 	sw	gp,16(sp)
  4a730c:	afb30028 	sw	s3,40(sp)
  4a7310:	24130002 	li	s3,2
  4a7314:	afb10020 	sw	s1,32(sp)
  4a7318:	00008821 	move	s1,zero
  4a731c:	afb0001c 	sw	s0,28(sp)
  4a7320:	00008021 	move	s0,zero
  4a7324:	afbf002c 	sw	ra,44(sp)
  4a7328:	1000001f 	b	0x4a73a8
  4a732c:	afb20024 	sw	s2,36(sp)
  4a7330:	8f9981c8 	lw	t9,-32312(gp)
  4a7334:	041101aa 	bal	0x4a79e0
  4a7338:	00000000 	nop
  4a733c:	24030003 	li	v1,3
  4a7340:	10430044 	beq	v0,v1,0x4a7454
  4a7344:	8fbc0010 	lw	gp,16(sp)
  4a7348:	8f998220 	lw	t9,-32224(gp)
  4a734c:	04110171 	bal	0x4a7914
  4a7350:	00000000 	nop
  4a7354:	14400004 	bnez	v0,0x4a7368
  4a7358:	8fbc0010 	lw	gp,16(sp)
  4a735c:	12200047 	beqz	s1,0x4a747c
  4a7360:	8f99823c 	lw	t9,-32196(gp)
  4a7364:	2631ffff 	addiu	s1,s1,-1
  4a7368:	8f9981e8 	lw	t9,-32280(gp)
  4a736c:	0411015c 	bal	0x4a78e0
  4a7370:	00000000 	nop
  4a7374:	00409021 	move	s2,v0
  4a7378:	24020001 	li	v0,1
  4a737c:	1242001d 	beq	s2,v0,0x4a73f4
  4a7380:	8fbc0010 	lw	gp,16(sp)
  4a7384:	8f9981e8 	lw	t9,-32280(gp)
  4a7388:	04110155 	bal	0x4a78e0
  4a738c:	00000000 	nop
  4a7390:	10400021 	beqz	v0,0x4a7418
  4a7394:	8fbc0010 	lw	gp,16(sp)
  4a7398:	8f99852c 	lw	t9,-31444(gp)
  4a739c:	0320f809 	jalr	t9
  4a73a0:	24040001 	li	a0,1
  4a73a4:	8fbc0010 	lw	gp,16(sp)
  4a73a8:	8f998240 	lw	t9,-32192(gp)
  4a73ac:	04110166 	bal	0x4a7948
  4a73b0:	00000000 	nop
  4a73b4:	1053001d 	beq	v0,s3,0x4a742c
  4a73b8:	8fbc0010 	lw	gp,16(sp)
  4a73bc:	8f9981c8 	lw	t9,-32312(gp)
  4a73c0:	04110187 	bal	0x4a79e0
  4a73c4:	00000000 	nop
  4a73c8:	1453ffd9 	bne	v0,s3,0x4a7330
  4a73cc:	8fbc0010 	lw	gp,16(sp)
  4a73d0:	8f998244 	lw	t9,-32188(gp)
  4a73d4:	0411faca 	bal	0x4a5f00
  4a73d8:	00000000 	nop
  4a73dc:	8fbc0010 	lw	gp,16(sp)
  4a73e0:	8f998248 	lw	t9,-32184(gp)
  4a73e4:	04110151 	bal	0x4a792c
  4a73e8:	00002021 	move	a0,zero
  4a73ec:	1000ffd6 	b	0x4a7348
  4a73f0:	8fbc0010 	lw	gp,16(sp)
  4a73f4:	8f998220 	lw	t9,-32224(gp)
  4a73f8:	04110146 	bal	0x4a7914
  4a73fc:	00000000 	nop
  4a7400:	1452ffe0 	bne	v0,s2,0x4a7384
  4a7404:	8fbc0010 	lw	gp,16(sp)
  4a7408:	12000032 	beqz	s0,0x4a74d4
  4a740c:	8f99824c 	lw	t9,-32180(gp)
  4a7410:	1000ffe1 	b	0x4a7398
  4a7414:	2610ffff 	addiu	s0,s0,-1
  4a7418:	8f998250 	lw	t9,-32176(gp)
  4a741c:	041103e2 	bal	0x4a83a8
  4a7420:	00008021 	move	s0,zero
  4a7424:	1000ffdc 	b	0x4a7398
  4a7428:	8fbc0010 	lw	gp,16(sp)
  4a742c:	8f998254 	lw	t9,-32172(gp)
  4a7430:	0411fa0a 	bal	0x4a5c5c
  4a7434:	00000000 	nop
  4a7438:	1440ffe0 	bnez	v0,0x4a73bc
  4a743c:	8fbc0010 	lw	gp,16(sp)
  4a7440:	8f9981c4 	lw	t9,-32316(gp)
  4a7444:	04110146 	bal	0x4a7960
  4a7448:	24040003 	li	a0,3
  4a744c:	1000ffdb 	b	0x4a73bc
  4a7450:	8fbc0010 	lw	gp,16(sp)
  4a7454:	8f998248 	lw	t9,-32184(gp)
  4a7458:	24040001 	li	a0,1
  4a745c:	04110133 	bal	0x4a792c
  4a7460:	00008821 	move	s1,zero
  4a7464:	8fbc0010 	lw	gp,16(sp)
  4a7468:	8f998258 	lw	t9,-32168(gp)
  4a746c:	04110269 	bal	0x4a7e14
  4a7470:	00000000 	nop
  4a7474:	1000ffb4 	b	0x4a7348
  4a7478:	8fbc0010 	lw	gp,16(sp)
  4a747c:	0411fbd2 	bal	0x4a63c8
  4a7480:	00000000 	nop
  4a7484:	1440000b 	bnez	v0,0x4a74b4
  4a7488:	8fbc0010 	lw	gp,16(sp)
  4a748c:	8f9981cc 	lw	t9,-32308(gp)
  4a7490:	04110159 	bal	0x4a79f8
  4a7494:	24040003 	li	a0,3
  4a7498:	24040001 	li	a0,1
  4a749c:	8fbc0010 	lw	gp,16(sp)
  4a74a0:	8f998248 	lw	t9,-32184(gp)
  4a74a4:	0320f809 	jalr	t9
  4a74a8:	00000000 	nop
  4a74ac:	1000ffae 	b	0x4a7368
  4a74b0:	8fbc0010 	lw	gp,16(sp)
  4a74b4:	8f9981c8 	lw	t9,-32312(gp)
  4a74b8:	04110149 	bal	0x4a79e0
  4a74bc:	24110003 	li	s1,3
  4a74c0:	1453ffa9 	bne	v0,s3,0x4a7368
  4a74c4:	8fbc0010 	lw	gp,16(sp)
  4a74c8:	24040004 	li	a0,4
  4a74cc:	1000fff5 	b	0x4a74a4
  4a74d0:	8f9981cc 	lw	t9,-32308(gp)
  4a74d4:	0411ff3d 	bal	0x4a71cc
  4a74d8:	24100003 	li	s0,3
  4a74dc:	00021027 	nor	v0,zero,v0
  4a74e0:	8fbc0010 	lw	gp,16(sp)
  4a74e4:	1000ffac 	b	0x4a7398
  4a74e8:	0002800b 	movn	s0,zero,v0

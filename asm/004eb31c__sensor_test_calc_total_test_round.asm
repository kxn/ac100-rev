; func _sensor_test_calc_total_test_round @ 0x004eb31c size=0x4c
  4eb31c:	00c4182b 	sltu	v1,a2,a0
  4eb320:	1460000f 	bnez	v1,0x4eb360
  4eb324:	00001021 	move	v0,zero
  4eb328:	18a0000d 	blez	a1,0x4eb360
  4eb32c:	24020001 	li	v0,1
  4eb330:	2402003c 	li	v0,60
  4eb334:	00c42023 	subu	a0,a2,a0
  4eb338:	70a22802 	mul	a1,a1,v0
  4eb33c:	00a001f4 	teq	a1,zero,0x7
  4eb340:	0085001b 	divu	zero,a0,a1
  4eb344:	00001010 	mfhi	v0
  4eb348:	00002012 	mflo	a0
  4eb34c:	0002102b 	sltu	v0,zero,v0
  4eb350:	00822021 	addu	a0,a0,v0
  4eb354:	2402000a 	li	v0,10
  4eb358:	2883000b 	slti	v1,a0,11
  4eb35c:	0083100b 	movn	v0,a0,v1
  4eb360:	03e00008 	jr	ra
  4eb364:	00000000 	nop

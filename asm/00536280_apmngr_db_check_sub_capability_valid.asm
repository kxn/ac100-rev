; func apmngr_db_check_sub_capability_valid @ 0x00536280 size=0x38
  536280:	2403002c 	li	v1,44
  536284:	10830007 	beq	a0,v1,0x5362a4
  536288:	2ca20006 	sltiu	v0,a1,6
  53628c:	2402005f 	li	v0,95
  536290:	10820006 	beq	a0,v0,0x5362ac
  536294:	38840002 	xori	a0,a0,0x2
  536298:	00001021 	move	v0,zero
  53629c:	2ca50002 	sltiu	a1,a1,2
  5362a0:	00a4100a 	movz	v0,a1,a0
  5362a4:	03e00008 	jr	ra
  5362a8:	00000000 	nop
  5362ac:	38a20001 	xori	v0,a1,0x1
  5362b0:	03e00008 	jr	ra
  5362b4:	2c420001 	sltiu	v0,v0,1

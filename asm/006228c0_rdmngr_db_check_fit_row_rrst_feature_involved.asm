; func rdmngr_db_check_fit_row_rrst_feature_involved @ 0x006228c0 size=0x30
  6228c0:	30a20001 	andi	v0,a1,0x1
  6228c4:	10400003 	beqz	v0,0x6228d4
  6228c8:	308400ff 	andi	a0,a0,0xff
  6228cc:	10800006 	beqz	a0,0x6228e8
  6228d0:	24020001 	li	v0,1
  6228d4:	30a50002 	andi	a1,a1,0x2
  6228d8:	10a00003 	beqz	a1,0x6228e8
  6228dc:	00001021 	move	v0,zero
  6228e0:	38820001 	xori	v0,a0,0x1
  6228e4:	2c420001 	sltiu	v0,v0,1
  6228e8:	03e00008 	jr	ra
  6228ec:	00000000 	nop

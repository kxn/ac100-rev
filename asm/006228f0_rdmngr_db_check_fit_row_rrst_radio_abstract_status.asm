; func rdmngr_db_check_fit_row_rrst_radio_abstract_status @ 0x006228f0 size=0x30
  6228f0:	30a20001 	andi	v0,a1,0x1
  6228f4:	10400003 	beqz	v0,0x622904
  6228f8:	308400ff 	andi	a0,a0,0xff
  6228fc:	10800006 	beqz	a0,0x622918
  622900:	24020001 	li	v0,1
  622904:	30a50002 	andi	a1,a1,0x2
  622908:	10a00003 	beqz	a1,0x622918
  62290c:	00001021 	move	v0,zero
  622910:	38820001 	xori	v0,a0,0x1
  622914:	2c420001 	sltiu	v0,v0,1
  622918:	03e00008 	jr	ra
  62291c:	00000000 	nop

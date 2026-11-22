; func _wserv_sqlite_db_str_tran @ 0x005f65c0 size=0x5c
  5f65c0:	00a01021 	move	v0,a1
  5f65c4:	00a01821 	move	v1,a1
  5f65c8:	24c6ffff 	addiu	a2,a2,-1
  5f65cc:	0817d979 	j	0x5f65e4
  5f65d0:	24050027 	li	a1,39
  5f65d4:	80870000 	lb	a3,0(a0)
  5f65d8:	24840001 	addiu	a0,a0,1
  5f65dc:	a0670000 	sb	a3,0(v1)
  5f65e0:	24630001 	addiu	v1,v1,1
  5f65e4:	80870000 	lb	a3,0(a0)
  5f65e8:	10e0000a 	beqz	a3,0x5f6614
  5f65ec:	00000000 	nop
  5f65f0:	00624023 	subu	t0,v1,v0
  5f65f4:	0106402a 	slt	t0,t0,a2
  5f65f8:	11000006 	beqz	t0,0x5f6614
  5f65fc:	00000000 	nop
  5f6600:	54e5fff5 	bnel	a3,a1,0x5f65d8
  5f6604:	80870000 	lb	a3,0(a0)
  5f6608:	a0650000 	sb	a1,0(v1)
  5f660c:	0817d975 	j	0x5f65d4
  5f6610:	24630001 	addiu	v1,v1,1
  5f6614:	03e00008 	jr	ra
  5f6618:	a0600000 	sb	zero,0(v1)

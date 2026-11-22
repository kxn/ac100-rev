; func apmngr_db_is_cfg_changed @ 0x00541500 size=0x34
  541500:	27bdffe0 	addiu	sp,sp,-32
  541504:	00001021 	move	v0,zero
  541508:	10800007 	beqz	a0,0x541528
  54150c:	afbf001c 	sw	ra,28(sp)
  541510:	10a00005 	beqz	a1,0x541528
  541514:	248400a8 	addiu	a0,a0,168
  541518:	24a500a8 	addiu	a1,a1,168
  54151c:	0c101e4c 	jal	0x407930
  541520:	24060120 	li	a2,288
  541524:	0002102b 	sltu	v0,zero,v0
  541528:	8fbf001c 	lw	ra,28(sp)
  54152c:	03e00008 	jr	ra
  541530:	27bd0020 	addiu	sp,sp,32

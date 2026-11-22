; func apmngr_db_is_led_timer_cfg_changed @ 0x00541534 size=0x34
  541534:	27bdffe0 	addiu	sp,sp,-32
  541538:	00001021 	move	v0,zero
  54153c:	10800007 	beqz	a0,0x54155c
  541540:	afbf001c 	sw	ra,28(sp)
  541544:	10a00005 	beqz	a1,0x54155c
  541548:	2484017c 	addiu	a0,a0,380
  54154c:	24a5017c 	addiu	a1,a1,380
  541550:	0c101e4c 	jal	0x407930
  541554:	24060009 	li	a2,9
  541558:	0002102b 	sltu	v0,zero,v0
  54155c:	8fbf001c 	lw	ra,28(sp)
  541560:	03e00008 	jr	ra
  541564:	27bd0020 	addiu	sp,sp,32

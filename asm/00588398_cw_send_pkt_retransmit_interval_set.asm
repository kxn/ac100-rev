; func cw_send_pkt_retransmit_interval_set @ 0x00588398 size=0x18
  588398:	10800003 	beqz	a0,0x5883a8
  58839c:	2402ffff 	li	v0,-1
  5883a0:	00001021 	move	v0,zero
  5883a4:	ac850004 	sw	a1,4(a0)
  5883a8:	03e00008 	jr	ra
  5883ac:	00000000 	nop

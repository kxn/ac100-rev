; func cw_send_pkt_retransmit_set @ 0x00588380 size=0x18
  588380:	10800003 	beqz	a0,0x588390
  588384:	2402ffff 	li	v0,-1
  588388:	00001021 	move	v0,zero
  58838c:	ac850000 	sw	a1,0(a0)
  588390:	03e00008 	jr	ra
  588394:	00000000 	nop

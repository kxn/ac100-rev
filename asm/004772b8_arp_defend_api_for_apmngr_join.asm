; func arp_defend_api_for_apmngr_join @ 0x004772b8 size=0x20
  4772b8:	8c82000c 	lw	v0,12(a0)
  4772bc:	2c420003 	sltiu	v0,v0,3
  4772c0:	14400003 	bnez	v0,0x4772d0
  4772c4:	00000000 	nop
  4772c8:	03e00008 	jr	ra
  4772cc:	00001021 	move	v0,zero
  4772d0:	0811f167 	j	0x47c59c
  4772d4:	94840010 	lhu	a0,16(a0)

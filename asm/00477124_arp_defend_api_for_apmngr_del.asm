; func arp_defend_api_for_apmngr_del @ 0x00477124 size=0x20
  477124:	8c82000c 	lw	v0,12(a0)
  477128:	2c420003 	sltiu	v0,v0,3
  47712c:	14400003 	bnez	v0,0x47713c
  477130:	00000000 	nop
  477134:	03e00008 	jr	ra
  477138:	00001021 	move	v0,zero
  47713c:	0811f7d5 	j	0x47df54
  477140:	00000000 	nop

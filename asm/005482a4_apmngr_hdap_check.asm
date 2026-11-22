; func apmngr_hdap_check @ 0x005482a4 size=0x44
  5482a4:	27bdffe0 	addiu	sp,sp,-32
  5482a8:	afb00018 	sw	s0,24(sp)
  5482ac:	00808021 	move	s0,a0
  5482b0:	00a02021 	move	a0,a1
  5482b4:	afbf001c 	sw	ra,28(sp)
  5482b8:	0c152099 	jal	0x548264
  5482bc:	00c02821 	move	a1,a2
  5482c0:	00401821 	move	v1,v0
  5482c4:	10600004 	beqz	v1,0x5482d8
  5482c8:	00001021 	move	v0,zero
  5482cc:	12000002 	beqz	s0,0x5482d8
  5482d0:	00708026 	xor	s0,v1,s0
  5482d4:	2e020001 	sltiu	v0,s0,1
  5482d8:	8fbf001c 	lw	ra,28(sp)
  5482dc:	8fb00018 	lw	s0,24(sp)
  5482e0:	03e00008 	jr	ra
  5482e4:	27bd0020 	addiu	sp,sp,32

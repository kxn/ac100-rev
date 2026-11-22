; func rdmngr_db_get_band_by_channel @ 0x0061e4c0 size=0x40
  61e4c0:	3084ffff 	andi	a0,a0,0xffff
  61e4c4:	2483ffff 	addiu	v1,a0,-1
  61e4c8:	2c63000d 	sltiu	v1,v1,13
  61e4cc:	14600005 	bnez	v1,0x61e4e4
  61e4d0:	24020001 	li	v0,1
  61e4d4:	2483ffdc 	addiu	v1,a0,-36
  61e4d8:	2c63001d 	sltiu	v1,v1,29
  61e4dc:	10600003 	beqz	v1,0x61e4ec
  61e4e0:	24020002 	li	v0,2
  61e4e4:	03e00008 	jr	ra
  61e4e8:	00000000 	nop
  61e4ec:	2484ff9c 	addiu	a0,a0,-100
  61e4f0:	24020003 	li	v0,3
  61e4f4:	2c840042 	sltiu	a0,a0,66
  61e4f8:	03e00008 	jr	ra
  61e4fc:	0004100a 	movz	v0,zero,a0

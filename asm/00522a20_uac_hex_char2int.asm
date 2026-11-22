; func uac_hex_char2int @ 0x00522a20 size=0x38
  522a20:	3c1c0024 	lui	gp,0x24
  522a24:	279ce6e0 	addiu	gp,gp,-6432
  522a28:	0399e021 	addu	gp,gp,t9
  522a2c:	2484ffcf 	addiu	a0,a0,-49
  522a30:	308400ff 	andi	a0,a0,0xff
  522a34:	2c830036 	sltiu	v1,a0,54
  522a38:	10600005 	beqz	v1,0x522a50
  522a3c:	00001021 	move	v0,zero
  522a40:	8f828028 	lw	v0,-32728(gp)
  522a44:	24423b60 	addiu	v0,v0,15200
  522a48:	00822021 	addu	a0,a0,v0
  522a4c:	90820000 	lbu	v0,0(a0)
  522a50:	03e00008 	jr	ra
  522a54:	00000000 	nop

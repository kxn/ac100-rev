; func ac_passthrough_hex_char2int @ 0x0050e008 size=0x2c
  50e008:	2484ffcf 	addiu	a0,a0,-49
  50e00c:	308400ff 	andi	a0,a0,0xff
  50e010:	2c830036 	sltiu	v1,a0,54
  50e014:	10600005 	beqz	v1,0x50e02c
  50e018:	00001021 	move	v0,zero
  50e01c:	3c02006c 	lui	v0,0x6c
  50e020:	2442e7c0 	addiu	v0,v0,-6208
  50e024:	00822021 	addu	a0,a0,v0
  50e028:	90820000 	lbu	v0,0(a0)
  50e02c:	03e00008 	jr	ra
  50e030:	00000000 	nop

; func dhcpdef_hex_char2int @ 0x00466e04 size=0x2c
  466e04:	2484ffcf 	addiu	a0,a0,-49
  466e08:	308400ff 	andi	a0,a0,0xff
  466e0c:	2c830036 	sltiu	v1,a0,54
  466e10:	10600005 	beqz	v1,0x466e28
  466e14:	00001021 	move	v0,zero
  466e18:	3c020069 	lui	v0,0x69
  466e1c:	2442e5b0 	addiu	v0,v0,-6736
  466e20:	00822021 	addu	a0,a0,v0
  466e24:	90820000 	lbu	v0,0(a0)
  466e28:	03e00008 	jr	ra
  466e2c:	00000000 	nop

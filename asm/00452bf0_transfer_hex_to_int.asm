; func transfer_hex_to_int @ 0x00452bf0 size=0x50
  452bf0:	7c042420 	seb	a0,a0
  452bf4:	308200ff 	andi	v0,a0,0xff
  452bf8:	2443ffd0 	addiu	v1,v0,-48
  452bfc:	2c63000a 	sltiu	v1,v1,10
  452c00:	1460000d 	bnez	v1,0x452c38
  452c04:	00000000 	nop
  452c08:	2443ff9f 	addiu	v1,v0,-97
  452c0c:	2c630006 	sltiu	v1,v1,6
  452c10:	14600007 	bnez	v1,0x452c30
  452c14:	00000000 	nop
  452c18:	2442ffbf 	addiu	v0,v0,-65
  452c1c:	2484ffc9 	addiu	a0,a0,-55
  452c20:	2c420006 	sltiu	v0,v0,6
  452c24:	0002200a 	movz	a0,zero,v0
  452c28:	03e00008 	jr	ra
  452c2c:	00801021 	move	v0,a0
  452c30:	03e00008 	jr	ra
  452c34:	2482ffa9 	addiu	v0,a0,-87
  452c38:	03e00008 	jr	ra
  452c3c:	2482ffd0 	addiu	v0,a0,-48

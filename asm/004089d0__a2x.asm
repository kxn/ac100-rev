; func _a2x @ 0x004089d0 size=0x58
  4089d0:	28820047 	slti	v0,a0,71
  4089d4:	1040000b 	beqz	v0,0x408a04
  4089d8:	2483ff9f 	addiu	v1,a0,-97
  4089dc:	28820041 	slti	v0,a0,65
  4089e0:	5040000f 	beqzl	v0,0x408a20
  4089e4:	2484ffc9 	addiu	a0,a0,-55
  4089e8:	2484ffd0 	addiu	a0,a0,-48
  4089ec:	24020009 	li	v0,9
  4089f0:	0044102b 	sltu	v0,v0,a0
  4089f4:	50400008 	beqzl	v0,0x408a18
  4089f8:	308200ff 	andi	v0,a0,0xff
  4089fc:	03e00008 	jr	ra
  408a00:	00001021 	move	v0,zero
  408a04:	24020005 	li	v0,5
  408a08:	0043102b 	sltu	v0,v0,v1
  408a0c:	1440fffb 	bnez	v0,0x4089fc
  408a10:	2484ffa9 	addiu	a0,a0,-87
  408a14:	308200ff 	andi	v0,a0,0xff
  408a18:	03e00008 	jr	ra
  408a1c:	00000000 	nop
  408a20:	03e00008 	jr	ra
  408a24:	308200ff 	andi	v0,a0,0xff

; func capwap_packet_is_application @ 0x00597ae8 size=0x2c
  597ae8:	10800005 	beqz	a0,0x597b00
  597aec:	00001021 	move	v0,zero
  597af0:	90850000 	lbu	a1,0(a0)
  597af4:	24030001 	li	v1,1
  597af8:	50a30003 	beql	a1,v1,0x597b08
  597afc:	90820004 	lbu	v0,4(a0)
  597b00:	03e00008 	jr	ra
  597b04:	00000000 	nop
  597b08:	38420017 	xori	v0,v0,0x17
  597b0c:	03e00008 	jr	ra
  597b10:	2c420001 	sltiu	v0,v0,1

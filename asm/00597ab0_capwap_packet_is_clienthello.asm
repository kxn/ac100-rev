; func capwap_packet_is_clienthello @ 0x00597ab0 size=0x38
  597ab0:	90850000 	lbu	a1,0(a0)
  597ab4:	24030001 	li	v1,1
  597ab8:	10a30003 	beq	a1,v1,0x597ac8
  597abc:	00001021 	move	v0,zero
  597ac0:	03e00008 	jr	ra
  597ac4:	00000000 	nop
  597ac8:	90850004 	lbu	a1,4(a0)
  597acc:	24030016 	li	v1,22
  597ad0:	14a3fffb 	bne	a1,v1,0x597ac0
  597ad4:	00000000 	nop
  597ad8:	90820011 	lbu	v0,17(a0)
  597adc:	38420001 	xori	v0,v0,0x1
  597ae0:	03e00008 	jr	ra
  597ae4:	2c420001 	sltiu	v0,v0,1

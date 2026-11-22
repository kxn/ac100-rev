; func wips_channel_contain @ 0x004c7d80 size=0x58
  4c7d80:	28a300c0 	slti	v1,a1,192
  4c7d84:	10600012 	beqz	v1,0x4c7dd0
  4c7d88:	00001021 	move	v0,zero
  4c7d8c:	24020020 	li	v0,32
  4c7d90:	24a3001f 	addiu	v1,a1,31
  4c7d94:	004001f4 	teq	v0,zero,0x7
  4c7d98:	00a2001a 	div	zero,a1,v0
  4c7d9c:	28a60000 	slti	a2,a1,0
  4c7da0:	0066280b 	movn	a1,v1,a2
  4c7da4:	24030001 	li	v1,1
  4c7da8:	00052943 	sra	a1,a1,0x5
  4c7dac:	00052880 	sll	a1,a1,0x2
  4c7db0:	00852021 	addu	a0,a0,a1
  4c7db4:	8c840000 	lw	a0,0(a0)
  4c7db8:	00001010 	mfhi	v0
  4c7dbc:	00431804 	sllv	v1,v1,v0
  4c7dc0:	00641824 	and	v1,v1,a0
  4c7dc4:	00431006 	srlv	v0,v1,v0
  4c7dc8:	38420001 	xori	v0,v0,0x1
  4c7dcc:	2c420001 	sltiu	v0,v0,1
  4c7dd0:	03e00008 	jr	ra
  4c7dd4:	00000000 	nop

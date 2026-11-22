; func serv_msg_mngr_get @ 0x00599b88 size=0x58
  599b88:	2482ffff 	addiu	v0,a0,-1
  599b8c:	2c43001a 	sltiu	v1,v0,26
  599b90:	1460000e 	bnez	v1,0x599bcc
  599b94:	3c03007c 	lui	v1,0x7c
  599b98:	3c02ffcc 	lui	v0,0xffcc
  599b9c:	244222ff 	addiu	v0,v0,8959
  599ba0:	00822021 	addu	a0,a0,v0
  599ba4:	2c830002 	sltiu	v1,a0,2
  599ba8:	10600006 	beqz	v1,0x599bc4
  599bac:	00001021 	move	v0,zero
  599bb0:	3c02007c 	lui	v0,0x7c
  599bb4:	00042080 	sll	a0,a0,0x2
  599bb8:	244259d0 	addiu	v0,v0,22992
  599bbc:	00822021 	addu	a0,a0,v0
  599bc0:	8c820000 	lw	v0,0(a0)
  599bc4:	03e00008 	jr	ra
  599bc8:	00000000 	nop
  599bcc:	00021080 	sll	v0,v0,0x2
  599bd0:	246359d8 	addiu	v1,v1,23000
  599bd4:	00431021 	addu	v0,v0,v1
  599bd8:	03e00008 	jr	ra
  599bdc:	8c420000 	lw	v0,0(v0)

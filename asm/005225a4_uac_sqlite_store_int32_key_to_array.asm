; func uac_sqlite_store_int32_key_to_array @ 0x005225a4 size=0x34
  5225a4:	10a0000a 	beqz	a1,0x5225d0
  5225a8:	00000000 	nop
  5225ac:	10c00008 	beqz	a2,0x5225d0
  5225b0:	00000000 	nop
  5225b4:	8cc20000 	lw	v0,0(a2)
  5225b8:	00021080 	sll	v0,v0,0x2
  5225bc:	00a22821 	addu	a1,a1,v0
  5225c0:	aca40000 	sw	a0,0(a1)
  5225c4:	8cc20000 	lw	v0,0(a2)
  5225c8:	24420001 	addiu	v0,v0,1
  5225cc:	acc20000 	sw	v0,0(a2)
  5225d0:	03e00008 	jr	ra
  5225d4:	00001021 	move	v0,zero

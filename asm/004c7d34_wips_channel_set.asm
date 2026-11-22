; func wips_channel_set @ 0x004c7d34 size=0x4c
  4c7d34:	28a200c0 	slti	v0,a1,192
  4c7d38:	1040000f 	beqz	v0,0x4c7d78
  4c7d3c:	24a2001f 	addiu	v0,a1,31
  4c7d40:	28a30000 	slti	v1,a1,0
  4c7d44:	00a3100a 	movz	v0,a1,v1
  4c7d48:	24030001 	li	v1,1
  4c7d4c:	00021143 	sra	v0,v0,0x5
  4c7d50:	00021080 	sll	v0,v0,0x2
  4c7d54:	00822021 	addu	a0,a0,v0
  4c7d58:	24020020 	li	v0,32
  4c7d5c:	004001f4 	teq	v0,zero,0x7
  4c7d60:	00a2001a 	div	zero,a1,v0
  4c7d64:	00001010 	mfhi	v0
  4c7d68:	00431004 	sllv	v0,v1,v0
  4c7d6c:	8c830000 	lw	v1,0(a0)
  4c7d70:	00621025 	or	v0,v1,v0
  4c7d74:	ac820000 	sw	v0,0(a0)
  4c7d78:	03e00008 	jr	ra
  4c7d7c:	00000000 	nop

; func Get7Bits @ 0x0043baa0 size=0x44
  43baa0:	24a20007 	addiu	v0,a1,7
  43baa4:	28a30000 	slti	v1,a1,0
  43baa8:	00a3100a 	movz	v0,a1,v1
  43baac:	000210c3 	sra	v0,v0,0x3
  43bab0:	00822021 	addu	a0,a0,v0
  43bab4:	90820000 	lbu	v0,0(a0)
  43bab8:	90830001 	lbu	v1,1(a0)
  43babc:	00021200 	sll	v0,v0,0x8
  43bac0:	00621025 	or	v0,v1,v0
  43bac4:	24030008 	li	v1,8
  43bac8:	006001f4 	teq	v1,zero,0x7
  43bacc:	00a3001a 	div	zero,a1,v1
  43bad0:	00002810 	mfhi	a1
  43bad4:	00652823 	subu	a1,v1,a1
  43bad8:	00a21006 	srlv	v0,v0,a1
  43badc:	03e00008 	jr	ra
  43bae0:	304200fe 	andi	v0,v0,0xfe

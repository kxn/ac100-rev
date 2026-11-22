; func _cloud_mngt_role_match @ 0x0048ba90 size=0x3c
  48ba90:	2c830002 	sltiu	v1,a0,2
  48ba94:	1460000b 	bnez	v1,0x48bac4
  48ba98:	24020001 	li	v0,1
  48ba9c:	24030003 	li	v1,3
  48baa0:	10830008 	beq	a0,v1,0x48bac4
  48baa4:	24030002 	li	v1,2
  48baa8:	10830006 	beq	a0,v1,0x48bac4
  48baac:	24030004 	li	v1,4
  48bab0:	10830004 	beq	a0,v1,0x48bac4
  48bab4:	24030008 	li	v1,8
  48bab8:	10830002 	beq	a0,v1,0x48bac4
  48babc:	38840006 	xori	a0,a0,0x6
  48bac0:	2c820001 	sltiu	v0,a0,1
  48bac4:	03e00008 	jr	ra
  48bac8:	00000000 	nop

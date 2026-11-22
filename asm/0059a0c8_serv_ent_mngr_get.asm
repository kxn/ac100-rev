; func serv_ent_mngr_get @ 0x0059a0c8 size=0x2c
  59a0c8:	3084ffff 	andi	a0,a0,0xffff
  59a0cc:	2c830004 	sltiu	v1,a0,4
  59a0d0:	10600006 	beqz	v1,0x59a0ec
  59a0d4:	00001021 	move	v0,zero
  59a0d8:	3c02007c 	lui	v0,0x7c
  59a0dc:	00042080 	sll	a0,a0,0x2
  59a0e0:	244259c0 	addiu	v0,v0,22976
  59a0e4:	00822021 	addu	a0,a0,v0
  59a0e8:	8c820000 	lw	v0,0(a0)
  59a0ec:	03e00008 	jr	ra
  59a0f0:	00000000 	nop

; func cw_msg_ele_priv_mngr_get @ 0x005a22d4 size=0x2c
  5a22d4:	3084ffff 	andi	a0,a0,0xffff
  5a22d8:	288300c1 	slti	v1,a0,193
  5a22dc:	10600006 	beqz	v1,0x5a22f8
  5a22e0:	00001021 	move	v0,zero
  5a22e4:	3c02006e 	lui	v0,0x6e
  5a22e8:	00042080 	sll	a0,a0,0x2
  5a22ec:	24426700 	addiu	v0,v0,26368
  5a22f0:	00822021 	addu	a0,a0,v0
  5a22f4:	8c820000 	lw	v0,0(a0)
  5a22f8:	03e00008 	jr	ra
  5a22fc:	00000000 	nop

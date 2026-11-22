; func uac_wservice_refresh_bind_list @ 0x005db5ec size=0x58
  5db5ec:	27bdffd8 	addiu	sp,sp,-40
  5db5f0:	30a5ffff 	andi	a1,a1,0xffff
  5db5f4:	30c6ffff 	andi	a2,a2,0xffff
  5db5f8:	8fa20038 	lw	v0,56(sp)
  5db5fc:	afa70010 	sw	a3,16(sp)
  5db600:	3c07005e 	lui	a3,0x5e
  5db604:	afbf0024 	sw	ra,36(sp)
  5db608:	24e79320 	addiu	a3,a3,-27872
  5db60c:	afa40028 	sw	a0,40(sp)
  5db610:	0c17c8df 	jal	0x5f237c
  5db614:	afa20014 	sw	v0,20(sp)
  5db618:	3c05005e 	lui	a1,0x5e
  5db61c:	27a60028 	addiu	a2,sp,40
  5db620:	3c04000f 	lui	a0,0xf
  5db624:	0c14e0b9 	jal	0x5382e4
  5db628:	24a5be60 	addiu	a1,a1,-16800
  5db62c:	0c176bd3 	jal	0x5daf4c
  5db630:	00000000 	nop
  5db634:	00001021 	move	v0,zero
  5db638:	8fbf0024 	lw	ra,36(sp)
  5db63c:	03e00008 	jr	ra
  5db640:	27bd0028 	addiu	sp,sp,40

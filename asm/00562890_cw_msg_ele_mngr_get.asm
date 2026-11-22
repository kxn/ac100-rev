; func cw_msg_ele_mngr_get @ 0x00562890 size=0x5c
  562890:	3084ffff 	andi	a0,a0,0xffff
  562894:	2482ffff 	addiu	v0,a0,-1
  562898:	3043ffff 	andi	v1,v0,0xffff
  56289c:	2c630036 	sltiu	v1,v1,54
  5628a0:	1460000d 	bnez	v1,0x5628d8
  5628a4:	3c03006d 	lui	v1,0x6d
  5628a8:	2484fc00 	addiu	a0,a0,-1024
  5628ac:	3083ffff 	andi	v1,a0,0xffff
  5628b0:	2c630019 	sltiu	v1,v1,25
  5628b4:	10600006 	beqz	v1,0x5628d0
  5628b8:	00001021 	move	v0,zero
  5628bc:	3c02006d 	lui	v0,0x6d
  5628c0:	00042080 	sll	a0,a0,0x2
  5628c4:	24422e88 	addiu	v0,v0,11912
  5628c8:	00822021 	addu	a0,a0,v0
  5628cc:	8c820000 	lw	v0,0(a0)
  5628d0:	03e00008 	jr	ra
  5628d4:	00000000 	nop
  5628d8:	00021080 	sll	v0,v0,0x2
  5628dc:	24632db0 	addiu	v1,v1,11696
  5628e0:	00431021 	addu	v0,v0,v1
  5628e4:	03e00008 	jr	ra
  5628e8:	8c420000 	lw	v0,0(v0)

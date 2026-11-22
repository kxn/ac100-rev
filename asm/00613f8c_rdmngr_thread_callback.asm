; func rdmngr_thread_callback @ 0x00613f8c size=0x5c
  613f8c:	27bdffd8 	addiu	sp,sp,-40
  613f90:	afb20020 	sw	s2,32(sp)
  613f94:	3c120075 	lui	s2,0x75
  613f98:	afb1001c 	sw	s1,28(sp)
  613f9c:	3c110075 	lui	s1,0x75
  613fa0:	afb00018 	sw	s0,24(sp)
  613fa4:	3c100075 	lui	s0,0x75
  613fa8:	afbf0024 	sw	ra,36(sp)
  613fac:	0c101ec4 	jal	0x407b10
  613fb0:	8e04fe9c 	lw	a0,-356(s0)
  613fb4:	8e03fe9c 	lw	v1,-356(s0)
  613fb8:	8e22fe98 	lw	v0,-360(s1)
  613fbc:	00031840 	sll	v1,v1,0x1
  613fc0:	0043202b 	sltu	a0,v0,v1
  613fc4:	0064100a 	movz	v0,v1,a0
  613fc8:	ae02fe9c 	sw	v0,-356(s0)
  613fcc:	8e42fe94 	lw	v0,-364(s2)
  613fd0:	1040fff6 	beqz	v0,0x613fac
  613fd4:	00000000 	nop
  613fd8:	0c184eca 	jal	0x613b28
  613fdc:	00000000 	nop
  613fe0:	08184feb 	j	0x613fac
  613fe4:	00000000 	nop

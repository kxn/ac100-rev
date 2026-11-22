; func cw_ac_data_destroy @ 0x00589eac size=0x98
  589eac:	27bdffe0 	addiu	sp,sp,-32
  589eb0:	afb00018 	sw	s0,24(sp)
  589eb4:	00808021 	move	s0,a0
  589eb8:	10800018 	beqz	a0,0x589f1c
  589ebc:	afbf001c 	sw	ra,28(sp)
  589ec0:	3c02007c 	lui	v0,0x7c
  589ec4:	8c425988 	lw	v0,22920(v0)
  589ec8:	14400008 	bnez	v0,0x589eec
  589ecc:	00000000 	nop
  589ed0:	0c1624a0 	jal	0x589280
  589ed4:	26040094 	addiu	a0,s0,148
  589ed8:	00001021 	move	v0,zero
  589edc:	8fbf001c 	lw	ra,28(sp)
  589ee0:	8fb00018 	lw	s0,24(sp)
  589ee4:	03e00008 	jr	ra
  589ee8:	27bd0020 	addiu	sp,sp,32
  589eec:	0c16276a 	jal	0x589da8
  589ef0:	00000000 	nop
  589ef4:	1040fff6 	beqz	v0,0x589ed0
  589ef8:	3c04006e 	lui	a0,0x6e
  589efc:	3c05006e 	lui	a1,0x6e
  589f00:	2484e7ac 	addiu	a0,a0,-6228
  589f04:	24a51198 	addiu	a1,a1,4504
  589f08:	24060316 	li	a2,790
  589f0c:	0c101b74 	jal	0x406dd0
  589f10:	02003821 	move	a3,s0
  589f14:	081627b4 	j	0x589ed0
  589f18:	00000000 	nop
  589f1c:	3c040069 	lui	a0,0x69
  589f20:	3c05006e 	lui	a1,0x6e
  589f24:	3c07006e 	lui	a3,0x6e
  589f28:	2484d3ac 	addiu	a0,a0,-11348
  589f2c:	24a51198 	addiu	a1,a1,4504
  589f30:	24060314 	li	a2,788
  589f34:	0c101b74 	jal	0x406dd0
  589f38:	24e7e7a4 	addiu	a3,a3,-6236
  589f3c:	081627b7 	j	0x589edc
  589f40:	2402ffff 	li	v0,-1

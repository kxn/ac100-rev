; func cw_msg_ele_remove @ 0x00562c94 size=0x80
  562c94:	27bdffd8 	addiu	sp,sp,-40
  562c98:	2402ffff 	li	v0,-1
  562c9c:	afb10020 	sw	s1,32(sp)
  562ca0:	00a08821 	move	s1,a1
  562ca4:	afbf0024 	sw	ra,36(sp)
  562ca8:	1080000f 	beqz	a0,0x562ce8
  562cac:	afb0001c 	sw	s0,28(sp)
  562cb0:	10a0000e 	beqz	a1,0x562cec
  562cb4:	8fbf0024 	lw	ra,36(sp)
  562cb8:	0c10206c 	jal	0x4081b0
  562cbc:	2484001c 	addiu	a0,a0,28
  562cc0:	08158b37 	j	0x562cdc
  562cc4:	00000000 	nop
  562cc8:	8e020010 	lw	v0,16(s0)
  562ccc:	1051000b 	beq	v0,s1,0x562cfc
  562cd0:	02002021 	move	a0,s0
  562cd4:	0c1021a0 	jal	0x408680
  562cd8:	00000000 	nop
  562cdc:	1440fffa 	bnez	v0,0x562cc8
  562ce0:	00408021 	move	s0,v0
  562ce4:	00001021 	move	v0,zero
  562ce8:	8fbf0024 	lw	ra,36(sp)
  562cec:	8fb10020 	lw	s1,32(sp)
  562cf0:	8fb0001c 	lw	s0,28(sp)
  562cf4:	03e00008 	jr	ra
  562cf8:	27bd0028 	addiu	sp,sp,40
  562cfc:	0c102140 	jal	0x408500
  562d00:	00000000 	nop
  562d04:	0c101f7c 	jal	0x407df0
  562d08:	02002021 	move	a0,s0
  562d0c:	08158b3a 	j	0x562ce8
  562d10:	00001021 	move	v0,zero

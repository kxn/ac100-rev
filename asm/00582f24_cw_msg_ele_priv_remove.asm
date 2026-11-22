; func cw_msg_ele_priv_remove @ 0x00582f24 size=0x80
  582f24:	27bdffd8 	addiu	sp,sp,-40
  582f28:	2402ffff 	li	v0,-1
  582f2c:	afb10020 	sw	s1,32(sp)
  582f30:	00a08821 	move	s1,a1
  582f34:	afbf0024 	sw	ra,36(sp)
  582f38:	1080000f 	beqz	a0,0x582f78
  582f3c:	afb0001c 	sw	s0,28(sp)
  582f40:	10a0000e 	beqz	a1,0x582f7c
  582f44:	8fbf0024 	lw	ra,36(sp)
  582f48:	0c10206c 	jal	0x4081b0
  582f4c:	24840008 	addiu	a0,a0,8
  582f50:	08160bdb 	j	0x582f6c
  582f54:	00000000 	nop
  582f58:	8e020010 	lw	v0,16(s0)
  582f5c:	1051000b 	beq	v0,s1,0x582f8c
  582f60:	02002021 	move	a0,s0
  582f64:	0c1021a0 	jal	0x408680
  582f68:	00000000 	nop
  582f6c:	1440fffa 	bnez	v0,0x582f58
  582f70:	00408021 	move	s0,v0
  582f74:	00001021 	move	v0,zero
  582f78:	8fbf0024 	lw	ra,36(sp)
  582f7c:	8fb10020 	lw	s1,32(sp)
  582f80:	8fb0001c 	lw	s0,28(sp)
  582f84:	03e00008 	jr	ra
  582f88:	27bd0028 	addiu	sp,sp,40
  582f8c:	0c102140 	jal	0x408500
  582f90:	00000000 	nop
  582f94:	0c101f7c 	jal	0x407df0
  582f98:	02002021 	move	a0,s0
  582f9c:	08160bde 	j	0x582f78
  582fa0:	00001021 	move	v0,zero

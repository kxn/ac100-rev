; func cw_sta_assoc_rslt_sub_ele_free @ 0x005c3f6c size=0xa0
  5c3f6c:	27bdffd0 	addiu	sp,sp,-48
  5c3f70:	afbf002c 	sw	ra,44(sp)
  5c3f74:	afb30028 	sw	s3,40(sp)
  5c3f78:	afb20024 	sw	s2,36(sp)
  5c3f7c:	afb10020 	sw	s1,32(sp)
  5c3f80:	1080001b 	beqz	a0,0x5c3ff0
  5c3f84:	afb0001c 	sw	s0,28(sp)
  5c3f88:	24920014 	addiu	s2,a0,20
  5c3f8c:	08170fe9 	j	0x5c3fa4
  5c3f90:	24130001 	li	s3,1
  5c3f94:	0c101f7c 	jal	0x407df0
  5c3f98:	8e040010 	lw	a0,16(s0)
  5c3f9c:	0c101f7c 	jal	0x407df0
  5c3fa0:	02002021 	move	a0,s0
  5c3fa4:	0c10206c 	jal	0x4081b0
  5c3fa8:	02402021 	move	a0,s2
  5c3fac:	10400010 	beqz	v0,0x5c3ff0
  5c3fb0:	00408021 	move	s0,v0
  5c3fb4:	0c102140 	jal	0x408500
  5c3fb8:	02002021 	move	a0,s0
  5c3fbc:	8e110010 	lw	s1,16(s0)
  5c3fc0:	1220fff6 	beqz	s1,0x5c3f9c
  5c3fc4:	00000000 	nop
  5c3fc8:	9602000c 	lhu	v0,12(s0)
  5c3fcc:	1453fff1 	bne	v0,s3,0x5c3f94
  5c3fd0:	00000000 	nop
  5c3fd4:	8e240004 	lw	a0,4(s1)
  5c3fd8:	1080ffee 	beqz	a0,0x5c3f94
  5c3fdc:	00000000 	nop
  5c3fe0:	0c101f7c 	jal	0x407df0
  5c3fe4:	00000000 	nop
  5c3fe8:	08170fe5 	j	0x5c3f94
  5c3fec:	ae200004 	sw	zero,4(s1)
  5c3ff0:	8fbf002c 	lw	ra,44(sp)
  5c3ff4:	8fb30028 	lw	s3,40(sp)
  5c3ff8:	8fb20024 	lw	s2,36(sp)
  5c3ffc:	8fb10020 	lw	s1,32(sp)
  5c4000:	8fb0001c 	lw	s0,28(sp)
  5c4004:	03e00008 	jr	ra
  5c4008:	27bd0030 	addiu	sp,sp,48

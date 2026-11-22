; func cw_image_identifier_free @ 0x00576f44 size=0x54
  576f44:	27bdffd8 	addiu	sp,sp,-40
  576f48:	afb10020 	sw	s1,32(sp)
  576f4c:	afbf0024 	sw	ra,36(sp)
  576f50:	afb0001c 	sw	s0,28(sp)
  576f54:	8c900010 	lw	s0,16(a0)
  576f58:	12000009 	beqz	s0,0x576f80
  576f5c:	00808821 	move	s1,a0
  576f60:	8e040008 	lw	a0,8(s0)
  576f64:	10800003 	beqz	a0,0x576f74
  576f68:	00000000 	nop
  576f6c:	0c101f7c 	jal	0x407df0
  576f70:	00000000 	nop
  576f74:	0c101f7c 	jal	0x407df0
  576f78:	02002021 	move	a0,s0
  576f7c:	ae200010 	sw	zero,16(s1)
  576f80:	8fbf0024 	lw	ra,36(sp)
  576f84:	00001021 	move	v0,zero
  576f88:	8fb10020 	lw	s1,32(sp)
  576f8c:	8fb0001c 	lw	s0,28(sp)
  576f90:	03e00008 	jr	ra
  576f94:	27bd0028 	addiu	sp,sp,40

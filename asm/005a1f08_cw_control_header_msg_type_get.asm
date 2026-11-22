; func cw_control_header_msg_type_get @ 0x005a1f08 size=0x6c
  5a1f08:	27bdffd8 	addiu	sp,sp,-40
  5a1f0c:	afb00020 	sw	s0,32(sp)
  5a1f10:	00808021 	move	s0,a0
  5a1f14:	afbf0024 	sw	ra,36(sp)
  5a1f18:	1080000c 	beqz	a0,0x5a1f4c
  5a1f1c:	afa00018 	sw	zero,24(sp)
  5a1f20:	0c1685ef 	jal	0x5a17bc
  5a1f24:	00000000 	nop
  5a1f28:	27a40018 	addiu	a0,sp,24
  5a1f2c:	02022821 	addu	a1,s0,v0
  5a1f30:	0c101c8c 	jal	0x407230
  5a1f34:	24060004 	li	a2,4
  5a1f38:	8fa20018 	lw	v0,24(sp)
  5a1f3c:	8fbf0024 	lw	ra,36(sp)
  5a1f40:	8fb00020 	lw	s0,32(sp)
  5a1f44:	03e00008 	jr	ra
  5a1f48:	27bd0028 	addiu	sp,sp,40
  5a1f4c:	3c040069 	lui	a0,0x69
  5a1f50:	3c05006e 	lui	a1,0x6e
  5a1f54:	3c07006e 	lui	a3,0x6e
  5a1f58:	2484d3ac 	addiu	a0,a0,-11348
  5a1f5c:	24a565dc 	addiu	a1,a1,26076
  5a1f60:	24060385 	li	a2,901
  5a1f64:	0c101b74 	jal	0x406dd0
  5a1f68:	24e7608c 	addiu	a3,a3,24716
  5a1f6c:	081687cf 	j	0x5a1f3c
  5a1f70:	00001021 	move	v0,zero

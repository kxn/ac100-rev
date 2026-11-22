; func cw_msg_eles_length_update @ 0x00588f2c size=0x7c
  588f2c:	27bdffe0 	addiu	sp,sp,-32
  588f30:	afb00018 	sw	s0,24(sp)
  588f34:	00808021 	move	s0,a0
  588f38:	1080000b 	beqz	a0,0x588f68
  588f3c:	afbf001c 	sw	ra,28(sp)
  588f40:	0c16224d 	jal	0x588934
  588f44:	00000000 	nop
  588f48:	24420003 	addiu	v0,v0,3
  588f4c:	a6020016 	sh	v0,22(s0)
  588f50:	00008021 	move	s0,zero
  588f54:	8fbf001c 	lw	ra,28(sp)
  588f58:	02001021 	move	v0,s0
  588f5c:	8fb00018 	lw	s0,24(sp)
  588f60:	03e00008 	jr	ra
  588f64:	27bd0020 	addiu	sp,sp,32
  588f68:	3c020075 	lui	v0,0x75
  588f6c:	8c42cf58 	lw	v0,-12456(v0)
  588f70:	1040fff8 	beqz	v0,0x588f54
  588f74:	2410ffff 	li	s0,-1
  588f78:	0c16276a 	jal	0x589da8
  588f7c:	00000000 	nop
  588f80:	5040fff5 	beqzl	v0,0x588f58
  588f84:	8fbf001c 	lw	ra,28(sp)
  588f88:	3c04006d 	lui	a0,0x6d
  588f8c:	3c05006e 	lui	a1,0x6e
  588f90:	24847cb0 	addiu	a0,a0,31920
  588f94:	24a5e384 	addiu	a1,a1,-7292
  588f98:	0c101b74 	jal	0x406dd0
  588f9c:	2406062e 	li	a2,1582
  588fa0:	081623d6 	j	0x588f58
  588fa4:	8fbf001c 	lw	ra,28(sp)

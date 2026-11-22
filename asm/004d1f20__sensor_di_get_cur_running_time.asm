; func _sensor_di_get_cur_running_time @ 0x004d1f20 size=0x6c
  4d1f20:	27bdffd8 	addiu	sp,sp,-40
  4d1f24:	2405ffff 	li	a1,-1
  4d1f28:	afb10020 	sw	s1,32(sp)
  4d1f2c:	3c110077 	lui	s1,0x77
  4d1f30:	afbf0024 	sw	ra,36(sp)
  4d1f34:	afb0001c 	sw	s0,28(sp)
  4d1f38:	0c1020b4 	jal	0x4082d0
  4d1f3c:	8e2485e4 	lw	a0,-31260(s1)
  4d1f40:	0c101f9c 	jal	0x407e70
  4d1f44:	00000000 	nop
  4d1f48:	3c020077 	lui	v0,0x77
  4d1f4c:	944285de 	lhu	v0,-31266(v0)
  4d1f50:	00628023 	subu	s0,v1,v0
  4d1f54:	7c108620 	seh	s0,s0
  4d1f58:	2a020259 	slti	v0,s0,601
  4d1f5c:	50400003 	beqzl	v0,0x4d1f6c
  4d1f60:	24100258 	li	s0,600
  4d1f64:	2a020000 	slti	v0,s0,0
  4d1f68:	0002800b 	movn	s0,zero,v0
  4d1f6c:	0c101fcc 	jal	0x407f30
  4d1f70:	8e2485e4 	lw	a0,-31260(s1)
  4d1f74:	02001021 	move	v0,s0
  4d1f78:	8fbf0024 	lw	ra,36(sp)
  4d1f7c:	8fb10020 	lw	s1,32(sp)
  4d1f80:	8fb0001c 	lw	s0,28(sp)
  4d1f84:	03e00008 	jr	ra
  4d1f88:	27bd0028 	addiu	sp,sp,40

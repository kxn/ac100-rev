; func sensor_test_db_case_setting_mem_free @ 0x00500f1c size=0x88
  500f1c:	27bdffe0 	addiu	sp,sp,-32
  500f20:	afb00018 	sw	s0,24(sp)
  500f24:	00808021 	move	s0,a0
  500f28:	1080001a 	beqz	a0,0x500f94
  500f2c:	afbf001c 	sw	ra,28(sp)
  500f30:	8c840034 	lw	a0,52(a0)
  500f34:	50800005 	beqzl	a0,0x500f4c
  500f38:	8e040038 	lw	a0,56(s0)
  500f3c:	0c101f7c 	jal	0x407df0
  500f40:	00000000 	nop
  500f44:	ae000034 	sw	zero,52(s0)
  500f48:	8e040038 	lw	a0,56(s0)
  500f4c:	50800005 	beqzl	a0,0x500f64
  500f50:	8e040030 	lw	a0,48(s0)
  500f54:	0c101f7c 	jal	0x407df0
  500f58:	00000000 	nop
  500f5c:	ae000038 	sw	zero,56(s0)
  500f60:	8e040030 	lw	a0,48(s0)
  500f64:	10800004 	beqz	a0,0x500f78
  500f68:	00000000 	nop
  500f6c:	0c101f7c 	jal	0x407df0
  500f70:	00000000 	nop
  500f74:	ae000030 	sw	zero,48(s0)
  500f78:	0c13fbd0 	jal	0x4fef40
  500f7c:	2604003c 	addiu	a0,s0,60
  500f80:	02002021 	move	a0,s0
  500f84:	8fbf001c 	lw	ra,28(sp)
  500f88:	8fb00018 	lw	s0,24(sp)
  500f8c:	08101f7c 	j	0x407df0
  500f90:	27bd0020 	addiu	sp,sp,32
  500f94:	8fbf001c 	lw	ra,28(sp)
  500f98:	8fb00018 	lw	s0,24(sp)
  500f9c:	03e00008 	jr	ra
  500fa0:	27bd0020 	addiu	sp,sp,32

; func _sensor_db_sqlite_thread_main @ 0x004cff1c size=0x144
  4cff1c:	27bdffb8 	addiu	sp,sp,-72
  4cff20:	afb40038 	sw	s4,56(sp)
  4cff24:	3c14006b 	lui	s4,0x6b
  4cff28:	afb20030 	sw	s2,48(sp)
  4cff2c:	3c120077 	lui	s2,0x77
  4cff30:	afb30034 	sw	s3,52(sp)
  4cff34:	27b30018 	addiu	s3,sp,24
  4cff38:	afb60040 	sw	s6,64(sp)
  4cff3c:	265280c0 	addiu	s2,s2,-32576
  4cff40:	afb5003c 	sw	s5,60(sp)
  4cff44:	3c160077 	lui	s6,0x77
  4cff48:	afb1002c 	sw	s1,44(sp)
  4cff4c:	3c150077 	lui	s5,0x77
  4cff50:	3c110077 	lui	s1,0x77
  4cff54:	afbf0044 	sw	ra,68(sp)
  4cff58:	26949140 	addiu	s4,s4,-28352
  4cff5c:	afb00028 	sw	s0,40(sp)
  4cff60:	02602021 	move	a0,s3
  4cff64:	afa00018 	sw	zero,24(sp)
  4cff68:	afa0001c 	sw	zero,28(sp)
  4cff6c:	0c146b62 	jal	0x51ad88
  4cff70:	afa00020 	sw	zero,32(sp)
  4cff74:	8ea480b8 	lw	a0,-32584(s5)
  4cff78:	2405ffff 	li	a1,-1
  4cff7c:	0c1020b4 	jal	0x4082d0
  4cff80:	3c100077 	lui	s0,0x77
  4cff84:	08133fe6 	j	0x4cff98
  4cff88:	00000000 	nop
  4cff8c:	2406ffff 	li	a2,-1
  4cff90:	0c1021b0 	jal	0x4086c0
  4cff94:	8e0580b8 	lw	a1,-32584(s0)
  4cff98:	0c10206c 	jal	0x4081b0
  4cff9c:	02402021 	move	a0,s2
  4cffa0:	5040fffa 	beqzl	v0,0x4cff8c
  4cffa4:	8ec480cc 	lw	a0,-32564(s6)
  4cffa8:	02602021 	move	a0,s3
  4cffac:	0c1020b0 	jal	0x4082c0
  4cffb0:	02402821 	move	a1,s2
  4cffb4:	0c101fcc 	jal	0x407f30
  4cffb8:	8e0480b8 	lw	a0,-32584(s0)
  4cffbc:	0c10206c 	jal	0x4081b0
  4cffc0:	02602021 	move	a0,s3
  4cffc4:	1040ffeb 	beqz	v0,0x4cff74
  4cffc8:	00408021 	move	s0,v0
  4cffcc:	0c102140 	jal	0x408500
  4cffd0:	02002021 	move	a0,s0
  4cffd4:	8e2280bc 	lw	v0,-32580(s1)
  4cffd8:	2442ffff 	addiu	v0,v0,-1
  4cffdc:	ae2280bc 	sw	v0,-32580(s1)
  4cffe0:	8e02000c 	lw	v0,12(s0)
  4cffe4:	2c430005 	sltiu	v1,v0,5
  4cffe8:	10600007 	beqz	v1,0x4d0008
  4cffec:	00021080 	sll	v0,v0,0x2
  4cfff0:	02821021 	addu	v0,s4,v0
  4cfff4:	8c420000 	lw	v0,0(v0)
  4cfff8:	00400008 	jr	v0
  4cfffc:	8e040010 	lw	a0,16(s0)
  4d0000:	0c133f58 	jal	0x4cfd60
  4d0004:	00000000 	nop
  4d0008:	0c101f7c 	jal	0x407df0
  4d000c:	8e040010 	lw	a0,16(s0)
  4d0010:	0c101f7c 	jal	0x407df0
  4d0014:	02002021 	move	a0,s0
  4d0018:	08133fef 	j	0x4cffbc
  4d001c:	00000000 	nop
  4d0020:	0c133d8c 	jal	0x4cf630
  4d0024:	94840000 	lhu	a0,0(a0)
  4d0028:	08134002 	j	0x4d0008
  4d002c:	00000000 	nop
  4d0030:	0c133d47 	jal	0x4cf51c
  4d0034:	00000000 	nop
  4d0038:	08134002 	j	0x4d0008
  4d003c:	00000000 	nop
  4d0040:	0c133fa1 	jal	0x4cfe84
  4d0044:	8c840000 	lw	a0,0(a0)
  4d0048:	08134002 	j	0x4d0008
  4d004c:	00000000 	nop
  4d0050:	0c133cfc 	jal	0x4cf3f0
  4d0054:	00000000 	nop
  4d0058:	08134002 	j	0x4d0008
  4d005c:	00000000 	nop

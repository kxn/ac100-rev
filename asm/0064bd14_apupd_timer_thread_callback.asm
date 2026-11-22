; func apupd_timer_thread_callback @ 0x0064bd14 size=0x12c
  64bd14:	27bdffb8 	addiu	sp,sp,-72
  64bd18:	27a40018 	addiu	a0,sp,24
  64bd1c:	afb60040 	sw	s6,64(sp)
  64bd20:	3c160072 	lui	s6,0x72
  64bd24:	afb5003c 	sw	s5,60(sp)
  64bd28:	3c150071 	lui	s5,0x71
  64bd2c:	afb20030 	sw	s2,48(sp)
  64bd30:	3c12007d 	lui	s2,0x7d
  64bd34:	afb40038 	sw	s4,56(sp)
  64bd38:	26b54a84 	addiu	s5,s5,19076
  64bd3c:	afb30034 	sw	s3,52(sp)
  64bd40:	2652c79c 	addiu	s2,s2,-14436
  64bd44:	3c13007d 	lui	s3,0x7d
  64bd48:	afbf0044 	sw	ra,68(sp)
  64bd4c:	3c14007d 	lui	s4,0x7d
  64bd50:	afb1002c 	sw	s1,44(sp)
  64bd54:	26d69c2c 	addiu	s6,s6,-25556
  64bd58:	afb00028 	sw	s0,40(sp)
  64bd5c:	afa00018 	sw	zero,24(sp)
  64bd60:	afa0001c 	sw	zero,28(sp)
  64bd64:	0c146b62 	jal	0x51ad88
  64bd68:	afa00020 	sw	zero,32(sp)
  64bd6c:	8e64c780 	lw	a0,-14464(s3)
  64bd70:	2405ffff 	li	a1,-1
  64bd74:	0c1020b4 	jal	0x4082d0
  64bd78:	3c10007d 	lui	s0,0x7d
  64bd7c:	08192f64 	j	0x64bd90
  64bd80:	00000000 	nop
  64bd84:	2406ffff 	li	a2,-1
  64bd88:	0c1021b0 	jal	0x4086c0
  64bd8c:	8e05c780 	lw	a1,-14464(s0)
  64bd90:	0c10206c 	jal	0x4081b0
  64bd94:	02402021 	move	a0,s2
  64bd98:	5040fffa 	beqzl	v0,0x64bd84
  64bd9c:	8e84c784 	lw	a0,-14460(s4)
  64bda0:	27a40018 	addiu	a0,sp,24
  64bda4:	0c1020b0 	jal	0x4082c0
  64bda8:	02402821 	move	a1,s2
  64bdac:	3c110076 	lui	s1,0x76
  64bdb0:	0c101fcc 	jal	0x407f30
  64bdb4:	8e04c780 	lw	a0,-14464(s0)
  64bdb8:	0c10206c 	jal	0x4081b0
  64bdbc:	27a40018 	addiu	a0,sp,24
  64bdc0:	1040ffea 	beqz	v0,0x64bd6c
  64bdc4:	00408021 	move	s0,v0
  64bdc8:	0c102140 	jal	0x408500
  64bdcc:	02002021 	move	a0,s0
  64bdd0:	8e02000c 	lw	v0,12(s0)
  64bdd4:	1440000d 	bnez	v0,0x64be0c
  64bdd8:	8e228c08 	lw	v0,-29688(s1)
  64bddc:	0c192d31 	jal	0x64b4c4
  64bde0:	8e040010 	lw	a0,16(s0)
  64bde4:	8e040010 	lw	a0,16(s0)
  64bde8:	10800004 	beqz	a0,0x64bdfc
  64bdec:	00000000 	nop
  64bdf0:	0c101f7c 	jal	0x407df0
  64bdf4:	00000000 	nop
  64bdf8:	ae000010 	sw	zero,16(s0)
  64bdfc:	0c101f7c 	jal	0x407df0
  64be00:	02002021 	move	a0,s0
  64be04:	08192f6e 	j	0x64bdb8
  64be08:	00000000 	nop
  64be0c:	5040fff6 	beqzl	v0,0x64bde8
  64be10:	8e040010 	lw	a0,16(s0)
  64be14:	0c16276a 	jal	0x589da8
  64be18:	00000000 	nop
  64be1c:	5040fff2 	beqzl	v0,0x64bde8
  64be20:	8e040010 	lw	a0,16(s0)
  64be24:	8e07000c 	lw	a3,12(s0)
  64be28:	24060d65 	li	a2,3429
  64be2c:	02a02021 	move	a0,s5
  64be30:	0c101b74 	jal	0x406dd0
  64be34:	02c02821 	move	a1,s6
  64be38:	08192f79 	j	0x64bde4
  64be3c:	00000000 	nop

; func mesh_db_uninit @ 0x004babd8 size=0xdc
  4babd8:	27bdffd0 	addiu	sp,sp,-48
  4babdc:	afb10020 	sw	s1,32(sp)
  4babe0:	3c110076 	lui	s1,0x76
  4babe4:	afbf002c 	sw	ra,44(sp)
  4babe8:	afb30028 	sw	s3,40(sp)
  4babec:	afb20024 	sw	s2,36(sp)
  4babf0:	afb0001c 	sw	s0,28(sp)
  4babf4:	8e227eb0 	lw	v0,32432(s1)
  4babf8:	10400026 	beqz	v0,0x4bac94
  4babfc:	26307eb0 	addiu	s0,s1,32432
  4bac00:	8e040004 	lw	a0,4(s0)
  4bac04:	10800005 	beqz	a0,0x4bac1c
  4bac08:	26227eb0 	addiu	v0,s1,32432
  4bac0c:	0c1020d8 	jal	0x408360
  4bac10:	00000000 	nop
  4bac14:	ae000004 	sw	zero,4(s0)
  4bac18:	26227eb0 	addiu	v0,s1,32432
  4bac1c:	8c4400b8 	lw	a0,184(v0)
  4bac20:	10800003 	beqz	a0,0x4bac30
  4bac24:	26307eb0 	addiu	s0,s1,32432
  4bac28:	0c1020c4 	jal	0x408310
  4bac2c:	00000000 	nop
  4bac30:	8e0200bc 	lw	v0,188(s0)
  4bac34:	10400014 	beqz	v0,0x4bac88
  4bac38:	00009021 	move	s2,zero
  4bac3c:	0c1506a9 	jal	0x541aa4
  4bac40:	00000000 	nop
  4bac44:	0242102a 	slt	v0,s2,v0
  4bac48:	1040000d 	beqz	v0,0x4bac80
  4bac4c:	00000000 	nop
  4bac50:	8e0200bc 	lw	v0,188(s0)
  4bac54:	001298c0 	sll	s3,s2,0x3
  4bac58:	00531021 	addu	v0,v0,s3
  4bac5c:	8c440004 	lw	a0,4(v0)
  4bac60:	1080fff6 	beqz	a0,0x4bac3c
  4bac64:	26520001 	addiu	s2,s2,1
  4bac68:	0c101f7c 	jal	0x407df0
  4bac6c:	00000000 	nop
  4bac70:	8e0200bc 	lw	v0,188(s0)
  4bac74:	00539821 	addu	s3,v0,s3
  4bac78:	0812eb0f 	j	0x4bac3c
  4bac7c:	ae600004 	sw	zero,4(s3)
  4bac80:	0c101f7c 	jal	0x407df0
  4bac84:	8e0400bc 	lw	a0,188(s0)
  4bac88:	26227eb0 	addiu	v0,s1,32432
  4bac8c:	ae207eb0 	sw	zero,32432(s1)
  4bac90:	ac4000a8 	sw	zero,168(v0)
  4bac94:	8fbf002c 	lw	ra,44(sp)
  4bac98:	00001021 	move	v0,zero
  4bac9c:	8fb30028 	lw	s3,40(sp)
  4baca0:	8fb20024 	lw	s2,36(sp)
  4baca4:	8fb10020 	lw	s1,32(sp)
  4baca8:	8fb0001c 	lw	s0,28(sp)
  4bacac:	03e00008 	jr	ra
  4bacb0:	27bd0030 	addiu	sp,sp,48

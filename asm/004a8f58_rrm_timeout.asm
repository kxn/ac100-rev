; func rrm_timeout @ 0x004a8f58 size=0x48
  4a8f58:	27bdffe0 	addiu	sp,sp,-32
  4a8f5c:	afbf001c 	sw	ra,28(sp)
  4a8f60:	0c12c70c 	jal	0x4b1c30
  4a8f64:	00000000 	nop
  4a8f68:	24030002 	li	v1,2
  4a8f6c:	24040005 	li	a0,5
  4a8f70:	38420001 	xori	v0,v0,0x1
  4a8f74:	0c12c708 	jal	0x4b1c20
  4a8f78:	0062200a 	movz	a0,v1,v0
  4a8f7c:	3c020076 	lui	v0,0x76
  4a8f80:	0c102070 	jal	0x4081c0
  4a8f84:	8c447c10 	lw	a0,31760(v0)
  4a8f88:	3c020073 	lui	v0,0x73
  4a8f8c:	8fbf001c 	lw	ra,28(sp)
  4a8f90:	2403ffff 	li	v1,-1
  4a8f94:	27bd0020 	addiu	sp,sp,32
  4a8f98:	03e00008 	jr	ra
  4a8f9c:	ac431914 	sw	v1,6420(v0)

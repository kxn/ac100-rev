; func _apdb_init_unsupported_ap_list @ 0x00611cd0 size=0xd8
  611cd0:	27bdffe0 	addiu	sp,sp,-32
  611cd4:	afb00018 	sw	s0,24(sp)
  611cd8:	3c10007d 	lui	s0,0x7d
  611cdc:	afbf001c 	sw	ra,28(sp)
  611ce0:	8e04c2cc 	lw	a0,-15668(s0)
  611ce4:	10800004 	beqz	a0,0x611cf8
  611ce8:	00000000 	nop
  611cec:	0c101c50 	jal	0x407140
  611cf0:	00000000 	nop
  611cf4:	ae00c2cc 	sw	zero,-15668(s0)
  611cf8:	0c101dcc 	jal	0x407730
  611cfc:	00000000 	nop
  611d00:	10400012 	beqz	v0,0x611d4c
  611d04:	ae02c2cc 	sw	v0,-15668(s0)
  611d08:	3c040061 	lui	a0,0x61
  611d0c:	3c050061 	lui	a1,0x61
  611d10:	3c060061 	lui	a2,0x61
  611d14:	2484eca4 	addiu	a0,a0,-4956
  611d18:	24a5ec64 	addiu	a1,a1,-5020
  611d1c:	24c6ece4 	addiu	a2,a2,-4892
  611d20:	24070258 	li	a3,600
  611d24:	0c102028 	jal	0x4080a0
  611d28:	00008021 	move	s0,zero
  611d2c:	3c03007d 	lui	v1,0x7d
  611d30:	10400013 	beqz	v0,0x611d80
  611d34:	ac62c2d0 	sw	v0,-15664(v1)
  611d38:	8fbf001c 	lw	ra,28(sp)
  611d3c:	02001021 	move	v0,s0
  611d40:	8fb00018 	lw	s0,24(sp)
  611d44:	03e00008 	jr	ra
  611d48:	27bd0020 	addiu	sp,sp,32
  611d4c:	3c020075 	lui	v0,0x75
  611d50:	8c42fe84 	lw	v0,-380(v0)
  611d54:	1040fff8 	beqz	v0,0x611d38
  611d58:	2410ffff 	li	s0,-1
  611d5c:	3c040070 	lui	a0,0x70
  611d60:	3c050070 	lui	a1,0x70
  611d64:	2484c014 	addiu	a0,a0,-16364
  611d68:	24a54d9c 	addiu	a1,a1,19868
  611d6c:	240608c3 	li	a2,2243
  611d70:	0c101b74 	jal	0x406dd0
  611d74:	00000000 	nop
  611d78:	0818474f 	j	0x611d3c
  611d7c:	8fbf001c 	lw	ra,28(sp)
  611d80:	3c020075 	lui	v0,0x75
  611d84:	8c42fe84 	lw	v0,-380(v0)
  611d88:	1040ffeb 	beqz	v0,0x611d38
  611d8c:	2410ffff 	li	s0,-1
  611d90:	3c040070 	lui	a0,0x70
  611d94:	3c050070 	lui	a1,0x70
  611d98:	24844b10 	addiu	a0,a0,19216
  611d9c:	24a54d9c 	addiu	a1,a1,19868
  611da0:	0818475c 	j	0x611d70
  611da4:	240608cb 	li	a2,2251

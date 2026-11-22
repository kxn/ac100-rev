; func apmngr_db_fini @ 0x00541d0c size=0xe0
  541d0c:	27bdffe0 	addiu	sp,sp,-32
  541d10:	afb00018 	sw	s0,24(sp)
  541d14:	3c10007c 	lui	s0,0x7c
  541d18:	afbf001c 	sw	ra,28(sp)
  541d1c:	8e045868 	lw	a0,22632(s0)
  541d20:	50800005 	beqzl	a0,0x541d38
  541d24:	3c10007c 	lui	s0,0x7c
  541d28:	0c102058 	jal	0x408160
  541d2c:	00000000 	nop
  541d30:	ae005868 	sw	zero,22632(s0)
  541d34:	3c10007c 	lui	s0,0x7c
  541d38:	8e045864 	lw	a0,22628(s0)
  541d3c:	50800005 	beqzl	a0,0x541d54
  541d40:	3c10007c 	lui	s0,0x7c
  541d44:	0c102058 	jal	0x408160
  541d48:	00000000 	nop
  541d4c:	ae005864 	sw	zero,22628(s0)
  541d50:	3c10007c 	lui	s0,0x7c
  541d54:	8e04587c 	lw	a0,22652(s0)
  541d58:	50800005 	beqzl	a0,0x541d70
  541d5c:	3c10007c 	lui	s0,0x7c
  541d60:	0c101f7c 	jal	0x407df0
  541d64:	00000000 	nop
  541d68:	ae00587c 	sw	zero,22652(s0)
  541d6c:	3c10007c 	lui	s0,0x7c
  541d70:	8e045874 	lw	a0,22644(s0)
  541d74:	50800005 	beqzl	a0,0x541d8c
  541d78:	3c10007c 	lui	s0,0x7c
  541d7c:	0c1020d8 	jal	0x408360
  541d80:	00000000 	nop
  541d84:	ae005874 	sw	zero,22644(s0)
  541d88:	3c10007c 	lui	s0,0x7c
  541d8c:	8e045894 	lw	a0,22676(s0)
  541d90:	50800005 	beqzl	a0,0x541da8
  541d94:	3c10007c 	lui	s0,0x7c
  541d98:	0c101f7c 	jal	0x407df0
  541d9c:	00000000 	nop
  541da0:	ae005894 	sw	zero,22676(s0)
  541da4:	3c10007c 	lui	s0,0x7c
  541da8:	8e0458a4 	lw	a0,22692(s0)
  541dac:	50800005 	beqzl	a0,0x541dc4
  541db0:	3c10007c 	lui	s0,0x7c
  541db4:	0c1020c4 	jal	0x408310
  541db8:	00000000 	nop
  541dbc:	ae0058a4 	sw	zero,22692(s0)
  541dc0:	3c10007c 	lui	s0,0x7c
  541dc4:	8e0458b8 	lw	a0,22712(s0)
  541dc8:	10800005 	beqz	a0,0x541de0
  541dcc:	8fbf001c 	lw	ra,28(sp)
  541dd0:	0c1020c4 	jal	0x408310
  541dd4:	00000000 	nop
  541dd8:	ae0058b8 	sw	zero,22712(s0)
  541ddc:	8fbf001c 	lw	ra,28(sp)
  541de0:	8fb00018 	lw	s0,24(sp)
  541de4:	03e00008 	jr	ra
  541de8:	27bd0020 	addiu	sp,sp,32

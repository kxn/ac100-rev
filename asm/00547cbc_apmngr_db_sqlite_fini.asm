; func apmngr_db_sqlite_fini @ 0x00547cbc size=0x12c
  547cbc:	27bdffd8 	addiu	sp,sp,-40
  547cc0:	afb10020 	sw	s1,32(sp)
  547cc4:	3c11007c 	lui	s1,0x7c
  547cc8:	afbf0024 	sw	ra,36(sp)
  547ccc:	afb0001c 	sw	s0,28(sp)
  547cd0:	8e225908 	lw	v0,22792(s1)
  547cd4:	1440002c 	bnez	v0,0x547d88
  547cd8:	3c02007c 	lui	v0,0x7c
  547cdc:	3c10007c 	lui	s0,0x7c
  547ce0:	8e0458e4 	lw	a0,22756(s0)
  547ce4:	50800005 	beqzl	a0,0x547cfc
  547ce8:	261058e4 	addiu	s0,s0,22756
  547cec:	0c10202c 	jal	0x4080b0
  547cf0:	00000000 	nop
  547cf4:	ae0058e4 	sw	zero,22756(s0)
  547cf8:	261058e4 	addiu	s0,s0,22756
  547cfc:	8e040004 	lw	a0,4(s0)
  547d00:	10800005 	beqz	a0,0x547d18
  547d04:	3c02007c 	lui	v0,0x7c
  547d08:	0c10202c 	jal	0x4080b0
  547d0c:	00000000 	nop
  547d10:	ae000004 	sw	zero,4(s0)
  547d14:	3c02007c 	lui	v0,0x7c
  547d18:	8c4458ec 	lw	a0,22764(v0)
  547d1c:	10800004 	beqz	a0,0x547d30
  547d20:	3c02007c 	lui	v0,0x7c
  547d24:	0c1020d8 	jal	0x408360
  547d28:	00000000 	nop
  547d2c:	3c02007c 	lui	v0,0x7c
  547d30:	8c445900 	lw	a0,22784(v0)
  547d34:	10800003 	beqz	a0,0x547d44
  547d38:	3c11007c 	lui	s1,0x7c
  547d3c:	0c102088 	jal	0x408220
  547d40:	00000000 	nop
  547d44:	08151f59 	j	0x547d64
  547d48:	263158f4 	addiu	s1,s1,22772
  547d4c:	0c102140 	jal	0x408500
  547d50:	02002021 	move	a0,s0
  547d54:	0c101f7c 	jal	0x407df0
  547d58:	8e040010 	lw	a0,16(s0)
  547d5c:	0c101f7c 	jal	0x407df0
  547d60:	02002021 	move	a0,s0
  547d64:	0c10206c 	jal	0x4081b0
  547d68:	02202021 	move	a0,s1
  547d6c:	1440fff7 	bnez	v0,0x547d4c
  547d70:	00408021 	move	s0,v0
  547d74:	8fbf0024 	lw	ra,36(sp)
  547d78:	8fb10020 	lw	s1,32(sp)
  547d7c:	8fb0001c 	lw	s0,28(sp)
  547d80:	03e00008 	jr	ra
  547d84:	27bd0028 	addiu	sp,sp,40
  547d88:	24050003 	li	a1,3
  547d8c:	0c101da0 	jal	0x407680
  547d90:	8c445904 	lw	a0,22788(v0)
  547d94:	10400005 	beqz	v0,0x547dac
  547d98:	00408021 	move	s0,v0
  547d9c:	3c020075 	lui	v0,0x75
  547da0:	8042bea4 	lb	v0,-16732(v0)
  547da4:	14400003 	bnez	v0,0x547db4
  547da8:	00000000 	nop
  547dac:	08151f37 	j	0x547cdc
  547db0:	ae205908 	sw	zero,22792(s1)
  547db4:	0c16276a 	jal	0x589da8
  547db8:	00000000 	nop
  547dbc:	5040ffc7 	beqzl	v0,0x547cdc
  547dc0:	ae205908 	sw	zero,22792(s1)
  547dc4:	3c04006d 	lui	a0,0x6d
  547dc8:	3c05006d 	lui	a1,0x6d
  547dcc:	2484ce78 	addiu	a0,a0,-12680
  547dd0:	24a5d618 	addiu	a1,a1,-10728
  547dd4:	24060660 	li	a2,1632
  547dd8:	0c101b74 	jal	0x406dd0
  547ddc:	02003821 	move	a3,s0
  547de0:	08151f37 	j	0x547cdc
  547de4:	ae205908 	sw	zero,22792(s1)

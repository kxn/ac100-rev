; func _uac_wserv_igmp_query_switch_to_ap @ 0x005ddf30 size=0x194
  5ddf30:	27bdffb0 	addiu	sp,sp,-80
  5ddf34:	afb00048 	sw	s0,72(sp)
  5ddf38:	00808021 	move	s0,a0
  5ddf3c:	afa40038 	sw	a0,56(sp)
  5ddf40:	27a4003c 	addiu	a0,sp,60
  5ddf44:	afbf004c 	sw	ra,76(sp)
  5ddf48:	afa0003c 	sw	zero,60(sp)
  5ddf4c:	afa00040 	sw	zero,64(sp)
  5ddf50:	0c146b62 	jal	0x51ad88
  5ddf54:	afa00044 	sw	zero,68(sp)
  5ddf58:	3c05005d 	lui	a1,0x5d
  5ddf5c:	27a60038 	addiu	a2,sp,56
  5ddf60:	24a57b64 	addiu	a1,a1,31588
  5ddf64:	0c1776e8 	jal	0x5ddba0
  5ddf68:	02002021 	move	a0,s0
  5ddf6c:	27a40028 	addiu	a0,sp,40
  5ddf70:	afa00028 	sw	zero,40(sp)
  5ddf74:	afa0002c 	sw	zero,44(sp)
  5ddf78:	afa00030 	sw	zero,48(sp)
  5ddf7c:	0c16683d 	jal	0x59a0f4
  5ddf80:	afa00034 	sw	zero,52(sp)
  5ddf84:	10400011 	beqz	v0,0x5ddfcc
  5ddf88:	3c02015f 	lui	v0,0x15f
  5ddf8c:	0c166906 	jal	0x59a418
  5ddf90:	27a40028 	addiu	a0,sp,40
  5ddf94:	081777eb 	j	0x5ddfac
  5ddf98:	00000000 	nop
  5ddf9c:	0c102140 	jal	0x408500
  5ddfa0:	02002021 	move	a0,s0
  5ddfa4:	0c101f7c 	jal	0x407df0
  5ddfa8:	02002021 	move	a0,s0
  5ddfac:	0c10206c 	jal	0x4081b0
  5ddfb0:	27a4003c 	addiu	a0,sp,60
  5ddfb4:	1440fff9 	bnez	v0,0x5ddf9c
  5ddfb8:	00408021 	move	s0,v0
  5ddfbc:	8fbf004c 	lw	ra,76(sp)
  5ddfc0:	8fb00048 	lw	s0,72(sp)
  5ddfc4:	03e00008 	jr	ra
  5ddfc8:	27bd0050 	addiu	sp,sp,80
  5ddfcc:	27a50028 	addiu	a1,sp,40
  5ddfd0:	afa20010 	sw	v0,16(sp)
  5ddfd4:	24020001 	li	v0,1
  5ddfd8:	24060001 	li	a2,1
  5ddfdc:	afa20014 	sw	v0,20(sp)
  5ddfe0:	24070001 	li	a3,1
  5ddfe4:	2402002b 	li	v0,43
  5ddfe8:	3204ffff 	andi	a0,s0,0xffff
  5ddfec:	0c14da0a 	jal	0x536828
  5ddff0:	afa20018 	sw	v0,24(sp)
  5ddff4:	14400013 	bnez	v0,0x5de044
  5ddff8:	3c02007d 	lui	v0,0x7d
  5ddffc:	8fa20030 	lw	v0,48(sp)
  5de000:	1440001f 	bnez	v0,0x5de080
  5de004:	3c02007d 	lui	v0,0x7d
  5de008:	8c42bee4 	lw	v0,-16668(v0)
  5de00c:	1040ffdf 	beqz	v0,0x5ddf8c
  5de010:	00000000 	nop
  5de014:	0c16276a 	jal	0x589da8
  5de018:	00000000 	nop
  5de01c:	1040ffdb 	beqz	v0,0x5ddf8c
  5de020:	3c04006f 	lui	a0,0x6f
  5de024:	3c05006f 	lui	a1,0x6f
  5de028:	24843590 	addiu	a0,a0,13712
  5de02c:	24a56fc0 	addiu	a1,a1,28608
  5de030:	24061351 	li	a2,4945
  5de034:	0c101b74 	jal	0x406dd0
  5de038:	02003821 	move	a3,s0
  5de03c:	081777e3 	j	0x5ddf8c
  5de040:	00000000 	nop
  5de044:	8c42bee0 	lw	v0,-16672(v0)
  5de048:	1040ffd0 	beqz	v0,0x5ddf8c
  5de04c:	00000000 	nop
  5de050:	0c16276a 	jal	0x589da8
  5de054:	00000000 	nop
  5de058:	1040ffcc 	beqz	v0,0x5ddf8c
  5de05c:	3c04006f 	lui	a0,0x6f
  5de060:	3c05006f 	lui	a1,0x6f
  5de064:	24845568 	addiu	a0,a0,21864
  5de068:	24a56fc0 	addiu	a1,a1,28608
  5de06c:	2406134c 	li	a2,4940
  5de070:	0c101b74 	jal	0x406dd0
  5de074:	00000000 	nop
  5de078:	081777e3 	j	0x5ddf8c
  5de07c:	00000000 	nop
  5de080:	27a40028 	addiu	a0,sp,40
  5de084:	0c17a187 	jal	0x5e861c
  5de088:	27a50038 	addiu	a1,sp,56
  5de08c:	1040ffbf 	beqz	v0,0x5ddf8c
  5de090:	3c020075 	lui	v0,0x75
  5de094:	8c42fe70 	lw	v0,-400(v0)
  5de098:	1040ffbc 	beqz	v0,0x5ddf8c
  5de09c:	00000000 	nop
  5de0a0:	0c16276a 	jal	0x589da8
  5de0a4:	00000000 	nop
  5de0a8:	1040ffb8 	beqz	v0,0x5ddf8c
  5de0ac:	3c04006f 	lui	a0,0x6f
  5de0b0:	3c05006f 	lui	a1,0x6f
  5de0b4:	248455a4 	addiu	a0,a0,21924
  5de0b8:	24a56fc0 	addiu	a1,a1,28608
  5de0bc:	0817781c 	j	0x5de070
  5de0c0:	24061356 	li	a2,4950

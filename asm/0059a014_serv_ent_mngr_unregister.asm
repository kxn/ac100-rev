; func serv_ent_mngr_unregister @ 0x0059a014 size=0xb4
  59a014:	27bdffd8 	addiu	sp,sp,-40
  59a018:	3084ffff 	andi	a0,a0,0xffff
  59a01c:	2c830004 	sltiu	v1,a0,4
  59a020:	afb20020 	sw	s2,32(sp)
  59a024:	2402ffff 	li	v0,-1
  59a028:	afb1001c 	sw	s1,28(sp)
  59a02c:	30b2ffff 	andi	s2,a1,0xffff
  59a030:	afbf0024 	sw	ra,36(sp)
  59a034:	00c08821 	move	s1,a2
  59a038:	10600017 	beqz	v1,0x59a098
  59a03c:	afb00018 	sw	s0,24(sp)
  59a040:	3c03007c 	lui	v1,0x7c
  59a044:	00042080 	sll	a0,a0,0x2
  59a048:	246359c0 	addiu	v1,v1,22976
  59a04c:	00832021 	addu	a0,a0,v1
  59a050:	8c840000 	lw	a0,0(a0)
  59a054:	10800011 	beqz	a0,0x59a09c
  59a058:	8fbf0024 	lw	ra,36(sp)
  59a05c:	0c10206c 	jal	0x4081b0
  59a060:	24840004 	addiu	a0,a0,4
  59a064:	08166823 	j	0x59a08c
  59a068:	00000000 	nop
  59a06c:	9602000c 	lhu	v0,12(s0)
  59a070:	14520004 	bne	v0,s2,0x59a084
  59a074:	02002021 	move	a0,s0
  59a078:	8e020010 	lw	v0,16(s0)
  59a07c:	1051000c 	beq	v0,s1,0x59a0b0
  59a080:	00000000 	nop
  59a084:	0c1021a0 	jal	0x408680
  59a088:	00000000 	nop
  59a08c:	1440fff7 	bnez	v0,0x59a06c
  59a090:	00408021 	move	s0,v0
  59a094:	00001021 	move	v0,zero
  59a098:	8fbf0024 	lw	ra,36(sp)
  59a09c:	8fb20020 	lw	s2,32(sp)
  59a0a0:	8fb1001c 	lw	s1,28(sp)
  59a0a4:	8fb00018 	lw	s0,24(sp)
  59a0a8:	03e00008 	jr	ra
  59a0ac:	27bd0028 	addiu	sp,sp,40
  59a0b0:	0c102140 	jal	0x408500
  59a0b4:	00000000 	nop
  59a0b8:	0c101f7c 	jal	0x407df0
  59a0bc:	02002021 	move	a0,s0
  59a0c0:	08166826 	j	0x59a098
  59a0c4:	00001021 	move	v0,zero

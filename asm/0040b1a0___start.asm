; func __start @ 0x0040b1a0 size=0x50
  40b1a0:	3c1c0076 	lui	gp,0x76
  40b1a4:	279c1100 	addiu	gp,gp,4352
  40b1a8:	0000f821 	move	ra,zero
  40b1ac:	3c040041 	lui	a0,0x41
  40b1b0:	2484a2c0 	addiu	a0,a0,-23872
  40b1b4:	8fa50000 	lw	a1,0(sp)
  40b1b8:	27a60004 	addiu	a2,sp,4
  40b1bc:	2401fff8 	li	at,-8
  40b1c0:	03a1e824 	and	sp,sp,at
  40b1c4:	27bdffe0 	addiu	sp,sp,-32
  40b1c8:	3c070040 	lui	a3,0x40
  40b1cc:	24e76d58 	addiu	a3,a3,27992
  40b1d0:	3c080067 	lui	t0,0x67
  40b1d4:	250854d0 	addiu	t0,t0,21712
  40b1d8:	afa80010 	sw	t0,16(sp)
  40b1dc:	afa20014 	sw	v0,20(sp)
  40b1e0:	0c101eb4 	jal	0x407ad0
  40b1e4:	afbd0018 	sw	sp,24(sp)
  40b1e8:	1000ffff 	b	0x40b1e8
  40b1ec:	00000000 	nop
  40b1f0:	27bdffd0 	addiu	sp,sp,-48
  40b1f4:	afb30028 	sw	s3,40(sp)
  40b1f8:	3c130076 	lui	s3,0x76
  40b1fc:	afbf002c 	sw	ra,44(sp)
  40b200:	afb20024 	sw	s2,36(sp)
  40b204:	afb10020 	sw	s1,32(sp)
  40b208:	afb0001c 	sw	s0,28(sp)
  40b20c:	92629930 	lbu	v0,-26320(s3)
  40b210:	14400015 	bnez	v0,0x40b268
  40b214:	3c120073 	lui	s2,0x73
  40b218:	3c110073 	lui	s1,0x73
  40b21c:	26521170 	addiu	s2,s2,4464
  40b220:	26311174 	addiu	s1,s1,4468
  40b224:	3c100076 	lui	s0,0x76
  40b228:	02328823 	subu	s1,s1,s2
  40b22c:	00118883 	sra	s1,s1,0x2
  40b230:	08102c94 	j	0x40b250
  40b234:	2631ffff 	addiu	s1,s1,-1
  40b238:	ae029934 	sw	v0,-26316(s0)
  40b23c:	00021080 	sll	v0,v0,0x2
  40b240:	00521021 	addu	v0,v0,s2
  40b244:	8c590000 	lw	t9,0(v0)
  40b248:	0320f809 	jalr	t9
  40b24c:	00000000 	nop
  40b250:	8e029934 	lw	v0,-26316(s0)
  40b254:	0051182b 	sltu	v1,v0,s1
  40b258:	1460fff7 	bnez	v1,0x40b238
  40b25c:	24420001 	addiu	v0,v0,1
  40b260:	24020001 	li	v0,1
  40b264:	a2629930 	sb	v0,-26320(s3)
  40b268:	8fbf002c 	lw	ra,44(sp)
  40b26c:	8fb30028 	lw	s3,40(sp)
  40b270:	8fb20024 	lw	s2,36(sp)
  40b274:	8fb10020 	lw	s1,32(sp)
  40b278:	8fb0001c 	lw	s0,28(sp)
  40b27c:	03e00008 	jr	ra
  40b280:	27bd0030 	addiu	sp,sp,48
  40b284:	3c040073 	lui	a0,0x73
  40b288:	8c821178 	lw	v0,4472(a0)
  40b28c:	10400007 	beqz	v0,0x40b2ac
  40b290:	00000000 	nop
  40b294:	3c190000 	lui	t9,0x0
  40b298:	27390000 	addiu	t9,t9,0
  40b29c:	13200003 	beqz	t9,0x40b2ac
  40b2a0:	00000000 	nop
  40b2a4:	03200008 	jr	t9
  40b2a8:	24841178 	addiu	a0,a0,4472
  40b2ac:	03e00008 	jr	ra
  40b2b0:	00000000 	nop
	...

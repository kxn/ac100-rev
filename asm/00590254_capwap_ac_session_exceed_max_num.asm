; func capwap_ac_session_exceed_max_num @ 0x00590254 size=0x68
  590254:	27bdffd8 	addiu	sp,sp,-40
  590258:	2405ffff 	li	a1,-1
  59025c:	afb0001c 	sw	s0,28(sp)
  590260:	3c10007c 	lui	s0,0x7c
  590264:	afb10020 	sw	s1,32(sp)
  590268:	00808821 	move	s1,a0
  59026c:	afbf0024 	sw	ra,36(sp)
  590270:	0c1020b4 	jal	0x4082d0
  590274:	8e0459a0 	lw	a0,22944(s0)
  590278:	3c02007c 	lui	v0,0x7c
  59027c:	8c4259a4 	lw	v0,22948(v0)
  590280:	0051882a 	slt	s1,v0,s1
  590284:	12200009 	beqz	s1,0x5902ac
  590288:	8e0459a0 	lw	a0,22944(s0)
  59028c:	0c101fcc 	jal	0x407f30
  590290:	00000000 	nop
  590294:	00001021 	move	v0,zero
  590298:	8fbf0024 	lw	ra,36(sp)
  59029c:	8fb10020 	lw	s1,32(sp)
  5902a0:	8fb0001c 	lw	s0,28(sp)
  5902a4:	03e00008 	jr	ra
  5902a8:	27bd0028 	addiu	sp,sp,40
  5902ac:	0c101fcc 	jal	0x407f30
  5902b0:	00000000 	nop
  5902b4:	081640a6 	j	0x590298
  5902b8:	24020001 	li	v0,1

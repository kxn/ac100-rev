; func balance_thread_callback @ 0x0045aaf8 size=0x58
  45aaf8:	27bdffd8 	addiu	sp,sp,-40
  45aafc:	afb20020 	sw	s2,32(sp)
  45ab00:	3c120046 	lui	s2,0x46
  45ab04:	afb1001c 	sw	s1,28(sp)
  45ab08:	3c110076 	lui	s1,0x76
  45ab0c:	afb00018 	sw	s0,24(sp)
  45ab10:	2652b128 	addiu	s2,s2,-20184
  45ab14:	3c100076 	lui	s0,0x76
  45ab18:	afbf0024 	sw	ra,36(sp)
  45ab1c:	0c101ec4 	jal	0x407b10
  45ab20:	2404012c 	li	a0,300
  45ab24:	2405ffff 	li	a1,-1
  45ab28:	0c1020b4 	jal	0x4082d0
  45ab2c:	8e047040 	lw	a0,28736(s0)
  45ab30:	00003021 	move	a2,zero
  45ab34:	8e24704c 	lw	a0,28748(s1)
  45ab38:	0c10215c 	jal	0x408570
  45ab3c:	02402821 	move	a1,s2
  45ab40:	0c101fcc 	jal	0x407f30
  45ab44:	8e047040 	lw	a0,28736(s0)
  45ab48:	08116ac7 	j	0x45ab1c
  45ab4c:	00000000 	nop

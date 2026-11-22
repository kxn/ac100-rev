; func uac_nms_report_msg_thread @ 0x0049d670 size=0xd4
  49d670:	27bdffc0 	addiu	sp,sp,-64
  49d674:	afb1002c 	sw	s1,44(sp)
  49d678:	3c110076 	lui	s1,0x76
  49d67c:	afb20030 	sw	s2,48(sp)
  49d680:	27b20018 	addiu	s2,sp,24
  49d684:	afb40038 	sw	s4,56(sp)
  49d688:	26317904 	addiu	s1,s1,30980
  49d68c:	afb30034 	sw	s3,52(sp)
  49d690:	3c140076 	lui	s4,0x76
  49d694:	3c130076 	lui	s3,0x76
  49d698:	afbf003c 	sw	ra,60(sp)
  49d69c:	02402021 	move	a0,s2
  49d6a0:	afb00028 	sw	s0,40(sp)
  49d6a4:	afa00018 	sw	zero,24(sp)
  49d6a8:	afa0001c 	sw	zero,28(sp)
  49d6ac:	0c146b62 	jal	0x51ad88
  49d6b0:	afa00020 	sw	zero,32(sp)
  49d6b4:	8e647900 	lw	a0,30976(s3)
  49d6b8:	2405ffff 	li	a1,-1
  49d6bc:	0c1020b4 	jal	0x4082d0
  49d6c0:	3c100076 	lui	s0,0x76
  49d6c4:	081275b6 	j	0x49d6d8
  49d6c8:	00000000 	nop
  49d6cc:	2406ffff 	li	a2,-1
  49d6d0:	0c1021b0 	jal	0x4086c0
  49d6d4:	8e057900 	lw	a1,30976(s0)
  49d6d8:	0c10206c 	jal	0x4081b0
  49d6dc:	02202021 	move	a0,s1
  49d6e0:	5040fffa 	beqzl	v0,0x49d6cc
  49d6e4:	8e847910 	lw	a0,30992(s4)
  49d6e8:	02402021 	move	a0,s2
  49d6ec:	0c1020b0 	jal	0x4082c0
  49d6f0:	02202821 	move	a1,s1
  49d6f4:	0c101fcc 	jal	0x407f30
  49d6f8:	8e047900 	lw	a0,30976(s0)
  49d6fc:	0c10206c 	jal	0x4081b0
  49d700:	02402021 	move	a0,s2
  49d704:	1040ffeb 	beqz	v0,0x49d6b4
  49d708:	00408021 	move	s0,v0
  49d70c:	0c102140 	jal	0x408500
  49d710:	02002021 	move	a0,s0
  49d714:	8e040010 	lw	a0,16(s0)
  49d718:	10800006 	beqz	a0,0x49d734
  49d71c:	00000000 	nop
  49d720:	0c127588 	jal	0x49d620
  49d724:	00000000 	nop
  49d728:	0c101f7c 	jal	0x407df0
  49d72c:	8e040010 	lw	a0,16(s0)
  49d730:	ae000010 	sw	zero,16(s0)
  49d734:	0c101f7c 	jal	0x407df0
  49d738:	02002021 	move	a0,s0
  49d73c:	081275bf 	j	0x49d6fc
  49d740:	00000000 	nop

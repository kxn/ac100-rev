; func apmngr_global_status_set @ 0x0052e6f4 size=0xe4
  52e6f4:	3c020075 	lui	v0,0x75
  52e6f8:	27bdffe0 	addiu	sp,sp,-32
  52e6fc:	8c43bef4 	lw	v1,-16652(v0)
  52e700:	afbf001c 	sw	ra,28(sp)
  52e704:	10830017 	beq	a0,v1,0x52e764
  52e708:	afb00018 	sw	s0,24(sp)
  52e70c:	ac44bef4 	sw	a0,-16652(v0)
  52e710:	10800009 	beqz	a0,0x52e738
  52e714:	3c10007c 	lui	s0,0x7c
  52e718:	0c162c40 	jal	0x58b100
  52e71c:	00000000 	nop
  52e720:	82025482 	lb	v0,21634(s0)
  52e724:	14400014 	bnez	v0,0x52e778
  52e728:	8fbf001c 	lw	ra,28(sp)
  52e72c:	8fb00018 	lw	s0,24(sp)
  52e730:	08162be0 	j	0x58af80
  52e734:	27bd0020 	addiu	sp,sp,32
  52e738:	24040001 	li	a0,1
  52e73c:	0c14b935 	jal	0x52e4d4
  52e740:	00002821 	move	a1,zero
  52e744:	0c162c57 	jal	0x58b15c
  52e748:	00000000 	nop
  52e74c:	82025482 	lb	v0,21634(s0)
  52e750:	14400015 	bnez	v0,0x52e7a8
  52e754:	8fbf001c 	lw	ra,28(sp)
  52e758:	8fb00018 	lw	s0,24(sp)
  52e75c:	08162c13 	j	0x58b04c
  52e760:	27bd0020 	addiu	sp,sp,32
  52e764:	8fbf001c 	lw	ra,28(sp)
  52e768:	00001021 	move	v0,zero
  52e76c:	8fb00018 	lw	s0,24(sp)
  52e770:	03e00008 	jr	ra
  52e774:	27bd0020 	addiu	sp,sp,32
  52e778:	0c16276a 	jal	0x589da8
  52e77c:	00000000 	nop
  52e780:	1040ffea 	beqz	v0,0x52e72c
  52e784:	8fbf001c 	lw	ra,28(sp)
  52e788:	3c04006c 	lui	a0,0x6c
  52e78c:	3c05006c 	lui	a1,0x6c
  52e790:	248464c0 	addiu	a0,a0,25792
  52e794:	24a5792c 	addiu	a1,a1,31020
  52e798:	0c101b74 	jal	0x406dd0
  52e79c:	240602f5 	li	a2,757
  52e7a0:	0814b9cb 	j	0x52e72c
  52e7a4:	8fbf001c 	lw	ra,28(sp)
  52e7a8:	0c16276a 	jal	0x589da8
  52e7ac:	00000000 	nop
  52e7b0:	1040ffe9 	beqz	v0,0x52e758
  52e7b4:	8fbf001c 	lw	ra,28(sp)
  52e7b8:	3c04006c 	lui	a0,0x6c
  52e7bc:	3c05006c 	lui	a1,0x6c
  52e7c0:	248464fc 	addiu	a0,a0,25852
  52e7c4:	24a5792c 	addiu	a1,a1,31020
  52e7c8:	0c101b74 	jal	0x406dd0
  52e7cc:	240602fe 	li	a2,766
  52e7d0:	0814b9d6 	j	0x52e758
  52e7d4:	8fbf001c 	lw	ra,28(sp)

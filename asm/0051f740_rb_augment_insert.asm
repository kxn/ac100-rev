; func rb_augment_insert @ 0x0051f740 size=0x34
  51f740:	3c1c0024 	lui	gp,0x24
  51f744:	279c19c0 	addiu	gp,gp,6592
  51f748:	0399e021 	addu	gp,gp,t9
  51f74c:	8c820008 	lw	v0,8(a0)
  51f750:	50400006 	beqzl	v0,0x51f76c
  51f754:	8c820004 	lw	v0,4(a0)
  51f758:	00402021 	move	a0,v0
  51f75c:	8f9982f8 	lw	t9,-32008(gp)
  51f760:	2739f0c8 	addiu	t9,t9,-3896
  51f764:	1000fe58 	b	0x51f0c8
  51f768:	00000000 	nop
  51f76c:	1000fffb 	b	0x51f75c
  51f770:	0042200b 	movn	a0,v0,v0

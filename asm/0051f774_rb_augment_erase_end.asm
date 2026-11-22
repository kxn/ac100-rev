; func rb_augment_erase_end @ 0x0051f774 size=0x2c
  51f774:	3c1c0024 	lui	gp,0x24
  51f778:	279c198c 	addiu	gp,gp,6540
  51f77c:	0399e021 	addu	gp,gp,t9
  51f780:	10800005 	beqz	a0,0x51f798
  51f784:	00000000 	nop
  51f788:	8f9982f8 	lw	t9,-32008(gp)
  51f78c:	2739f0c8 	addiu	t9,t9,-3896
  51f790:	1000fe4d 	b	0x51f0c8
  51f794:	00000000 	nop
  51f798:	03e00008 	jr	ra
  51f79c:	00000000 	nop

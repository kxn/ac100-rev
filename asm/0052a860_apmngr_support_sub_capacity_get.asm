; func apmngr_support_sub_capacity_get @ 0x0052a860 size=0x38
  52a860:	00801021 	move	v0,a0
  52a864:	1040000a 	beqz	v0,0x52a890
  52a868:	00a02021 	move	a0,a1
  52a86c:	10a00008 	beqz	a1,0x52a890
  52a870:	00000000 	nop
  52a874:	3c03007c 	lui	v1,0x7c
  52a878:	3c05007c 	lui	a1,0x7c
  52a87c:	94665494 	lhu	a2,21652(v1)
  52a880:	24a55498 	addiu	a1,a1,21656
  52a884:	a4460000 	sh	a2,0(v0)
  52a888:	08101c8c 	j	0x407230
  52a88c:	000630c0 	sll	a2,a2,0x3
  52a890:	03e00008 	jr	ra
  52a894:	00000000 	nop

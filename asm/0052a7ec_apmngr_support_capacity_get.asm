; func apmngr_support_capacity_get @ 0x0052a7ec size=0x2c
  52a7ec:	18a00008 	blez	a1,0x52a810
  52a7f0:	00000000 	nop
  52a7f4:	24060004 	li	a2,4
  52a7f8:	28a20005 	slti	v0,a1,5
  52a7fc:	00a2300b 	movn	a2,a1,v0
  52a800:	3c05007c 	lui	a1,0x7c
  52a804:	24a55484 	addiu	a1,a1,21636
  52a808:	08101c8c 	j	0x407230
  52a80c:	00063080 	sll	a2,a2,0x2
  52a810:	03e00008 	jr	ra
  52a814:	00000000 	nop

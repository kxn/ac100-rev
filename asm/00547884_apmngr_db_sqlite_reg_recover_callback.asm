; func apmngr_db_sqlite_reg_recover_callback @ 0x00547884 size=0x1c
  547884:	2402000c 	li	v0,12
  547888:	3c030075 	lui	v1,0x75
  54788c:	70821002 	mul	v0,a0,v0
  547890:	2463c0a0 	addiu	v1,v1,-16224
  547894:	00431021 	addu	v0,v0,v1
  547898:	03e00008 	jr	ra
  54789c:	ac450008 	sw	a1,8(v0)

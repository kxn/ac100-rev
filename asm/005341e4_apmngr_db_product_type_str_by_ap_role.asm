; func apmngr_db_product_type_str_by_ap_role @ 0x005341e4 size=0x2c
  5341e4:	2c820009 	sltiu	v0,a0,9
  5341e8:	10400006 	beqz	v0,0x534204
  5341ec:	00042080 	sll	a0,a0,0x2
  5341f0:	3c02006d 	lui	v0,0x6d
  5341f4:	24429ce8 	addiu	v0,v0,-25368
  5341f8:	00822021 	addu	a0,a0,v0
  5341fc:	03e00008 	jr	ra
  534200:	8c820000 	lw	v0,0(a0)
  534204:	3c020071 	lui	v0,0x71
  534208:	03e00008 	jr	ra
  53420c:	24424854 	addiu	v0,v0,18516

; func apmngr_db_product_type_str @ 0x005341b8 size=0x2c
  5341b8:	2c820004 	sltiu	v0,a0,4
  5341bc:	10400006 	beqz	v0,0x5341d8
  5341c0:	00042080 	sll	a0,a0,0x2
  5341c4:	3c02006d 	lui	v0,0x6d
  5341c8:	24429cd8 	addiu	v0,v0,-25384
  5341cc:	00822021 	addu	a0,a0,v0
  5341d0:	03e00008 	jr	ra
  5341d4:	8c820000 	lw	v0,0(a0)
  5341d8:	3c020071 	lui	v0,0x71
  5341dc:	03e00008 	jr	ra
  5341e0:	24424854 	addiu	v0,v0,18516

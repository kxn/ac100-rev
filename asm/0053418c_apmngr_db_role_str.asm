; func apmngr_db_role_str @ 0x0053418c size=0x2c
  53418c:	2c820009 	sltiu	v0,a0,9
  534190:	10400006 	beqz	v0,0x5341ac
  534194:	00042080 	sll	a0,a0,0x2
  534198:	3c02006d 	lui	v0,0x6d
  53419c:	24429cb4 	addiu	v0,v0,-25420
  5341a0:	00822021 	addu	a0,a0,v0
  5341a4:	03e00008 	jr	ra
  5341a8:	8c820000 	lw	v0,0(a0)
  5341ac:	3c020069 	lui	v0,0x69
  5341b0:	03e00008 	jr	ra
  5341b4:	24428af8 	addiu	v0,v0,-29960

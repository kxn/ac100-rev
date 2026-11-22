; func apmngr_db_is_template_exceed @ 0x005414b0 size=0x1c
  5414b0:	3c02007c 	lui	v0,0x7c
  5414b4:	944358bc 	lhu	v1,22716(v0)
  5414b8:	3c02007c 	lui	v0,0x7c
  5414bc:	8c425880 	lw	v0,22656(v0)
  5414c0:	0062102a 	slt	v0,v1,v0
  5414c4:	03e00008 	jr	ra
  5414c8:	38420001 	xori	v0,v0,0x1

; func audit_client_db_is_server_enable @ 0x0050a03c size=0x14
  50a03c:	3c020077 	lui	v0,0x77
  50a040:	8c4288e0 	lw	v0,-30496(v0)
  50a044:	38420001 	xori	v0,v0,0x1
  50a048:	03e00008 	jr	ra
  50a04c:	2c420001 	sltiu	v0,v0,1

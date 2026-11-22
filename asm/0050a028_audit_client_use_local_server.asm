; func audit_client_use_local_server @ 0x0050a028 size=0x14
  50a028:	3c020077 	lui	v0,0x77
  50a02c:	8c4288f8 	lw	v0,-30472(v0)
  50a030:	38420001 	xori	v0,v0,0x1
  50a034:	03e00008 	jr	ra
  50a038:	2c420001 	sltiu	v0,v0,1

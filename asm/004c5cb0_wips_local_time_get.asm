; func wips_local_time_get @ 0x004c5cb0 size=0x34
  4c5cb0:	27bdffb0 	addiu	sp,sp,-80
  4c5cb4:	afbf004c 	sw	ra,76(sp)
  4c5cb8:	0c101e38 	jal	0x4078e0
  4c5cbc:	00002021 	move	a0,zero
  4c5cc0:	27a5001c 	addiu	a1,sp,28
  4c5cc4:	27a40018 	addiu	a0,sp,24
  4c5cc8:	0c101f20 	jal	0x407c80
  4c5ccc:	afa20018 	sw	v0,24(sp)
  4c5cd0:	0c101cc0 	jal	0x407300
  4c5cd4:	27a4001c 	addiu	a0,sp,28
  4c5cd8:	8fbf004c 	lw	ra,76(sp)
  4c5cdc:	03e00008 	jr	ra
  4c5ce0:	27bd0050 	addiu	sp,sp,80

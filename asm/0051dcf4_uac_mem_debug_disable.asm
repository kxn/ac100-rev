; func uac_mem_debug_disable @ 0x0051dcf4 size=0x18
  51dcf4:	3c1c0024 	lui	gp,0x24
  51dcf8:	279c340c 	addiu	gp,gp,13324
  51dcfc:	0399e021 	addu	gp,gp,t9
  51dd00:	8f828350 	lw	v0,-31920(gp)
  51dd04:	03e00008 	jr	ra
  51dd08:	ac400000 	sw	zero,0(v0)

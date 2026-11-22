; func uac_sqlite_err_switch_disable @ 0x00521bf8 size=0x18
  521bf8:	3c1c0024 	lui	gp,0x24
  521bfc:	279cf508 	addiu	gp,gp,-2808
  521c00:	0399e021 	addu	gp,gp,t9
  521c04:	8f8283a0 	lw	v0,-31840(gp)
  521c08:	03e00008 	jr	ra
  521c0c:	ac400000 	sw	zero,0(v0)

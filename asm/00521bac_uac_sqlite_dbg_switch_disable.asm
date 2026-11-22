; func uac_sqlite_dbg_switch_disable @ 0x00521bac size=0x18
  521bac:	3c1c0024 	lui	gp,0x24
  521bb0:	279cf554 	addiu	gp,gp,-2732
  521bb4:	0399e021 	addu	gp,gp,t9
  521bb8:	8f82839c 	lw	v0,-31844(gp)
  521bbc:	03e00008 	jr	ra
  521bc0:	ac400000 	sw	zero,0(v0)

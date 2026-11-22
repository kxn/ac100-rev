; func uac_sqlite_err_switch_enable @ 0x00521bdc size=0x1c
  521bdc:	3c1c0024 	lui	gp,0x24
  521be0:	279cf524 	addiu	gp,gp,-2780
  521be4:	0399e021 	addu	gp,gp,t9
  521be8:	8f8283a0 	lw	v0,-31840(gp)
  521bec:	24030001 	li	v1,1
  521bf0:	03e00008 	jr	ra
  521bf4:	ac430000 	sw	v1,0(v0)

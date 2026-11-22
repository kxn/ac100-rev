; func uac_sqlite_dbg_switch_enable @ 0x00521b90 size=0x1c
  521b90:	3c1c0024 	lui	gp,0x24
  521b94:	279cf570 	addiu	gp,gp,-2704
  521b98:	0399e021 	addu	gp,gp,t9
  521b9c:	8f82839c 	lw	v0,-31844(gp)
  521ba0:	24030001 	li	v1,1
  521ba4:	03e00008 	jr	ra
  521ba8:	ac430000 	sw	v1,0(v0)

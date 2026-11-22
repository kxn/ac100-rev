; func uac_mem_debug_enable @ 0x0051dcd8 size=0x1c
  51dcd8:	3c1c0024 	lui	gp,0x24
  51dcdc:	279c3428 	addiu	gp,gp,13352
  51dce0:	0399e021 	addu	gp,gp,t9
  51dce4:	8f828350 	lw	v0,-31920(gp)
  51dce8:	24030001 	li	v1,1
  51dcec:	03e00008 	jr	ra
  51dcf0:	ac430000 	sw	v1,0(v0)

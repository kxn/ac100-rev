; func set_uac_mem_check @ 0x0051de94 size=0x18
  51de94:	3c1c0024 	lui	gp,0x24
  51de98:	279c326c 	addiu	gp,gp,12908
  51de9c:	0399e021 	addu	gp,gp,t9
  51dea0:	8f828364 	lw	v0,-31900(gp)
  51dea4:	03e00008 	jr	ra
  51dea8:	ac440000 	sw	a0,0(v0)

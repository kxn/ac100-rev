; func uac_mem_debug_switch_get @ 0x0051dd0c size=0x18
  51dd0c:	3c1c0024 	lui	gp,0x24
  51dd10:	279c33f4 	addiu	gp,gp,13300
  51dd14:	0399e021 	addu	gp,gp,t9
  51dd18:	8f828350 	lw	v0,-31920(gp)
  51dd1c:	03e00008 	jr	ra
  51dd20:	8c420000 	lw	v0,0(v0)

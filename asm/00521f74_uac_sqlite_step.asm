; func uac_sqlite_step @ 0x00521f74 size=0x24
  521f74:	3c1c0024 	lui	gp,0x24
  521f78:	279cf18c 	addiu	gp,gp,-3700
  521f7c:	0399e021 	addu	gp,gp,t9
  521f80:	10800003 	beqz	a0,0x521f90
  521f84:	8f998674 	lw	t9,-31116(gp)
  521f88:	03200008 	jr	t9
  521f8c:	00000000 	nop
  521f90:	03e00008 	jr	ra
  521f94:	2402ffff 	li	v0,-1

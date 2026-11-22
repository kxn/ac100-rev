; func uac_mem_count_clear @ 0x0051dd24 size=0x18
  51dd24:	3c1c0024 	lui	gp,0x24
  51dd28:	279c33dc 	addiu	gp,gp,13276
  51dd2c:	0399e021 	addu	gp,gp,t9
  51dd30:	8f828354 	lw	v0,-31916(gp)
  51dd34:	03e00008 	jr	ra
  51dd38:	ac400000 	sw	zero,0(v0)

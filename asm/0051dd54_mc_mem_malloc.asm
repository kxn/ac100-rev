; func mc_mem_malloc @ 0x0051dd54 size=0x2c
  51dd54:	3c1c0024 	lui	gp,0x24
  51dd58:	279c33ac 	addiu	gp,gp,13228
  51dd5c:	0399e021 	addu	gp,gp,t9
  51dd60:	27bdfff8 	addiu	sp,sp,-8
  51dd64:	8f998168 	lw	t9,-32408(gp)
  51dd68:	00c03821 	move	a3,a2
  51dd6c:	03e03021 	move	a2,ra
  51dd70:	afbf0004 	sw	ra,4(sp)
  51dd74:	8fbf0004 	lw	ra,4(sp)
  51dd78:	100023f5 	b	0x526d50
  51dd7c:	27bd0008 	addiu	sp,sp,8

; func mc_mem_realloc @ 0x0051dd98 size=0x38
  51dd98:	3c1c0024 	lui	gp,0x24
  51dd9c:	279c3368 	addiu	gp,gp,13160
  51dda0:	0399e021 	addu	gp,gp,t9
  51dda4:	27bdffd8 	addiu	sp,sp,-40
  51dda8:	8f998358 	lw	t9,-31912(gp)
  51ddac:	afbc0018 	sw	gp,24(sp)
  51ddb0:	afbf0024 	sw	ra,36(sp)
  51ddb4:	afa70010 	sw	a3,16(sp)
  51ddb8:	03e03821 	move	a3,ra
  51ddbc:	0411245c 	bal	0x526f30
  51ddc0:	00000000 	nop
  51ddc4:	8fbf0024 	lw	ra,36(sp)
  51ddc8:	03e00008 	jr	ra
  51ddcc:	27bd0028 	addiu	sp,sp,40

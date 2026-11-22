; func mc_mem_calloc @ 0x0051ddd0 size=0x38
  51ddd0:	3c1c0024 	lui	gp,0x24
  51ddd4:	279c3330 	addiu	gp,gp,13104
  51ddd8:	0399e021 	addu	gp,gp,t9
  51dddc:	27bdffd8 	addiu	sp,sp,-40
  51dde0:	8f99835c 	lw	t9,-31908(gp)
  51dde4:	afbc0018 	sw	gp,24(sp)
  51dde8:	afbf0024 	sw	ra,36(sp)
  51ddec:	afa70010 	sw	a3,16(sp)
  51ddf0:	03e03821 	move	a3,ra
  51ddf4:	041124ab 	bal	0x5270a4
  51ddf8:	00000000 	nop
  51ddfc:	8fbf0024 	lw	ra,36(sp)
  51de00:	03e00008 	jr	ra
  51de04:	27bd0028 	addiu	sp,sp,40

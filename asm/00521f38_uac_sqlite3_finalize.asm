; func uac_sqlite3_finalize @ 0x00521f38 size=0x3c
  521f38:	3c1c0024 	lui	gp,0x24
  521f3c:	279cf1c8 	addiu	gp,gp,-3640
  521f40:	0399e021 	addu	gp,gp,t9
  521f44:	27bdffe0 	addiu	sp,sp,-32
  521f48:	afbc0010 	sw	gp,16(sp)
  521f4c:	afbf001c 	sw	ra,28(sp)
  521f50:	10800005 	beqz	a0,0x521f68
  521f54:	2402ffff 	li	v0,-1
  521f58:	8f998554 	lw	t9,-31404(gp)
  521f5c:	0320f809 	jalr	t9
  521f60:	00000000 	nop
  521f64:	00001021 	move	v0,zero
  521f68:	8fbf001c 	lw	ra,28(sp)
  521f6c:	03e00008 	jr	ra
  521f70:	27bd0020 	addiu	sp,sp,32

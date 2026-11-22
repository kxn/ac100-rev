; func uac_sqlite_close @ 0x00521d30 size=0x3c
  521d30:	3c1c0024 	lui	gp,0x24
  521d34:	279cf3d0 	addiu	gp,gp,-3120
  521d38:	0399e021 	addu	gp,gp,t9
  521d3c:	27bdffe0 	addiu	sp,sp,-32
  521d40:	afbc0010 	sw	gp,16(sp)
  521d44:	afbf001c 	sw	ra,28(sp)
  521d48:	10800005 	beqz	a0,0x521d60
  521d4c:	2402ffff 	li	v0,-1
  521d50:	8f998654 	lw	t9,-31148(gp)
  521d54:	0320f809 	jalr	t9
  521d58:	00000000 	nop
  521d5c:	00001021 	move	v0,zero
  521d60:	8fbf001c 	lw	ra,28(sp)
  521d64:	03e00008 	jr	ra
  521d68:	27bd0020 	addiu	sp,sp,32

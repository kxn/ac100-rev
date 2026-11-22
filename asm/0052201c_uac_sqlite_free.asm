; func uac_sqlite_free @ 0x0052201c size=0x3c
  52201c:	3c1c0024 	lui	gp,0x24
  522020:	279cf0e4 	addiu	gp,gp,-3868
  522024:	0399e021 	addu	gp,gp,t9
  522028:	27bdffe0 	addiu	sp,sp,-32
  52202c:	afbc0010 	sw	gp,16(sp)
  522030:	afbf001c 	sw	ra,28(sp)
  522034:	10800005 	beqz	a0,0x52204c
  522038:	2402ffff 	li	v0,-1
  52203c:	8f998530 	lw	t9,-31440(gp)
  522040:	0320f809 	jalr	t9
  522044:	00000000 	nop
  522048:	00001021 	move	v0,zero
  52204c:	8fbf001c 	lw	ra,28(sp)
  522050:	03e00008 	jr	ra
  522054:	27bd0020 	addiu	sp,sp,32

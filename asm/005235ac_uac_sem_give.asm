; func uac_sem_give @ 0x005235ac size=0x3c
  5235ac:	3c1c0024 	lui	gp,0x24
  5235b0:	279cdb54 	addiu	gp,gp,-9388
  5235b4:	0399e021 	addu	gp,gp,t9
  5235b8:	27bdffe0 	addiu	sp,sp,-32
  5235bc:	8f9987c8 	lw	t9,-30776(gp)
  5235c0:	afbc0010 	sw	gp,16(sp)
  5235c4:	afbf001c 	sw	ra,28(sp)
  5235c8:	0320f809 	jalr	t9
  5235cc:	00000000 	nop
  5235d0:	2403ffff 	li	v1,-1
  5235d4:	8fbf001c 	lw	ra,28(sp)
  5235d8:	27bd0020 	addiu	sp,sp,32
  5235dc:	0002180a 	movz	v1,zero,v0
  5235e0:	03e00008 	jr	ra
  5235e4:	00601021 	move	v0,v1

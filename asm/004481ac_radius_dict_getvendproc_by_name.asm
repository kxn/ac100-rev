; func radius_dict_getvendproc_by_name @ 0x004481ac size=0x40
  4481ac:	3c1c0032 	lui	gp,0x32
  4481b0:	279c8f54 	addiu	gp,gp,-28844
  4481b4:	0399e021 	addu	gp,gp,t9
  4481b8:	27bdffe0 	addiu	sp,sp,-32
  4481bc:	8f998180 	lw	t9,-32384(gp)
  4481c0:	afbc0010 	sw	gp,16(sp)
  4481c4:	afbf001c 	sw	ra,28(sp)
  4481c8:	0320f809 	jalr	t9
  4481cc:	8c84001c 	lw	a0,28(a0)
  4481d0:	00401821 	move	v1,v0
  4481d4:	10600002 	beqz	v1,0x4481e0
  4481d8:	00001021 	move	v0,zero
  4481dc:	8c620044 	lw	v0,68(v1)
  4481e0:	8fbf001c 	lw	ra,28(sp)
  4481e4:	03e00008 	jr	ra
  4481e8:	27bd0020 	addiu	sp,sp,32

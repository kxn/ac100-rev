; func _ucl_auth_offline_station_cmp_func @ 0x004a77d0 size=0x38
  4a77d0:	3c1c002c 	lui	gp,0x2c
  4a77d4:	279c9930 	addiu	gp,gp,-26320
  4a77d8:	0399e021 	addu	gp,gp,t9
  4a77dc:	27bdffe0 	addiu	sp,sp,-32
  4a77e0:	8f998588 	lw	t9,-31352(gp)
  4a77e4:	2484000c 	addiu	a0,a0,12
  4a77e8:	afbc0010 	sw	gp,16(sp)
  4a77ec:	afbf001c 	sw	ra,28(sp)
  4a77f0:	0320f809 	jalr	t9
  4a77f4:	24060006 	li	a2,6
  4a77f8:	8fbf001c 	lw	ra,28(sp)
  4a77fc:	2c420001 	sltiu	v0,v0,1
  4a7800:	03e00008 	jr	ra
  4a7804:	27bd0020 	addiu	sp,sp,32

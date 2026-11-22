; func radius_dict_getvend_by_value @ 0x00448174 size=0x38
  448174:	3c1c0032 	lui	gp,0x32
  448178:	279c8f8c 	addiu	gp,gp,-28788
  44817c:	0399e021 	addu	gp,gp,t9
  448180:	27bdffe0 	addiu	sp,sp,-32
  448184:	8f998180 	lw	t9,-32384(gp)
  448188:	afbc0010 	sw	gp,16(sp)
  44818c:	afbf001c 	sw	ra,28(sp)
  448190:	afa50024 	sw	a1,36(sp)
  448194:	27a50024 	addiu	a1,sp,36
  448198:	0320f809 	jalr	t9
  44819c:	8c840014 	lw	a0,20(a0)
  4481a0:	8fbf001c 	lw	ra,28(sp)
  4481a4:	03e00008 	jr	ra
  4481a8:	27bd0020 	addiu	sp,sp,32

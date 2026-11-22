; func radius_dict_getattr_by_value @ 0x00448124 size=0x38
  448124:	3c1c0032 	lui	gp,0x32
  448128:	279c8fdc 	addiu	gp,gp,-28708
  44812c:	0399e021 	addu	gp,gp,t9
  448130:	27bdffe0 	addiu	sp,sp,-32
  448134:	8f998180 	lw	t9,-32384(gp)
  448138:	afbc0010 	sw	gp,16(sp)
  44813c:	afbf001c 	sw	ra,28(sp)
  448140:	afa50024 	sw	a1,36(sp)
  448144:	27a50024 	addiu	a1,sp,36
  448148:	0320f809 	jalr	t9
  44814c:	8c840010 	lw	a0,16(a0)
  448150:	8fbf001c 	lw	ra,28(sp)
  448154:	03e00008 	jr	ra
  448158:	27bd0020 	addiu	sp,sp,32

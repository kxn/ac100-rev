; func radius_conf_str @ 0x004480e0 size=0x44
  4480e0:	3c1c0032 	lui	gp,0x32
  4480e4:	279c9020 	addiu	gp,gp,-28640
  4480e8:	0399e021 	addu	gp,gp,t9
  4480ec:	8f998048 	lw	t9,-32696(gp)
  4480f0:	27bdffe0 	addiu	sp,sp,-32
  4480f4:	afbc0010 	sw	gp,16(sp)
  4480f8:	27397788 	addiu	t9,t9,30600
  4480fc:	afbf001c 	sw	ra,28(sp)
  448100:	0411fda1 	bal	0x447788
  448104:	24060001 	li	a2,1
  448108:	00401821 	move	v1,v0
  44810c:	10600002 	beqz	v1,0x448118
  448110:	00001021 	move	v0,zero
  448114:	8c620048 	lw	v0,72(v1)
  448118:	8fbf001c 	lw	ra,28(sp)
  44811c:	03e00008 	jr	ra
  448120:	27bd0020 	addiu	sp,sp,32

; func apmngr_exceed_status_get @ 0x0052b15c size=0x44
  52b15c:	27bdffe0 	addiu	sp,sp,-32
  52b160:	2403ffff 	li	v1,-1
  52b164:	afb00018 	sw	s0,24(sp)
  52b168:	3c100075 	lui	s0,0x75
  52b16c:	afbf001c 	sw	ra,28(sp)
  52b170:	8e04bee8 	lw	a0,-16664(s0)
  52b174:	10830006 	beq	a0,v1,0x52b190
  52b178:	00001021 	move	v0,zero
  52b17c:	0c101f9c 	jal	0x407e70
  52b180:	00000000 	nop
  52b184:	8e02bee8 	lw	v0,-16664(s0)
  52b188:	00621023 	subu	v0,v1,v0
  52b18c:	2842003c 	slti	v0,v0,60
  52b190:	8fbf001c 	lw	ra,28(sp)
  52b194:	8fb00018 	lw	s0,24(sp)
  52b198:	03e00008 	jr	ra
  52b19c:	27bd0020 	addiu	sp,sp,32

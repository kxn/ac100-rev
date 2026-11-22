; func band_navigation_config_destroy @ 0x00560214 size=0x28
  560214:	27bdffe0 	addiu	sp,sp,-32
  560218:	2402ffff 	li	v0,-1
  56021c:	10800004 	beqz	a0,0x560230
  560220:	afbf001c 	sw	ra,28(sp)
  560224:	0c101f7c 	jal	0x407df0
  560228:	00000000 	nop
  56022c:	00001021 	move	v0,zero
  560230:	8fbf001c 	lw	ra,28(sp)
  560234:	03e00008 	jr	ra
  560238:	27bd0020 	addiu	sp,sp,32

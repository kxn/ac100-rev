; func apmngr_apdb_update_proc @ 0x0052a0f8 size=0x3c
  52a0f8:	27bdffd0 	addiu	sp,sp,-48
  52a0fc:	afa5001c 	sw	a1,28(sp)
  52a100:	3c050053 	lui	a1,0x53
  52a104:	afa40018 	sw	a0,24(sp)
  52a108:	2404ffff 	li	a0,-1
  52a10c:	afa60020 	sw	a2,32(sp)
  52a110:	24a5f330 	addiu	a1,a1,-3280
  52a114:	27a60018 	addiu	a2,sp,24
  52a118:	afbf002c 	sw	ra,44(sp)
  52a11c:	0c14e0b9 	jal	0x5382e4
  52a120:	afa70024 	sw	a3,36(sp)
  52a124:	00001021 	move	v0,zero
  52a128:	8fbf002c 	lw	ra,44(sp)
  52a12c:	03e00008 	jr	ra
  52a130:	27bd0030 	addiu	sp,sp,48

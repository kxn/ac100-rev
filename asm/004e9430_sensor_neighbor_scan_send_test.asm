; func sensor_neighbor_scan_send_test @ 0x004e9430 size=0x2c
  4e9430:	27bdffd0 	addiu	sp,sp,-48
  4e9434:	3084ffff 	andi	a0,a0,0xffff
  4e9438:	8fa20040 	lw	v0,64(sp)
  4e943c:	afbf002c 	sw	ra,44(sp)
  4e9440:	afa00014 	sw	zero,20(sp)
  4e9444:	afa20010 	sw	v0,16(sp)
  4e9448:	0c1396b8 	jal	0x4e5ae0
  4e944c:	afa00018 	sw	zero,24(sp)
  4e9450:	8fbf002c 	lw	ra,44(sp)
  4e9454:	03e00008 	jr	ra
  4e9458:	27bd0030 	addiu	sp,sp,48

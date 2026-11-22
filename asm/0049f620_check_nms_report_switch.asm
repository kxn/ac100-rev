; func check_nms_report_switch @ 0x0049f620 size=0x2c
  49f620:	3c020076 	lui	v0,0x76
  49f624:	24030001 	li	v1,1
  49f628:	8c4478fc 	lw	a0,30972(v0)
  49f62c:	14830005 	bne	a0,v1,0x49f644
  49f630:	2402ffff 	li	v0,-1
  49f634:	3c030076 	lui	v1,0x76
  49f638:	8c6378ec 	lw	v1,30956(v1)
  49f63c:	38630001 	xori	v1,v1,0x1
  49f640:	0003100a 	movz	v0,zero,v1
  49f644:	03e00008 	jr	ra
  49f648:	00000000 	nop

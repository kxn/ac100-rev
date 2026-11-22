; func band_navigation_config_differ_threshold_get @ 0x00560374 size=0x24
  560374:	10800006 	beqz	a0,0x560390
  560378:	2402ffff 	li	v0,-1
  56037c:	10a00004 	beqz	a1,0x560390
  560380:	00000000 	nop
  560384:	8c82000c 	lw	v0,12(a0)
  560388:	aca20000 	sw	v0,0(a1)
  56038c:	00001021 	move	v0,zero
  560390:	03e00008 	jr	ra
  560394:	00000000 	nop

; func uac_schedule_container_async_report_set @ 0x00521344 size=0x18
  521344:	10800003 	beqz	a0,0x521354
  521348:	2402ffff 	li	v0,-1
  52134c:	00001021 	move	v0,zero
  521350:	ac85007c 	sw	a1,124(a0)
  521354:	03e00008 	jr	ra
  521358:	00000000 	nop

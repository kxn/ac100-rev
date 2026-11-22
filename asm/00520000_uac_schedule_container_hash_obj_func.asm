; func uac_schedule_container_hash_obj_func @ 0x00520000 size=0x20
  520000:	10800005 	beqz	a0,0x520018
  520004:	00000000 	nop
  520008:	8c820010 	lw	v0,16(a0)
  52000c:	8c59006c 	lw	t9,108(v0)
  520010:	03200008 	jr	t9
  520014:	8c84000c 	lw	a0,12(a0)
  520018:	03e00008 	jr	ra
  52001c:	00001021 	move	v0,zero

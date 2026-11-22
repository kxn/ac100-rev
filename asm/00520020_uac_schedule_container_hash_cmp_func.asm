; func uac_schedule_container_hash_cmp_func @ 0x00520020 size=0x20
  520020:	10800005 	beqz	a0,0x520038
  520024:	00000000 	nop
  520028:	8c820010 	lw	v0,16(a0)
  52002c:	8c590074 	lw	t9,116(v0)
  520030:	03200008 	jr	t9
  520034:	8c84000c 	lw	a0,12(a0)
  520038:	03e00008 	jr	ra
  52003c:	00001021 	move	v0,zero

; func _sensor_di_db_get_chnl_cnt @ 0x004dcf78 size=0x3c
  4dcf78:	24030001 	li	v1,1
  4dcf7c:	308400ff 	andi	a0,a0,0xff
  4dcf80:	1083000a 	beq	a0,v1,0x4dcfac
  4dcf84:	2402000d 	li	v0,13
  4dcf88:	24030002 	li	v1,2
  4dcf8c:	10830007 	beq	a0,v1,0x4dcfac
  4dcf90:	24020008 	li	v0,8
  4dcf94:	24030003 	li	v1,3
  4dcf98:	10830004 	beq	a0,v1,0x4dcfac
  4dcf9c:	2402000c 	li	v0,12
  4dcfa0:	24020005 	li	v0,5
  4dcfa4:	38840004 	xori	a0,a0,0x4
  4dcfa8:	0004100b 	movn	v0,zero,a0
  4dcfac:	03e00008 	jr	ra
  4dcfb0:	00000000 	nop

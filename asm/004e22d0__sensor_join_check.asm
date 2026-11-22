; func _sensor_join_check @ 0x004e22d0 size=0x5c
  4e22d0:	3c02007c 	lui	v0,0x7c
  4e22d4:	8c435860 	lw	v1,22624(v0)
  4e22d8:	14600005 	bnez	v1,0x4e22f0
  4e22dc:	24020001 	li	v0,1
  4e22e0:	8c860014 	lw	a2,20(a0)
  4e22e4:	24030007 	li	v1,7
  4e22e8:	50c30003 	beql	a2,v1,0x4e22f8
  4e22ec:	8c83003c 	lw	v1,60(a0)
  4e22f0:	03e00008 	jr	ra
  4e22f4:	00000000 	nop
  4e22f8:	1460fffd 	bnez	v1,0x4e22f0
  4e22fc:	00000000 	nop
  4e2300:	10a0fffb 	beqz	a1,0x4e22f0
  4e2304:	00001021 	move	v0,zero
  4e2308:	3c030077 	lui	v1,0x77
  4e230c:	8c638628 	lw	v1,-31192(v1)
  4e2310:	1060fff7 	beqz	v1,0x4e22f0
  4e2314:	00000000 	nop
  4e2318:	3c020077 	lui	v0,0x77
  4e231c:	8c428630 	lw	v0,-31184(v0)
  4e2320:	38420001 	xori	v0,v0,0x1
  4e2324:	03e00008 	jr	ra
  4e2328:	2c420001 	sltiu	v0,v0,1

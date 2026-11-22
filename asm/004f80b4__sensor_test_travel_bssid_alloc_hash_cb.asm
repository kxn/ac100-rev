; func _sensor_test_travel_bssid_alloc_hash_cb @ 0x004f80b4 size=0x3c
  4f80b4:	10800007 	beqz	a0,0x4f80d4
  4f80b8:	00801021 	move	v0,a0
  4f80bc:	10a00005 	beqz	a1,0x4f80d4
  4f80c0:	00000000 	nop
  4f80c4:	94840020 	lhu	a0,32(a0)
  4f80c8:	94a30000 	lhu	v1,0(a1)
  4f80cc:	50830003 	beql	a0,v1,0x4f80dc
  4f80d0:	24030001 	li	v1,1
  4f80d4:	03e00008 	jr	ra
  4f80d8:	00000000 	nop
  4f80dc:	a4400020 	sh	zero,32(v0)
  4f80e0:	a0430022 	sb	v1,34(v0)
  4f80e4:	8ca40004 	lw	a0,4(a1)
  4f80e8:	08141309 	j	0x504c24
  4f80ec:	2445000c 	addiu	a1,v0,12

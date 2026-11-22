; func apdb_init_region_code_list @ 0x0060d264 size=0x24
  60d264:	00001021 	move	v0,zero
  60d268:	2405ffff 	li	a1,-1
  60d26c:	24030020 	li	v1,32
  60d270:	00823021 	addu	a2,a0,v0
  60d274:	24420001 	addiu	v0,v0,1
  60d278:	1443fffd 	bne	v0,v1,0x60d270
  60d27c:	a0c50000 	sb	a1,0(a2)
  60d280:	03e00008 	jr	ra
  60d284:	00001021 	move	v0,zero

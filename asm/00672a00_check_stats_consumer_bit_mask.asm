; func check_stats_consumer_bit_mask @ 0x00672a00 size=0x18
  672a00:	00a41007 	srav	v0,a0,a1
  672a04:	2403ffff 	li	v1,-1
  672a08:	30420001 	andi	v0,v0,0x1
  672a0c:	0002180b 	movn	v1,zero,v0
  672a10:	03e00008 	jr	ra
  672a14:	00601021 	move	v0,v1

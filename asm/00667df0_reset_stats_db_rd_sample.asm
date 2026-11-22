; func reset_stats_db_rd_sample @ 0x00667df0 size=0x3c
  667df0:	1080000c 	beqz	a0,0x667e24
  667df4:	2402ffff 	li	v0,-1
  667df8:	a0800048 	sb	zero,72(a0)
  667dfc:	a0800064 	sb	zero,100(a0)
  667e00:	a0820011 	sb	v0,17(a0)
  667e04:	a0820031 	sb	v0,49(a0)
  667e08:	a0820032 	sb	v0,50(a0)
  667e0c:	a0820012 	sb	v0,18(a0)
  667e10:	a0820030 	sb	v0,48(a0)
  667e14:	a0820033 	sb	v0,51(a0)
  667e18:	2402ffff 	li	v0,-1
  667e1c:	ac820070 	sw	v0,112(a0)
  667e20:	ac820074 	sw	v0,116(a0)
  667e24:	03e00008 	jr	ra
  667e28:	00000000 	nop

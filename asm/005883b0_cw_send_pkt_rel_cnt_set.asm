; func cw_send_pkt_rel_cnt_set @ 0x005883b0 size=0x18
  5883b0:	10800003 	beqz	a0,0x5883c0
  5883b4:	2402ffff 	li	v0,-1
  5883b8:	00001021 	move	v0,zero
  5883bc:	ac850008 	sw	a1,8(a0)
  5883c0:	03e00008 	jr	ra
  5883c4:	00000000 	nop

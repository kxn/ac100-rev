; func cw_priv_dhcp_defend_length @ 0x005af7e0 size=0x24
  5af7e0:	10800006 	beqz	a0,0x5af7fc
  5af7e4:	00001021 	move	v0,zero
  5af7e8:	8c830004 	lw	v1,4(a0)
  5af7ec:	24020007 	li	v0,7
  5af7f0:	70621002 	mul	v0,v1,v0
  5af7f4:	24420006 	addiu	v0,v0,6
  5af7f8:	3042ffff 	andi	v0,v0,0xffff
  5af7fc:	03e00008 	jr	ra
  5af800:	00000000 	nop

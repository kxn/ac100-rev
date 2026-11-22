; func cw_priv_wechat_iplist_length @ 0x005cb080 size=0x1c
  5cb080:	10800004 	beqz	a0,0x5cb094
  5cb084:	00001021 	move	v0,zero
  5cb088:	8c820000 	lw	v0,0(a0)
  5cb08c:	24420004 	addiu	v0,v0,4
  5cb090:	3042ffff 	andi	v0,v0,0xffff
  5cb094:	03e00008 	jr	ra
  5cb098:	00000000 	nop

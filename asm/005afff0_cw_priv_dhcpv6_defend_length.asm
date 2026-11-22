; func cw_priv_dhcpv6_defend_length @ 0x005afff0 size=0x24
  5afff0:	10800006 	beqz	a0,0x5b000c
  5afff4:	00001021 	move	v0,zero
  5afff8:	8c830004 	lw	v1,4(a0)
  5afffc:	24020011 	li	v0,17
  5b0000:	70621002 	mul	v0,v1,v0
  5b0004:	24420006 	addiu	v0,v0,6
  5b0008:	3042ffff 	andi	v0,v0,0xffff
  5b000c:	03e00008 	jr	ra
  5b0010:	00000000 	nop

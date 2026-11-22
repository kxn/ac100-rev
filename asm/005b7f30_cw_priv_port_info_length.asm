; func cw_priv_port_info_length @ 0x005b7f30 size=0x2c
  5b7f30:	10800008 	beqz	a0,0x5b7f54
  5b7f34:	00001021 	move	v0,zero
  5b7f38:	8c830004 	lw	v1,4(a0)
  5b7f3c:	10600004 	beqz	v1,0x5b7f50
  5b7f40:	24020001 	li	v0,1
  5b7f44:	90820000 	lbu	v0,0(a0)
  5b7f48:	000210c0 	sll	v0,v0,0x3
  5b7f4c:	24420001 	addiu	v0,v0,1
  5b7f50:	3042ffff 	andi	v0,v0,0xffff
  5b7f54:	03e00008 	jr	ra
  5b7f58:	00000000 	nop

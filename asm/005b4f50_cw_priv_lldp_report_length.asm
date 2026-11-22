; func cw_priv_lldp_report_length @ 0x005b4f50 size=0x1c
  5b4f50:	10800004 	beqz	a0,0x5b4f64
  5b4f54:	00001021 	move	v0,zero
  5b4f58:	8c820000 	lw	v0,0(a0)
  5b4f5c:	24420004 	addiu	v0,v0,4
  5b4f60:	3042ffff 	andi	v0,v0,0xffff
  5b4f64:	03e00008 	jr	ra
  5b4f68:	00000000 	nop

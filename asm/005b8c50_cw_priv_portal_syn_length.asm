; func cw_priv_portal_syn_length @ 0x005b8c50 size=0x1c
  5b8c50:	10800004 	beqz	a0,0x5b8c64
  5b8c54:	00001021 	move	v0,zero
  5b8c58:	94820000 	lhu	v0,0(a0)
  5b8c5c:	24420002 	addiu	v0,v0,2
  5b8c60:	3042ffff 	andi	v0,v0,0xffff
  5b8c64:	03e00008 	jr	ra
  5b8c68:	00000000 	nop

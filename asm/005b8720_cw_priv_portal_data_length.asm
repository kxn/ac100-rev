; func cw_priv_portal_data_length @ 0x005b8720 size=0x1c
  5b8720:	10800004 	beqz	a0,0x5b8734
  5b8724:	00001021 	move	v0,zero
  5b8728:	94820000 	lhu	v0,0(a0)
  5b872c:	24420002 	addiu	v0,v0,2
  5b8730:	3042ffff 	andi	v0,v0,0xffff
  5b8734:	03e00008 	jr	ra
  5b8738:	00000000 	nop

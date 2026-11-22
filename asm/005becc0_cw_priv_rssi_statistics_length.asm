; func cw_priv_rssi_statistics_length @ 0x005becc0 size=0x24
  5becc0:	10800006 	beqz	a0,0x5becdc
  5becc4:	00001021 	move	v0,zero
  5becc8:	8c830010 	lw	v1,16(a0)
  5beccc:	2402000e 	li	v0,14
  5becd0:	70621002 	mul	v0,v1,v0
  5becd4:	24420014 	addiu	v0,v0,20
  5becd8:	3042ffff 	andi	v0,v0,0xffff
  5becdc:	03e00008 	jr	ra
  5bece0:	00000000 	nop

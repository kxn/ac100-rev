; func cw_priv_igmp_query_config_by_ssid_length @ 0x005b22d0 size=0x24
  5b22d0:	10800006 	beqz	a0,0x5b22ec
  5b22d4:	00001021 	move	v0,zero
  5b22d8:	8c830000 	lw	v1,0(a0)
  5b22dc:	24020003 	li	v0,3
  5b22e0:	70621002 	mul	v0,v1,v0
  5b22e4:	24420004 	addiu	v0,v0,4
  5b22e8:	3042ffff 	andi	v0,v0,0xffff
  5b22ec:	03e00008 	jr	ra
  5b22f0:	00000000 	nop

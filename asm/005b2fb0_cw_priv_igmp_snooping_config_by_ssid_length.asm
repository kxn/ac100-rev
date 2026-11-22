; func cw_priv_igmp_snooping_config_by_ssid_length @ 0x005b2fb0 size=0x24
  5b2fb0:	10800006 	beqz	a0,0x5b2fcc
  5b2fb4:	00001021 	move	v0,zero
  5b2fb8:	8c830000 	lw	v1,0(a0)
  5b2fbc:	24020003 	li	v0,3
  5b2fc0:	70621002 	mul	v0,v1,v0
  5b2fc4:	24420004 	addiu	v0,v0,4
  5b2fc8:	3042ffff 	andi	v0,v0,0xffff
  5b2fcc:	03e00008 	jr	ra
  5b2fd0:	00000000 	nop

; func cw_priv_igmp_snooping_config_length @ 0x005b2950 size=0x20
  5b2950:	10800005 	beqz	a0,0x5b2968
  5b2954:	00001021 	move	v0,zero
  5b2958:	90820002 	lbu	v0,2(a0)
  5b295c:	24030003 	li	v1,3
  5b2960:	24420001 	addiu	v0,v0,1
  5b2964:	70431002 	mul	v0,v0,v1
  5b2968:	03e00008 	jr	ra
  5b296c:	00000000 	nop

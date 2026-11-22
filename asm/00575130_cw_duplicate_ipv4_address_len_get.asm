; func cw_duplicate_ipv4_address_len_get @ 0x00575130 size=0x18
  575130:	10800003 	beqz	a0,0x575140
  575134:	00001021 	move	v0,zero
  575138:	90820005 	lbu	v0,5(a0)
  57513c:	24420006 	addiu	v0,v0,6
  575140:	03e00008 	jr	ra
  575144:	00000000 	nop

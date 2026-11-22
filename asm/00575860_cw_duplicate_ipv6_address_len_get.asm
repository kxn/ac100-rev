; func cw_duplicate_ipv6_address_len_get @ 0x00575860 size=0x18
  575860:	10800003 	beqz	a0,0x575870
  575864:	00001021 	move	v0,zero
  575868:	90820011 	lbu	v0,17(a0)
  57586c:	24420012 	addiu	v0,v0,18
  575870:	03e00008 	jr	ra
  575874:	00000000 	nop

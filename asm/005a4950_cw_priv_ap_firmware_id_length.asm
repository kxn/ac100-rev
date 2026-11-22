; func cw_priv_ap_firmware_id_length @ 0x005a4950 size=0x20
  5a4950:	10800005 	beqz	a0,0x5a4968
  5a4954:	00001021 	move	v0,zero
  5a4958:	90820010 	lbu	v0,16(a0)
  5a495c:	00021100 	sll	v0,v0,0x4
  5a4960:	24420011 	addiu	v0,v0,17
  5a4964:	3042ffff 	andi	v0,v0,0xffff
  5a4968:	03e00008 	jr	ra
  5a496c:	00000000 	nop

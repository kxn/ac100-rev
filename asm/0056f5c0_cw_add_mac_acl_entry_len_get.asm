; func cw_add_mac_acl_entry_len_get @ 0x0056f5c0 size=0x24
  56f5c0:	10800006 	beqz	a0,0x56f5dc
  56f5c4:	00001021 	move	v0,zero
  56f5c8:	90830001 	lbu	v1,1(a0)
  56f5cc:	90820000 	lbu	v0,0(a0)
  56f5d0:	70621002 	mul	v0,v1,v0
  56f5d4:	24420002 	addiu	v0,v0,2
  56f5d8:	3042ffff 	andi	v0,v0,0xffff
  56f5dc:	03e00008 	jr	ra
  56f5e0:	00000000 	nop

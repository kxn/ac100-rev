; func cw_delete_mac_acl_entry_len_get @ 0x00573f60 size=0x24
  573f60:	10800006 	beqz	a0,0x573f7c
  573f64:	00001021 	move	v0,zero
  573f68:	90830001 	lbu	v1,1(a0)
  573f6c:	90820000 	lbu	v0,0(a0)
  573f70:	70621002 	mul	v0,v1,v0
  573f74:	24420002 	addiu	v0,v0,2
  573f78:	3042ffff 	andi	v0,v0,0xffff
  573f7c:	03e00008 	jr	ra
  573f80:	00000000 	nop

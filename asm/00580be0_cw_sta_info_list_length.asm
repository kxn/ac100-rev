; func cw_sta_info_list_length @ 0x00580be0 size=0x24
  580be0:	10800006 	beqz	a0,0x580bfc
  580be4:	00001021 	move	v0,zero
  580be8:	8c830008 	lw	v1,8(a0)
  580bec:	2402000e 	li	v0,14
  580bf0:	70621002 	mul	v0,v1,v0
  580bf4:	24420009 	addiu	v0,v0,9
  580bf8:	3042ffff 	andi	v0,v0,0xffff
  580bfc:	03e00008 	jr	ra
  580c00:	00000000 	nop

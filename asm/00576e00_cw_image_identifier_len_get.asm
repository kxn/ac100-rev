; func cw_image_identifier_len_get @ 0x00576e00 size=0x1c
  576e00:	10800004 	beqz	a0,0x576e14
  576e04:	00001021 	move	v0,zero
  576e08:	94820004 	lhu	v0,4(a0)
  576e0c:	24420004 	addiu	v0,v0,4
  576e10:	3042ffff 	andi	v0,v0,0xffff
  576e14:	03e00008 	jr	ra
  576e18:	00000000 	nop

; func cw_image_data_len_get @ 0x00576650 size=0x1c
  576650:	10800004 	beqz	a0,0x576664
  576654:	00001021 	move	v0,zero
  576658:	94820002 	lhu	v0,2(a0)
  57665c:	24420001 	addiu	v0,v0,1
  576660:	3042ffff 	andi	v0,v0,0xffff
  576664:	03e00008 	jr	ra
  576668:	00000000 	nop

; func cw_data_transfer_data_len_get @ 0x00572850 size=0x1c
  572850:	10800004 	beqz	a0,0x572864
  572854:	00001021 	move	v0,zero
  572858:	94820002 	lhu	v0,2(a0)
  57285c:	24420004 	addiu	v0,v0,4
  572860:	3042ffff 	andi	v0,v0,0xffff
  572864:	03e00008 	jr	ra
  572868:	00000000 	nop

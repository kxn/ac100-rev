; func cw_ac_name_with_priority_len_get @ 0x0056edd0 size=0x1c
  56edd0:	10800004 	beqz	a0,0x56ede4
  56edd4:	00001021 	move	v0,zero
  56edd8:	94820002 	lhu	v0,2(a0)
  56eddc:	24420001 	addiu	v0,v0,1
  56ede0:	3042ffff 	andi	v0,v0,0xffff
  56ede4:	03e00008 	jr	ra
  56ede8:	00000000 	nop

; func cw_priv_special_frame_rate_ctrl_length @ 0x005bb1a0 size=0x1c
  5bb1a0:	10800004 	beqz	a0,0x5bb1b4
  5bb1a4:	00001021 	move	v0,zero
  5bb1a8:	90820002 	lbu	v0,2(a0)
  5bb1ac:	24420001 	addiu	v0,v0,1
  5bb1b0:	00021080 	sll	v0,v0,0x2
  5bb1b4:	03e00008 	jr	ra
  5bb1b8:	00000000 	nop

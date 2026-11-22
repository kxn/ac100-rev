; func cw_priv_nd_defend_length @ 0x005b70b0 size=0x24
  5b70b0:	10800006 	beqz	a0,0x5b70cc
  5b70b4:	00001021 	move	v0,zero
  5b70b8:	8c830004 	lw	v1,4(a0)
  5b70bc:	24020016 	li	v0,22
  5b70c0:	70621002 	mul	v0,v1,v0
  5b70c4:	24420006 	addiu	v0,v0,6
  5b70c8:	3042ffff 	andi	v0,v0,0xffff
  5b70cc:	03e00008 	jr	ra
  5b70d0:	00000000 	nop

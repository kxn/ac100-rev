; func cw_priv_fail_station_length @ 0x005b0c30 size=0x24
  5b0c30:	10800006 	beqz	a0,0x5b0c4c
  5b0c34:	00001021 	move	v0,zero
  5b0c38:	8c830000 	lw	v1,0(a0)
  5b0c3c:	24020011 	li	v0,17
  5b0c40:	70621002 	mul	v0,v1,v0
  5b0c44:	24420004 	addiu	v0,v0,4
  5b0c48:	3042ffff 	andi	v0,v0,0xffff
  5b0c4c:	03e00008 	jr	ra
  5b0c50:	00000000 	nop

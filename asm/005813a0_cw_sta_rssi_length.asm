; func cw_sta_rssi_length @ 0x005813a0 size=0x24
  5813a0:	10800006 	beqz	a0,0x5813bc
  5813a4:	00001021 	move	v0,zero
  5813a8:	8c830004 	lw	v1,4(a0)
  5813ac:	24020007 	li	v0,7
  5813b0:	70621002 	mul	v0,v1,v0
  5813b4:	24420005 	addiu	v0,v0,5
  5813b8:	3042ffff 	andi	v0,v0,0xffff
  5813bc:	03e00008 	jr	ra
  5813c0:	00000000 	nop

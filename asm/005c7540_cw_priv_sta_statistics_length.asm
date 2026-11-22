; func cw_priv_sta_statistics_length @ 0x005c7540 size=0x24
  5c7540:	10800006 	beqz	a0,0x5c755c
  5c7544:	00001021 	move	v0,zero
  5c7548:	8c830000 	lw	v1,0(a0)
  5c754c:	24020026 	li	v0,38
  5c7550:	70621002 	mul	v0,v1,v0
  5c7554:	24420004 	addiu	v0,v0,4
  5c7558:	3042ffff 	andi	v0,v0,0xffff
  5c755c:	03e00008 	jr	ra
  5c7560:	00000000 	nop

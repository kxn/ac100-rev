; func cw_priv_wlan_list_length @ 0x005cb580 size=0x24
  5cb580:	10800006 	beqz	a0,0x5cb59c
  5cb584:	00001021 	move	v0,zero
  5cb588:	8c830004 	lw	v1,4(a0)
  5cb58c:	24020021 	li	v0,33
  5cb590:	70621002 	mul	v0,v1,v0
  5cb594:	24420008 	addiu	v0,v0,8
  5cb598:	3042ffff 	andi	v0,v0,0xffff
  5cb59c:	03e00008 	jr	ra
  5cb5a0:	00000000 	nop

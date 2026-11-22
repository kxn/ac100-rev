; func cw_ac_ipv6_list_len_get @ 0x0056e330 size=0x1c
  56e330:	10800004 	beqz	a0,0x56e344
  56e334:	00001021 	move	v0,zero
  56e338:	94820000 	lhu	v0,0(a0)
  56e33c:	00021100 	sll	v0,v0,0x4
  56e340:	3042ffff 	andi	v0,v0,0xffff
  56e344:	03e00008 	jr	ra
  56e348:	00000000 	nop

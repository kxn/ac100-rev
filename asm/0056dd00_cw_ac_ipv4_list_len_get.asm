; func cw_ac_ipv4_list_len_get @ 0x0056dd00 size=0x1c
  56dd00:	10800004 	beqz	a0,0x56dd14
  56dd04:	00001021 	move	v0,zero
  56dd08:	94820000 	lhu	v0,0(a0)
  56dd0c:	00021080 	sll	v0,v0,0x2
  56dd10:	3042ffff 	andi	v0,v0,0xffff
  56dd14:	03e00008 	jr	ra
  56dd18:	00000000 	nop

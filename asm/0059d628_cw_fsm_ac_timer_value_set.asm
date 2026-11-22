; func cw_fsm_ac_timer_value_set @ 0x0059d628 size=0x38
  59d628:	2483ffff 	addiu	v1,a0,-1
  59d62c:	2c63000a 	sltiu	v1,v1,10
  59d630:	10600007 	beqz	v1,0x59d650
  59d634:	00801021 	move	v0,a0
  59d638:	3c030075 	lui	v1,0x75
  59d63c:	00041080 	sll	v0,a0,0x2
  59d640:	2463cfac 	addiu	v1,v1,-12372
  59d644:	00431021 	addu	v0,v0,v1
  59d648:	03e00008 	jr	ra
  59d64c:	ac450000 	sw	a1,0(v0)
  59d650:	3c04006e 	lui	a0,0x6e
  59d654:	00402821 	move	a1,v0
  59d658:	08101b74 	j	0x406dd0
  59d65c:	248448b0 	addiu	a0,a0,18608

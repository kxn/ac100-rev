; func cw_fsm_ac_get_timer_name @ 0x0059c85c size=0x2c
  59c85c:	2c82000c 	sltiu	v0,a0,12
  59c860:	10400006 	beqz	v0,0x59c87c
  59c864:	00042080 	sll	a0,a0,0x2
  59c868:	3c02006e 	lui	v0,0x6e
  59c86c:	24424ae8 	addiu	v0,v0,19176
  59c870:	00822021 	addu	a0,a0,v0
  59c874:	03e00008 	jr	ra
  59c878:	8c820000 	lw	v0,0(a0)
  59c87c:	3c02006e 	lui	v0,0x6e
  59c880:	03e00008 	jr	ra
  59c884:	24424560 	addiu	v0,v0,17760

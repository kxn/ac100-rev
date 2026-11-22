; func cw_fsm_ac_get_event_name @ 0x0059c830 size=0x2c
  59c830:	2c82000e 	sltiu	v0,a0,14
  59c834:	10400006 	beqz	v0,0x59c850
  59c838:	00042080 	sll	a0,a0,0x2
  59c83c:	3c02006e 	lui	v0,0x6e
  59c840:	24424ab0 	addiu	v0,v0,19120
  59c844:	00822021 	addu	a0,a0,v0
  59c848:	03e00008 	jr	ra
  59c84c:	8c820000 	lw	v0,0(a0)
  59c850:	3c02006e 	lui	v0,0x6e
  59c854:	03e00008 	jr	ra
  59c858:	24424550 	addiu	v0,v0,17744

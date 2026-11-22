; func cw_fsm_get_state_name @ 0x0059c800 size=0x2c
  59c800:	2c82000f 	sltiu	v0,a0,15
  59c804:	10400006 	beqz	v0,0x59c820
  59c808:	00042080 	sll	a0,a0,0x2
  59c80c:	3c02006e 	lui	v0,0x6e
  59c810:	24424510 	addiu	v0,v0,17680
  59c814:	00822021 	addu	a0,a0,v0
  59c818:	03e00008 	jr	ra
  59c81c:	8c820000 	lw	v0,0(a0)
  59c820:	3c02006e 	lui	v0,0x6e
  59c824:	03e00008 	jr	ra
  59c828:	24424450 	addiu	v0,v0,17488
  59c82c:	00000000 	nop

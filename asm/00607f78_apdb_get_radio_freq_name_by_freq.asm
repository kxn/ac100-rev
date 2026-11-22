; func apdb_get_radio_freq_name_by_freq @ 0x00607f78 size=0x28
  607f78:	2c830002 	sltiu	v1,a0,2
  607f7c:	10600006 	beqz	v1,0x607f98
  607f80:	00001021 	move	v0,zero
  607f84:	3c020070 	lui	v0,0x70
  607f88:	00042080 	sll	a0,a0,0x2
  607f8c:	24422480 	addiu	v0,v0,9344
  607f90:	00822021 	addu	a0,a0,v0
  607f94:	8c820000 	lw	v0,0(a0)
  607f98:	03e00008 	jr	ra
  607f9c:	00000000 	nop

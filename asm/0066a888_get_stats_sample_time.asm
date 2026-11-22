; func get_stats_sample_time @ 0x0066a888 size=0x28
  66a888:	2c830004 	sltiu	v1,a0,4
  66a88c:	10600006 	beqz	v1,0x66a8a8
  66a890:	2402ffff 	li	v0,-1
  66a894:	3c020076 	lui	v0,0x76
  66a898:	00042080 	sll	a0,a0,0x2
  66a89c:	24428cd4 	addiu	v0,v0,-29484
  66a8a0:	00822021 	addu	a0,a0,v0
  66a8a4:	8c820000 	lw	v0,0(a0)
  66a8a8:	03e00008 	jr	ra
  66a8ac:	00000000 	nop

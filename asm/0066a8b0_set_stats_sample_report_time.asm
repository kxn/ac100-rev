; func set_stats_sample_report_time @ 0x0066a8b0 size=0x2c
  66a8b0:	2ca20004 	sltiu	v0,a1,4
  66a8b4:	10400007 	beqz	v0,0x66a8d4
  66a8b8:	3c020076 	lui	v0,0x76
  66a8bc:	00052880 	sll	a1,a1,0x2
  66a8c0:	24428ce4 	addiu	v0,v0,-29468
  66a8c4:	00a22821 	addu	a1,a1,v0
  66a8c8:	8ca20000 	lw	v0,0(a1)
  66a8cc:	54820001 	bnel	a0,v0,0x66a8d4
  66a8d0:	aca40000 	sw	a0,0(a1)
  66a8d4:	03e00008 	jr	ra
  66a8d8:	00000000 	nop

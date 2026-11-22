; func get_stats_sample_report_time @ 0x0066aec8 size=0x28
  66aec8:	2c830004 	sltiu	v1,a0,4
  66aecc:	10600006 	beqz	v1,0x66aee8
  66aed0:	2402ffff 	li	v0,-1
  66aed4:	3c020076 	lui	v0,0x76
  66aed8:	00042080 	sll	a0,a0,0x2
  66aedc:	24428ce4 	addiu	v0,v0,-29468
  66aee0:	00822021 	addu	a0,a0,v0
  66aee4:	8c820000 	lw	v0,0(a0)
  66aee8:	03e00008 	jr	ra
  66aeec:	00000000 	nop

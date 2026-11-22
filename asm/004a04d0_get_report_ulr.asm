; func get_report_ulr @ 0x004a04d0 size=0x28
  4a04d0:	2c830003 	sltiu	v1,a0,3
  4a04d4:	10600006 	beqz	v1,0x4a04f0
  4a04d8:	00001021 	move	v0,zero
  4a04dc:	3c02006a 	lui	v0,0x6a
  4a04e0:	00042080 	sll	a0,a0,0x2
  4a04e4:	2442cc98 	addiu	v0,v0,-13160
  4a04e8:	00822021 	addu	a0,a0,v0
  4a04ec:	8c820000 	lw	v0,0(a0)
  4a04f0:	03e00008 	jr	ra
  4a04f4:	00000000 	nop

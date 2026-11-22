; func apmngr_support_capacity_register @ 0x0052a898 size=0x40
  52a898:	2c830060 	sltiu	v1,a0,96
  52a89c:	1060000c 	beqz	v1,0x52a8d0
  52a8a0:	2402ffff 	li	v0,-1
  52a8a4:	00041943 	sra	v1,a0,0x5
  52a8a8:	3c02007c 	lui	v0,0x7c
  52a8ac:	00031880 	sll	v1,v1,0x2
  52a8b0:	24425484 	addiu	v0,v0,21636
  52a8b4:	00621021 	addu	v0,v1,v0
  52a8b8:	24030001 	li	v1,1
  52a8bc:	00832004 	sllv	a0,v1,a0
  52a8c0:	8c430000 	lw	v1,0(v0)
  52a8c4:	00832025 	or	a0,a0,v1
  52a8c8:	ac440000 	sw	a0,0(v0)
  52a8cc:	00001021 	move	v0,zero
  52a8d0:	03e00008 	jr	ra
  52a8d4:	00000000 	nop

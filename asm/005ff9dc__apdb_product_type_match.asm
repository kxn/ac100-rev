; func _apdb_product_type_match @ 0x005ff9dc size=0x24
  5ff9dc:	2c830004 	sltiu	v1,a0,4
  5ff9e0:	10600005 	beqz	v1,0x5ff9f8
  5ff9e4:	00001021 	move	v0,zero
  5ff9e8:	3c020075 	lui	v0,0x75
  5ff9ec:	8c42fe80 	lw	v0,-384(v0)
  5ff9f0:	00821007 	srav	v0,v0,a0
  5ff9f4:	30420001 	andi	v0,v0,0x1
  5ff9f8:	03e00008 	jr	ra
  5ff9fc:	00000000 	nop

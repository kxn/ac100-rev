; func apdb_support_product_type_register @ 0x00606840 size=0x30
  606840:	2c830004 	sltiu	v1,a0,4
  606844:	10600008 	beqz	v1,0x606868
  606848:	2402ffff 	li	v0,-1
  60684c:	3c020075 	lui	v0,0x75
  606850:	24030001 	li	v1,1
  606854:	00832004 	sllv	a0,v1,a0
  606858:	8c43fe80 	lw	v1,-384(v0)
  60685c:	00832025 	or	a0,a0,v1
  606860:	ac44fe80 	sw	a0,-384(v0)
  606864:	00001021 	move	v0,zero
  606868:	03e00008 	jr	ra
  60686c:	00000000 	nop

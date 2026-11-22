; func set_stats_consumer_bit_mask @ 0x006729c8 size=0x38
  6729c8:	14a00007 	bnez	a1,0x6729e8
  6729cc:	24030001 	li	v1,1
  6729d0:	10830007 	beq	a0,v1,0x6729f0
  6729d4:	3c02007d 	lui	v0,0x7d
  6729d8:	8c44ca0c 	lw	a0,-13812(v0)
  6729dc:	2403fffe 	li	v1,-2
  6729e0:	00831824 	and	v1,a0,v1
  6729e4:	ac43ca0c 	sw	v1,-13812(v0)
  6729e8:	03e00008 	jr	ra
  6729ec:	00000000 	nop
  6729f0:	8c43ca0c 	lw	v1,-13812(v0)
  6729f4:	34630001 	ori	v1,v1,0x1
  6729f8:	03e00008 	jr	ra
  6729fc:	ac43ca0c 	sw	v1,-13812(v0)

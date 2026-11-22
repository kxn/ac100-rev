; func _radius_attr_hash_cmp_func @ 0x00447760 size=0x14
  447760:	8c820044 	lw	v0,68(a0)
  447764:	8ca30000 	lw	v1,0(a1)
  447768:	00431026 	xor	v0,v0,v1
  44776c:	03e00008 	jr	ra
  447770:	2c420001 	sltiu	v0,v0,1

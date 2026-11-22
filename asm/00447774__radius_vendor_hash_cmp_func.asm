; func _radius_vendor_hash_cmp_func @ 0x00447774 size=0x14
  447774:	8c820044 	lw	v0,68(a0)
  447778:	8ca30000 	lw	v1,0(a1)
  44777c:	00431026 	xor	v0,v0,v1
  447780:	03e00008 	jr	ra
  447784:	2c420001 	sltiu	v0,v0,1

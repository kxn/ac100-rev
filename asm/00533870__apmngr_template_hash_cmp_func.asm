; func _apmngr_template_hash_cmp_func @ 0x00533870 size=0x14
  533870:	8c820040 	lw	v0,64(a0)
  533874:	8ca30000 	lw	v1,0(a1)
  533878:	00431026 	xor	v0,v0,v1
  53387c:	03e00008 	jr	ra
  533880:	2c420001 	sltiu	v0,v0,1

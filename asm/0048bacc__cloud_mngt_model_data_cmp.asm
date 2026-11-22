; func _cloud_mngt_model_data_cmp @ 0x0048bacc size=0x28
  48bacc:	10800007 	beqz	a0,0x48baec
  48bad0:	00001021 	move	v0,zero
  48bad4:	10a00005 	beqz	a1,0x48baec
  48bad8:	00000000 	nop
  48badc:	8c83000c 	lw	v1,12(a0)
  48bae0:	8ca20000 	lw	v0,0(a1)
  48bae4:	00621026 	xor	v0,v1,v0
  48bae8:	2c420001 	sltiu	v0,v0,1
  48baec:	03e00008 	jr	ra
  48baf0:	00000000 	nop

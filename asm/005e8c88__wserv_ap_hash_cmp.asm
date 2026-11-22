; func _wserv_ap_hash_cmp @ 0x005e8c88 size=0x28
  5e8c88:	10800007 	beqz	a0,0x5e8ca8
  5e8c8c:	00001021 	move	v0,zero
  5e8c90:	10a00005 	beqz	a1,0x5e8ca8
  5e8c94:	00000000 	nop
  5e8c98:	8c830000 	lw	v1,0(a0)
  5e8c9c:	8ca20000 	lw	v0,0(a1)
  5e8ca0:	00621026 	xor	v0,v1,v0
  5e8ca4:	2c420001 	sltiu	v0,v0,1
  5e8ca8:	03e00008 	jr	ra
  5e8cac:	00000000 	nop

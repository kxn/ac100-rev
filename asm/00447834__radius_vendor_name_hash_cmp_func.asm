; func _radius_vendor_name_hash_cmp_func @ 0x00447834 size=0x34
  447834:	3c1c0032 	lui	gp,0x32
  447838:	279c98cc 	addiu	gp,gp,-26420
  44783c:	0399e021 	addu	gp,gp,t9
  447840:	27bdffe0 	addiu	sp,sp,-32
  447844:	8f9985bc 	lw	t9,-31300(gp)
  447848:	afbc0010 	sw	gp,16(sp)
  44784c:	afbf001c 	sw	ra,28(sp)
  447850:	0320f809 	jalr	t9
  447854:	00000000 	nop
  447858:	8fbf001c 	lw	ra,28(sp)
  44785c:	2c420001 	sltiu	v0,v0,1
  447860:	03e00008 	jr	ra
  447864:	27bd0020 	addiu	sp,sp,32

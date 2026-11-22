; func _radius_attr_key_hash_func @ 0x00447b14 size=0x40
  447b14:	3c1c0032 	lui	gp,0x32
  447b18:	279c95ec 	addiu	gp,gp,-27156
  447b1c:	0399e021 	addu	gp,gp,t9
  447b20:	27bdffd8 	addiu	sp,sp,-40
  447b24:	8f998178 	lw	t9,-32392(gp)
  447b28:	24050004 	li	a1,4
  447b2c:	afbc0010 	sw	gp,16(sp)
  447b30:	00003021 	move	a2,zero
  447b34:	afbf0024 	sw	ra,36(sp)
  447b38:	8c820000 	lw	v0,0(a0)
  447b3c:	27a40018 	addiu	a0,sp,24
  447b40:	0320f809 	jalr	t9
  447b44:	afa20018 	sw	v0,24(sp)
  447b48:	8fbf0024 	lw	ra,36(sp)
  447b4c:	03e00008 	jr	ra
  447b50:	27bd0028 	addiu	sp,sp,40

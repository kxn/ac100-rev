; func _radius_vendor_key_hash_func @ 0x00447ab4 size=0x40
  447ab4:	3c1c0032 	lui	gp,0x32
  447ab8:	279c964c 	addiu	gp,gp,-27060
  447abc:	0399e021 	addu	gp,gp,t9
  447ac0:	27bdffd8 	addiu	sp,sp,-40
  447ac4:	8f998178 	lw	t9,-32392(gp)
  447ac8:	24050004 	li	a1,4
  447acc:	afbc0010 	sw	gp,16(sp)
  447ad0:	00003021 	move	a2,zero
  447ad4:	afbf0024 	sw	ra,36(sp)
  447ad8:	8c820000 	lw	v0,0(a0)
  447adc:	27a40018 	addiu	a0,sp,24
  447ae0:	0320f809 	jalr	t9
  447ae4:	afa20018 	sw	v0,24(sp)
  447ae8:	8fbf0024 	lw	ra,36(sp)
  447aec:	03e00008 	jr	ra
  447af0:	27bd0028 	addiu	sp,sp,40

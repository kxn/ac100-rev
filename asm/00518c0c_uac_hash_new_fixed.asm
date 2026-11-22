; func uac_hash_new_fixed @ 0x00518c0c size=0x34
  518c0c:	3c1c0025 	lui	gp,0x25
  518c10:	279c84f4 	addiu	gp,gp,-31500
  518c14:	0399e021 	addu	gp,gp,t9
  518c18:	27bdffd8 	addiu	sp,sp,-40
  518c1c:	8f9982f4 	lw	t9,-32012(gp)
  518c20:	afbc0018 	sw	gp,24(sp)
  518c24:	afa70010 	sw	a3,16(sp)
  518c28:	afbf0024 	sw	ra,36(sp)
  518c2c:	0411ffac 	bal	0x518ae0
  518c30:	00003821 	move	a3,zero
  518c34:	8fbf0024 	lw	ra,36(sp)
  518c38:	03e00008 	jr	ra
  518c3c:	27bd0028 	addiu	sp,sp,40

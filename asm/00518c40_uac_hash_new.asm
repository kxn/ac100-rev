; func uac_hash_new @ 0x00518c40 size=0x38
  518c40:	3c1c0025 	lui	gp,0x25
  518c44:	279c84c0 	addiu	gp,gp,-31552
  518c48:	0399e021 	addu	gp,gp,t9
  518c4c:	27bdffd8 	addiu	sp,sp,-40
  518c50:	8f9982f4 	lw	t9,-32012(gp)
  518c54:	2402001d 	li	v0,29
  518c58:	24070001 	li	a3,1
  518c5c:	afbc0018 	sw	gp,24(sp)
  518c60:	afbf0024 	sw	ra,36(sp)
  518c64:	0411ff9e 	bal	0x518ae0
  518c68:	afa20010 	sw	v0,16(sp)
  518c6c:	8fbf0024 	lw	ra,36(sp)
  518c70:	03e00008 	jr	ra
  518c74:	27bd0028 	addiu	sp,sp,40

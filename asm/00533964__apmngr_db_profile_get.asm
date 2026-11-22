; func _apmngr_db_profile_get @ 0x00533964 size=0x3c
  533964:	27bdffd8 	addiu	sp,sp,-40
  533968:	00802821 	move	a1,a0
  53396c:	3c04006a 	lui	a0,0x6a
  533970:	27a60018 	addiu	a2,sp,24
  533974:	afbf0024 	sw	ra,36(sp)
  533978:	2484c014 	addiu	a0,a0,-16364
  53397c:	0c147ad2 	jal	0x51eb48
  533980:	afa00018 	sw	zero,24(sp)
  533984:	10400002 	beqz	v0,0x533990
  533988:	2402ffff 	li	v0,-1
  53398c:	afa20018 	sw	v0,24(sp)
  533990:	8fbf0024 	lw	ra,36(sp)
  533994:	8fa20018 	lw	v0,24(sp)
  533998:	03e00008 	jr	ra
  53399c:	27bd0028 	addiu	sp,sp,40

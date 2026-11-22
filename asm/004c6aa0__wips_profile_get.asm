; func _wips_profile_get @ 0x004c6aa0 size=0x3c
  4c6aa0:	27bdffd8 	addiu	sp,sp,-40
  4c6aa4:	00802821 	move	a1,a0
  4c6aa8:	3c04006a 	lui	a0,0x6a
  4c6aac:	27a60018 	addiu	a2,sp,24
  4c6ab0:	afbf0024 	sw	ra,36(sp)
  4c6ab4:	248468d4 	addiu	a0,a0,26836
  4c6ab8:	0c147ad2 	jal	0x51eb48
  4c6abc:	afa00018 	sw	zero,24(sp)
  4c6ac0:	10400002 	beqz	v0,0x4c6acc
  4c6ac4:	2402ffff 	li	v0,-1
  4c6ac8:	afa20018 	sw	v0,24(sp)
  4c6acc:	8fbf0024 	lw	ra,36(sp)
  4c6ad0:	8fa20018 	lw	v0,24(sp)
  4c6ad4:	03e00008 	jr	ra
  4c6ad8:	27bd0028 	addiu	sp,sp,40

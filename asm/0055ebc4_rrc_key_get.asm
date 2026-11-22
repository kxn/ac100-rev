; func rrc_key_get @ 0x0055ebc4 size=0x24
  55ebc4:	10800006 	beqz	a0,0x55ebe0
  55ebc8:	2402ffff 	li	v0,-1
  55ebcc:	10a00004 	beqz	a1,0x55ebe0
  55ebd0:	00000000 	nop
  55ebd4:	8c820000 	lw	v0,0(a0)
  55ebd8:	aca20000 	sw	v0,0(a1)
  55ebdc:	00001021 	move	v0,zero
  55ebe0:	03e00008 	jr	ra
  55ebe4:	00000000 	nop

; func rrc_destroy @ 0x0055e7cc size=0x28
  55e7cc:	27bdffe0 	addiu	sp,sp,-32
  55e7d0:	2402ffff 	li	v0,-1
  55e7d4:	10800004 	beqz	a0,0x55e7e8
  55e7d8:	afbf001c 	sw	ra,28(sp)
  55e7dc:	0c101f7c 	jal	0x407df0
  55e7e0:	00000000 	nop
  55e7e4:	00001021 	move	v0,zero
  55e7e8:	8fbf001c 	lw	ra,28(sp)
  55e7ec:	03e00008 	jr	ra
  55e7f0:	27bd0020 	addiu	sp,sp,32

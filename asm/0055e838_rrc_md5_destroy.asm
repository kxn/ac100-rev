; func rrc_md5_destroy @ 0x0055e838 size=0x28
  55e838:	27bdffe0 	addiu	sp,sp,-32
  55e83c:	2402ffff 	li	v0,-1
  55e840:	10800004 	beqz	a0,0x55e854
  55e844:	afbf001c 	sw	ra,28(sp)
  55e848:	0c101f7c 	jal	0x407df0
  55e84c:	00000000 	nop
  55e850:	00001021 	move	v0,zero
  55e854:	8fbf001c 	lw	ra,28(sp)
  55e858:	03e00008 	jr	ra
  55e85c:	27bd0020 	addiu	sp,sp,32

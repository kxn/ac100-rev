; func _wportal_username_cmp_func @ 0x0042c5b4 size=0x30
  42c5b4:	27bdffe0 	addiu	sp,sp,-32
  42c5b8:	00001021 	move	v0,zero
  42c5bc:	10800006 	beqz	a0,0x42c5d8
  42c5c0:	afbf001c 	sw	ra,28(sp)
  42c5c4:	10a00005 	beqz	a1,0x42c5dc
  42c5c8:	8fbf001c 	lw	ra,28(sp)
  42c5cc:	0c101f44 	jal	0x407d10
  42c5d0:	00000000 	nop
  42c5d4:	2c420001 	sltiu	v0,v0,1
  42c5d8:	8fbf001c 	lw	ra,28(sp)
  42c5dc:	03e00008 	jr	ra
  42c5e0:	27bd0020 	addiu	sp,sp,32

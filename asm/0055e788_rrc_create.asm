; func rrc_create @ 0x0055e788 size=0x44
  55e788:	27bdffe0 	addiu	sp,sp,-32
  55e78c:	240401b4 	li	a0,436
  55e790:	afb00018 	sw	s0,24(sp)
  55e794:	afbf001c 	sw	ra,28(sp)
  55e798:	0c102114 	jal	0x408450
  55e79c:	24050113 	li	a1,275
  55e7a0:	10400005 	beqz	v0,0x55e7b8
  55e7a4:	00408021 	move	s0,v0
  55e7a8:	00002821 	move	a1,zero
  55e7ac:	240601b4 	li	a2,436
  55e7b0:	0c101cf0 	jal	0x4073c0
  55e7b4:	00402021 	move	a0,v0
  55e7b8:	8fbf001c 	lw	ra,28(sp)
  55e7bc:	02001021 	move	v0,s0
  55e7c0:	8fb00018 	lw	s0,24(sp)
  55e7c4:	03e00008 	jr	ra
  55e7c8:	27bd0020 	addiu	sp,sp,32

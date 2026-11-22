; func rrc_md5_create @ 0x0055e7f4 size=0x44
  55e7f4:	27bdffe0 	addiu	sp,sp,-32
  55e7f8:	24040048 	li	a0,72
  55e7fc:	afb00018 	sw	s0,24(sp)
  55e800:	afbf001c 	sw	ra,28(sp)
  55e804:	0c102114 	jal	0x408450
  55e808:	24050136 	li	a1,310
  55e80c:	10400005 	beqz	v0,0x55e824
  55e810:	00408021 	move	s0,v0
  55e814:	00002821 	move	a1,zero
  55e818:	24060048 	li	a2,72
  55e81c:	0c101cf0 	jal	0x4073c0
  55e820:	00402021 	move	a0,v0
  55e824:	8fbf001c 	lw	ra,28(sp)
  55e828:	02001021 	move	v0,s0
  55e82c:	8fb00018 	lw	s0,24(sp)
  55e830:	03e00008 	jr	ra
  55e834:	27bd0020 	addiu	sp,sp,32

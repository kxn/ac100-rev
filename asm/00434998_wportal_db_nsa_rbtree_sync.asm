; func wportal_db_nsa_rbtree_sync @ 0x00434998 size=0x4c
  434998:	3c020076 	lui	v0,0x76
  43499c:	27bdffe0 	addiu	sp,sp,-32
  4349a0:	8c42a0b8 	lw	v0,-24392(v0)
  4349a4:	14400004 	bnez	v0,0x4349b8
  4349a8:	afbf001c 	sw	ra,28(sp)
  4349ac:	8fbf001c 	lw	ra,28(sp)
  4349b0:	03e00008 	jr	ra
  4349b4:	27bd0020 	addiu	sp,sp,32
  4349b8:	0c16276a 	jal	0x589da8
  4349bc:	00000000 	nop
  4349c0:	1040fffb 	beqz	v0,0x4349b0
  4349c4:	8fbf001c 	lw	ra,28(sp)
  4349c8:	3c040068 	lui	a0,0x68
  4349cc:	3c050068 	lui	a1,0x68
  4349d0:	2484e63c 	addiu	a0,a0,-6596
  4349d4:	24a5ec88 	addiu	a1,a1,-4984
  4349d8:	24061e88 	li	a2,7816
  4349dc:	08101b74 	j	0x406dd0
  4349e0:	27bd0020 	addiu	sp,sp,32

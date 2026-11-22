; func _wportal_wserv_del_rdt_ftt @ 0x004151a4 size=0x64
  4151a4:	27bdffe0 	addiu	sp,sp,-32
  4151a8:	10c00004 	beqz	a2,0x4151bc
  4151ac:	afbf001c 	sw	ra,28(sp)
  4151b0:	8fbf001c 	lw	ra,28(sp)
  4151b4:	081053aa 	j	0x414ea8
  4151b8:	27bd0020 	addiu	sp,sp,32
  4151bc:	3c020073 	lui	v0,0x73
  4151c0:	8c421230 	lw	v0,4656(v0)
  4151c4:	10400006 	beqz	v0,0x4151e0
  4151c8:	8fbf001c 	lw	ra,28(sp)
  4151cc:	0c16276a 	jal	0x589da8
  4151d0:	00000000 	nop
  4151d4:	14400005 	bnez	v0,0x4151ec
  4151d8:	3c040068 	lui	a0,0x68
  4151dc:	8fbf001c 	lw	ra,28(sp)
  4151e0:	2402ffff 	li	v0,-1
  4151e4:	03e00008 	jr	ra
  4151e8:	27bd0020 	addiu	sp,sp,32
  4151ec:	3c050068 	lui	a1,0x68
  4151f0:	24848228 	addiu	a0,a0,-32216
  4151f4:	24a5c040 	addiu	a1,a1,-16320
  4151f8:	0c101b74 	jal	0x406dd0
  4151fc:	24061d7c 	li	a2,7548
  415200:	08105478 	j	0x4151e0
  415204:	8fbf001c 	lw	ra,28(sp)

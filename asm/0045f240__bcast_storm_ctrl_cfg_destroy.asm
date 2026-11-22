; func _bcast_storm_ctrl_cfg_destroy @ 0x0045f240 size=0x5c
  45f240:	27bdffe0 	addiu	sp,sp,-32
  45f244:	10800004 	beqz	a0,0x45f258
  45f248:	afbf001c 	sw	ra,28(sp)
  45f24c:	8fbf001c 	lw	ra,28(sp)
  45f250:	08101f7c 	j	0x407df0
  45f254:	27bd0020 	addiu	sp,sp,32
  45f258:	3c020076 	lui	v0,0x76
  45f25c:	8c427070 	lw	v0,28784(v0)
  45f260:	14400003 	bnez	v0,0x45f270
  45f264:	8fbf001c 	lw	ra,28(sp)
  45f268:	03e00008 	jr	ra
  45f26c:	27bd0020 	addiu	sp,sp,32
  45f270:	0c16276a 	jal	0x589da8
  45f274:	00000000 	nop
  45f278:	1040fffb 	beqz	v0,0x45f268
  45f27c:	8fbf001c 	lw	ra,28(sp)
  45f280:	3c040069 	lui	a0,0x69
  45f284:	3c050069 	lui	a1,0x69
  45f288:	2484b440 	addiu	a0,a0,-19392
  45f28c:	24a5b8a0 	addiu	a1,a1,-18272
  45f290:	240600b9 	li	a2,185
  45f294:	08101b74 	j	0x406dd0
  45f298:	27bd0020 	addiu	sp,sp,32

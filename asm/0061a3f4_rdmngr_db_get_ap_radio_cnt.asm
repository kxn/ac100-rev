; func rdmngr_db_get_ap_radio_cnt @ 0x0061a3f4 size=0x74
  61a3f4:	27bdffe0 	addiu	sp,sp,-32
  61a3f8:	afb00018 	sw	s0,24(sp)
  61a3fc:	afbf001c 	sw	ra,28(sp)
  61a400:	0c1827fb 	jal	0x609fec
  61a404:	00000000 	nop
  61a408:	00408021 	move	s0,v0
  61a40c:	2402ffff 	li	v0,-1
  61a410:	12020006 	beq	s0,v0,0x61a42c
  61a414:	3c020075 	lui	v0,0x75
  61a418:	8fbf001c 	lw	ra,28(sp)
  61a41c:	02001021 	move	v0,s0
  61a420:	8fb00018 	lw	s0,24(sp)
  61a424:	03e00008 	jr	ra
  61a428:	27bd0020 	addiu	sp,sp,32
  61a42c:	8c42feb4 	lw	v0,-332(v0)
  61a430:	1040fffa 	beqz	v0,0x61a41c
  61a434:	8fbf001c 	lw	ra,28(sp)
  61a438:	0c16276a 	jal	0x589da8
  61a43c:	00000000 	nop
  61a440:	5040fff6 	beqzl	v0,0x61a41c
  61a444:	8fbf001c 	lw	ra,28(sp)
  61a448:	3c040071 	lui	a0,0x71
  61a44c:	3c050071 	lui	a1,0x71
  61a450:	248484a0 	addiu	a0,a0,-31584
  61a454:	24a5a81c 	addiu	a1,a1,-22500
  61a458:	0c101b74 	jal	0x406dd0
  61a45c:	24060676 	li	a2,1654
  61a460:	08186907 	j	0x61a41c
  61a464:	8fbf001c 	lw	ra,28(sp)

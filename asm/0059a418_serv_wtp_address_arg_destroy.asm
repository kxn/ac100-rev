; func serv_wtp_address_arg_destroy @ 0x0059a418 size=0x5c
  59a418:	27bdffe0 	addiu	sp,sp,-32
  59a41c:	afb00018 	sw	s0,24(sp)
  59a420:	00808021 	move	s0,a0
  59a424:	1080000f 	beqz	a0,0x59a464
  59a428:	afbf001c 	sw	ra,28(sp)
  59a42c:	0c16687c 	jal	0x59a1f0
  59a430:	00000000 	nop
  59a434:	8e040000 	lw	a0,0(s0)
  59a438:	50800005 	beqzl	a0,0x59a450
  59a43c:	8e040004 	lw	a0,4(s0)
  59a440:	0c101f7c 	jal	0x407df0
  59a444:	00000000 	nop
  59a448:	ae000000 	sw	zero,0(s0)
  59a44c:	8e040004 	lw	a0,4(s0)
  59a450:	10800005 	beqz	a0,0x59a468
  59a454:	8fbf001c 	lw	ra,28(sp)
  59a458:	0c101f7c 	jal	0x407df0
  59a45c:	00000000 	nop
  59a460:	ae000004 	sw	zero,4(s0)
  59a464:	8fbf001c 	lw	ra,28(sp)
  59a468:	8fb00018 	lw	s0,24(sp)
  59a46c:	03e00008 	jr	ra
  59a470:	27bd0020 	addiu	sp,sp,32

; func uac_sem_destroy @ 0x00523444 size=0x78
  523444:	3c1c0024 	lui	gp,0x24
  523448:	279cdcbc 	addiu	gp,gp,-9028
  52344c:	0399e021 	addu	gp,gp,t9
  523450:	27bdffe0 	addiu	sp,sp,-32
  523454:	afbc0010 	sw	gp,16(sp)
  523458:	afb00018 	sw	s0,24(sp)
  52345c:	00808021 	move	s0,a0
  523460:	10800012 	beqz	a0,0x5234ac
  523464:	afbf001c 	sw	ra,28(sp)
  523468:	8f998540 	lw	t9,-31424(gp)
  52346c:	0320f809 	jalr	t9
  523470:	00000000 	nop
  523474:	8e040010 	lw	a0,16(s0)
  523478:	10800006 	beqz	a0,0x523494
  52347c:	8fbc0010 	lw	gp,16(sp)
  523480:	8f998054 	lw	t9,-32684(gp)
  523484:	0411ead3 	bal	0x51dfd4
  523488:	00000000 	nop
  52348c:	8fbc0010 	lw	gp,16(sp)
  523490:	ae000010 	sw	zero,16(s0)
  523494:	02002021 	move	a0,s0
  523498:	8fbf001c 	lw	ra,28(sp)
  52349c:	8fb00018 	lw	s0,24(sp)
  5234a0:	8f998054 	lw	t9,-32684(gp)
  5234a4:	1000eacb 	b	0x51dfd4
  5234a8:	27bd0020 	addiu	sp,sp,32
  5234ac:	8fbf001c 	lw	ra,28(sp)
  5234b0:	8fb00018 	lw	s0,24(sp)
  5234b4:	03e00008 	jr	ra
  5234b8:	27bd0020 	addiu	sp,sp,32

; func cw_priv_radio_role_table_control_free @ 0x0057e450 size=0x74
  57e450:	3c02007c 	lui	v0,0x7c
  57e454:	27bdffe0 	addiu	sp,sp,-32
  57e458:	8c425988 	lw	v0,22920(v0)
  57e45c:	afb00018 	sw	s0,24(sp)
  57e460:	00808021 	move	s0,a0
  57e464:	1440000b 	bnez	v0,0x57e494
  57e468:	afbf001c 	sw	ra,28(sp)
  57e46c:	8e040010 	lw	a0,16(s0)
  57e470:	10800004 	beqz	a0,0x57e484
  57e474:	8fbf001c 	lw	ra,28(sp)
  57e478:	0c15f8e5 	jal	0x57e394
  57e47c:	00000000 	nop
  57e480:	8fbf001c 	lw	ra,28(sp)
  57e484:	00001021 	move	v0,zero
  57e488:	8fb00018 	lw	s0,24(sp)
  57e48c:	03e00008 	jr	ra
  57e490:	27bd0020 	addiu	sp,sp,32
  57e494:	0c16276a 	jal	0x589da8
  57e498:	00000000 	nop
  57e49c:	5040fff4 	beqzl	v0,0x57e470
  57e4a0:	8e040010 	lw	a0,16(s0)
  57e4a4:	3c04006e 	lui	a0,0x6e
  57e4a8:	3c05006e 	lui	a1,0x6e
  57e4ac:	2484a8e4 	addiu	a0,a0,-22300
  57e4b0:	24a5ac70 	addiu	a1,a1,-21392
  57e4b4:	0c101b74 	jal	0x406dd0
  57e4b8:	2406017c 	li	a2,380
  57e4bc:	0815f91c 	j	0x57e470
  57e4c0:	8e040010 	lw	a0,16(s0)

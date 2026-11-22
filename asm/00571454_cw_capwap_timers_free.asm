; func cw_capwap_timers_free @ 0x00571454 size=0x3c
  571454:	27bdffe0 	addiu	sp,sp,-32
  571458:	afb00018 	sw	s0,24(sp)
  57145c:	00808021 	move	s0,a0
  571460:	afbf001c 	sw	ra,28(sp)
  571464:	8c840010 	lw	a0,16(a0)
  571468:	10800005 	beqz	a0,0x571480
  57146c:	8fbf001c 	lw	ra,28(sp)
  571470:	0c101f7c 	jal	0x407df0
  571474:	00000000 	nop
  571478:	ae000010 	sw	zero,16(s0)
  57147c:	8fbf001c 	lw	ra,28(sp)
  571480:	00001021 	move	v0,zero
  571484:	8fb00018 	lw	s0,24(sp)
  571488:	03e00008 	jr	ra
  57148c:	27bd0020 	addiu	sp,sp,32

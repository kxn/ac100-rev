; func cw_idle_timeout_free @ 0x00576400 size=0x3c
  576400:	27bdffe0 	addiu	sp,sp,-32
  576404:	afb00018 	sw	s0,24(sp)
  576408:	00808021 	move	s0,a0
  57640c:	afbf001c 	sw	ra,28(sp)
  576410:	8c840010 	lw	a0,16(a0)
  576414:	10800005 	beqz	a0,0x57642c
  576418:	8fbf001c 	lw	ra,28(sp)
  57641c:	0c101f7c 	jal	0x407df0
  576420:	00000000 	nop
  576424:	ae000010 	sw	zero,16(s0)
  576428:	8fbf001c 	lw	ra,28(sp)
  57642c:	00001021 	move	v0,zero
  576430:	8fb00018 	lw	s0,24(sp)
  576434:	03e00008 	jr	ra
  576438:	27bd0020 	addiu	sp,sp,32

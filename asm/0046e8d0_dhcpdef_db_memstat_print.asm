; func dhcpdef_db_memstat_print @ 0x0046e8d0 size=0x3c
  46e8d0:	27bdffe0 	addiu	sp,sp,-32
  46e8d4:	afb00018 	sw	s0,24(sp)
  46e8d8:	3c100069 	lui	s0,0x69
  46e8dc:	afbf001c 	sw	ra,28(sp)
  46e8e0:	0c101dd4 	jal	0x407750
  46e8e4:	2604d614 	addiu	a0,s0,-10732
  46e8e8:	3c040069 	lui	a0,0x69
  46e8ec:	00002821 	move	a1,zero
  46e8f0:	0c101b74 	jal	0x406dd0
  46e8f4:	2484df90 	addiu	a0,a0,-8304
  46e8f8:	2604d614 	addiu	a0,s0,-10732
  46e8fc:	8fbf001c 	lw	ra,28(sp)
  46e900:	8fb00018 	lw	s0,24(sp)
  46e904:	08101dd4 	j	0x407750
  46e908:	27bd0020 	addiu	sp,sp,32

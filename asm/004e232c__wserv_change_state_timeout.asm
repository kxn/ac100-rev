; func _wserv_change_state_timeout @ 0x004e232c size=0x44
  4e232c:	27bdffe0 	addiu	sp,sp,-32
  4e2330:	2405ffff 	li	a1,-1
  4e2334:	afb00018 	sw	s0,24(sp)
  4e2338:	3c100077 	lui	s0,0x77
  4e233c:	afbf001c 	sw	ra,28(sp)
  4e2340:	0c1020b4 	jal	0x4082d0
  4e2344:	8e04862c 	lw	a0,-31188(s0)
  4e2348:	3c020073 	lui	v0,0x73
  4e234c:	2403ffff 	li	v1,-1
  4e2350:	8e04862c 	lw	a0,-31188(s0)
  4e2354:	8fbf001c 	lw	ra,28(sp)
  4e2358:	8fb00018 	lw	s0,24(sp)
  4e235c:	27bd0020 	addiu	sp,sp,32
  4e2360:	ac431b00 	sw	v1,6912(v0)
  4e2364:	3c020077 	lui	v0,0x77
  4e2368:	08101fcc 	j	0x407f30
  4e236c:	ac408658 	sw	zero,-31144(v0)

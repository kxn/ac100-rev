; func rdmngr_uninit @ 0x0061830c size=0x3c
  61830c:	27bdffe0 	addiu	sp,sp,-32
  618310:	afb00018 	sw	s0,24(sp)
  618314:	3c10007d 	lui	s0,0x7d
  618318:	afbf001c 	sw	ra,28(sp)
  61831c:	8e04c614 	lw	a0,-14828(s0)
  618320:	10800005 	beqz	a0,0x618338
  618324:	8fbf001c 	lw	ra,28(sp)
  618328:	0c1020d8 	jal	0x408360
  61832c:	00000000 	nop
  618330:	ae00c614 	sw	zero,-14828(s0)
  618334:	8fbf001c 	lw	ra,28(sp)
  618338:	00001021 	move	v0,zero
  61833c:	8fb00018 	lw	s0,24(sp)
  618340:	03e00008 	jr	ra
  618344:	27bd0020 	addiu	sp,sp,32
	...

; func cw_priv_lag_config_free @ 0x005b4348 size=0x4c
  5b4348:	27bdffe0 	addiu	sp,sp,-32
  5b434c:	afbf001c 	sw	ra,28(sp)
  5b4350:	afb00018 	sw	s0,24(sp)
  5b4354:	8c900010 	lw	s0,16(a0)
  5b4358:	1200000a 	beqz	s0,0x5b4384
  5b435c:	8fbf001c 	lw	ra,28(sp)
  5b4360:	8e040004 	lw	a0,4(s0)
  5b4364:	10800004 	beqz	a0,0x5b4378
  5b4368:	00000000 	nop
  5b436c:	0c101f7c 	jal	0x407df0
  5b4370:	00000000 	nop
  5b4374:	ae000004 	sw	zero,4(s0)
  5b4378:	0c101f7c 	jal	0x407df0
  5b437c:	02002021 	move	a0,s0
  5b4380:	8fbf001c 	lw	ra,28(sp)
  5b4384:	00001021 	move	v0,zero
  5b4388:	8fb00018 	lw	s0,24(sp)
  5b438c:	03e00008 	jr	ra
  5b4390:	27bd0020 	addiu	sp,sp,32

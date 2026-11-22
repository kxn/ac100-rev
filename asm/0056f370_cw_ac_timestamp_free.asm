; func cw_ac_timestamp_free @ 0x0056f370 size=0x3c
  56f370:	27bdffe0 	addiu	sp,sp,-32
  56f374:	afb00018 	sw	s0,24(sp)
  56f378:	00808021 	move	s0,a0
  56f37c:	afbf001c 	sw	ra,28(sp)
  56f380:	8c840010 	lw	a0,16(a0)
  56f384:	10800005 	beqz	a0,0x56f39c
  56f388:	8fbf001c 	lw	ra,28(sp)
  56f38c:	0c101f7c 	jal	0x407df0
  56f390:	00000000 	nop
  56f394:	ae000010 	sw	zero,16(s0)
  56f398:	8fbf001c 	lw	ra,28(sp)
  56f39c:	00001021 	move	v0,zero
  56f3a0:	8fb00018 	lw	s0,24(sp)
  56f3a4:	03e00008 	jr	ra
  56f3a8:	27bd0020 	addiu	sp,sp,32

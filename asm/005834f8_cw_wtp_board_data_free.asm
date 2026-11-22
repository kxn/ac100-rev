; func cw_wtp_board_data_free @ 0x005834f8 size=0x3c
  5834f8:	27bdffe0 	addiu	sp,sp,-32
  5834fc:	afb00018 	sw	s0,24(sp)
  583500:	00808021 	move	s0,a0
  583504:	afbf001c 	sw	ra,28(sp)
  583508:	8c840010 	lw	a0,16(a0)
  58350c:	10800005 	beqz	a0,0x583524
  583510:	8fbf001c 	lw	ra,28(sp)
  583514:	0c160d1e 	jal	0x583478
  583518:	00000000 	nop
  58351c:	ae000010 	sw	zero,16(s0)
  583520:	8fbf001c 	lw	ra,28(sp)
  583524:	00001021 	move	v0,zero
  583528:	8fb00018 	lw	s0,24(sp)
  58352c:	03e00008 	jr	ra
  583530:	27bd0020 	addiu	sp,sp,32

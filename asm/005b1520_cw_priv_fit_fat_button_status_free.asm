; func cw_priv_fit_fat_button_status_free @ 0x005b1520 size=0x3c
  5b1520:	27bdffe0 	addiu	sp,sp,-32
  5b1524:	afb00018 	sw	s0,24(sp)
  5b1528:	00808021 	move	s0,a0
  5b152c:	afbf001c 	sw	ra,28(sp)
  5b1530:	8c840010 	lw	a0,16(a0)
  5b1534:	10800005 	beqz	a0,0x5b154c
  5b1538:	8fbf001c 	lw	ra,28(sp)
  5b153c:	0c101f7c 	jal	0x407df0
  5b1540:	00000000 	nop
  5b1544:	ae000010 	sw	zero,16(s0)
  5b1548:	8fbf001c 	lw	ra,28(sp)
  5b154c:	00001021 	move	v0,zero
  5b1550:	8fb00018 	lw	s0,24(sp)
  5b1554:	03e00008 	jr	ra
  5b1558:	27bd0020 	addiu	sp,sp,32

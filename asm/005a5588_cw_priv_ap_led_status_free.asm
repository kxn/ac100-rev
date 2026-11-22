; func cw_priv_ap_led_status_free @ 0x005a5588 size=0x3c
  5a5588:	27bdffe0 	addiu	sp,sp,-32
  5a558c:	afb00018 	sw	s0,24(sp)
  5a5590:	00808021 	move	s0,a0
  5a5594:	afbf001c 	sw	ra,28(sp)
  5a5598:	8c840010 	lw	a0,16(a0)
  5a559c:	10800005 	beqz	a0,0x5a55b4
  5a55a0:	8fbf001c 	lw	ra,28(sp)
  5a55a4:	0c101f7c 	jal	0x407df0
  5a55a8:	00000000 	nop
  5a55ac:	ae000010 	sw	zero,16(s0)
  5a55b0:	8fbf001c 	lw	ra,28(sp)
  5a55b4:	00001021 	move	v0,zero
  5a55b8:	8fb00018 	lw	s0,24(sp)
  5a55bc:	03e00008 	jr	ra
  5a55c0:	27bd0020 	addiu	sp,sp,32

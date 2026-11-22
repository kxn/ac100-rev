; func cw_priv_statistics_control_free @ 0x005c83a0 size=0x3c
  5c83a0:	27bdffe0 	addiu	sp,sp,-32
  5c83a4:	afb00018 	sw	s0,24(sp)
  5c83a8:	00808021 	move	s0,a0
  5c83ac:	afbf001c 	sw	ra,28(sp)
  5c83b0:	8c840010 	lw	a0,16(a0)
  5c83b4:	10800005 	beqz	a0,0x5c83cc
  5c83b8:	8fbf001c 	lw	ra,28(sp)
  5c83bc:	0c101f7c 	jal	0x407df0
  5c83c0:	00000000 	nop
  5c83c4:	ae000010 	sw	zero,16(s0)
  5c83c8:	8fbf001c 	lw	ra,28(sp)
  5c83cc:	00001021 	move	v0,zero
  5c83d0:	8fb00018 	lw	s0,24(sp)
  5c83d4:	03e00008 	jr	ra
  5c83d8:	27bd0020 	addiu	sp,sp,32

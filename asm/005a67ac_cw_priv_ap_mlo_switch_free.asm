; func cw_priv_ap_mlo_switch_free @ 0x005a67ac size=0x3c
  5a67ac:	27bdffe0 	addiu	sp,sp,-32
  5a67b0:	afb00018 	sw	s0,24(sp)
  5a67b4:	00808021 	move	s0,a0
  5a67b8:	afbf001c 	sw	ra,28(sp)
  5a67bc:	8c840010 	lw	a0,16(a0)
  5a67c0:	10800005 	beqz	a0,0x5a67d8
  5a67c4:	8fbf001c 	lw	ra,28(sp)
  5a67c8:	0c101f7c 	jal	0x407df0
  5a67cc:	00000000 	nop
  5a67d0:	ae000010 	sw	zero,16(s0)
  5a67d4:	8fbf001c 	lw	ra,28(sp)
  5a67d8:	00001021 	move	v0,zero
  5a67dc:	8fb00018 	lw	s0,24(sp)
  5a67e0:	03e00008 	jr	ra
  5a67e4:	27bd0020 	addiu	sp,sp,32

; func cw_priv_11ax_rate_free @ 0x005a27e0 size=0x3c
  5a27e0:	27bdffe0 	addiu	sp,sp,-32
  5a27e4:	afb00018 	sw	s0,24(sp)
  5a27e8:	00808021 	move	s0,a0
  5a27ec:	afbf001c 	sw	ra,28(sp)
  5a27f0:	8c840010 	lw	a0,16(a0)
  5a27f4:	10800005 	beqz	a0,0x5a280c
  5a27f8:	8fbf001c 	lw	ra,28(sp)
  5a27fc:	0c101f7c 	jal	0x407df0
  5a2800:	00000000 	nop
  5a2804:	ae000010 	sw	zero,16(s0)
  5a2808:	8fbf001c 	lw	ra,28(sp)
  5a280c:	00001021 	move	v0,zero
  5a2810:	8fb00018 	lw	s0,24(sp)
  5a2814:	03e00008 	jr	ra
  5a2818:	27bd0020 	addiu	sp,sp,32

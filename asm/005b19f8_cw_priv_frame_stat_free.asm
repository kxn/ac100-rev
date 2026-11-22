; func cw_priv_frame_stat_free @ 0x005b19f8 size=0x3c
  5b19f8:	27bdffe0 	addiu	sp,sp,-32
  5b19fc:	afb00018 	sw	s0,24(sp)
  5b1a00:	00808021 	move	s0,a0
  5b1a04:	afbf001c 	sw	ra,28(sp)
  5b1a08:	8c840010 	lw	a0,16(a0)
  5b1a0c:	10800005 	beqz	a0,0x5b1a24
  5b1a10:	8fbf001c 	lw	ra,28(sp)
  5b1a14:	0c101f7c 	jal	0x407df0
  5b1a18:	00000000 	nop
  5b1a1c:	ae000010 	sw	zero,16(s0)
  5b1a20:	8fbf001c 	lw	ra,28(sp)
  5b1a24:	00001021 	move	v0,zero
  5b1a28:	8fb00018 	lw	s0,24(sp)
  5b1a2c:	03e00008 	jr	ra
  5b1a30:	27bd0020 	addiu	sp,sp,32

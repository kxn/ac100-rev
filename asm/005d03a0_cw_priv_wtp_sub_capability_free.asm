; func cw_priv_wtp_sub_capability_free @ 0x005d03a0 size=0x4c
  5d03a0:	27bdffe0 	addiu	sp,sp,-32
  5d03a4:	afb00018 	sw	s0,24(sp)
  5d03a8:	afbf001c 	sw	ra,28(sp)
  5d03ac:	8c820010 	lw	v0,16(a0)
  5d03b0:	10400009 	beqz	v0,0x5d03d8
  5d03b4:	00808021 	move	s0,a0
  5d03b8:	8c440004 	lw	a0,4(v0)
  5d03bc:	10800003 	beqz	a0,0x5d03cc
  5d03c0:	00000000 	nop
  5d03c4:	0c101f7c 	jal	0x407df0
  5d03c8:	00000000 	nop
  5d03cc:	0c101f7c 	jal	0x407df0
  5d03d0:	8e040010 	lw	a0,16(s0)
  5d03d4:	ae000010 	sw	zero,16(s0)
  5d03d8:	8fbf001c 	lw	ra,28(sp)
  5d03dc:	00001021 	move	v0,zero
  5d03e0:	8fb00018 	lw	s0,24(sp)
  5d03e4:	03e00008 	jr	ra
  5d03e8:	27bd0020 	addiu	sp,sp,32

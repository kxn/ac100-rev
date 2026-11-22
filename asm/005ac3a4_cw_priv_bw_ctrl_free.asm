; func cw_priv_bw_ctrl_free @ 0x005ac3a4 size=0x58
  5ac3a4:	27bdffd8 	addiu	sp,sp,-40
  5ac3a8:	afb10020 	sw	s1,32(sp)
  5ac3ac:	afbf0024 	sw	ra,36(sp)
  5ac3b0:	afb0001c 	sw	s0,28(sp)
  5ac3b4:	8c900010 	lw	s0,16(a0)
  5ac3b8:	1200000a 	beqz	s0,0x5ac3e4
  5ac3bc:	00808821 	move	s1,a0
  5ac3c0:	8e04000c 	lw	a0,12(s0)
  5ac3c4:	10800004 	beqz	a0,0x5ac3d8
  5ac3c8:	00000000 	nop
  5ac3cc:	0c101f7c 	jal	0x407df0
  5ac3d0:	00000000 	nop
  5ac3d4:	ae00000c 	sw	zero,12(s0)
  5ac3d8:	0c101f7c 	jal	0x407df0
  5ac3dc:	02002021 	move	a0,s0
  5ac3e0:	ae200010 	sw	zero,16(s1)
  5ac3e4:	8fbf0024 	lw	ra,36(sp)
  5ac3e8:	00001021 	move	v0,zero
  5ac3ec:	8fb10020 	lw	s1,32(sp)
  5ac3f0:	8fb0001c 	lw	s0,28(sp)
  5ac3f4:	03e00008 	jr	ra
  5ac3f8:	27bd0028 	addiu	sp,sp,40

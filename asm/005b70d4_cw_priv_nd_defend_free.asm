; func cw_priv_nd_defend_free @ 0x005b70d4 size=0x58
  5b70d4:	27bdffd8 	addiu	sp,sp,-40
  5b70d8:	afb10020 	sw	s1,32(sp)
  5b70dc:	afbf0024 	sw	ra,36(sp)
  5b70e0:	afb0001c 	sw	s0,28(sp)
  5b70e4:	8c900010 	lw	s0,16(a0)
  5b70e8:	1200000a 	beqz	s0,0x5b7114
  5b70ec:	00808821 	move	s1,a0
  5b70f0:	8e040008 	lw	a0,8(s0)
  5b70f4:	10800004 	beqz	a0,0x5b7108
  5b70f8:	00000000 	nop
  5b70fc:	0c101f7c 	jal	0x407df0
  5b7100:	00000000 	nop
  5b7104:	ae000008 	sw	zero,8(s0)
  5b7108:	0c101f7c 	jal	0x407df0
  5b710c:	02002021 	move	a0,s0
  5b7110:	ae200010 	sw	zero,16(s1)
  5b7114:	8fbf0024 	lw	ra,36(sp)
  5b7118:	00001021 	move	v0,zero
  5b711c:	8fb10020 	lw	s1,32(sp)
  5b7120:	8fb0001c 	lw	s0,28(sp)
  5b7124:	03e00008 	jr	ra
  5b7128:	27bd0028 	addiu	sp,sp,40

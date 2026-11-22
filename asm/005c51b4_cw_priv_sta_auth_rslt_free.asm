; func cw_priv_sta_auth_rslt_free @ 0x005c51b4 size=0x54
  5c51b4:	27bdffd8 	addiu	sp,sp,-40
  5c51b8:	afb10020 	sw	s1,32(sp)
  5c51bc:	afbf0024 	sw	ra,36(sp)
  5c51c0:	afb0001c 	sw	s0,28(sp)
  5c51c4:	8c900010 	lw	s0,16(a0)
  5c51c8:	12000009 	beqz	s0,0x5c51f0
  5c51cc:	00808821 	move	s1,a0
  5c51d0:	8e040010 	lw	a0,16(s0)
  5c51d4:	10800003 	beqz	a0,0x5c51e4
  5c51d8:	00000000 	nop
  5c51dc:	0c101f7c 	jal	0x407df0
  5c51e0:	00000000 	nop
  5c51e4:	0c101f7c 	jal	0x407df0
  5c51e8:	02002021 	move	a0,s0
  5c51ec:	ae200010 	sw	zero,16(s1)
  5c51f0:	8fbf0024 	lw	ra,36(sp)
  5c51f4:	00001021 	move	v0,zero
  5c51f8:	8fb10020 	lw	s1,32(sp)
  5c51fc:	8fb0001c 	lw	s0,28(sp)
  5c5200:	03e00008 	jr	ra
  5c5204:	27bd0028 	addiu	sp,sp,40

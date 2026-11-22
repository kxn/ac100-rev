; func cw_priv_ap_statistics_free @ 0x005a79e8 size=0x68
  5a79e8:	27bdffd8 	addiu	sp,sp,-40
  5a79ec:	afb10020 	sw	s1,32(sp)
  5a79f0:	afbf0024 	sw	ra,36(sp)
  5a79f4:	afb0001c 	sw	s0,28(sp)
  5a79f8:	8c900010 	lw	s0,16(a0)
  5a79fc:	1200000e 	beqz	s0,0x5a7a38
  5a7a00:	00808821 	move	s1,a0
  5a7a04:	8e04002c 	lw	a0,44(s0)
  5a7a08:	50800004 	beqzl	a0,0x5a7a1c
  5a7a0c:	8e040030 	lw	a0,48(s0)
  5a7a10:	0c101f7c 	jal	0x407df0
  5a7a14:	00000000 	nop
  5a7a18:	8e040030 	lw	a0,48(s0)
  5a7a1c:	10800003 	beqz	a0,0x5a7a2c
  5a7a20:	00000000 	nop
  5a7a24:	0c101f7c 	jal	0x407df0
  5a7a28:	00000000 	nop
  5a7a2c:	0c101f7c 	jal	0x407df0
  5a7a30:	02002021 	move	a0,s0
  5a7a34:	ae200010 	sw	zero,16(s1)
  5a7a38:	8fbf0024 	lw	ra,36(sp)
  5a7a3c:	00001021 	move	v0,zero
  5a7a40:	8fb10020 	lw	s1,32(sp)
  5a7a44:	8fb0001c 	lw	s0,28(sp)
  5a7a48:	03e00008 	jr	ra
  5a7a4c:	27bd0028 	addiu	sp,sp,40

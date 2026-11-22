; func cw_priv_fail_station_free @ 0x005b0e04 size=0x54
  5b0e04:	27bdffd8 	addiu	sp,sp,-40
  5b0e08:	afb10020 	sw	s1,32(sp)
  5b0e0c:	afbf0024 	sw	ra,36(sp)
  5b0e10:	afb0001c 	sw	s0,28(sp)
  5b0e14:	8c900010 	lw	s0,16(a0)
  5b0e18:	12000009 	beqz	s0,0x5b0e40
  5b0e1c:	00808821 	move	s1,a0
  5b0e20:	8e040004 	lw	a0,4(s0)
  5b0e24:	10800003 	beqz	a0,0x5b0e34
  5b0e28:	00000000 	nop
  5b0e2c:	0c101f7c 	jal	0x407df0
  5b0e30:	00000000 	nop
  5b0e34:	0c101f7c 	jal	0x407df0
  5b0e38:	02002021 	move	a0,s0
  5b0e3c:	ae200010 	sw	zero,16(s1)
  5b0e40:	8fbf0024 	lw	ra,36(sp)
  5b0e44:	00001021 	move	v0,zero
  5b0e48:	8fb10020 	lw	s1,32(sp)
  5b0e4c:	8fb0001c 	lw	s0,28(sp)
  5b0e50:	03e00008 	jr	ra
  5b0e54:	27bd0028 	addiu	sp,sp,40

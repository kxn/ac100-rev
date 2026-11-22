; func cw_priv_sta_assoc_rslt_free @ 0x005c2f44 size=0x54
  5c2f44:	27bdffd8 	addiu	sp,sp,-40
  5c2f48:	afb10020 	sw	s1,32(sp)
  5c2f4c:	afbf0024 	sw	ra,36(sp)
  5c2f50:	afb0001c 	sw	s0,28(sp)
  5c2f54:	8c900010 	lw	s0,16(a0)
  5c2f58:	12000009 	beqz	s0,0x5c2f80
  5c2f5c:	00808821 	move	s1,a0
  5c2f60:	8e040010 	lw	a0,16(s0)
  5c2f64:	10800003 	beqz	a0,0x5c2f74
  5c2f68:	00000000 	nop
  5c2f6c:	0c101f7c 	jal	0x407df0
  5c2f70:	00000000 	nop
  5c2f74:	0c101f7c 	jal	0x407df0
  5c2f78:	02002021 	move	a0,s0
  5c2f7c:	ae200010 	sw	zero,16(s1)
  5c2f80:	8fbf0024 	lw	ra,36(sp)
  5c2f84:	00001021 	move	v0,zero
  5c2f88:	8fb10020 	lw	s1,32(sp)
  5c2f8c:	8fb0001c 	lw	s0,28(sp)
  5c2f90:	03e00008 	jr	ra
  5c2f94:	27bd0028 	addiu	sp,sp,40

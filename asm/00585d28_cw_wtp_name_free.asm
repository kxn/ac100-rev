; func cw_wtp_name_free @ 0x00585d28 size=0x54
  585d28:	27bdffd8 	addiu	sp,sp,-40
  585d2c:	afb10020 	sw	s1,32(sp)
  585d30:	afbf0024 	sw	ra,36(sp)
  585d34:	afb0001c 	sw	s0,28(sp)
  585d38:	8c900010 	lw	s0,16(a0)
  585d3c:	12000009 	beqz	s0,0x585d64
  585d40:	00808821 	move	s1,a0
  585d44:	8e040004 	lw	a0,4(s0)
  585d48:	10800003 	beqz	a0,0x585d58
  585d4c:	00000000 	nop
  585d50:	0c101f7c 	jal	0x407df0
  585d54:	00000000 	nop
  585d58:	0c101f7c 	jal	0x407df0
  585d5c:	02002021 	move	a0,s0
  585d60:	ae200010 	sw	zero,16(s1)
  585d64:	8fbf0024 	lw	ra,36(sp)
  585d68:	00001021 	move	v0,zero
  585d6c:	8fb10020 	lw	s1,32(sp)
  585d70:	8fb0001c 	lw	s0,28(sp)
  585d74:	03e00008 	jr	ra
  585d78:	27bd0028 	addiu	sp,sp,40

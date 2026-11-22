; func cw_duplicate_ipv6_address_free @ 0x00575a24 size=0x54
  575a24:	27bdffd8 	addiu	sp,sp,-40
  575a28:	afb10020 	sw	s1,32(sp)
  575a2c:	afbf0024 	sw	ra,36(sp)
  575a30:	afb0001c 	sw	s0,28(sp)
  575a34:	8c900010 	lw	s0,16(a0)
  575a38:	12000009 	beqz	s0,0x575a60
  575a3c:	00808821 	move	s1,a0
  575a40:	8e040014 	lw	a0,20(s0)
  575a44:	10800003 	beqz	a0,0x575a54
  575a48:	00000000 	nop
  575a4c:	0c101f7c 	jal	0x407df0
  575a50:	00000000 	nop
  575a54:	0c101f7c 	jal	0x407df0
  575a58:	02002021 	move	a0,s0
  575a5c:	ae200010 	sw	zero,16(s1)
  575a60:	8fbf0024 	lw	ra,36(sp)
  575a64:	00001021 	move	v0,zero
  575a68:	8fb10020 	lw	s1,32(sp)
  575a6c:	8fb0001c 	lw	s0,28(sp)
  575a70:	03e00008 	jr	ra
  575a74:	27bd0028 	addiu	sp,sp,40

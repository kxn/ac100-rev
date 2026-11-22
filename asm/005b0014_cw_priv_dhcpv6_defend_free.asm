; func cw_priv_dhcpv6_defend_free @ 0x005b0014 size=0x54
  5b0014:	27bdffd8 	addiu	sp,sp,-40
  5b0018:	afb10020 	sw	s1,32(sp)
  5b001c:	afbf0024 	sw	ra,36(sp)
  5b0020:	afb0001c 	sw	s0,28(sp)
  5b0024:	8c900010 	lw	s0,16(a0)
  5b0028:	12000009 	beqz	s0,0x5b0050
  5b002c:	00808821 	move	s1,a0
  5b0030:	8e040008 	lw	a0,8(s0)
  5b0034:	10800003 	beqz	a0,0x5b0044
  5b0038:	00000000 	nop
  5b003c:	0c101f7c 	jal	0x407df0
  5b0040:	00000000 	nop
  5b0044:	0c101f7c 	jal	0x407df0
  5b0048:	02002021 	move	a0,s0
  5b004c:	ae200010 	sw	zero,16(s1)
  5b0050:	8fbf0024 	lw	ra,36(sp)
  5b0054:	00001021 	move	v0,zero
  5b0058:	8fb10020 	lw	s1,32(sp)
  5b005c:	8fb0001c 	lw	s0,28(sp)
  5b0060:	03e00008 	jr	ra
  5b0064:	27bd0028 	addiu	sp,sp,40

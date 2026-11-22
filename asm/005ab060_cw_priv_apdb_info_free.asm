; func cw_priv_apdb_info_free @ 0x005ab060 size=0x58
  5ab060:	27bdffd8 	addiu	sp,sp,-40
  5ab064:	afb10020 	sw	s1,32(sp)
  5ab068:	afbf0024 	sw	ra,36(sp)
  5ab06c:	afb0001c 	sw	s0,28(sp)
  5ab070:	8c900010 	lw	s0,16(a0)
  5ab074:	1200000a 	beqz	s0,0x5ab0a0
  5ab078:	00808821 	move	s1,a0
  5ab07c:	8e040004 	lw	a0,4(s0)
  5ab080:	10800004 	beqz	a0,0x5ab094
  5ab084:	00000000 	nop
  5ab088:	0c101f7c 	jal	0x407df0
  5ab08c:	00000000 	nop
  5ab090:	ae000004 	sw	zero,4(s0)
  5ab094:	0c101f7c 	jal	0x407df0
  5ab098:	8e240010 	lw	a0,16(s1)
  5ab09c:	ae200010 	sw	zero,16(s1)
  5ab0a0:	8fbf0024 	lw	ra,36(sp)
  5ab0a4:	00001021 	move	v0,zero
  5ab0a8:	8fb10020 	lw	s1,32(sp)
  5ab0ac:	8fb0001c 	lw	s0,28(sp)
  5ab0b0:	03e00008 	jr	ra
  5ab0b4:	27bd0028 	addiu	sp,sp,40

; func cw_add_station_free @ 0x0056feb4 size=0x68
  56feb4:	27bdffd8 	addiu	sp,sp,-40
  56feb8:	afb10020 	sw	s1,32(sp)
  56febc:	afbf0024 	sw	ra,36(sp)
  56fec0:	afb0001c 	sw	s0,28(sp)
  56fec4:	8c900010 	lw	s0,16(a0)
  56fec8:	1200000e 	beqz	s0,0x56ff04
  56fecc:	00808821 	move	s1,a0
  56fed0:	8e040004 	lw	a0,4(s0)
  56fed4:	50800004 	beqzl	a0,0x56fee8
  56fed8:	8e04000c 	lw	a0,12(s0)
  56fedc:	0c101f7c 	jal	0x407df0
  56fee0:	00000000 	nop
  56fee4:	8e04000c 	lw	a0,12(s0)
  56fee8:	10800003 	beqz	a0,0x56fef8
  56feec:	00000000 	nop
  56fef0:	0c101f7c 	jal	0x407df0
  56fef4:	00000000 	nop
  56fef8:	0c101f7c 	jal	0x407df0
  56fefc:	02002021 	move	a0,s0
  56ff00:	ae200010 	sw	zero,16(s1)
  56ff04:	8fbf0024 	lw	ra,36(sp)
  56ff08:	00001021 	move	v0,zero
  56ff0c:	8fb10020 	lw	s1,32(sp)
  56ff10:	8fb0001c 	lw	s0,28(sp)
  56ff14:	03e00008 	jr	ra
  56ff18:	27bd0028 	addiu	sp,sp,40

; func cw_ac_name_free @ 0x0056ea18 size=0x54
  56ea18:	27bdffd8 	addiu	sp,sp,-40
  56ea1c:	afb10020 	sw	s1,32(sp)
  56ea20:	afbf0024 	sw	ra,36(sp)
  56ea24:	afb0001c 	sw	s0,28(sp)
  56ea28:	8c900010 	lw	s0,16(a0)
  56ea2c:	12000009 	beqz	s0,0x56ea54
  56ea30:	00808821 	move	s1,a0
  56ea34:	8e040004 	lw	a0,4(s0)
  56ea38:	10800003 	beqz	a0,0x56ea48
  56ea3c:	00000000 	nop
  56ea40:	0c101f7c 	jal	0x407df0
  56ea44:	00000000 	nop
  56ea48:	0c101f7c 	jal	0x407df0
  56ea4c:	02002021 	move	a0,s0
  56ea50:	ae200010 	sw	zero,16(s1)
  56ea54:	8fbf0024 	lw	ra,36(sp)
  56ea58:	00001021 	move	v0,zero
  56ea5c:	8fb10020 	lw	s1,32(sp)
  56ea60:	8fb0001c 	lw	s0,28(sp)
  56ea64:	03e00008 	jr	ra
  56ea68:	27bd0028 	addiu	sp,sp,40

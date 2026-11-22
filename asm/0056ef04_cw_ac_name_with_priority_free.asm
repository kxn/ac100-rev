; func cw_ac_name_with_priority_free @ 0x0056ef04 size=0x54
  56ef04:	27bdffd8 	addiu	sp,sp,-40
  56ef08:	afb10020 	sw	s1,32(sp)
  56ef0c:	afbf0024 	sw	ra,36(sp)
  56ef10:	afb0001c 	sw	s0,28(sp)
  56ef14:	8c900010 	lw	s0,16(a0)
  56ef18:	12000009 	beqz	s0,0x56ef40
  56ef1c:	00808821 	move	s1,a0
  56ef20:	8e040004 	lw	a0,4(s0)
  56ef24:	10800003 	beqz	a0,0x56ef34
  56ef28:	00000000 	nop
  56ef2c:	0c101f7c 	jal	0x407df0
  56ef30:	00000000 	nop
  56ef34:	0c101f7c 	jal	0x407df0
  56ef38:	02002021 	move	a0,s0
  56ef3c:	ae200010 	sw	zero,16(s1)
  56ef40:	8fbf0024 	lw	ra,36(sp)
  56ef44:	00001021 	move	v0,zero
  56ef48:	8fb10020 	lw	s1,32(sp)
  56ef4c:	8fb0001c 	lw	s0,28(sp)
  56ef50:	03e00008 	jr	ra
  56ef54:	27bd0028 	addiu	sp,sp,40

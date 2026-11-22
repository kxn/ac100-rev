; func cw_priv_delete_implicitly_leave_station_free @ 0x005af26c size=0x54
  5af26c:	27bdffd8 	addiu	sp,sp,-40
  5af270:	afb10020 	sw	s1,32(sp)
  5af274:	afbf0024 	sw	ra,36(sp)
  5af278:	afb0001c 	sw	s0,28(sp)
  5af27c:	8c900010 	lw	s0,16(a0)
  5af280:	12000009 	beqz	s0,0x5af2a8
  5af284:	00808821 	move	s1,a0
  5af288:	8e040004 	lw	a0,4(s0)
  5af28c:	10800003 	beqz	a0,0x5af29c
  5af290:	00000000 	nop
  5af294:	0c101f7c 	jal	0x407df0
  5af298:	00000000 	nop
  5af29c:	0c101f7c 	jal	0x407df0
  5af2a0:	02002021 	move	a0,s0
  5af2a4:	ae200010 	sw	zero,16(s1)
  5af2a8:	8fbf0024 	lw	ra,36(sp)
  5af2ac:	00001021 	move	v0,zero
  5af2b0:	8fb10020 	lw	s1,32(sp)
  5af2b4:	8fb0001c 	lw	s0,28(sp)
  5af2b8:	03e00008 	jr	ra
  5af2bc:	27bd0028 	addiu	sp,sp,40

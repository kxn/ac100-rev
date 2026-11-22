; func cw_duplicate_ipv4_address_free @ 0x005752d8 size=0x54
  5752d8:	27bdffd8 	addiu	sp,sp,-40
  5752dc:	afb10020 	sw	s1,32(sp)
  5752e0:	afbf0024 	sw	ra,36(sp)
  5752e4:	afb0001c 	sw	s0,28(sp)
  5752e8:	8c900010 	lw	s0,16(a0)
  5752ec:	12000009 	beqz	s0,0x575314
  5752f0:	00808821 	move	s1,a0
  5752f4:	8e040008 	lw	a0,8(s0)
  5752f8:	10800003 	beqz	a0,0x575308
  5752fc:	00000000 	nop
  575300:	0c101f7c 	jal	0x407df0
  575304:	00000000 	nop
  575308:	0c101f7c 	jal	0x407df0
  57530c:	02002021 	move	a0,s0
  575310:	ae200010 	sw	zero,16(s1)
  575314:	8fbf0024 	lw	ra,36(sp)
  575318:	00001021 	move	v0,zero
  57531c:	8fb10020 	lw	s1,32(sp)
  575320:	8fb0001c 	lw	s0,28(sp)
  575324:	03e00008 	jr	ra
  575328:	27bd0028 	addiu	sp,sp,40

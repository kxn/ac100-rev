; func cw_priv_roaming_trigger_free @ 0x005bd294 size=0x90
  5bd294:	27bdffd8 	addiu	sp,sp,-40
  5bd298:	afb20020 	sw	s2,32(sp)
  5bd29c:	afbf0024 	sw	ra,36(sp)
  5bd2a0:	afb1001c 	sw	s1,28(sp)
  5bd2a4:	afb00018 	sw	s0,24(sp)
  5bd2a8:	8c900010 	lw	s0,16(a0)
  5bd2ac:	12000016 	beqz	s0,0x5bd308
  5bd2b0:	00809021 	move	s2,a0
  5bd2b4:	8e020008 	lw	v0,8(s0)
  5bd2b8:	10400010 	beqz	v0,0x5bd2fc
  5bd2bc:	00008821 	move	s1,zero
  5bd2c0:	8e020004 	lw	v0,4(s0)
  5bd2c4:	0222102b 	sltu	v0,s1,v0
  5bd2c8:	1040000a 	beqz	v0,0x5bd2f4
  5bd2cc:	8e040008 	lw	a0,8(s0)
  5bd2d0:	00111100 	sll	v0,s1,0x4
  5bd2d4:	00822021 	addu	a0,a0,v0
  5bd2d8:	8c84000c 	lw	a0,12(a0)
  5bd2dc:	1080fff8 	beqz	a0,0x5bd2c0
  5bd2e0:	26310001 	addiu	s1,s1,1
  5bd2e4:	0c101f7c 	jal	0x407df0
  5bd2e8:	00000000 	nop
  5bd2ec:	0816f4b1 	j	0x5bd2c4
  5bd2f0:	8e020004 	lw	v0,4(s0)
  5bd2f4:	0c101f7c 	jal	0x407df0
  5bd2f8:	00000000 	nop
  5bd2fc:	0c101f7c 	jal	0x407df0
  5bd300:	02002021 	move	a0,s0
  5bd304:	ae400010 	sw	zero,16(s2)
  5bd308:	8fbf0024 	lw	ra,36(sp)
  5bd30c:	00001021 	move	v0,zero
  5bd310:	8fb20020 	lw	s2,32(sp)
  5bd314:	8fb1001c 	lw	s1,28(sp)
  5bd318:	8fb00018 	lw	s0,24(sp)
  5bd31c:	03e00008 	jr	ra
  5bd320:	27bd0028 	addiu	sp,sp,40

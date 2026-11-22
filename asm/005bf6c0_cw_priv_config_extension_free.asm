; func cw_priv_config_extension_free @ 0x005bf6c0 size=0x58
  5bf6c0:	27bdffd8 	addiu	sp,sp,-40
  5bf6c4:	afb10020 	sw	s1,32(sp)
  5bf6c8:	afbf0024 	sw	ra,36(sp)
  5bf6cc:	afb0001c 	sw	s0,28(sp)
  5bf6d0:	8c900010 	lw	s0,16(a0)
  5bf6d4:	1200000a 	beqz	s0,0x5bf700
  5bf6d8:	00808821 	move	s1,a0
  5bf6dc:	8e040008 	lw	a0,8(s0)
  5bf6e0:	10800004 	beqz	a0,0x5bf6f4
  5bf6e4:	00000000 	nop
  5bf6e8:	0c101f7c 	jal	0x407df0
  5bf6ec:	00000000 	nop
  5bf6f0:	ae000008 	sw	zero,8(s0)
  5bf6f4:	0c101f7c 	jal	0x407df0
  5bf6f8:	02002021 	move	a0,s0
  5bf6fc:	ae200010 	sw	zero,16(s1)
  5bf700:	8fbf0024 	lw	ra,36(sp)
  5bf704:	00001021 	move	v0,zero
  5bf708:	8fb10020 	lw	s1,32(sp)
  5bf70c:	8fb0001c 	lw	s0,28(sp)
  5bf710:	03e00008 	jr	ra
  5bf714:	27bd0028 	addiu	sp,sp,40

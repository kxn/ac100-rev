; func cw_priv_sta_auth_req_free @ 0x005c4ab4 size=0x54
  5c4ab4:	27bdffd8 	addiu	sp,sp,-40
  5c4ab8:	afb10020 	sw	s1,32(sp)
  5c4abc:	afbf0024 	sw	ra,36(sp)
  5c4ac0:	afb0001c 	sw	s0,28(sp)
  5c4ac4:	8c900010 	lw	s0,16(a0)
  5c4ac8:	12000009 	beqz	s0,0x5c4af0
  5c4acc:	00808821 	move	s1,a0
  5c4ad0:	8e04000c 	lw	a0,12(s0)
  5c4ad4:	10800003 	beqz	a0,0x5c4ae4
  5c4ad8:	00000000 	nop
  5c4adc:	0c101f7c 	jal	0x407df0
  5c4ae0:	00000000 	nop
  5c4ae4:	0c101f7c 	jal	0x407df0
  5c4ae8:	02002021 	move	a0,s0
  5c4aec:	ae200010 	sw	zero,16(s1)
  5c4af0:	8fbf0024 	lw	ra,36(sp)
  5c4af4:	00001021 	move	v0,zero
  5c4af8:	8fb10020 	lw	s1,32(sp)
  5c4afc:	8fb0001c 	lw	s0,28(sp)
  5c4b00:	03e00008 	jr	ra
  5c4b04:	27bd0028 	addiu	sp,sp,40

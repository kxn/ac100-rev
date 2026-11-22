; func cw_priv_trans_data_request_free @ 0x005c9ab8 size=0x58
  5c9ab8:	27bdffd8 	addiu	sp,sp,-40
  5c9abc:	afb10020 	sw	s1,32(sp)
  5c9ac0:	afbf0024 	sw	ra,36(sp)
  5c9ac4:	afb0001c 	sw	s0,28(sp)
  5c9ac8:	8c900010 	lw	s0,16(a0)
  5c9acc:	1200000a 	beqz	s0,0x5c9af8
  5c9ad0:	00808821 	move	s1,a0
  5c9ad4:	8e040008 	lw	a0,8(s0)
  5c9ad8:	10800004 	beqz	a0,0x5c9aec
  5c9adc:	00000000 	nop
  5c9ae0:	0c101f7c 	jal	0x407df0
  5c9ae4:	00000000 	nop
  5c9ae8:	ae000008 	sw	zero,8(s0)
  5c9aec:	0c101f7c 	jal	0x407df0
  5c9af0:	8e240010 	lw	a0,16(s1)
  5c9af4:	ae200010 	sw	zero,16(s1)
  5c9af8:	8fbf0024 	lw	ra,36(sp)
  5c9afc:	00001021 	move	v0,zero
  5c9b00:	8fb10020 	lw	s1,32(sp)
  5c9b04:	8fb0001c 	lw	s0,28(sp)
  5c9b08:	03e00008 	jr	ra
  5c9b0c:	27bd0028 	addiu	sp,sp,40

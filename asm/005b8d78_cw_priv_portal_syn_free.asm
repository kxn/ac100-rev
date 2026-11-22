; func cw_priv_portal_syn_free @ 0x005b8d78 size=0x58
  5b8d78:	27bdffd8 	addiu	sp,sp,-40
  5b8d7c:	afb10020 	sw	s1,32(sp)
  5b8d80:	afbf0024 	sw	ra,36(sp)
  5b8d84:	afb0001c 	sw	s0,28(sp)
  5b8d88:	8c900010 	lw	s0,16(a0)
  5b8d8c:	1200000a 	beqz	s0,0x5b8db8
  5b8d90:	00808821 	move	s1,a0
  5b8d94:	8e040004 	lw	a0,4(s0)
  5b8d98:	10800004 	beqz	a0,0x5b8dac
  5b8d9c:	00000000 	nop
  5b8da0:	0c101f7c 	jal	0x407df0
  5b8da4:	00000000 	nop
  5b8da8:	ae000004 	sw	zero,4(s0)
  5b8dac:	0c101f7c 	jal	0x407df0
  5b8db0:	8e240010 	lw	a0,16(s1)
  5b8db4:	ae200010 	sw	zero,16(s1)
  5b8db8:	8fbf0024 	lw	ra,36(sp)
  5b8dbc:	00001021 	move	v0,zero
  5b8dc0:	8fb10020 	lw	s1,32(sp)
  5b8dc4:	8fb0001c 	lw	s0,28(sp)
  5b8dc8:	03e00008 	jr	ra
  5b8dcc:	27bd0028 	addiu	sp,sp,40

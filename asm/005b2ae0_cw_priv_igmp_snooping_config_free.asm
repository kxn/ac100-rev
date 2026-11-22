; func cw_priv_igmp_snooping_config_free @ 0x005b2ae0 size=0x54
  5b2ae0:	27bdffd8 	addiu	sp,sp,-40
  5b2ae4:	afb10020 	sw	s1,32(sp)
  5b2ae8:	afbf0024 	sw	ra,36(sp)
  5b2aec:	afb0001c 	sw	s0,28(sp)
  5b2af0:	8c900010 	lw	s0,16(a0)
  5b2af4:	12000009 	beqz	s0,0x5b2b1c
  5b2af8:	00808821 	move	s1,a0
  5b2afc:	8e040004 	lw	a0,4(s0)
  5b2b00:	10800003 	beqz	a0,0x5b2b10
  5b2b04:	00000000 	nop
  5b2b08:	0c101f7c 	jal	0x407df0
  5b2b0c:	00000000 	nop
  5b2b10:	0c101f7c 	jal	0x407df0
  5b2b14:	02002021 	move	a0,s0
  5b2b18:	ae200010 	sw	zero,16(s1)
  5b2b1c:	8fbf0024 	lw	ra,36(sp)
  5b2b20:	00001021 	move	v0,zero
  5b2b24:	8fb10020 	lw	s1,32(sp)
  5b2b28:	8fb0001c 	lw	s0,28(sp)
  5b2b2c:	03e00008 	jr	ra
  5b2b30:	27bd0028 	addiu	sp,sp,40

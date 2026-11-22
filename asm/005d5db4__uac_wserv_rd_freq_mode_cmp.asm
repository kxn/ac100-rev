; func _uac_wserv_rd_freq_mode_cmp @ 0x005d5db4 size=0x50
  5d5db4:	27bdffd8 	addiu	sp,sp,-40
  5d5db8:	00c02021 	move	a0,a2
  5d5dbc:	24020001 	li	v0,1
  5d5dc0:	afb10020 	sw	s1,32(sp)
  5d5dc4:	00a08821 	move	s1,a1
  5d5dc8:	afbf0024 	sw	ra,36(sp)
  5d5dcc:	10c00008 	beqz	a2,0x5d5df0
  5d5dd0:	afb0001c 	sw	s0,28(sp)
  5d5dd4:	0c101db4 	jal	0x4076d0
  5d5dd8:	00000000 	nop
  5d5ddc:	02202021 	move	a0,s1
  5d5de0:	0c18750b 	jal	0x61d42c
  5d5de4:	00408021 	move	s0,v0
  5d5de8:	02021026 	xor	v0,s0,v0
  5d5dec:	0002102b 	sltu	v0,zero,v0
  5d5df0:	8fbf0024 	lw	ra,36(sp)
  5d5df4:	8fb10020 	lw	s1,32(sp)
  5d5df8:	8fb0001c 	lw	s0,28(sp)
  5d5dfc:	03e00008 	jr	ra
  5d5e00:	27bd0028 	addiu	sp,sp,40

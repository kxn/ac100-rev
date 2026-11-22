; func cw_priv_chnl_scan_report_free @ 0x005adee4 size=0x54
  5adee4:	27bdffd8 	addiu	sp,sp,-40
  5adee8:	afb10020 	sw	s1,32(sp)
  5adeec:	afbf0024 	sw	ra,36(sp)
  5adef0:	afb0001c 	sw	s0,28(sp)
  5adef4:	8c900010 	lw	s0,16(a0)
  5adef8:	12000009 	beqz	s0,0x5adf20
  5adefc:	00808821 	move	s1,a0
  5adf00:	8e040004 	lw	a0,4(s0)
  5adf04:	10800003 	beqz	a0,0x5adf14
  5adf08:	00000000 	nop
  5adf0c:	0c101f7c 	jal	0x407df0
  5adf10:	00000000 	nop
  5adf14:	0c101f7c 	jal	0x407df0
  5adf18:	02002021 	move	a0,s0
  5adf1c:	ae200010 	sw	zero,16(s1)
  5adf20:	8fbf0024 	lw	ra,36(sp)
  5adf24:	00001021 	move	v0,zero
  5adf28:	8fb10020 	lw	s1,32(sp)
  5adf2c:	8fb0001c 	lw	s0,28(sp)
  5adf30:	03e00008 	jr	ra
  5adf34:	27bd0028 	addiu	sp,sp,40

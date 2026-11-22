; func cw_priv_ap_firmware_id_free @ 0x005a4aa4 size=0x58
  5a4aa4:	27bdffd8 	addiu	sp,sp,-40
  5a4aa8:	afb10020 	sw	s1,32(sp)
  5a4aac:	afbf0024 	sw	ra,36(sp)
  5a4ab0:	afb0001c 	sw	s0,28(sp)
  5a4ab4:	8c900010 	lw	s0,16(a0)
  5a4ab8:	1200000a 	beqz	s0,0x5a4ae4
  5a4abc:	00808821 	move	s1,a0
  5a4ac0:	8e040014 	lw	a0,20(s0)
  5a4ac4:	10800004 	beqz	a0,0x5a4ad8
  5a4ac8:	00000000 	nop
  5a4acc:	0c101f7c 	jal	0x407df0
  5a4ad0:	00000000 	nop
  5a4ad4:	ae000014 	sw	zero,20(s0)
  5a4ad8:	0c101f7c 	jal	0x407df0
  5a4adc:	8e240010 	lw	a0,16(s1)
  5a4ae0:	ae200010 	sw	zero,16(s1)
  5a4ae4:	8fbf0024 	lw	ra,36(sp)
  5a4ae8:	00001021 	move	v0,zero
  5a4aec:	8fb10020 	lw	s1,32(sp)
  5a4af0:	8fb0001c 	lw	s0,28(sp)
  5a4af4:	03e00008 	jr	ra
  5a4af8:	27bd0028 	addiu	sp,sp,40

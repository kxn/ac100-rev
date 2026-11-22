; func cw_ac_ipv4_list_free @ 0x0056de84 size=0x54
  56de84:	27bdffd8 	addiu	sp,sp,-40
  56de88:	afb10020 	sw	s1,32(sp)
  56de8c:	afbf0024 	sw	ra,36(sp)
  56de90:	afb0001c 	sw	s0,28(sp)
  56de94:	8c900010 	lw	s0,16(a0)
  56de98:	12000009 	beqz	s0,0x56dec0
  56de9c:	00808821 	move	s1,a0
  56dea0:	8e040004 	lw	a0,4(s0)
  56dea4:	10800003 	beqz	a0,0x56deb4
  56dea8:	00000000 	nop
  56deac:	0c101f7c 	jal	0x407df0
  56deb0:	00000000 	nop
  56deb4:	0c101f7c 	jal	0x407df0
  56deb8:	02002021 	move	a0,s0
  56debc:	ae200010 	sw	zero,16(s1)
  56dec0:	8fbf0024 	lw	ra,36(sp)
  56dec4:	00001021 	move	v0,zero
  56dec8:	8fb10020 	lw	s1,32(sp)
  56decc:	8fb0001c 	lw	s0,28(sp)
  56ded0:	03e00008 	jr	ra
  56ded4:	27bd0028 	addiu	sp,sp,40

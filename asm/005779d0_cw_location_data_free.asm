; func cw_location_data_free @ 0x005779d0 size=0x54
  5779d0:	27bdffd8 	addiu	sp,sp,-40
  5779d4:	afb10020 	sw	s1,32(sp)
  5779d8:	afbf0024 	sw	ra,36(sp)
  5779dc:	afb0001c 	sw	s0,28(sp)
  5779e0:	8c900010 	lw	s0,16(a0)
  5779e4:	12000009 	beqz	s0,0x577a0c
  5779e8:	00808821 	move	s1,a0
  5779ec:	8e040004 	lw	a0,4(s0)
  5779f0:	10800003 	beqz	a0,0x577a00
  5779f4:	00000000 	nop
  5779f8:	0c101f7c 	jal	0x407df0
  5779fc:	00000000 	nop
  577a00:	0c101f7c 	jal	0x407df0
  577a04:	02002021 	move	a0,s0
  577a08:	ae200010 	sw	zero,16(s1)
  577a0c:	8fbf0024 	lw	ra,36(sp)
  577a10:	00001021 	move	v0,zero
  577a14:	8fb10020 	lw	s1,32(sp)
  577a18:	8fb0001c 	lw	s0,28(sp)
  577a1c:	03e00008 	jr	ra
  577a20:	27bd0028 	addiu	sp,sp,40

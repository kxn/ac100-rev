; func cw_priv_sta_ip_list_free @ 0x005c61d0 size=0x54
  5c61d0:	27bdffd8 	addiu	sp,sp,-40
  5c61d4:	afb10020 	sw	s1,32(sp)
  5c61d8:	afbf0024 	sw	ra,36(sp)
  5c61dc:	afb0001c 	sw	s0,28(sp)
  5c61e0:	8c900010 	lw	s0,16(a0)
  5c61e4:	12000009 	beqz	s0,0x5c620c
  5c61e8:	00808821 	move	s1,a0
  5c61ec:	8e040004 	lw	a0,4(s0)
  5c61f0:	10800003 	beqz	a0,0x5c6200
  5c61f4:	00000000 	nop
  5c61f8:	0c101f7c 	jal	0x407df0
  5c61fc:	00000000 	nop
  5c6200:	0c101f7c 	jal	0x407df0
  5c6204:	02002021 	move	a0,s0
  5c6208:	ae200010 	sw	zero,16(s1)
  5c620c:	8fbf0024 	lw	ra,36(sp)
  5c6210:	00001021 	move	v0,zero
  5c6214:	8fb10020 	lw	s1,32(sp)
  5c6218:	8fb0001c 	lw	s0,28(sp)
  5c621c:	03e00008 	jr	ra
  5c6220:	27bd0028 	addiu	sp,sp,40

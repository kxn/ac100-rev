; func cw_delete_station_free @ 0x005747fc size=0x54
  5747fc:	27bdffd8 	addiu	sp,sp,-40
  574800:	afb10020 	sw	s1,32(sp)
  574804:	afbf0024 	sw	ra,36(sp)
  574808:	afb0001c 	sw	s0,28(sp)
  57480c:	8c900010 	lw	s0,16(a0)
  574810:	12000009 	beqz	s0,0x574838
  574814:	00808821 	move	s1,a0
  574818:	8e040004 	lw	a0,4(s0)
  57481c:	10800003 	beqz	a0,0x57482c
  574820:	00000000 	nop
  574824:	0c101f7c 	jal	0x407df0
  574828:	00000000 	nop
  57482c:	0c101f7c 	jal	0x407df0
  574830:	02002021 	move	a0,s0
  574834:	ae200010 	sw	zero,16(s1)
  574838:	8fbf0024 	lw	ra,36(sp)
  57483c:	00001021 	move	v0,zero
  574840:	8fb10020 	lw	s1,32(sp)
  574844:	8fb0001c 	lw	s0,28(sp)
  574848:	03e00008 	jr	ra
  57484c:	27bd0028 	addiu	sp,sp,40

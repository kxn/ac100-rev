; func cw_image_data_free @ 0x005767fc size=0x54
  5767fc:	27bdffd8 	addiu	sp,sp,-40
  576800:	afb10020 	sw	s1,32(sp)
  576804:	afbf0024 	sw	ra,36(sp)
  576808:	afb0001c 	sw	s0,28(sp)
  57680c:	8c900010 	lw	s0,16(a0)
  576810:	12000009 	beqz	s0,0x576838
  576814:	00808821 	move	s1,a0
  576818:	8e040004 	lw	a0,4(s0)
  57681c:	10800003 	beqz	a0,0x57682c
  576820:	00000000 	nop
  576824:	0c101f7c 	jal	0x407df0
  576828:	00000000 	nop
  57682c:	0c101f7c 	jal	0x407df0
  576830:	02002021 	move	a0,s0
  576834:	ae200010 	sw	zero,16(s1)
  576838:	8fbf0024 	lw	ra,36(sp)
  57683c:	00001021 	move	v0,zero
  576840:	8fb10020 	lw	s1,32(sp)
  576844:	8fb0001c 	lw	s0,28(sp)
  576848:	03e00008 	jr	ra
  57684c:	27bd0028 	addiu	sp,sp,40

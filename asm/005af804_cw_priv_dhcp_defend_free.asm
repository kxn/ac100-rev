; func cw_priv_dhcp_defend_free @ 0x005af804 size=0x54
  5af804:	27bdffd8 	addiu	sp,sp,-40
  5af808:	afb10020 	sw	s1,32(sp)
  5af80c:	afbf0024 	sw	ra,36(sp)
  5af810:	afb0001c 	sw	s0,28(sp)
  5af814:	8c900010 	lw	s0,16(a0)
  5af818:	12000009 	beqz	s0,0x5af840
  5af81c:	00808821 	move	s1,a0
  5af820:	8e040008 	lw	a0,8(s0)
  5af824:	10800003 	beqz	a0,0x5af834
  5af828:	00000000 	nop
  5af82c:	0c101f7c 	jal	0x407df0
  5af830:	00000000 	nop
  5af834:	0c101f7c 	jal	0x407df0
  5af838:	02002021 	move	a0,s0
  5af83c:	ae200010 	sw	zero,16(s1)
  5af840:	8fbf0024 	lw	ra,36(sp)
  5af844:	00001021 	move	v0,zero
  5af848:	8fb10020 	lw	s1,32(sp)
  5af84c:	8fb0001c 	lw	s0,28(sp)
  5af850:	03e00008 	jr	ra
  5af854:	27bd0028 	addiu	sp,sp,40

; func cw_priv_igmp_snooping_group_policy_free @ 0x005b3818 size=0x54
  5b3818:	27bdffd8 	addiu	sp,sp,-40
  5b381c:	afb10020 	sw	s1,32(sp)
  5b3820:	afbf0024 	sw	ra,36(sp)
  5b3824:	afb0001c 	sw	s0,28(sp)
  5b3828:	8c900010 	lw	s0,16(a0)
  5b382c:	12000009 	beqz	s0,0x5b3854
  5b3830:	00808821 	move	s1,a0
  5b3834:	8e040004 	lw	a0,4(s0)
  5b3838:	10800003 	beqz	a0,0x5b3848
  5b383c:	00000000 	nop
  5b3840:	0c101f7c 	jal	0x407df0
  5b3844:	00000000 	nop
  5b3848:	0c101f7c 	jal	0x407df0
  5b384c:	02002021 	move	a0,s0
  5b3850:	ae200010 	sw	zero,16(s1)
  5b3854:	8fbf0024 	lw	ra,36(sp)
  5b3858:	00001021 	move	v0,zero
  5b385c:	8fb10020 	lw	s1,32(sp)
  5b3860:	8fb0001c 	lw	s0,28(sp)
  5b3864:	03e00008 	jr	ra
  5b3868:	27bd0028 	addiu	sp,sp,40

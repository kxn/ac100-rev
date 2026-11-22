; func cw_priv_region_list_free @ 0x005ba7f8 size=0x98
  5ba7f8:	3c02007c 	lui	v0,0x7c
  5ba7fc:	27bdffd8 	addiu	sp,sp,-40
  5ba800:	8c425988 	lw	v0,22920(v0)
  5ba804:	afb10020 	sw	s1,32(sp)
  5ba808:	00808821 	move	s1,a0
  5ba80c:	afbf0024 	sw	ra,36(sp)
  5ba810:	14400013 	bnez	v0,0x5ba860
  5ba814:	afb0001c 	sw	s0,28(sp)
  5ba818:	8e300010 	lw	s0,16(s1)
  5ba81c:	1200000b 	beqz	s0,0x5ba84c
  5ba820:	8fbf0024 	lw	ra,36(sp)
  5ba824:	8e040004 	lw	a0,4(s0)
  5ba828:	10800004 	beqz	a0,0x5ba83c
  5ba82c:	00000000 	nop
  5ba830:	0c101f7c 	jal	0x407df0
  5ba834:	00000000 	nop
  5ba838:	ae000004 	sw	zero,4(s0)
  5ba83c:	0c101f7c 	jal	0x407df0
  5ba840:	8e240010 	lw	a0,16(s1)
  5ba844:	ae200010 	sw	zero,16(s1)
  5ba848:	8fbf0024 	lw	ra,36(sp)
  5ba84c:	00001021 	move	v0,zero
  5ba850:	8fb10020 	lw	s1,32(sp)
  5ba854:	8fb0001c 	lw	s0,28(sp)
  5ba858:	03e00008 	jr	ra
  5ba85c:	27bd0028 	addiu	sp,sp,40
  5ba860:	0c16276a 	jal	0x589da8
  5ba864:	00000000 	nop
  5ba868:	5040ffec 	beqzl	v0,0x5ba81c
  5ba86c:	8e300010 	lw	s0,16(s1)
  5ba870:	3c04006f 	lui	a0,0x6f
  5ba874:	3c05006f 	lui	a1,0x6f
  5ba878:	2484d720 	addiu	a0,a0,-10464
  5ba87c:	24a5d87c 	addiu	a1,a1,-10116
  5ba880:	0c101b74 	jal	0x406dd0
  5ba884:	24060138 	li	a2,312
  5ba888:	0816ea07 	j	0x5ba81c
  5ba88c:	8e300010 	lw	s0,16(s1)

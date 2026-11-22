; func cw_priv_mesh_public_control_val_destroy @ 0x005b67f4 size=0x90
  5b67f4:	27bdffe0 	addiu	sp,sp,-32
  5b67f8:	afb00018 	sw	s0,24(sp)
  5b67fc:	00808021 	move	s0,a0
  5b6800:	10800010 	beqz	a0,0x5b6844
  5b6804:	afbf001c 	sw	ra,28(sp)
  5b6808:	8c840004 	lw	a0,4(a0)
  5b680c:	10800003 	beqz	a0,0x5b681c
  5b6810:	00000000 	nop
  5b6814:	0c101f7c 	jal	0x407df0
  5b6818:	00000000 	nop
  5b681c:	0c16d9bd 	jal	0x5b66f4
  5b6820:	02002021 	move	a0,s0
  5b6824:	02002021 	move	a0,s0
  5b6828:	0c101f7c 	jal	0x407df0
  5b682c:	00008021 	move	s0,zero
  5b6830:	8fbf001c 	lw	ra,28(sp)
  5b6834:	02001021 	move	v0,s0
  5b6838:	8fb00018 	lw	s0,24(sp)
  5b683c:	03e00008 	jr	ra
  5b6840:	27bd0020 	addiu	sp,sp,32
  5b6844:	3c020075 	lui	v0,0x75
  5b6848:	8c42cf58 	lw	v0,-12456(v0)
  5b684c:	1040fff8 	beqz	v0,0x5b6830
  5b6850:	2410ffff 	li	s0,-1
  5b6854:	0c16276a 	jal	0x589da8
  5b6858:	00000000 	nop
  5b685c:	5040fff5 	beqzl	v0,0x5b6834
  5b6860:	8fbf001c 	lw	ra,28(sp)
  5b6864:	3c04006d 	lui	a0,0x6d
  5b6868:	3c05006f 	lui	a1,0x6f
  5b686c:	24847cb0 	addiu	a0,a0,31920
  5b6870:	24a5c754 	addiu	a1,a1,-14508
  5b6874:	0c101b74 	jal	0x406dd0
  5b6878:	2406006c 	li	a2,108
  5b687c:	0816da0d 	j	0x5b6834
  5b6880:	8fbf001c 	lw	ra,28(sp)

; func uac_rrm_uninit @ 0x004af8ac size=0x80
  4af8ac:	3c020076 	lui	v0,0x76
  4af8b0:	27bdffe0 	addiu	sp,sp,-32
  4af8b4:	8c447c10 	lw	a0,31760(v0)
  4af8b8:	afbf001c 	sw	ra,28(sp)
  4af8bc:	10800003 	beqz	a0,0x4af8cc
  4af8c0:	afb00018 	sw	s0,24(sp)
  4af8c4:	0c1020e4 	jal	0x408390
  4af8c8:	00000000 	nop
  4af8cc:	0c12c6dc 	jal	0x4b1b70
  4af8d0:	00000000 	nop
  4af8d4:	10400009 	beqz	v0,0x4af8fc
  4af8d8:	3c020073 	lui	v0,0x73
  4af8dc:	804219b0 	lb	v0,6576(v0)
  4af8e0:	1440000a 	bnez	v0,0x4af90c
  4af8e4:	2410ffff 	li	s0,-1
  4af8e8:	8fbf001c 	lw	ra,28(sp)
  4af8ec:	02001021 	move	v0,s0
  4af8f0:	8fb00018 	lw	s0,24(sp)
  4af8f4:	03e00008 	jr	ra
  4af8f8:	27bd0020 	addiu	sp,sp,32
  4af8fc:	0c12c05a 	jal	0x4b0168
  4af900:	00008021 	move	s0,zero
  4af904:	0812be3b 	j	0x4af8ec
  4af908:	8fbf001c 	lw	ra,28(sp)
  4af90c:	3c04006a 	lui	a0,0x6a
  4af910:	3c05006a 	lui	a1,0x6a
  4af914:	24840f68 	addiu	a0,a0,3944
  4af918:	24a515ec 	addiu	a1,a1,5612
  4af91c:	0c101b74 	jal	0x406dd0
  4af920:	24060bb2 	li	a2,2994
  4af924:	0812be3b 	j	0x4af8ec
  4af928:	8fbf001c 	lw	ra,28(sp)

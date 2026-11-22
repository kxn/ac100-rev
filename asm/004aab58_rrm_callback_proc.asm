; func rrm_callback_proc @ 0x004aab58 size=0xec
  4aab58:	27bdffc0 	addiu	sp,sp,-64
  4aab5c:	afb2002c 	sw	s2,44(sp)
  4aab60:	00809021 	move	s2,a0
  4aab64:	3c040076 	lui	a0,0x76
  4aab68:	afb50038 	sw	s5,56(sp)
  4aab6c:	afb40034 	sw	s4,52(sp)
  4aab70:	3c15006a 	lui	s5,0x6a
  4aab74:	24847c04 	addiu	a0,a0,31748
  4aab78:	afb30030 	sw	s3,48(sp)
  4aab7c:	afb10028 	sw	s1,40(sp)
  4aab80:	3c14006a 	lui	s4,0x6a
  4aab84:	afb00024 	sw	s0,36(sp)
  4aab88:	00008821 	move	s1,zero
  4aab8c:	afbf003c 	sw	ra,60(sp)
  4aab90:	0c10206c 	jal	0x4081b0
  4aab94:	3c130073 	lui	s3,0x73
  4aab98:	26940020 	addiu	s4,s4,32
  4aab9c:	00408021 	move	s0,v0
  4aaba0:	12000012 	beqz	s0,0x4aabec
  4aaba4:	26b51310 	addiu	s5,s5,4880
  4aaba8:	1640001a 	bnez	s2,0x4aac14
  4aabac:	24020001 	li	v0,1
  4aabb0:	8e190010 	lw	t9,16(s0)
  4aabb4:	13200004 	beqz	t9,0x4aabc8
  4aabb8:	00000000 	nop
  4aabbc:	0320f809 	jalr	t9
  4aabc0:	00000000 	nop
  4aabc4:	00408821 	move	s1,v0
  4aabc8:	12200003 	beqz	s1,0x4aabd8
  4aabcc:	826219b0 	lb	v0,6576(s3)
  4aabd0:	54400014 	bnezl	v0,0x4aac24
  4aabd4:	8e02000c 	lw	v0,12(s0)
  4aabd8:	0c1021a0 	jal	0x408680
  4aabdc:	02002021 	move	a0,s0
  4aabe0:	00408021 	move	s0,v0
  4aabe4:	1600fff0 	bnez	s0,0x4aaba8
  4aabe8:	00000000 	nop
  4aabec:	8fbf003c 	lw	ra,60(sp)
  4aabf0:	00001021 	move	v0,zero
  4aabf4:	8fb50038 	lw	s5,56(sp)
  4aabf8:	8fb40034 	lw	s4,52(sp)
  4aabfc:	8fb30030 	lw	s3,48(sp)
  4aac00:	8fb2002c 	lw	s2,44(sp)
  4aac04:	8fb10028 	lw	s1,40(sp)
  4aac08:	8fb00024 	lw	s0,36(sp)
  4aac0c:	03e00008 	jr	ra
  4aac10:	27bd0040 	addiu	sp,sp,64
  4aac14:	1642ffec 	bne	s2,v0,0x4aabc8
  4aac18:	00000000 	nop
  4aac1c:	0812aaed 	j	0x4aabb4
  4aac20:	8e190014 	lw	t9,20(s0)
  4aac24:	24060171 	li	a2,369
  4aac28:	02802021 	move	a0,s4
  4aac2c:	02a02821 	move	a1,s5
  4aac30:	02403821 	move	a3,s2
  4aac34:	0c101b74 	jal	0x406dd0
  4aac38:	afa20010 	sw	v0,16(sp)
  4aac3c:	0812aaf6 	j	0x4aabd8
  4aac40:	00000000 	nop

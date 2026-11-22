; func cw_priv_portal_data_free @ 0x005b8848 size=0x58
  5b8848:	27bdffd8 	addiu	sp,sp,-40
  5b884c:	afb10020 	sw	s1,32(sp)
  5b8850:	afbf0024 	sw	ra,36(sp)
  5b8854:	afb0001c 	sw	s0,28(sp)
  5b8858:	8c900010 	lw	s0,16(a0)
  5b885c:	1200000a 	beqz	s0,0x5b8888
  5b8860:	00808821 	move	s1,a0
  5b8864:	8e040004 	lw	a0,4(s0)
  5b8868:	10800004 	beqz	a0,0x5b887c
  5b886c:	00000000 	nop
  5b8870:	0c101f7c 	jal	0x407df0
  5b8874:	00000000 	nop
  5b8878:	ae000004 	sw	zero,4(s0)
  5b887c:	0c101f7c 	jal	0x407df0
  5b8880:	8e240010 	lw	a0,16(s1)
  5b8884:	ae200010 	sw	zero,16(s1)
  5b8888:	8fbf0024 	lw	ra,36(sp)
  5b888c:	00001021 	move	v0,zero
  5b8890:	8fb10020 	lw	s1,32(sp)
  5b8894:	8fb0001c 	lw	s0,28(sp)
  5b8898:	03e00008 	jr	ra
  5b889c:	27bd0028 	addiu	sp,sp,40

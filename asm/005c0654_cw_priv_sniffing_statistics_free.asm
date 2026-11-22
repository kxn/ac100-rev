; func cw_priv_sniffing_statistics_free @ 0x005c0654 size=0x54
  5c0654:	27bdffd8 	addiu	sp,sp,-40
  5c0658:	afb10020 	sw	s1,32(sp)
  5c065c:	afbf0024 	sw	ra,36(sp)
  5c0660:	afb0001c 	sw	s0,28(sp)
  5c0664:	8c900010 	lw	s0,16(a0)
  5c0668:	12000009 	beqz	s0,0x5c0690
  5c066c:	00808821 	move	s1,a0
  5c0670:	8e040004 	lw	a0,4(s0)
  5c0674:	10800003 	beqz	a0,0x5c0684
  5c0678:	00000000 	nop
  5c067c:	0c101f7c 	jal	0x407df0
  5c0680:	00000000 	nop
  5c0684:	0c101f7c 	jal	0x407df0
  5c0688:	02002021 	move	a0,s0
  5c068c:	ae200010 	sw	zero,16(s1)
  5c0690:	8fbf0024 	lw	ra,36(sp)
  5c0694:	00001021 	move	v0,zero
  5c0698:	8fb10020 	lw	s1,32(sp)
  5c069c:	8fb0001c 	lw	s0,28(sp)
  5c06a0:	03e00008 	jr	ra
  5c06a4:	27bd0028 	addiu	sp,sp,40

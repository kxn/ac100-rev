; func cw_priv_sta_statistics_free @ 0x005c7804 size=0x54
  5c7804:	27bdffd8 	addiu	sp,sp,-40
  5c7808:	afb10020 	sw	s1,32(sp)
  5c780c:	afbf0024 	sw	ra,36(sp)
  5c7810:	afb0001c 	sw	s0,28(sp)
  5c7814:	8c900010 	lw	s0,16(a0)
  5c7818:	12000009 	beqz	s0,0x5c7840
  5c781c:	00808821 	move	s1,a0
  5c7820:	8e040004 	lw	a0,4(s0)
  5c7824:	10800003 	beqz	a0,0x5c7834
  5c7828:	00000000 	nop
  5c782c:	0c101f7c 	jal	0x407df0
  5c7830:	00000000 	nop
  5c7834:	0c101f7c 	jal	0x407df0
  5c7838:	02002021 	move	a0,s0
  5c783c:	ae200010 	sw	zero,16(s1)
  5c7840:	8fbf0024 	lw	ra,36(sp)
  5c7844:	00001021 	move	v0,zero
  5c7848:	8fb10020 	lw	s1,32(sp)
  5c784c:	8fb0001c 	lw	s0,28(sp)
  5c7850:	03e00008 	jr	ra
  5c7854:	27bd0028 	addiu	sp,sp,40

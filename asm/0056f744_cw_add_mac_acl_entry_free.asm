; func cw_add_mac_acl_entry_free @ 0x0056f744 size=0x54
  56f744:	27bdffd8 	addiu	sp,sp,-40
  56f748:	afb10020 	sw	s1,32(sp)
  56f74c:	afbf0024 	sw	ra,36(sp)
  56f750:	afb0001c 	sw	s0,28(sp)
  56f754:	8c900010 	lw	s0,16(a0)
  56f758:	12000009 	beqz	s0,0x56f780
  56f75c:	00808821 	move	s1,a0
  56f760:	8e040004 	lw	a0,4(s0)
  56f764:	10800003 	beqz	a0,0x56f774
  56f768:	00000000 	nop
  56f76c:	0c101f7c 	jal	0x407df0
  56f770:	00000000 	nop
  56f774:	0c101f7c 	jal	0x407df0
  56f778:	02002021 	move	a0,s0
  56f77c:	ae200010 	sw	zero,16(s1)
  56f780:	8fbf0024 	lw	ra,36(sp)
  56f784:	00001021 	move	v0,zero
  56f788:	8fb10020 	lw	s1,32(sp)
  56f78c:	8fb0001c 	lw	s0,28(sp)
  56f790:	03e00008 	jr	ra
  56f794:	27bd0028 	addiu	sp,sp,40

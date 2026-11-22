; func cw_priv_wlan_list_free @ 0x005cb6ec size=0x54
  5cb6ec:	27bdffd8 	addiu	sp,sp,-40
  5cb6f0:	afb10020 	sw	s1,32(sp)
  5cb6f4:	afbf0024 	sw	ra,36(sp)
  5cb6f8:	afb0001c 	sw	s0,28(sp)
  5cb6fc:	8c900010 	lw	s0,16(a0)
  5cb700:	12000009 	beqz	s0,0x5cb728
  5cb704:	00808821 	move	s1,a0
  5cb708:	8e040008 	lw	a0,8(s0)
  5cb70c:	10800003 	beqz	a0,0x5cb71c
  5cb710:	00000000 	nop
  5cb714:	0c101f7c 	jal	0x407df0
  5cb718:	00000000 	nop
  5cb71c:	0c101f7c 	jal	0x407df0
  5cb720:	02002021 	move	a0,s0
  5cb724:	ae200010 	sw	zero,16(s1)
  5cb728:	8fbf0024 	lw	ra,36(sp)
  5cb72c:	00001021 	move	v0,zero
  5cb730:	8fb10020 	lw	s1,32(sp)
  5cb734:	8fb0001c 	lw	s0,28(sp)
  5cb738:	03e00008 	jr	ra
  5cb73c:	27bd0028 	addiu	sp,sp,40

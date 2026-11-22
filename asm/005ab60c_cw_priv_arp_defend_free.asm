; func cw_priv_arp_defend_free @ 0x005ab60c size=0x58
  5ab60c:	27bdffd8 	addiu	sp,sp,-40
  5ab610:	afb10020 	sw	s1,32(sp)
  5ab614:	afbf0024 	sw	ra,36(sp)
  5ab618:	afb0001c 	sw	s0,28(sp)
  5ab61c:	8c900010 	lw	s0,16(a0)
  5ab620:	1200000a 	beqz	s0,0x5ab64c
  5ab624:	00808821 	move	s1,a0
  5ab628:	8e040008 	lw	a0,8(s0)
  5ab62c:	10800004 	beqz	a0,0x5ab640
  5ab630:	00000000 	nop
  5ab634:	0c101f7c 	jal	0x407df0
  5ab638:	00000000 	nop
  5ab63c:	ae000008 	sw	zero,8(s0)
  5ab640:	0c101f7c 	jal	0x407df0
  5ab644:	02002021 	move	a0,s0
  5ab648:	ae200010 	sw	zero,16(s1)
  5ab64c:	8fbf0024 	lw	ra,36(sp)
  5ab650:	00001021 	move	v0,zero
  5ab654:	8fb10020 	lw	s1,32(sp)
  5ab658:	8fb0001c 	lw	s0,28(sp)
  5ab65c:	03e00008 	jr	ra
  5ab660:	27bd0028 	addiu	sp,sp,40

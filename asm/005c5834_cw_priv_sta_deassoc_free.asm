; func cw_priv_sta_deassoc_free @ 0x005c5834 size=0x3c
  5c5834:	27bdffe0 	addiu	sp,sp,-32
  5c5838:	afb00018 	sw	s0,24(sp)
  5c583c:	00808021 	move	s0,a0
  5c5840:	afbf001c 	sw	ra,28(sp)
  5c5844:	8c840010 	lw	a0,16(a0)
  5c5848:	10800005 	beqz	a0,0x5c5860
  5c584c:	8fbf001c 	lw	ra,28(sp)
  5c5850:	0c101f7c 	jal	0x407df0
  5c5854:	00000000 	nop
  5c5858:	ae000010 	sw	zero,16(s0)
  5c585c:	8fbf001c 	lw	ra,28(sp)
  5c5860:	00001021 	move	v0,zero
  5c5864:	8fb00018 	lw	s0,24(sp)
  5c5868:	03e00008 	jr	ra
  5c586c:	27bd0020 	addiu	sp,sp,32

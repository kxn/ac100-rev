; func cw_user_send_pkt_node_destroy @ 0x005882a0 size=0x4c
  5882a0:	27bdffe0 	addiu	sp,sp,-32
  5882a4:	afb00018 	sw	s0,24(sp)
  5882a8:	00808021 	move	s0,a0
  5882ac:	1080000b 	beqz	a0,0x5882dc
  5882b0:	afbf001c 	sw	ra,28(sp)
  5882b4:	8c84000c 	lw	a0,12(a0)
  5882b8:	50800004 	beqzl	a0,0x5882cc
  5882bc:	02002021 	move	a0,s0
  5882c0:	0c16207c 	jal	0x5881f0
  5882c4:	00000000 	nop
  5882c8:	02002021 	move	a0,s0
  5882cc:	8fbf001c 	lw	ra,28(sp)
  5882d0:	8fb00018 	lw	s0,24(sp)
  5882d4:	08101f7c 	j	0x407df0
  5882d8:	27bd0020 	addiu	sp,sp,32
  5882dc:	8fbf001c 	lw	ra,28(sp)
  5882e0:	8fb00018 	lw	s0,24(sp)
  5882e4:	03e00008 	jr	ra
  5882e8:	27bd0020 	addiu	sp,sp,32

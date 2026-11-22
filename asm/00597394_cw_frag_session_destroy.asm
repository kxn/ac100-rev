; func cw_frag_session_destroy @ 0x00597394 size=0x4c
  597394:	27bdffe0 	addiu	sp,sp,-32
  597398:	afb00018 	sw	s0,24(sp)
  59739c:	00808021 	move	s0,a0
  5973a0:	1080000b 	beqz	a0,0x5973d0
  5973a4:	afbf001c 	sw	ra,28(sp)
  5973a8:	8c990040 	lw	t9,64(a0)
  5973ac:	53200004 	beqzl	t9,0x5973c0
  5973b0:	02002021 	move	a0,s0
  5973b4:	0320f809 	jalr	t9
  5973b8:	00000000 	nop
  5973bc:	02002021 	move	a0,s0
  5973c0:	8fbf001c 	lw	ra,28(sp)
  5973c4:	8fb00018 	lw	s0,24(sp)
  5973c8:	08101f7c 	j	0x407df0
  5973cc:	27bd0020 	addiu	sp,sp,32
  5973d0:	8fbf001c 	lw	ra,28(sp)
  5973d4:	8fb00018 	lw	s0,24(sp)
  5973d8:	03e00008 	jr	ra
  5973dc:	27bd0020 	addiu	sp,sp,32
